#include <stdio.h>
#include <unistd.h>  // pour usleep()
#include <stdlib.h>

// Efface tout l'écran et replace le curseur en haut à gauche
void update() {
    printf("\033[H\033[J");
}

// Place le curseur à la ligne x, colonne y
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", x, y);
}

// Affiche la vache regardant vers la gauche, avec les yeux passés en paramètre
void affiche_vache(const char *eyes) {
    printf("\n"); // sans cette ligne, la tête de la vache « disparaîtrait »    
    printf("            ^__^\n");
    printf("            (%s)\\_______\n", eyes);
    printf("            (__)\\       )\\/\\\n");
    printf("               ||----w |\n");
    printf("               ||     ||\n");
}

// Vache miroir avec animation des jambes selon leg_frame (0 ou 1)
void affiche_vache_mirror(const char *eyes, int row, int col, int leg_frame) {
    printf("\n");
    gotoxy(row+0, col);  printf("            ^__^    ");
    gotoxy(row+1, col);  printf("     ______/(%s)   ", eyes);
    gotoxy(row+2, col);  printf(" \\/\\(      /(__)    ");
    gotoxy(row+3, col);  printf("    | w----||        ");

    // Animation des jambes
    gotoxy(row+4, col);
    if (leg_frame == 0) {
        // Pieds “plantés”
        printf("    ||     ||        ");
    } else {
        // Pied droit avancé (on inverse barres)
        printf("    \\\\     //        ");
    }
}

// Affiche la vache miroir tête baissée (yeux fermés) et un rang de "herbe"
void affiche_vache_mirror_graze(int row, int col, const char *tail) {
    printf("\n");
    gotoxy(row+0, col);  printf("                ");
    gotoxy(row+1, col);  printf("     ________ ^__^   ");
    gotoxy(row+2, col);  printf(" %s(        \\(--)    ", tail);
    gotoxy(row+3, col);  printf("    | w----|| (__)      ");
    gotoxy(row+4, col);  printf("    ||     ||        ");
    gotoxy(row+5, col); printf("             ^^  ^^    ");  // herbe
}

int main(void) {
    // 1) La vache cligne 3 fois
    for (int i = 0; i < 3; i++) {
        // yeux ouverts
        update();
        gotoxy(5, 10);
        affiche_vache("oo");
        fflush(stdout);
        usleep(400000);  // 0,4 s

        // yeux fermés
        update();
        gotoxy(5, 10);
        affiche_vache("--");
        fflush(stdout);
        usleep(200000);  // 0,2 s
    }

    // Petite pause avant le retournement
    usleep(300000);

    // 2) Marche vers la droite avec animation des jambes
    int leg_frame   = 0;
    int frame_count = 0;
    int last_col = 5;
    for (int c = 5; c <= 30; c += 1) {
        last_col = c;    // on mémorise à chaque itération
        frame_count++;

        update();
        if (frame_count % 5 == 0) {
            // Toutes les 5 frames, la vache cligne (yeux fermés "--")
            affiche_vache_mirror("--", 5, c, leg_frame);
        } else {
            // Sinon, yeux ouverts
            affiche_vache_mirror("oo", 5, c, leg_frame);
        }
        fflush(stdout);
        usleep(100000);

        // Alterner la position des jambes
        leg_frame = 1 - leg_frame;
    }

    // 3) Grazing en miroir, à la position atteinte
    const char *tails[] = {"\\/\\", "/\\_", "\\__", "__\\", "_\\/",
                           "\\/\\", "/\\_", "\\__", "__\\", "_\\/"};
    int nframes = sizeof(tails)/sizeof(*tails);
    for (int f = 0; f < nframes; f++) {
        update();
        affiche_vache_mirror_graze(5, last_col, tails[f]);
        fflush(stdout);
        usleep(200000);
    }

    // 4) Relever la tête et cligner 2 fois, face à droite
    for (int i = 0; i < 2; i++) {
        // Clignement : yeux ouverts
        update();
        gotoxy(5, last_col);
        affiche_vache_mirror("oo", 5, last_col, leg_frame);
        fflush(stdout);
        usleep(400000);

        // Clignement : yeux fermés
        update();
        gotoxy(5, last_col);
        affiche_vache_mirror("--", 5, last_col, leg_frame);
        fflush(stdout);
        usleep(200000);
    }

    // 5) Dernier état : yeux ouverts
    update();
    gotoxy(5, last_col);
    affiche_vache_mirror("oo", 5, last_col, leg_frame);
    printf("\n");

    return 0;
}
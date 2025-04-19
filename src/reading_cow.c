#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>   // pour sleep()

// Efface tout l'écran et replace le curseur en haut à gauche
void update() {
    printf("\033[H\033[J");
}

// Affiche la bulle autour des 'len' premiers caractères de buf
void print_bubble(const char *buf, int len) {
    // bord supérieur
    printf("  ");
    for (int i = 0; i < len + 2; i++) putchar('-');
    printf("\n");
    // texte
    printf(" < ");
    for (int i = 0; i < len; i++) putchar(buf[i]);
    printf(" >\n");
    // bord inférieur
    printf("  ");
    for (int i = 0; i < len + 2; i++) putchar('-');
    printf("\n\n");
}

// Affiche la vache avec le caractère 'mouth' dans la bouche
void print_cow(char mouth) {
    printf("      \\   ^__^\n");
    printf("       \\  (oo)\\_______\n");
    printf("          (__)\\       )\\/\\\n");
    if (mouth != '\n') printf("           %c ||----w |\n", mouth);
    else printf("             ||----w |\n");
    printf("             ||     ||\n");
}

// Anime la lecture de src[0..total-1]
void animate(const char *src, int total) {
    char buffer[1024] = {0};
    int len = 0;

    for (int i = 0; i < total; i++) {
        char c = src[i];

        // 1) effacement
        update();

        // 2) bulle de ce qui est déjà avalé
        print_bubble(buffer, len);

        // 3) vache qui lit le caractère courant
        print_cow(c);

        fflush(stdout);
        sleep(1);

        // 4) on ajoute c au buffer
        buffer[len++] = c;
    }
    // fin
    update();
    print_bubble(buffer, len);
    print_cow(' ');
    fflush(stdout);
}

int main(int argc, char *argv[]) {
    char src[1024];
    int total = 0;

    if (argc > 1) {
        // Lecture depuis un fichier passé en argument
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            perror(argv[1]);
            return 1;
        }
        char c;
        // premier caractère
        fscanf(f, "%c", &c);
        // on boucle jusqu'à feof ou buffer plein
        while (!feof(f) && total < (int)sizeof(src)) {
            src[total++] = c;
            fscanf(f, "%c", &c);
        }
        fclose(f);
    } else {
        // Lecture d'une seule phrase depuis stdin, caractère par caractère
        // jusqu'au '\n' ou EOF
        printf("Tapez la chaîne de caractères: ");
        char c;
        while (total < (int)sizeof(src) &&
               fscanf(stdin, "%c", &c) == 1 &&
               c != '\n') {
            src[total++] = c;
        }
    }

    // Lancement de l'animation
    animate(src, total);
    return 0;
}

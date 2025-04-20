#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BYEBYELIFE 0
#define LIFESUCKS 1
#define LIFEROCKS 2

void update() {
    printf("\033[H\033[J");
}

// Place le curseur à la ligne x, colonne y
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", x, y);
}


void affiche_vache(int etat){
    update();
    gotoxy(5,0);
    //affiche une vache correspondant au niveau de fitness
    switch (etat){
        case BYEBYELIFE : {
            printf("   ^__^\n");
            printf("   (XX)_,,,,___\n");
            printf("   (__)\\)))    )\\\n");
            printf("      \\/----w / |\n");
            printf("      /\\     /\\ \\\n");
        break;
        }
        
        case LIFESUCKS : {
            printf("   ^__^\n");
            printf("   (--)\\_______\n");
            printf("   (__)\\       )\\/\\\n");
            printf("      ||----w |\n");
            printf("      ||     ||\n");
        break;
        }
        
        case LIFEROCKS : {
            printf("   ^__^\n");
            printf("   (^^)\\_______\n");
            printf("   (__)\\       )\\/\\\n");
            printf("    U ||----w |\n");
            printf("      ||     ||\n");
        break;
        }
    }
}

long generer_entier ( long borne ) {
static int seme = 0;
if (! seme ) {
srandom ( getpid ());
seme = 1;
}
return random () % borne ;
}

int int_max(int a,int b){
     if (a>b) return a;
     return b;
}

int int_min(int a,int b){
     if (a>b) return b;
     return a;
}


void fitness_update(int *fitness, int lunchfood){
    //actualise la variable fitness en fonction de l'entree du joueur
    //verifie que fitness reste dans son domaine de definition {0,...,10}
    *fitness = int_min(int_max(*fitness + lunchfood - generer_entier(4),0),10);
}

void stock_update(int *stock, int lunchfood){
    //actualise la variable stock en fonction de l'entree du joueur
    //verifie que fitness reste dans son domaine de definition {0,...,10}
    *stock = int_min(int_max(*stock - lunchfood + generer_entier(8) - 4,0),10);
}

int lire_lunchfood(int stock) {
    //lit en entree standard la valeur rentree par le joueur
    //si l'entree est invalide, la sortie sera la valeur vallable la plus proche possible (soit 0 soit stock)
    char c ;
    scanf("\n%c", &c) ;
    if ((c < '0') || (c > stock + '0')) {
        if(c > stock + '0') return stock ;
        return c-'0' ;
    }
        return 0;
}

int fitness2state(fitness){
    switch (fitness){
        case 0 : return BYEBYELIFE;
        case 10 : return BYEBYELIFE;
        case 4 : return LIFEROCKS;
        case 5 : return LIFEROCKS;
        case 6 : return LIFEROCKS;
        default : return LIFESUCKS;
    }
}

int main(){
    int lunchfood,fitness = 5, stock = 5,score = 0;

    while (fitness2state(fitness) != BYEBYELIFE){
        lunchfood = lire_lunchfood(stock);
        fitness_update(&fitness,lunchfood);
        stock_update(&stock,lunchfood);
        affiche_vache(fitness2state(fitness));
        printf("%d",fitness);
        score++;
    }
    printf("perdu en %d tours\n",score);
    return 0;
}
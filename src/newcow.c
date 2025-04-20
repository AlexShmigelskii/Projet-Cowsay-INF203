#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void affiche_vache(char *eyes, char *tongue, int tail_length, int legs_length) {

    // Fonction d'affichage de la vache
    // Paramètres :
    //   eyes        : chaîne de 2 caractères pour les yeux
    //   tongue      : chaîne de un ou deux caractères pour la langue (peut être vide)
    //   tail_length : entier indiquant le nombre de caractères supplémentaires pour la queue
    //   legs_length : entier indiquant le nombre de lignes supplémentaires pour allonger les jambes

    // 1) Tête et yeux
    printf("      \\    ^__^\n");
    printf("       \\   (%s)\\_______\n", eyes);

    // 2) Queue : on imprime toujours la même indentation, puis ')'
    printf("           (__)\\       )");
    //    et on répète "\/" tail_length fois
    for (int i = 0; i < tail_length; i++) {
        printf("\\/");
    }
    // puis on termine la ligne
    printf("\n");

    // 3) Ligne de la langue
    switch (strlen(tongue)) {
        case 1:
            printf("            %s  ||----w |\n", tongue);
            break;
        case 2:
            printf("            %s ||----w |\n", tongue);
            break;
        default:
            printf("               ||----w |\n");
            break;
    }

    // 4) Jambes
    printf("               ||     ||\n");
    for (int i = 0; i < legs_length; i++) {
        printf("               ||     ||\n");
    }
}

int main(int argc, char *argv[]) {
    // Valeurs par défaut
    char eyes[3] = "oo";      // yeux par défaut (2 caractères)
    char tongue[3] = "";      // langue vide par défaut (affiche la ligne par défaut)
    int tail_length = 0;      // queue par défaut sans allongement
    int legs_length = 0;      // jambes par défaut (1 ligne seulement)

    // Analyse des arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--eyes") == 0) {
            if (i + 1 < argc) {
                if (strlen(argv[i + 1]) == 2) {
                    strcpy(eyes, argv[i + 1]);
                    i++; // sauter l'argument traité
                } else {
                    fprintf(stderr, "Erreur : l'argument pour -e (eyes) doit être une chaîne de deux caractères.\n");
                    return 1;
                }
            } else {
                fprintf(stderr, "Erreur : -e requiert un argument (deux caractères).\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "-T") == 0 || strcmp(argv[i], "--tongue") == 0) {
            if (i + 1 < argc) {
                if (strlen(argv[i + 1]) <= 2) {
                    strcpy(tongue, argv[i + 1]);
                    i++;
                } else {
                    fprintf(stderr, "Erreur : l'argument pour -T doit être une chaîne de un ou deux caractères.\n");
                    return 1;
                }
            } else {
                fprintf(stderr, "Erreur : -T requiert un argument (un ou deux caractères).\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "--tail") == 0) {
            if (i + 1 < argc) {
                tail_length = atoi(argv[i + 1]); // ASCII to Int
                i++;
            } else {
                fprintf(stderr, "Erreur : --tail requiert un argument numérique.\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "--legs") == 0) {
            if (i + 1 < argc) {
                legs_length = atoi(argv[i + 1]);
                i++;
            } else {
                fprintf(stderr, "Erreur : --legs requiert un argument numérique.\n");
                return 1;
            }
        }
        // D'autres options pourraient être traitées ici.
    }
    
    // Appel de la fonction affiche_vache avec les paramètres personnalisés
    affiche_vache(eyes, tongue, tail_length, legs_length);
    return 0;
}
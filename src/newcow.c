#include <stdio.h>
#include <string.h>

void affiche_vache(char *eyes, char *tongue) {
    printf("      \\    ^__^\n");
    // On insère la chaîne eyes dans la partie correspondant aux yeux de la vache.
    printf("       \\   (%s)\\_______\n", eyes);
    printf("           (__)\\       )\\/\\\n");
    switch (strlen(tongue)){
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
    printf("               ||     ||\n");
}

int main(int argc, char *argv[]) {
    // Valeur par défaut pour les yeux : "oo" (deux caractères)
    char eyes[3] = "oo";
    char tongue[3] = "";

    // Parcours des arguments pour traiter -e ou --eyes
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--eyes") == 0) {
            if (i + 1 < argc) { // S'assurer qu'un argument suit l'option
                if (strlen(argv[i + 1]) == 2) {
                    strcpy(eyes, argv[i + 1]);
                    i++; // On saute l'argument utilisé pour les yeux
                } else {
                    fprintf(stderr, "Erreur : l'argument pour -e doit être une chaîne de deux caractères.\n");
                    return 1;
                }
            } else {
                fprintf(stderr, "Erreur : -e requiert un argument (deux caractères).\n");
                return 1;
            }
        }
        
        if (strcmp(argv[i], "-T") == 0 || strcmp(argv[i], "--tongue") == 0) {
            if (i + 1 < argc) {
                // Pour -T, on autorise une chaîne de un ou deux caractères
                if (strlen(argv[i + 1]) <= 2) {
                    strcpy(tongue, argv[i + 1]);
                    i++; // On saute l'argument utilisé pour la langue
                } else {
                    fprintf(stderr, "Erreur : l'argument pour -T doit être une chaîne de un ou deux caractères.\n");
                    return 1;
                }
            } else {
                fprintf(stderr, "Erreur : -T requiert un argument (un ou deux caractères).\n");
                return 1;
            }
        }
    }

    // Appel de la fonction affiche_vache
    affiche_vache(eyes, tongue);

    return 0;
}
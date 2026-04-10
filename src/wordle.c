#include <stdio.h>
#include <string.h>
#include "../include/filter.h"

#define MAX_MOTS 3000
#define TAILLE_MOT 50

int charger_mots(char mots[][TAILLE_MOT]) {
    FILE *fichier = fopen("ressource/bdd_wordle.txt", "r");

    if (fichier == NULL) {
        printf("Erreur ouverture fichier\n");
        return 0;
    }

    int n = 0;

    while (n < MAX_MOTS && fscanf(fichier, "%s", mots[n]) == 1) {
        n++;
    }

    fclose(fichier);
    return n;
}

int main() {
    char mots[MAX_MOTS][TAILLE_MOT];
    int choix;
    char lettre;
    char sub[50];

    int n = charger_mots(mots);

    printf("Nombre de mots charges : %d\n", n);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Filtre contient une lettre\n");
        printf("2. Filtre exclure une lettre\n");
        printf("3. Filtre substring\n");
        printf("4. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrer la lettre minuscule : ");
                scanf(" %c", &lettre);
                filtre_contient(mots, n, lettre);
                break;

            case 2:
                printf("Entrer la lettre minuscule : ");
                scanf(" %c", &lettre);
                filtre_exclure(mots, n, lettre);
                break;

            case 3:
                printf("Entrer le substring en minuscule : ");
                scanf("%s", sub);
                filtre_substring(mots, n, sub);
                break;

            case 4:
                printf("Fin du programme\n");
                break;

            default:
                printf("Choix invalide\n");
        }

    } while (choix != 4);

    return 0;
}

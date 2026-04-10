#include <stdio.h>
#include <string.h>
#include "../include/filter.h"

void filtre_contient(char mots[][50], int n, char lettre) {
    for (int i = 0; i < n; i++) {
        if (strchr(mots[i], lettre)  !=NULL) {
           printf ("%s\n", mots[i]);
        }
    }
}

void filtre_exclure(char mots[][50], int n, char lettre) {
    for (int i = 0; i < n; i++) {
        if (strchr(mots[i], lettre)  ==NULL) {
           printf ("%s\n", mots[i]);
        }
    }
}

void filtre_substring(char mots[][50], int n, char *sub) {
    for (int i = 0; i < n; i++) {
        if (strchr(mots[i], sub)  !=NULL) {
           printf ("%s\n", mots[i]);
        }
    }
}

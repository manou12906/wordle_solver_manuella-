#ifndef FILTER_H
#define FILTER_H

void filtre_contient(char mots[][50], int n, char lettre);
void filtre_exclure(char mots[][50], int n, char lettre);
void filtre_substring(char mots[][50], int n, char *sub);

#endif

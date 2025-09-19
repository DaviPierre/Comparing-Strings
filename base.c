#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "levenshtein.c"
#include "similarity.c"



// Programa principal
int main() {
    char *s1 = NULL, *s2 = NULL;
    size_t len = 0;

    printf("Digite a primeira string:\n");
    getline(&s1, &len, stdin);
    s1[strcspn(s1, "\n")] = 0;

    len = 0;
    printf("Digite a segunda string:\n");
    getline(&s2, &len, stdin);
    s2[strcspn(s2, "\n")] = 0;

    int dist = levenshtein_classic(s1, s2);
    double sim = similarity(s1, s2);

    printf("\nDistancia de Levenshtein: %d\n", dist);
    printf("Similaridade: %.2f\n", sim);

    return 0;
}


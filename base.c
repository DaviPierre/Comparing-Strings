#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "levenshtein.c"
#include "similarity.c"



// Programa principal
int main() {
    char str1[100], str2[100];

    printf("Digite a primeira string: ");
    scanf("%99s", str1);
    printf("Digite a segunda string: ");
    scanf("%99s", str2);

    int dist = levenshtein(str1, str2);
    double sim = similarity(str1, str2);

    printf("\nDistancia de Levenshtein: %d\n", dist);
    printf("Similaridade: %.2f\n", sim);

    return 0;
}


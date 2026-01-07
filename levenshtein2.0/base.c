#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "levenshteinLinear.c"
#include "similarity.c"

int main() {
    char *s1 = NULL, *s2 = NULL;
    size_t len = 0;

    printf("Digite a primeira string:\n");
    if (getline(&s1, &len, stdin) == -1) {
        fprintf(stderr, "Erro ao ler a string.\n");
        return 1;
    }
    s1[strcspn(s1, "\n")] = 0;

    len = 0;
    printf("Digite a segunda string:\n");
    if (getline(&s2, &len, stdin) == -1) {
        fprintf(stderr, "Erro ao ler a string.\n");
        free(s1);
        return 1;
    }
    s2[strcspn(s2, "\n")] = 0;

    int dist = levenshtein_classic(s1, s2);

    double sim = similarity(dist, s1, s2);

    printf("\nDistancia de Levenshtein: %d\n", dist);
    printf("Similaridade: %.2f%%\n", sim * 100);

    free(s1);
    free(s2);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para calcular o mínimo entre três números
int min3(int a, int b, int c) {
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

// Função para calcular a distância de Levenshtein
int levenshtein(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Alocação dinâmica da matriz (len1+1) x (len2+1)
    int **dist = malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dist[i] = malloc((len2 + 1) * sizeof(int));
    }

    // Inicialização
    for (int i = 0; i <= len1; i++) dist[i][0] = i;
    for (int j = 0; j <= len2; j++) dist[0][j] = j;

    // Preenchimento da matriz
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
            dist[i][j] = min3(
                dist[i-1][j] + 1,      // deleção
                dist[i][j-1] + 1,      // inserção
                dist[i-1][j-1] + cost  // substituição
            );
        }
    }

    int result = dist[len1][len2];

    // Liberação da memória
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return result;
}

// Similaridade normalizada (0.0 a 1.0)
double similarity(const char *s1, const char *s2) {
    int dist = levenshtein(s1, s2);
    int max_len = (strlen(s1) > strlen(s2)) ? strlen(s1) : strlen(s2);
    return 1.0 - (double)dist / max_len;
}

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


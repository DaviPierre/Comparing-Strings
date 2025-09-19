#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "levenshtein.c"
#include "similarity.c"


void run_test(const char *s1, const char *s2, int expected_dist, double expected_sim) {
    int dist = levenshtein_classic(s1, s2);
    double sim = similarity(s1, s2);

    printf("Testando: %s vs %s\n", s1, s2);
    printf("Esperado: dist=%d, sim=%.2f\n", expected_dist, expected_sim);
    printf("Obtido  : dist=%d, sim=%.2f\n", dist, sim);

    assert(dist == expected_dist);

    assert((sim - expected_sim < 0.01) && (expected_sim - sim < 0.01));

    printf("✔ Teste passou!\n\n");
}

int main() {
    run_test("gato", "cato", 1, 0.75);
    run_test("gato", "rato", 1, 0.75);
    run_test("casa", "caso", 1, 0.75);
    run_test("bola", "bolo", 1, 0.75);
    run_test("kitten", "sitting", 3, 0.57);
    run_test("flamengo", "flamenca", 2, 0.75);
    run_test("abcd", "efgh", 4, 0.00);
    run_test("programa", "programa", 0, 1.00);
    run_test("carro", "caro", 1, 0.80);
    run_test("algoritmo", "logaritmo", 3, 0.67);

    printf("✅ Todos os testes passaram!\n");
    return 0;
}


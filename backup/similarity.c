#include <stdio.h>
#include <stdlib.h>

double similarity(const char *s1, const char *s2) {
    int dist = levenshtein_classic(s1, s2);
    int max_len = (strlen(s1) > strlen(s2)) ? strlen(s1) : strlen(s2);
    return 1.0 - (double)dist / max_len;
}


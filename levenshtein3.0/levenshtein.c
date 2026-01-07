int min3(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int levenshtein(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    size_t rows = len1 + 1;
    size_t cols = len2 + 1;

    int *matrix = malloc(rows * cols * sizeof(int));
    if (!matrix) return -1;

    for (size_t i = 0; i < rows; i++) matrix[i * cols] = i;
    for (size_t j = 0; j < cols; j++) matrix[j] = j;

    for (size_t k = 2; k <= len1 + len2; k++) {
        size_t start_i = (k > len2) ? (k - len2) : 1;
        size_t end_i   = (k > len1) ? len1 : (k - 1);

        for (size_t i = start_i; i <= end_i; i++) {
            size_t j = k - i;

            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;

            int deletion = matrix[(i - 1) * cols + j] + 1;
            int insertion = matrix[i * cols + (j - 1)] + 1;
            int substitution = matrix[(i - 1) * cols + (j - 1)] + cost;

            matrix[i * cols + j] = min3(deletion, insertion, substitution);
        }
    }

    int dist = matrix[len1 * cols + len2];
    free(matrix);
    return dist;
}

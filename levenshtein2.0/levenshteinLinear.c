int min3(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int levenshtein_classic(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    size_t rows = len1 + 1;
    size_t cols = len2 + 1; 

    int *matrix = malloc(rows * cols * sizeof(int));
    if (!matrix) return -1;

    for (size_t i = 0; i < rows; i++) {
        matrix[i * cols + 0] = i; 
    }
    for (size_t j = 0; j < cols; j++) {
        matrix[0 * cols + j] = j; 
    }

    for (size_t i = 1; i < rows; i++) {
        for (size_t j = 1; j < cols; j++) {
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

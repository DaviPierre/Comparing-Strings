int min3(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int levenshtein_classic(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
	//alloc memory
    int **matrix = malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = malloc((len2 + 1) * sizeof(int));
    }
	//init
    for (int i = 0; i <= len1; i++) matrix[i][0] = i;
    for (int j = 0; j <= len2; j++) matrix[0][j] = j;
	//creates levenshtein matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min3(
                matrix[i - 1][j] + 1,     
                matrix[i][j - 1] + 1,      
                matrix[i - 1][j - 1] + cost 
            );
        }
    }

    int dist = matrix[len1][len2];
	//clean-up
    for (int i = 0; i <= len1; i++) free(matrix[i]);
    free(matrix);

    return dist;
}

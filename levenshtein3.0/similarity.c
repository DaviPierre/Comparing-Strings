double similarity(int dist, const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    size_t max_len = (len1 > len2) ? len1 : len2;

    if (max_len == 0) {
        return 1.0; 
    }

    return 1.0 - ((double)dist / max_len);
}

#include <stdio.h>

char is_digit(char c) {
    return c >= 65 && c <= 90 || c >= 97 && c <= 122;
}

char min_ch(char s[]) {
    if (*s == 0) return 0;

    char min = min_ch(s + 1);

    //printf("in: \"%s\", cmp: '%c' '%c'\n", s, *s, min);

    return min == 0 || *s < min ? *s : min;
}

int main(int argc, char const * argv[]) {
    printf("risultato: '%c'", min_ch(argv[1]));
}
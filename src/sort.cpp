#include "../header.h"

static int without_registr(const char *p1, const char *p2) { //i take strcmp and make some features that this func skip upper and lower registr of words(upper == lower)
    const unsigned char *s1 = (const unsigned char *) p1;
    const unsigned char *s2 = (const unsigned char *) p2;
    unsigned char c1, c2;

    do {
        c1 = (unsigned char) *s1++;
        if (c1 > 96 && c1 < 123)
            c1 = c1 - 32;
        c2 = (unsigned char) *s2++;
        if (c2 > 96 && c2 < 123)
            c2 = c2 - 32;
        if (c1 == '\0')
            return c1 - c2;
    } while (c1 == c2);

    return c1 - c2;
}

void sort(char ***names, int len) { //bubble sort
    char *temp = NULL;

    for (int j = 0; j < len -1; j++) {
        for (int i = 0; i < len - 1; i++) {
            if (without_registr((*names)[i], (*names)[i + 1]) > 0) {
                temp = (*names)[i];
                (*names)[i] = (*names)[i + 1];
                (*names)[i + 1] = temp;
            }
        }
    }
}

#include "../header.h"

char *strjoin(const char *s1, const char *s2) {
    if (s1 == NULL && s2 == NULL)
        return NULL;
    else if (s1 == NULL && s2 != NULL)
        return strdup(s2);
    else if (s2 == NULL && s1 != NULL)
        return strdup(s1); 
    int j = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int k = 0;
    char *alen = new char[len1 + len2 + 1];

    for (int i = 0; i < len1; i++) {
        alen[i] = s1[i];
    }
    for (j = len1; j < len1 + len2; j++) {
        alen[j] = s2[k];
        k++;
    }
    alen[j] = '\0';
    return alen;
}

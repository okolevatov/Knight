#include "../header.h"

int find_max_so(char **mass) {
    int k = 0;
    struct stat buff;
    struct passwd *pw;

    for (int l = 0; mass[l] != NULL; l++) {
        lstat(mass[l], &buff);
        pw = getpwuid(buff.st_uid);
        if (strlen(pw->pw_name) > k)
            k = strlen(pw->pw_name);
    }
    return k;
}

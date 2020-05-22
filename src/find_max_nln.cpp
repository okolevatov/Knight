#include "../header.h"

int find_max_nln(char **mass) {
    int k = 0;
    struct stat buff;

    for (int i = 0; mass[i]; i++) {
        lstat(mass[i], &buff);
        if (buff.st_nlink > k)
            k = buff.st_nlink;
    }
    k = numlenth(k);
    return k;
}

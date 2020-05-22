#include "../header.h"

int find_max_ss(char **mass) {
    int k = 0;
    struct stat buff;

    for (int i = 0; mass[i]; i++) {
        lstat(mass[i], &buff);
        if (buff.st_size > k)
            k = buff.st_size;
    }
    k = numlenth(k);
    return k;
}

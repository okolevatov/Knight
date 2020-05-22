#include "../header.h"

int find_max_gr(char **mass) {
    int k = 0;
    struct stat buff;
    struct group *gr;

    for (int l = 0; mass[l] != NULL; l++) {
        lstat(mass[l], &buff);
        gr = getgrgid(buff.st_gid);
        if (strlen(gr->gr_name) > k)
            k = strlen(gr->gr_name);
    }
    return k;
}

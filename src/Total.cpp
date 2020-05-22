#include "../header.h"

void Total(char *namedir, char **dir_mass) { //how many blocks in total
    struct stat buff;
    blkcnt_t k = 0;
    int i;

    for (i = 0; dir_mass[i] != NULL; i++) {
        lstat(dir_mass[i], &buff);
        k += buff.st_blocks;
    }
    if (i != 0) 
        std::cout<<"total "<<k / 2<<"\n";
}

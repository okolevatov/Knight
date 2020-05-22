#include "../header.h"

static int numlen(int num) {
    int len = 0;

    if (num == 0)
        return 1;
    while (num != 0) {
        num = num / 10;
        len++;
    }
    return len;
}

void Num_links(char *name, int f) {
    struct stat buff;
    int k = 0;
    int nlink;

    lstat(name, &buff);
    nlink = buff.st_nlink;
    if (f != -1) {
        while ((k + numlen(nlink)) != f) { //substitute spaces along the lenght of the largest digit
            std::cout<<' ';
            k++;
        }
    }
    std::cout<<' ';
    std::cout<<nlink;
    std::cout<<' ';
}


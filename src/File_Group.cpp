#include "../header.h"

void File_Group(int f, char *name) {
    struct group *gr;
    struct stat buff;
    int k = 0;

    lstat(name, &buff);
    gr = getgrgid(buff.st_gid);
    if (f != -1)
        for (; (k + strlen(gr->gr_name)) != f; k++)
            std::cout<<' ';
    std::cout<<gr->gr_name;
    std::cout<<' ';
}

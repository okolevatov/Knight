#include "../header.h"

void File_Owner(int f, char *name) {
    struct passwd *pw;
    struct stat buff;
    int k = 0;

    lstat(name, &buff);
    pw = getpwuid(buff.st_uid); 
    if (f != -1)
        for (; (k + strlen(pw->pw_name)) != f; k++)
            std::cout<<' ';
    std::cout<<pw->pw_name;
    std::cout<<' ';
}

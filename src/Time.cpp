#include "../header.h"

void Time(char *name) {
    struct stat buff;
    int t = 4;
    char *s;
    int count = 0;

    lstat(name, &buff);
    std::cout<<' '; 
    s = ctime(&buff.st_mtime);
    for (; t < strlen(s) - 1; t++) {
        if (s[t] == ':')
            count++;
        if (count == 2)
            break;
        std::cout<<s[t];
    }
    std::cout<<' ';
}

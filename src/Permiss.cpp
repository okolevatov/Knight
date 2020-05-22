#include "../header.h"

static void file_type(int mode) { // printing is that what type of fyle
    if (S_ISREG(mode))
        std::cout<<'-'; //if it simple file
    else if (S_ISDIR(mode))
        std::cout<<'d'; //if it directory
    else if (S_ISBLK(mode))
        std::cout<<'b'; //if it Block Device
    else if (S_ISCHR(mode))
        std::cout<<'c'; //sybmbolik device
    else if (S_ISFIFO(mode))
        std::cout<<'p'; // a pipe
    else if (S_ISLNK(mode))
        std::cout<<'l'; // link
    else if (S_ISSOCK(mode))
        std::cout<<'s'; //socket
    else
        std::cout<<'?'; //unknown  
}

static void file_perm(int mode) {
    (mode & S_IRUSR) ? std::cout<<'r' : std::cout<<'-'; // access mode for the owner of file
    (mode & S_IWUSR) ? std::cout<<'w' : std::cout<<'-';
    if (mode & S_ISUID)
        (mode & S_IXUSR) ? std::cout<<'s' : std::cout<<'S';
    else
        (mode & S_IXUSR) ? std::cout<<'x' : std::cout<<'-'; // till here
    (mode & S_IRGRP) ? std::cout<<'r' : std::cout<<'-'; // acces mode for the groupe of users 
    (mode & S_IWGRP) ? std::cout<<'w' : std::cout<<'-';
    if (mode & S_ISGID)
        (mode & S_IXGRP) ? std::cout<<'s' : std::cout<<'l';
    else
        (mode & S_IXGRP) ? std::cout<<'x' : std::cout<<'-'; // till here
    (mode & S_IROTH) ? std::cout<<'r' : std::cout<<'-'; // access mode for another users in system 
    (mode & S_IWOTH) ? std::cout<<'w' : std::cout<<'-';
    if (mode & S_ISVTX)
        (mode & S_IXOTH) ? std::cout<<'t' : std::cout<<'T';
    else
        (mode & S_IXOTH) ? std::cout<<'x' : std::cout<<'-'; // till here
}

void Permiss(char *name) { // outputting access mode 
    struct stat buff;

    lstat(name, &buff);
    file_type(buff.st_mode);
    file_perm(buff.st_mode);
}

#include "../header.h"

char *dec_to_hex(int dec) {
    int quotient = dec;
    int remainder;
    char *hex = (char *)malloc(sizeof(char) * 100);
    int j = 0;

    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10)
            hex[j++] = 48 + remainder;
        else
            hex[j++] = 87 + remainder;
        quotient = quotient / 16;
    }
    hex[j] = '\0';
    return hex;
}

static int major_my(unsigned int num) {
    int c = 0;

    c = num >> 24;
    return c;
}

static int minor_my(unsigned int num) {
    int c = 0;

    c = num & (1U << 24) - 1;
    return c;
}

static void minor_output(int j, int rdev) {
    for (j = 0; (j + numlenth(minor_my(rdev))) != 3; j++)
        std::cout<<" ";
    std::cout<<minor_my(rdev);
}

void File_Size(int max_ss, char *name) {
    int k;
    int j;
    struct stat buff;

    lstat(name, &buff);
    if (S_ISCHR(buff.st_mode) || S_ISBLK(buff.st_mode)) { // if this is a links
        for (j = 0; (j + numlenth(major_my(buff.st_rdev))) != 3; j++)
            std::cout<<" ";
        std::cout<<major_my(buff.st_rdev);
        std::cout<<", ";
        if ((k = minor_my(buff.st_rdev)) > 255) {
            std::cout<<"0x";
            for (j = 0; (j + strlen(dec_to_hex(k))) != 8; j++)
                std::cout<<'0';
            std::cout<<dec_to_hex(k);
        }
        else
            minor_output(j, buff.st_rdev);
    }
    else {
        for (j = 0; (j + numlenth(buff.st_size)) <= max_ss - 1; j++)
            std::cout<<" ";
        std::cout<<buff.st_size;
    }
}

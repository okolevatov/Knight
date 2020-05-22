#include "../header.h"

int numlenth(int num) {
    int len = 0;

    if (num == 0)
        return 1;
    while (num != 0) {
        num = num / 10;
        len++;
    }
    return len;
}

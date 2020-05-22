#include "../header.h"

void Name_out(char *name) { //outputing our name, because of names looks lile path, example: "/bin/echo" and we must output only "echo"
    int i = strlen(name) - 1;

    for (; i > 0 && name[i - 1] != '/'; i--); //counting till first slash or first elem from back 
    for (; name[i]; i++) // then outputing it
        std::cout<<name[i];
    std::cout<<"\n";
}

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <cstdlib>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

void Permiss(char *name);
char *strjoin(const char *s1, const char *s2);
void Num_links(char *name, int f);
void File_Owner(int f, char *name);
void File_Group(int f, char *name);
void File_Size(int max_ss, char *name);
int numlenth(int num);
void Time(char *name);
void Name_out(char *name);
void Total(char *namedir, char **dir_mass);
int find_max_ss(char **mass);
int find_max_nln(char **mass);
int find_max_so(char **mass);
int find_max_gr(char **mass);
void sort(char ***names, int len);

#endif
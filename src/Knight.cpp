#include "../header.h"

static void print_result(char *name, int max_nln, int max_size_owner, int max_size_group, int max_ss) { // printing result for each element of array 
    Permiss(name); //permissions for user(owner)/groups/another user
    Num_links(name, max_nln); // how many links on that file
    File_Owner(max_size_owner, name); //name of owner
    File_Group(max_size_group, name); //name of group
    File_Size(max_ss, name); // size of file in blocks
    Time(name); // last time modified
    Name_out(name); // name of file/dir
}

static void inside_dir(char *namedir) { // opening our argument dir and creating new array with files 
    DIR *dir;
    struct dirent *entry;
    int count_of_dirs = 0;
    char **dir_mass = NULL;
    int i = 0;
    char *namenew = strjoin(namedir, "/"); // making path for them 

    int max_len_link = 0;
    int max_size_user = 0;
    int max_size_group = 0;
    int max_ss = 0;

    dir = opendir(namedir); 
    while ((entry = readdir(dir)) != NULL)
        count_of_dirs++;
    closedir(dir);
    dir_mass = new char * [count_of_dirs + 1];
    dir = opendir(namedir);
    while ((entry = readdir(dir)) != NULL) 
        dir_mass[i++] = strjoin(namenew, entry->d_name); //creating array with files, which name have path
    dir_mass[i] = NULL;
    closedir(dir);

    sort(&dir_mass, i); // sorting them

    max_len_link = find_max_nln(dir_mass); // searching for the most long number of links, to know how many spaces we must to put in for another numbers
    max_size_user = find_max_so(dir_mass); // searching for the most long owner, to know how many spaces we must to put in for another owners
    max_size_group = find_max_gr(dir_mass); // searching for the most long group, to know how many spaces we must to put in for another groups
    max_ss = find_max_ss(dir_mass); // searching for the most long number of size in blocks, to know how many spaces we must to put in for anouther sizes

    Total(namedir, dir_mass); //printing total number of blocks
    for (int j = 0; dir_mass[j]; j++)
        print_result(dir_mass[j], max_len_link, max_size_user, max_size_group, max_ss); //printing for each element info about file/dir

    for (int j = 0; dir_mass[j]; j++)
        delete [] dir_mass[j];
    delete [] dir_mass;
    delete [] namenew;
}

static char **ArrDirs_func(char **namedir) { //creating array of dirs
    struct stat buff;
    int count = 0;
    char **dirs = NULL;
    int h = 0;

    for (int i = 0; namedir[i]; i++) {
        lstat(namedir[i], &buff);
        if ((buff.st_mode & S_IFMT) == S_IFDIR) //if it dir we counting it
            count++;
    }
    
    dirs = new char * [count + 1];

    for (int i = 0; namedir[i]; i++) {
        lstat(namedir[i], &buff);
        if ((buff.st_mode & S_IFMT) == S_IFDIR) // if it dir we add it
            dirs[h++] = strdup(namedir[i]);
    }
    dirs[h] = NULL;

    return dirs;
}

static char **ArrFiles_func(char **namedir) { //creating array of files
    struct stat buff;
    int count = 0;
    char **files = NULL;
    int h = 0;

    for (int i = 0; namedir[i]; i++) {
        lstat(namedir[i], &buff);
        if ((buff.st_mode & S_IFMT) == S_IFREG) // if this is a Regular file we counting it
            count++;
    }

    files = new char * [count + 1];

    for (int i = 0; namedir[i]; i++) {
        lstat(namedir[i], &buff);
        if ((buff.st_mode & S_IFMT) == S_IFREG) // if this is a Regular file we add it
            files[h++] = strdup(namedir[i]);
    }
    files[h] = NULL;
    
    return files;
}

int main(int argc, char *argv[]) { // as arguments you can input files and dirs
    char **namedir = NULL;
    int i = 0;
    char **dirs = NULL;
    char **files = NULL;

    int max_nln = 0;
    int max_size_owner = 0;
    int max_size_group = 0;
    int max_ss = 0;

    if (argc == 1) {
        namedir = new char * [2];
        namedir[0] = strdup("."); // if there is no args, we shoulde show info about our dirs/files in stream dir
        i = 1;
    } else { 
        namedir = new char * [argc];
        for (int h = 1; i < argc - 1; i++, h++)
            namedir[i] = strdup(argv[h]); // if there is args - we will duplicate them
    }
    namedir[i] = NULL;
    sort(&namedir, i); //sorting them(bubble sort)
    
    /*  we must split up dirs and files
        after spliting we woulde have sorted dirs and sorted files
        it's help us to sort one time, if there woulde be a lot of arguments
    */
    dirs = ArrDirs_func(namedir); 
    files = ArrFiles_func(namedir);

    for (int j = 0; namedir[j]; j++) // free memory 
        delete [] namedir[j];
    delete [] namedir;
    namedir = NULL; //

    max_nln = find_max_nln(files); // searching for the most long number of links, to know how many spaces we must to put in for another numbers
    max_size_owner = find_max_so(files); // searching for the most long owner, to know how many spaces we must to put in for another owners
    max_size_group = find_max_gr(files); // searching for the most long group, to know how many spaces we must to put in for another groups
    max_ss = find_max_ss(files); // searching for the most long number of size in blocks, to know how many spaces we must to put in for anouther sizes


    if (files[0] != NULL) { // if files as arguments is
        for (int j = 0; files[j]; j++) // if there is files as arguments
            print_result(files[j], max_nln, max_size_owner, max_size_group, max_ss); //printing result 
        if (dirs[0])
            std::cout<<"\n";
    }
    for (int j = 0; dirs[j]; j++) {
        if (files[0] || dirs[1]) // checking if there is files or another directories, we woulde print "DIRNAME: \n " and then all what inside 
            std::cout<<dirs[j]<<":\n";
        inside_dir(dirs[j]); // we must open dir and then work with those files in it
    }

    for (int j = 0; files[j]; j++) // free memory 
        delete [] files[j];
    delete [] files;    //
    for (int j = 0; dirs[j]; j++) // free memory 
        delete [] dirs[j];
    delete [] dirs;    //
    
    return 0;
} 
/* The work of Oleksii Kolevatov */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct dirent *dp;
    struct stat statbuf;
    DIR *dirp;

    if(argc != 2){
        fprintf(stderr, "Usage: %s directory_name\n", argv[0]);
        //exit(1);
    }

    if ((dirp = opendir(argv[1])) == NULL) {
        perror("Failed to open directory");
        exit(1);
    }

    while ((dp = readdir(dirp)) != NULL) {
        if (stat(dp->d_name, &statbuf) == -1) {
            perror("Failed to get file status");
            continue;
        }

        
        printf("%c", (S_ISDIR(statbuf.st_mode)) ? 'd' : '-');
        printf("%c", (statbuf.st_mode & S_IRUSR) ? 'r' : '-');
        printf("%c", (statbuf.st_mode & S_IWUSR) ? 'w' : '-');
        printf("%c", (statbuf.st_mode & S_IXUSR) ? 'x' : '-');
        printf("%c", (statbuf.st_mode & S_IRGRP) ? 'r' : '-');
        printf("%c", (statbuf.st_mode & S_IWGRP) ? 'w' : '-');
        printf("%c", (statbuf.st_mode & S_IXGRP) ? 'x' : '-');
        printf("%c", (statbuf.st_mode & S_IROTH) ? 'r' : '-');
        printf("%c", (statbuf.st_mode & S_IWOTH) ? 'w' : '-');
        printf("%c ", (statbuf.st_mode & S_IXOTH) ? 'x' : '-');
        

        printf("%d ", (int)statbuf.st_nlink);     

        //printf("%s ", getpwuid(statbuf.st_uid)->pw_name); 
        //printf("%s ", getgrgid(statbuf.st_gid)->gr_name);

        printf("%lld ", (long long)statbuf.st_size);        //tamanho do arquivo em bytes

        //printf("%.12s ", 4+ctime(&statbuf.st_mtime));     //data de modificacao 
        printf("%s\n", dp->d_name);                         //nome do arquvio
    }

    closedir(dirp);
    return 0;
}

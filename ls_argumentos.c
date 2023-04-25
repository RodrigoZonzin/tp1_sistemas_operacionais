#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    //TIPOS DA BIBLIOTECA
    DIR *dir; 
    struct dirent *dir_entry; 

    //SE FOR MENOR DO QUE 1, NAO HÁ ARGUMENTOS
    if(argc <= 1){
        dir = opendir(".");
    }
    else{
        dir = opendir(argv[1]); 
    }

    //SE FOR NULL (NAO EXISTIR, POR EXEMPLO), PRINTA UM ERRO
    if(dir == NULL){
        perror("opendir");
        printf("Erro :( \n"); 
        return 1; 
    } 

    //LÊ TODOS OS ARQUIVOS DO DIRETÓRIO ATÉ O FIM E PRINTA
    while((dir_entry = readdir(dir)) != NULL){
        printf("%s\n", dir_entry->d_name); 
    }

    //FECHA
    closedir(dir); 
    return 0;
}

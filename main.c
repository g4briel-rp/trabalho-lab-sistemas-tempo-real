#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char linha[100];
    char *comando;
    char *parametro;
    char *search = " ";
    int ret;

    do
    {
        printf("$ ");
        fgets(linha, 100, stdin);
        // puts(linha);
        // perror(linha);

        comando = strtok(linha, search);
        parametro = strtok(NULL, search);
        comando[strcspn(comando, "\n")] = 0;

        // printf("%s", comando);
        // printf("%s", parametro);

        if (strcmp(comando, "ls") == 0)
        {
            char *cmd[] = {comando, parametro, (char *)0};
            ret = execvp(comando, cmd);
        }
        else if (strcmp(comando, "mkdir") == 0)
        {
            printf("mkdir\n");
        }
        else if (strcmp(comando, "man") == 0)
        {
            printf("man\n");
        }
        else if (strcmp(comando, "pwd") == 0)
        {
            printf("pwd\n");
        }
        else if (strcmp(comando, "cd") == 0)
        {
            printf("cd\n");
        }
        else if (strcmp(comando, "rm") == 0)
        {
            printf("rm\n");
        }
        else if (strcmp(comando, "touch") == 0)
        {
            printf("touch\n");
        }
        else if (strcmp(comando, "cp") == 0)
        {
            printf("cp\n");
        }
        else if (strcmp(comando, "mv") == 0)
        {
            printf("mv\n");
        }
        else if (strcmp(comando, "date") == 0)
        {
            printf("date\n");
        }
        else if (strcmp(comando, "cal") == 0)
        {
            printf("cal\n");
        }
        else if (strcmp(comando, "uname") == 0)
        {
            printf("uname");
        }

    } while (strcmp(comando, "sair") != 0);

    return 0;
}
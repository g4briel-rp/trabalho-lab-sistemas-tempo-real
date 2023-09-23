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
        comando[strcspn(comando, "\n")] = 0;

        // printf("%s\n", comando);
        // printf("%s\n", parametro);

        if (strcmp(comando, "ls") == 0)
        {
            if (parametro = strtok(NULL, search)) //  comando + parametro
            {
                parametro[strcspn(parametro, "\n")] = 0;
                char *cmd[] = {comando, parametro, (char *)0};
                ret = execvp(cmd[0], cmd);
            }
            else // somente o comando
            {
                char *cmd[] = {comando, NULL};
                ret = execvp(cmd[0], cmd);
            }
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
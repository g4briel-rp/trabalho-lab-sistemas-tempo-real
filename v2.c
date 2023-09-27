#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void run(char *search, char *comando, char *parametro)
{
    int index = 1, ret;
    char *save[30];

    save[0] = comando;
    // parametro = strtok(parametro, search);

    if (parametro)
    {
        parametro = strtok(parametro, search);
        while (parametro != NULL)
        {
            parametro[strcspn(parametro, "\n")] = 0;
            printf("%s\n", parametro);
            save[index] = parametro;
            index++;
            parametro = strtok(NULL, search);
        }
    }

    save[index] = NULL;

    if (strcmp(comando, "cd") != 0)
        ret = execvp(save[0], save);
    else
        ret = chdir(save);
}

int main(int argc, char *argv[])
{
    pid_t pid;
    char linha[100];
    char *comando;
    char *parametro;
    char *search = " ";

    do
    {
        printf("$ ");
        fgets(linha, 100, stdin);
        // puts(linha);
        // perror(linha);

        comando = strtok(linha, search);
        comando[strcspn(comando, "\n")] = 0;
        parametro = strtok(NULL, "");
        // printf("%s\n", comando);
        // if (parametro)
        // {
        //     printf("%s\n", parametro);
        // }

        pid = fork();

        if (pid < 0)
        {
            fprintf(stderr, "erro\n");
            return 1;
        }
        else if (pid == 0)
        {
            run(search, comando, parametro);
            exit(0);
        }
        else
        {
            wait(NULL);
        }
    } while (strcmp(comando, "sair") != 0);

    return 0;
}
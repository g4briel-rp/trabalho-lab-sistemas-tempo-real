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

    if (parametro)
    {
        parametro = strtok(parametro, search);
        while (parametro != NULL)
        {
            parametro[strcspn(parametro, "\n")] = 0;
            save[index] = parametro;
            index++;
            parametro = strtok(NULL, search);
        }
    }

    save[index] = NULL;

    ret = execvp(save[0], save);

    if (ret == -1)
    {
        perror("Erro ao executar o comando");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    pid_t pid;
    char linha[100], copia[100];
    char *comando;
    char *parametro;
    char *search = " ";

    do
    {
        printf("$ ");
        fgets(linha, 100, stdin);
        strcpy(copia, linha);
        linha[strcspn(linha, "\n")] = 0; // Remove o caractere de nova linha

        comando = strtok(linha, search);
        if (comando == NULL)
            continue; // Ignora linhas vazias

        parametro = strtok(NULL, "\n"); // Pega o restante da linha como parâmetro

        if (strcmp(comando, "cd") == 0)
        {
            if (parametro == NULL)
            {
                fprintf(stderr, "cd: argumento ausente\n");
            }
            else if (chdir(parametro) != 0)
            {
                perror("cd");
            }
        }
        else if (strcmp(comando, "sair") != 0) // Adiciona verificação para o comando 'sair'
        {
            pid = fork();

            if (pid < 0)
            {
                perror("Erro ao criar processo filho");
                return 1;
            }
            else if (pid == 0)
            {
                if (strcmp(comando, "mkdir") == 0)
                {
                    system(copia);
                }
                else
                {
                    run(search, comando, parametro);
                }
                exit(0);
            }
            else
            {
                wait(NULL);
            }
        }
    } while (strcmp(comando, "sair") != 0);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int cont = 0;
    FILE *file = fopen("Empresas.csv", "r");
    if (!file) // Verifica se o arquivo foi aberto corretamente
    {
        fprintf(stderr, "Cannot open file test.csv\n"); // Imprime uma mensagem de erro se o arquivo não puder ser aberto
        return 1; // Retorna um código de erro e encerra o programa
    }

    while (!feof(file))
    {
        if (cont > 4)
            break;
        char line[256] = ""; // Cria um buffer para armazenar a linha lida do arquivo
        char *field = NULL; // Ponteiro para armazenar os campos individuais
        char name[64] = ""; // Armazena o nome

        fgets(line, 255, file);

        line[strlen(line) - 1] = '\x0'; // Remove o caractere de nova linha (\n) do final da string

        field = strtok(line, ";");

        strcpy(name, (field ? field : ""));

        field = strtok(NULL, ";");

        printf("%s\n", name);

        cont++;
    }
}

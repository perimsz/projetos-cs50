/**
 * main.c
 * * Este programa solicita o nome do usuário através da entrada padrão
 * e exibe uma saudação personalizada no terminal.
 * * Utiliza a biblioteca cs50.h para facilitar a captura de strings.
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Solicita o nome do usuário via terminal
    string name = get_string("Qual o seu nome? ");

    // Exibe a saudação utilizando o especificador de formato %s para strings
    printf("Olá, %s!\n", name);

    return 0;
}

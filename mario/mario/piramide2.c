/**
 * @file mario.c
 * @brief Recriação das pirâmides do Mario (Exercício CS50).
 */

#include <cs50.h>
#include <stdio.h>

/**
 * Solicita a altura ao usuário e imprime duas pirâmides espelhadas.
 */
int main(void)
{
    int altura;

    // Garante que a entrada esteja no intervalo
    do
    {
        altura = get_int("Altura: ");
    }
    while (altura < 1 || altura > 8);

    // Itera por cada linha da pirâmide
    for (int i = 0; i < altura; i++)
    {
        // 1. Imprime os espaços à esquerda para alinhar à direita
        for (int j = 0; j < altura - i - 1; j++)
        {
            printf(" ");
        }

        // 2. Imprime o primeiro conjunto de hashtags
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // 3. Imprime o "gap" central de dois espaços
        printf("  ");

        // 4. Imprime o segundo conjunto de hashtags (espelhada)
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // 5. Salta para a próxima linha
        printf("\n");
    }

    return 0; // Boa prática indicar que terminou sem erros
}

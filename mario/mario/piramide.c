/**
 * @file mario_less.c
 * @author Nicolas Perim Fontes
 * @brief Implementação da pirâmide simples do Super Mario Bros.
 * @details Este programa solicita ao usuário uma altura (1 a 8) e imprime
 * uma pirâmide de hashtags (#) alinhada à direita, usando pontos (.)
 * para representar os espaços vazios.
 */

#include <cs50.h>
#include <stdio.h>

/**
 * @brief Executa a lógica de construção da pirâmide.
 * @return 0 em caso de sucesso.
 */
int main(void)
{
    int altura;

    // Garante que o usuário digite um número válido
    do
    {
        altura = get_int("Altura: ");
    }
    while (altura < 1 || altura > 8);

    // Loop principal: controla cada linha da pirâmide
    for (int i = 0; i < altura; i++)
    {
        // Imprime os pontos (espaços) necessários para o alinhamento
        for (int j = 0; j < altura - i - 1; j++)
        {
            printf(".");
        }

        // Imprime as hashtags que formam a escada
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Vai para a próxima linha
        printf("\n");
    }

    return 0;
}

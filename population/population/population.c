/**
 * population.c
 * * Este programa calcula o número de anos necessários para uma população de lhamas
 * crescer de um tamanho inicial para um tamanho final desejado.
 * * Regras de crescimento anual:
 * - 1/3 da população atual nasce.
 * - 1/4 da população atual morre.
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Solicita o tamanho inicial da população ao usuário
    // O tamanho mínimo deve ser 9 para garantir que as divisões resultem em inteiros válidos
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // Solicita o tamanho final desejado
    // Deve ser maior ou igual ao tamanho inicial
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    /**
     * Loop de simulação:
     * Calcula o crescimento ano após ano até que a população inicial (start)
     * atinja ou supere a população final (end).
     */
    int years = 0;
    while (start < end)
    {
        // Aplica a fórmula:
        // + (populacao / 3) para nascimentos
        // - (populacao / 4) para mortes
        // O C realiza o truncamento automático de decimais em divisões de inteiros.
        start = start + (start / 3) - (start / 4);
        years++;
    }

    // Exibe o número total de anos calculados
    printf("Years: %i\n", years);
}

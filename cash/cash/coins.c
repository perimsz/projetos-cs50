#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float cash;
    int total_coins = 0;

    // Garante que o usuário insira um valor positivo para o troco
    do
    {
        cash = get_float("Troco: ");
    }
    while (cash <= 0);

    // Converte dólares para centavos para evitar imprecisões de ponto flutuante
    int cents = round(cash * 100);

    // Algoritmo Guloso: Subtrai o maior valor de moeda possível sucessivamente
    // Verifica quarters (25)
    while (cents >= 25)
    {
        cents -= 25;
        total_coins++;
    }

    // Verifica dimes (10)
    while (cents >= 10)
    {
        cents -= 10;
        total_coins++;
    }

    // Verifica nickels (5)
    while (cents >= 5)
    {
        cents -= 5;
        total_coins++;
    }

    // Verifica pennies (1)
    while (cents >= 1)
    {
        cents -= 1;
        total_coins++;
    }

    printf("%i coins\n", total_coins);
}

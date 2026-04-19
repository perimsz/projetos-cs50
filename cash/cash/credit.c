/**
 * credit.c
 *
 * Este programa valida a autenticidade de um número de cartão de crédito
 * utilizando o Algoritmo de Luhn e identifica a bandeira (VISA, MASTERCARD, AMEX)
 * baseando-se no comprimento do número e nos dígitos iniciais (prefixos).
 * * Processo:
 * 1. Extrai dígitos da direita para a esquerda.
 * 2. Aplica a soma de Luhn: soma dígitos em posições pares e dobra os dígitos
 * em posições ímpares, somando os algarismos resultantes se necessário.
 * 3. Valida se a soma total é múltiplo de 10.
 * 4. Identifica a bandeira caso a validação de Luhn seja bem-sucedida.
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Card number: ");
    long temp = number;
    int sum1 = 0;
    int sum2 = 0;
    int cont = 0;
    int total_digits = 0;

    // Processamento do número para o Algoritmo de Luhn
    while (temp > 0)
    {
        long digit = temp % 10;

        if (cont % 2 == 0)
        {
            sum1 += digit;
        }
        else
        {
            long doubled = digit * 2;
            sum2 += (doubled / 10) + (doubled % 10);
        }

        temp /= 10;
        cont++;
        total_digits++;
    }

    bool valid = (sum1 + sum2) % 10 == 0;

    // Redução do número para extrair os primeiros dígitos (prefixos)
    long first_digits = number;
    while (first_digits >= 100)
    {
        first_digits /= 10;
    }

    // Validação da bandeira e verificação final
    if (valid)
    {
        if ((first_digits / 10 == 4) && (total_digits == 13 || total_digits == 16))
            printf("VISA\n");
        else if ((total_digits == 16) && (first_digits >= 51 && first_digits <= 55))
            printf("MASTERCARD\n");
        else if ((total_digits == 15) && (first_digits == 34 || first_digits == 37))
            printf("AMEX\n");
        else
            printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

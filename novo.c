#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <string.h>



void decimalPraHexa(int decimal) {
    int resto;
    char hexadecimal[100];
    int i = 0;

    while (decimal > 0) {
        resto = decimal % 16;
        decimal = decimal / 16;
        hexadecimal[i] = resto;
        i++;
    }
    printf("Decimal pra Hexadecimal:\n");
    for (int j = i - 1; j >= 0; j--) {
        printf("%X", hexadecimal[j]);
    }
}
int transformaCharParaDecimal(char hexa) {
    int num = hexa;
    int decimal = num - 'A' + 10;
    return decimal;
}

int hexadecimalPraDecimal(char hexadecimal[]) {
    int valores[100];
    int valor = 0;
    int resultado = 0;
    // Distribuindo valores pelo vetor valores[]
    for (int i = 0; i < strlen(hexadecimal); i++) {
        valor = hexadecimal[i] - '0';
        if (hexadecimal[i] == 'a' || hexadecimal[i] == 'b' || hexadecimal[i] == 'c' || hexadecimal[i] == 'd' ||
            hexadecimal[i] == 'e' || hexadecimal[i] == 'f') {
            valor = transformaCharParaDecimal(hexadecimal[i]) - 32;
        }
        if (hexadecimal[i] == 'A' || hexadecimal[i] == 'B' || hexadecimal[i] == 'C' || hexadecimal[i] == 'D' ||
            hexadecimal[i] == 'E' || hexadecimal[i] == 'F') {
            valor = transformaCharParaDecimal(hexadecimal[i]);
        }
        valores[i] = valor;
    }

    // Calcular os valores no vetor
    for (int i = strlen(hexadecimal); i > 0; i--) {
        int digitoFinal = valores[strlen(hexadecimal) - i] * pow(16.0, (double)i - 1);
        resultado += digitoFinal;
    }
    return resultado;
}

int main() {


    printf("Qual conversão deseja realizar? \n");
    printf("\t1 - Decimal para Hexadecimal\n\t2 - Hexadecimal para Decimal\n");

    int opcao;
    printf("Opção: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        int decimal;
        do {
            printf("\nDigite um número decimal maior 0: ");
            scanf("%d", &decimal);
            if (decimal <= 0) {
                printf("\nPor favor digite um número maior que 0\n");
            }
        } while (decimal <= 0);
        decimalPraHexa(decimal);
    }
    if (opcao == 2) {
        char hexadecimal[100];
        printf("\nDigite um número hexadecimal menor que 3F e maior que 0\n");
        scanf("%s", hexadecimal);

        int resultado = hexadecimalPraDecimal(hexadecimal);
        printf("Resultado: %d", resultado);
    }

    return 0;
}
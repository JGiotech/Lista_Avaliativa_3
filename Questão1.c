#include <stdio.h>
#include <string.h>


int RomanoParaDecimal(char *romano) {
    
    int decimal = 0;
    int ultimoNumero = 0;

    for (int i = strlen(romano) - 1; i >= 0; i--) {
        char c = romano[i];
        int letraParaNumero;

        switch (c) {
            case 'I': letraParaNumero = 1; 
            break;
            case 'V': letraParaNumero = 5; 
            break;
            case 'X': letraParaNumero = 10; 
            break;
            case 'L': letraParaNumero = 50; 
            break;
            case 'C': letraParaNumero = 100;
             break;
            case 'D': letraParaNumero = 500;
             break;
            case 'M': letraParaNumero = 1000; 
            break;
            
            default: return -1; 
        }

        if (letraParaNumero < ultimoNumero) {
            decimal -= letraParaNumero;
        } else {
            decimal += letraParaNumero;
        }
        ultimoNumero = letraParaNumero;
    }

    return decimal;
}

void DecimalParaBinario(int numero, char *binario) {
    
    int indice = 0;
    int inicial = 0;

    for (int i = 31; i >= 0; i--) {
        int j = numero >> i;
        if (j & 1) {
            binario[indice++] = '1';
            inicial = 1;
        } else if (inicial) {
            binario[indice++] = '0';
        }
    }

    if (indice == 0) {
       binario[indice++] = '0';
    }
    binario[indice] = '\0';
}

int main() {

    char digiteNumeroRomano[13];

    scanf("%s", digiteNumeroRomano);

    int numeroDecimal = RomanoParaDecimal(digiteNumeroRomano);

    if (numeroDecimal == -1) {
       
        return 1;
    }

   char binario[33]; 

    DecimalParaBinario(numeroDecimal, binario);

    printf("%s na base 2: %s\n", digiteNumeroRomano, binario); 
    printf("%s na base 10: %d\n", digiteNumeroRomano, numeroDecimal);
    printf("%s na base 16: %x\n", digiteNumeroRomano, numeroDecimal);


    return 0;
}

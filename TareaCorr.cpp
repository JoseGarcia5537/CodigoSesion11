#include <stdio.h>

// Funcion decimal a binario
void decimalABinario(int num) {
    int bin[32], i = 0;
    if (num == 0) {
        printf("");
        return;
    }
    while (num > 0) {
        bin[i] = num % 2;
        num = num / 2;
        i++;
    }
    printf("");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", bin[j]);
}

// Funcion decimal a hexadecimal
void decimalAHexadecimal(int num) {
    char hex[32];
    int i = 0;
    if (num == 0) {
        printf("");
        return;
    }
    while (num > 0) {
        int temp = num % 16;
        if (temp < 10)
            hex[i] = temp + 48;  // Numeros del 0 al 9
        else
            hex[i] = temp + 55;  // Letras de A a F
        i++;
        num = num / 16;
    }
    printf("");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
}

int main() {
    int a[15], i, j, k, n = 15;
    int validInput;
    int repetidos[15] = {0}; 

    printf("Digite 15 numeros naturales entre 20 y 1024:\n");
    
    // Leer el arreglo
    for (i = 0; i < n; i++) {
        do {
            printf("Ingrese un numero (%d): ", i + 1);
            validInput = scanf("%d", &a[i]);

            // Verificar si la entrada es valida y si esta en el rango
            if (validInput != 1 || a[i] < 20 || a[i] > 1024) {
                printf("\nNo se encuentra en el intervalo o ha ingresado un valor no entero. \nDebe ser un numero entero entre 20 y 1024.\n");

                // Limpiar el buffer de entrada
                fflush(stdin);
            }
        } while (validInput != 1 || a[i] < 20 || a[i] > 1024);
    }

    // Marcar los repetidos
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j] && repetidos[j] == 0) {
                repetidos[j] = 1; 
                a[j] = 0;         
            }
        }
    }

    // Mostrar y aplicar funciones
    for (i = 0; i < n; i++) {
        if (a[i] == 0) {
            printf("Posicion %d: 0\n", i);
        } else {
            printf("Posicion %d: %d - ", i, a[i]);
            if (a[i] % 2 == 0) {
                decimalABinario(a[i]); // Numeros pares a binario
            } else {
                decimalAHexadecimal(a[i]); // Numeros impares a hexadecimal
            }
            printf("\n");
        }
    }

    return 0;  
}
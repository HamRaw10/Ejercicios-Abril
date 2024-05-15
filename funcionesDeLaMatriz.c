#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void creacion_Matriz(int l, char a[][100], int *pf, int *pc, int *tf, int *tc) {
    puts("Ingrese el espacio de su tablero: ");
    scanf("%d", &l);
    
    if(l < 4){
        printf("No se puede crear el tablero.\n");
        return;
    }
    
    int fila = l, columna = l;
    if (fila <= 0 || columna <= 0) {
        printf("Las dimensiones deben ser siempre numeros y positivas.\nEl juego se termina por querer romperlo.\n");
        return;
    }
 
    srand(time(NULL));
    *pc=(rand()%(l - 2))+1;
    *pf=(rand()%(l - 2))+1;
    *tc=(rand()%(l - 2))+1;
    *tf=(rand()%(l - 2))+1;
     
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (i == 0 || i == fila - 1 || j == 0 || j == columna - 1) {
                a[i][j] = 'o';
            } else { 
                a[i][j] = 'x';
                if(*pf != *tf && *pc != *tc){
                    a[*pf][*pc] = 'P';
                    a[*tf][*tc] = 'x';
                }
            }
            a[0][l - 1] = '-';
            a[l - 1][0] = '-';
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
}

void jugar(int fila, int columna, char a[][100], int *pf, int *pc, int tf, int tc) {
    int intentos = 0;
    while(intentos <= 50) {
        intentos++;
        printf("A donde te quieres mover:\n1 es de Norte, 2 es de Sur, 3 es de Este y 4 es de Oeste:\n");
        int movimiento;
        scanf("%d", &movimiento);
        printf("\n");

        int pfn = *pf;
        int pcn = *pc;

        if(movimiento == 1) {
            a[*pf - 1][*pc] = 'P';
            a[pfn][pcn] = 'x';
            (*pf)--;
            if(a[*pf][*pc] == a[tf][tc]) {
                printf("Encontraste el tesoro en %d intentos.\n", intentos);
                return;
            }
        }
        // Resto de las condiciones de movimiento y verificación de agua y tesoro...
    }
    printf("¡Te quedaste sin intentos!\n");
}

void imprimirLaMatriz(char a[][100], int fila, int columna) {
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas, columnas;
    char a[100][100];
    int pf, pc, tf, tc;

    creacion_Matriz(filas, a, &pf, &pc, &tf, &tc);
    imprimirLaMatriz(a, filas, columnas);
    jugar(filas, columnas, a, &pf, &pc, tf, tc);

    return 0;
}

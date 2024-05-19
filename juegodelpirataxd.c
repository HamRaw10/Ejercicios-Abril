#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Creamos todas las variables que se van a usar en la matriz para crearla, y ademas creamos la primer funcion 
Que va a darnos las posiciones del pirata y el tesoro, los valores de las filas, columnas y interior de la matriz*/
void crearMatriz(char a[][20], int fila, int columna, int *pf, int *pc, int *tf, int *tc) {
    srand(time(NULL));
    //Creo un numero aleatorio para la posicion de la columna del pirata
    *pc = (rand() % (columna - 2)) + 1;
    //Creo un numero aleatorio para la posicion de la fila del pirata 
    *pf = (rand() % (fila - 2)) + 1;
    //Creo un numero aleatorio para la posicion de la columna del tesoro 
    *tc = (rand() % (columna - 2)) + 1;
    //Creo un numero aleatorio para la posicion de la columna del tesoro 
    *tf = (rand() % (fila - 2)) + 1;
    

       //Creo un for para almacenar los valores de la fila
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (i == 0 || i == fila - 1 || j == 0 || j == columna - 1) {
                a[i][j] = 'o';
            } else {
                a[i][j] = '_';
            }
        }
    }
/* Agrego un else que asigna '_' el interior de la matriz y dentro de ese else agrego 2 valores, uno que es un espacio 
aleatorio donde se encuentre el pirata como 'P', y el otro para un espacio aleatorio donde se encuentre el tesoro como 'T'(Ahora esta oculta) */
    a[*pf][*pc] = 'P';
    a[*tf][*tc] = '_';
    a[0][columna - 1] = '-';
    a[fila - 1][0] = '-';
}

void imprimirMatriz(char a[][20], int fila, int columna) {
    //hacemos una funcion especificamente para imrpimir la matriz
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
}

//Creamos una segunda funcion que nos sirve para los movimientos en el juego
void jugarJuego(char a[][20], int fila, int columna, int pf, int pc, int tf, int tc) {
//hacemos una funcion para empezar a jugar el juego
    int intentos = 0;
    int movimiento;

/* Creo un for que nos va a indicar que si la posicion del pirata es igual a la del tesoro al iniciar el juego, 
    nos diga que ya ganamos */
    if (a[pf][pc] == a[tf][tc]) {
        puts("Encontraste el tesoro sin moverte. ¡Qué suerte tienes!");
        return 0;
    }
 //Creo un while que nos va a hacer funcionar el juego, que tiene un limite de 50 movimientos
    while (intentos <= 50) {
        intentos++;
        printf("A dónde te quieres mover:\n 1 es Norte, 2 es Sur, 3 es Este y 4 es Oeste:\n");
 //En este scanf el usuario va a moverse al norte, sur, este u oeste mediante la tecla que seleccione
        scanf("%d", &movimiento);
        printf("\n");

        int pfn = pf;
        int pcn = pc;

 //Creamos los movimientos los cuales se usan con: 1, 2 ,3 ,4
 if (movimiento == 1) { 
// Este es el movimiento Norte (Arriba)
            if (pf - 1 <= 0) {
                printf("Tocaste el agua, perdiste!!\n");
                return;
            }
            a[pf - 1][pc] = 'P';
            a[pfn][pcn] = 'x';
            pf = pfn - 1;
        } else if (movimiento == 2) { 
// Este es el movimiento Sur (Abajo)
            if (pf + 1 >= fila - 1) {
                printf("Tocaste el agua, perdiste!!\n");
                return;
            }
            a[pf + 1][pc] = 'P';
            a[pfn][pcn] = 'x';
            pf = pfn + 1;
        } else if (movimiento == 3) { 
// Este es el movimiento Este (Izquierda)
            if (pc - 1 <= 0) {
                printf("Tocaste el agua, perdiste!!\n");
                return;
            }
            a[pf][pc - 1] = 'P';
            a[pfn][pcn] = 'x';
            pc = pcn - 1;
        } else if (movimiento == 4) { 
// Este es el movimiento Oeste (Derecha)
            if (pc + 1 >= columna - 1) {
                printf("Tocaste el agua, perdiste!!\n");
                return;
            }
            a[pf][pc + 1] = 'P';
            a[pfn][pcn] = 'x';
            pc = pcn + 1;
        }

        a[pfn][pcn] = '_';
        a[pf][pc] = 'P';
/* Creo un if que indica que si las posiciones del pirata son iguales a las del tesoro, nos da un mensaje de las intentos en que 
encontramos el tesoro */
        if (pf == tf && pc == tc) {
            printf("¡Encontraste el tesoro en %d intentos!\n", intentos);
            return;
        }
        imprimirMatriz(a, fila, columna);
    }

    puts("Lo siento, no encontraste el tesoro en 50 intentos.");
}

//Creo una tercer funcion que nos va a imprimir la matriz deseada y llamara a las anteriores funciones
int main() {
    int l;
    puts("Ingrese el tamaño de su tablero: ");
    scanf("%d", &l);

//Creo otra condicion que nos indica que si el movimiento es menor o igual 
//a 0 nos indica que debemos ingresar tecla valida
    if (l <= 0) {
        printf("El movimiento debe ser siempre el indicado anteriormente.\nEl juego se termina por querer romperlo, juega normal");
        return 0;
    }
    //llamamos a todas las funciones para poder poner en marcha el codigo
    //creamos todas las variables necesarias (a, pf, pc, tf, tc, l)
    char a[20][20];
    int pf, pc, tf, tc;
    //asignamos & para obtener la direccion de una variable y * en las primeras partes para los punteros
    crearMatriz(a, l, l, &pf, &pc, &tf, &tc);
    imprimirMatriz(a, l, l);
    jugarJuego(a, l, l, pf, pc, tf, tc);

    return 0;
}

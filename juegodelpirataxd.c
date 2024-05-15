#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  //Creo una variable entera para las filas de la matriz
    int i; 
    //Creo una variable entera para el numero que ponga el usuario para el tamaño de la matriz
    int l;
    //Creo una variable entera para las columnas de la matriz 
      int j;
    //Creo una chariable que al presionar n el pirata se desplaze hacia el norte
    char n;
    //Creo una chariable que al presionar s el pirata se desplaze hacia el sur
    char s;
      //Creo una chariable que al presionar e el pirata se desplaze hacia el este
    char e;
    //Creo una chariable que al presionar o el pirata se desplaze hacia el oeste
    char o;
     //Creo una variable donde se van a almacenar los movimientos segun la direccion
    int movimiento;
     //Creo una variable de entero para la columna donde esta el pirata
    int pc;
     //Creo una variable de entero para la fila donde esta el pirata
    int pf;
    //Creo una variable de entero para la columna donde esta el tesoro
    //Creo una variable de entero para la fila donde esta el tesoro
    int tf; 
    int tc;
    //Creo una variable entera para los intentos posibles de los movimientos del pirata
    int intentos = 0;

    puts("Ingrese el espacio de su tablero: ");
     //El usuario ingresa un valor para el temeño de la matriz donde se va a jugar
    scanf("%d", &l);
    
    //Creo 2 enteros, fila y columna que son iguales al valor que ingrese el usuario
    int fila = l, columna = l;
     //Creo un if que avise que si el tamaño es menor o igual a 0 nos anule el codigo y de ese mensaje
    if (fila <= 0 || columna <= 0) {
        printf("Las dimensiones deben ser siempre numeros y positivas.\nEl juego se termina por querer romperlo\nPdt:esto es para eduardo");
        return 1;
    }
    //Si los valores son positios inicia el codigo
    
    
    //Creo un array para crear la matriz
    char a[fila][columna];
    //Activo el modo aleatorio
    srand(time(NULL));
        //Creo un numero aleatorio para la posicion de la columna del pirata 
     pc=(rand()%(l - 2))+1;
          //Creo un numero aleatorio para la posicion de la fila del pirata
     pf=(rand()%(l - 2))+1;
     //Creo un numero aleatorio para la posicion de la columna del tesoro
     tc=(rand()%(l - 2))+1;
       //Creo un numero aleatorio para la posicion de la fila del tesoro
     tf=(rand()%(l - 2))+1;
     
    // iniciar la a e imprimirla

       //Creo un for para almacenar los valores de la fila
    for (int i = 0; i < fila; i++) {
        //Creo un for para almacenar los valores de la columna
        for (int j = 0; j < columna; j++) {
            //Creo un if para asignar los bordes de la matriz como 'o'
            if (i == 0 || i == fila - 1 || j == 0 || j == columna - 1) {
                a[i][j] = 'o';
            } else{ 
                  /* Agrego un else que asigna 'x' el interior de la matriz 
            y dentro de ese else agrego 2 valores, uno que es un espacio aleatorio donde se encuentre el pirata como 'P',
            y el otro para un espacio aleatorio donde se encuentre el tesoro como 'T' */
                a[i][j] = 'x';  // asignar 'o' al interior de la a
                if(pf != tf && pc != tc){
                a[pf][pc] = 'P';
                a[tf][tc] = 'x';
                }
            }
            a[0][l - 1] = '-';//se crean los puentes
            a[l - 1][0] = '-';
             //Agrego un printf que nos va a imprimir los 'O' en los bordes y  las 'X', 'P' y 'T' en el interior de la matriz
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
    //Creo un for que nos va a indicar que si la posicion del pirata es igual a la del tesoro al iniciar el juego, nos diga que ya ganamos
    if(a[pf][pc] == a[tf][tc]){
                    puts("Encontraste el tesoro sin moverte. ¡Que suerte que tenes!");
                    return 0;
                }

 //Creo un while que nos va a hacer funcionar el juego, que tiene un limite de 50 movimientos
    while(intentos <= 50){
        intentos++;
        printf("a donde te quieres mover:\n 1 es de Norte, 2 es de Sur, 3 es de Este y 4 es de Oeste:\n");
         //En este scanf el usuario va a moverse al norte, sur, este u oeste mediante la tecla que seleccione
        scanf("%d", &movimiento);
        printf("\n");
                /*Creo 2 variables enteras donde van a desaparecer los antiguos espacios donde se encontraba el pirata y se 
        actualiza segun el movimiento del usuario*/
        int pfn = pf;
        int pcn = pc;
        //Creamos los movimientos los cuales se usan con: 1, 2 ,3 ,4
        if(movimiento == 1){
            a[pf - 1][pc] = 'P';
            a[pfn][pcn] = 'x';
            pf = pfn - 1;
            pc = pcn;
            if(a[pf][pc] == a[tf][tc]){
                    printf("Encontraste el , en %d intentos", intentos);
                    return 0;
            }
        }
        else if(movimiento == 2){
            a[pf + 1][pc] = 'P';
            a[pfn][pcn] = 'x';
            pf = pfn + 1;
            pc = pcn;
            if(a[pf][pc] == a[tf][tc]){
                    printf("Encontraste el , en %d intentos", intentos);
                    return 0;
            }
        }
        else if(movimiento == 3){
            a[pf ][pc - 1] = 'P';
            a[pfn][pcn] = 'x';
            pf = pfn;
            pc = pcn - 1;
            if(a[pf][pc] == a[tf][tc]){
                    printf("Encontraste el , en %d intentos", intentos);;
                    return 0;
            }
        }
        else if(movimiento == 4){
            a[pf][pc + 1] = 'P';
            a[pfn][pcn] = 'x';
            pf = pfn;
            pc = pcn + 1;
            if(a[pf][pc] == a[tf][tc]){
                    printf("Encontraste el , en %d intentos", intentos);
                    return 0;
            }
        } 
        //Creo otra condicion que nos indica que si el movimiento es menor o igual a 0 nos indica que debemos ingresar tecla valida
        else if(movimiento <= 0) {
        printf("El movimiento debe ser siempre el indicado anteriormente.\nEl juego se termina por querer romperlo, juega normal");
        return 0;
    }
    //Y agrego otra condicion que indica que si el numero es mayor o igual a 5, nos dara un mensaje de agregar una opcion correcta
    else if(movimiento >= 5){
        printf("el numero debe ser el indicado\n");
    }
     //Creo 4 if, que nos indican que si el pirata llega al agua, nos dara un mensaje de "agua" y se termina el juego
            if(pf == l - 1){
                puts("agua");
                return 0;
            }
        if(pf == 0){
                puts("agua");
                return 0;
            }
        if(pc == l - 1){
                puts("agua");
                return 0;
            }
        if(pc == 0){
                puts("agua");
                return 0;
            }

            /*
        Creo 2 for que van a imprimir la matriz actualizada segun el movimiento del pirata, y hasta que cumpla su objetivo
        */ 
             for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            printf("%c ", a[i][j]);
            }
            printf("\n");

        }
        
    }
    return 0;
    
}

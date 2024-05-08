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
    char movimiento;
    //Creo una variable de entero para la columna donde esta el pirata
    int pc;
    //Creo una variable de entero para la fila donde esta el pirata
    int pf;
    //Creo una variable de entero para la columna donde esta el tesoro
    int tc;
    //Creo una variable de entero para la fila donde esta el tesoro
    int tf; 
    //Creo una variable entera para los intentos posibles de los movimientos del pirata
    int intentos = 0;
    
    puts("Ingrese el espacio de su tablero: ");
    //El usuario ingresa un valor para el temeño de la matriz donde se va a jugar
    scanf("%d", &l);
    
    //Creo 2 enteros, fila y columna que son iguales al valor que ingrese el usuario
    int fila = l, columna = l;
    //Creo un if que avise que si el tamaño es menor o igual a 0 nos anule el codigo y de ese mensaje
    if (fila <= 0 || columna <= 0) { 
        printf("Las dimensiones deben ser positivas.\n");
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
    
    // int randomFila = (rand()% 6 ) +1;
    // int randomColumna = (rand() % 6)+ 1;
    // iniciar la matriz e imprimirla
    
    //Creo un for para almacenar los valores de la f
    for (int i = 0; i < fila; i++) {
        //Creo un for para almacenar los valores de la columna
        for (int j = 0; j < columna; j++) {
            
            //Creo un if para asignar los bordes de la matriz como 'o'
            if (i == 0 || i == fila - 1 || j == 0 || j == columna - 1) { 
                a[i][j] = 'o';
            } 
            /* Agrego un else que asigna 'x' el interior de la matriz 
            y dentro de ese else agrego 2 valores, uno que es un espacio aleatorio donde se encuentre el pirata como 'P',
            y el otro para un espacio aleatorio donde se encuentre el tesoro como 'T' */
            else{ 

                a[i][j] = 'x';  
                if(pf != tf && pc != tc){
                a[pf][pc] = 'P';
                a[tf][tc] = 'T';
                }
            }
            //Agrego un printf que nos va a imprimir los 'O' en los bordes y  las 'X', 'P' y 'T' en el interior de la matriz
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
    //Creo un while que nos va a hacer funcionar el juego, que tiene un limite de 50 movimientos
     while(intentos <= 50){
        printf("a donde te quieres mover: N es de Norte, S es de Sur, E es de Este y O es de Oeste: ");
        //En este scanf el usuario va a moverse al norte, sur, este u oeste mediante la tecla que seleccione
        scanf(" %c", &movimiento);
        printf("\n");
        /*Creo 2 variables enteras donde van a desaparecer los antiguos espacios donde se encontraba el pirata y se 
        actualiza segun el movimiento del usuario*/
        int pfn = pf;
        int pcn = pc;

        //Creo un if que indica que cada vez que el usuario ingrese 'n' o 'N', la 'P' del pirata se movera al norte
        if(movimiento == 'n' || 'N'){
            //Creo un array que indica que cada vez que el pirata vaya al norte se le resta un valor a la fila de la matriz donde se encuentra el pirata
            a[pf - 1][pc] = 'P';
            //Creo un array que indica que la 'x' de la matriz va cambiando segun el movimiento del pirata
            a[pfn][pcn] = 'x';
            pf = pfn - 1;
            pc = pcn;
        }
        //Agrego un else if que indica que cada vez que el usuario ingrese 's' o 'S', la 'P' del pirata se movera al sur
        else if(movimiento == 's' || 'S'){
            //Creo un array que nos indica que para que el pirata vaya al sur se suma 1 valor a la fila de la matriz donde se encuentra el pirataa
            a[pf + 1][pc] = 'P';
            //Creo un array que indica que la 'x' de la matriz va cambiando segun el movimiento del pirata
            a[pfn][pcn] = 'x';
            pf = pfn + 1;
            pc = pcn;
        }
        //Agrego un else if que indica que cada vez que el usuario ingrese 'e' o 'E', la 'P' del pirata se movera al este
        else if(movimiento == 'e' || 'E'){
            //Creo un array que indica que cada vez que el pirata vaya al este se le resta un valor a la columna de la matriz donde se encuentra el pirata
            a[pf ][pc - 1] = 'P';
            //Creo un array que indica que la 'x' de la matriz va cambiando segun el movimiento del pirata
            a[pfn][pcn] = 'x';
            pf = pfn;
            pc = pcn - 1;
        }
        //Agrego un else if que indica que cada vez que el usuario ingrese 'o' u 'O', la 'P' del pirata se movera al oeste
        else if(movimiento == 'o' || 'O'){
            //Creo un array que indica que cada vez que el pirata vaya al oeste se le suma un valor a la columna de la matriz donde se encuentra el pirata
            a[pf][pc] = 'P';
            //Creo un array que indica que la 'x' de la matriz va cambiando segun el movimiento del pirata
            a[pfn][pcn + 1] = 'x';
            pf = pfn;
            pc = pcn + 1;
        }
         
        /*
        Creo 2 for que van a imprimir la matriz
        */ 
             for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            printf("%c ", a[i][j]);
            }
            printf("\n");
        }
        intentos++;
    }
    return 0;
    
}



  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *ppt[] = {"piedra", "papel", "tijera"}; //Creo un array para las 3 variables
    int puntosU = 0, puntosPC = 0; //Creo 2 variables que van a ir contando los puntos en los juegos
    int contadorUsuario = 0, contadorPC = 0; //Creo otras 2 variables que van a ir contando los puntos en las rondas
    int usuarioPPT, pcPPT; //Creo otras 2 variables que van a ir almacenando el numero elegido por el usuario y la computdora para competir
    
    srand(time(NULL)); //Inicia el rand
    puts("Juguemos piedra papel o tijera!!");
    puts("No hagas tonterias o me llevo un punto. . .");
    puts("5 de 3, que gane el mejor\n");
    puts("Se juega con: piedra(0), papel(1), tijera(2)\n");
    puts("Ingrese alguno de los objetos para el juego que sean permitidos para empezar");
    
    while(contadorUsuario < 3 || contadorPC < 3) { //Creo un loop para las rondas que son menores a 3 van a cumplir las siguientes condiciones
        scanf("%d", &usuarioPPT);  //Agrego un scanf que va a ser el valor que ingrese el usuario para competir
        pcPPT = rand() % 3; //La variable pcPPT la asgino como un numero al azar que sea hasta 3
        printf("Vos: %d   VS   PC: %d\n", usuarioPPT, pcPPT); 
        
        if(usuarioPPT != 0 && usuarioPPT != 1 && usuarioPPT !=2){ //Creo una condicion que nos va a servir en caso de que se ingrese un numero invalido no va a sumar puntos a ningun jugador
            printf("Ingrese un valor valido >:v \n"); 
            puntosPC--;
        }
        
        if(usuarioPPT == pcPPT) { //Creo un condicional en caso de empate
            puts("Empate! Esta jugada se repite \n");
        } else if((usuarioPPT == 0 && pcPPT == 2) || (usuarioPPT == 1 && pcPPT == 0) || (usuarioPPT == 2 && pcPPT == 1)) { //Creo otro condicional en caso de que el usuario gane un juego
            printf("Ganas un punto\n\n");
            puntosU++;
        } else { //Creo otro condicional en caso de que no ocurra ningun condicional dado y la maquina gane un juego
            printf("La pc gana un punto\n\n");
            puntosPC++;
        }
        
        printf("Juegos: Tu ganaste: %d, la pc gano %d por el momento.\n\n", puntosU, puntosPC);
        printf("Rondas: Tu ganaste: %d, la pc gano %d por el momento.\n\n", contadorUsuario, contadorPC);
        
        if(puntosU == 2) { //Creo un condicional en caso de que el usuario gane una ronda
            contadorUsuario ++;
            puntosU = 0;
            puntosPC = 0;
        } else if(puntosPC == 2) { //Creo otro condicional en caso de que la computadora gane una ronda
            contadorPC ++;
            puntosPC = 0;
            puntosU = 0;
        }
        if(contadorUsuario == 3) { printf("Ganaste!! \n\n"); break; } //Creo un penultimo condicional en caso de que el usuario gane las rondas totales y por ende el juego
        if(contadorPC== 3) { printf("Perdiste\n\n"); break; } //Creo una ultima condicion en caso de que la maquina gane las rondas totales y por ende el juego
    }
        printf("Tu ganaste %d rondas en total y la pc gano %d rondas en total\n\n", contadorUsuario, contadorPC);
    return 0;
}

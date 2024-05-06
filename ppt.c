#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *ppt[] = {"piedra", "papel", "tijera"};
    int puntosU = 0, puntosPC = 0;
    int contadorUsuario = 0, contadorPC = 0;
    int usuarioPPT, pcPPT;
    
    srand(time(NULL));
    puts("Juguemos piedra papel o tijera!!");
    puts("No hagas tonterias o me llevo un punto. . .");
    puts("5 de 3, el que gana saca y el que pierde elige arco\n");
    
    while(contadorUsuario < 3 || contadorPC < 3) {
        scanf("%d", &usuarioPPT);
        pcPPT = rand() % 3;
        printf("Vos: %d   VS   Pc: %d\n", usuarioPPT, pcPPT); 
        
        if(usuarioPPT == pcPPT) {
            puts("Empate! Esta jugada se repite \n");
        } else if((usuarioPPT == 0 && pcPPT == 2) || (usuarioPPT == 1 && pcPPT == 0) || (usuarioPPT == 2 && pcPPT == 1)) {
            printf("Ganas un punto\n\n");
            puntosU++;
        } else {
            printf("La pc gana un punto\n\n");
            puntosPC++;
        }
        
        printf("Juegos: Tu ganaste: %d, la pc gano %d por el momento.\n", puntosU, puntosPC);
        printf("Rondas: Tu ganaste: %d, la pc gano %d por el momento.\n\n", contadorUsuario, contadorPC);
        
        if(puntosU == 2) {
            contadorUsuario ++;
            puntosU = 0;
            puntosPC = 0;
        } else if(puntosPC == 2) {
            contadorPC ++;
            puntosPC = 0;
            puntosU = 0;
        }
        if(contadorUsuario == 3) { printf("Ganaste!! \n\n"); break; }
        if(contadorPC== 3) { printf("Perdiste\n\n"); break; }
    }
    
    return 0;
}

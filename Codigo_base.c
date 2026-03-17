#include <stdio.h>
#include <stdlib.h>

int main()
{

    int tablero[5][5];
    char tabc[5][5];
    int fila, columna;
    int bandera = 1, b_total = 3;
    int b_encontrado = 0, tries = 0;
    char name1[20];


    printf("---BIENVENIDO AL JUEGO DE BATALLA NAVAL---\n");

    printf("Ingrese su nombre:  ");
    fgets(name1, sizeof(name1), stdin);
    printf("El tablero es el siguiente:\n");

    // Inicializar tablero
    for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
        tablero[i][j] = 0;
    }
    }

    for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
        tabc[i][j] = '~';
    }
    }
    for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
        printf("%c ", tabc[i][j]);
    }
        printf("\n");
    }
    // Colocar barcos manualmente
    tablero[1][2] = 1;
    tablero[3][4] = 1;
    tablero[0][0] = 1;

    do{
    // Pedir disparo

        printf("\nTurno de %s\n", name1);
        printf("Ingrese la fila y la columna en donde desea disparar:\n");
        printf("Fila: ");
        scanf("%d", &fila);
        printf("Columna: ");
        scanf("%d", &columna);

        if(tablero[fila][columna] == 1){
            printf("Has disparado al barco %i!\n", b_encontrado+1);
            tablero[fila][columna] = 3;
            tabc[fila][columna] = 'X';
            b_total --;
            b_encontrado ++;
            tries ++;
        }else if(tablero[fila][columna] == 0){
            printf("Fallaste! Su disparo ha aterrizado en agua\n");
            tablero[fila][columna] = 2;
            tabc[fila][columna] = 'o';
            tries ++;
        }else if(tablero[fila][columna] == 2){
            printf("Jaja Ya habias disparado aqui antes...");
        }

        for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%c ", tabc[i][j]);
        }
            printf("\n");
        }

        if(b_total == 0){
            bandera = 0;
        }


    } while(bandera == 1);

    printf("\nFelicidades %sHas encontrado los %i barcos que habia!", name1, b_encontrado);
    printf("\nTe tomo %i intentos encontrarlos.", tries);


    return 0;
}

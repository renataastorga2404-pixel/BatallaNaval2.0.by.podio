#include <stdio.h>
#include <stdlib.h>

int main()
{
FILE *archivo;
archivo = fopen("tablero.txt", "w");

    int tablero[5][5];
    char tabc[5][5];
    int x,y;
    int fila, columna;
    int bandera = 1;
    int barcos=3;
    int b_encontrados=0;
    int intentos=0;
    char jugador[20];

    printf("---BIENVENIDO AL JUEGO DE BATALLA NAVAL---\n");

    printf("Ingresa tu nombre:\n");
    fgets(jugador,sizeof(jugador),stdin);

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
    //escoger los barcos
    printf("%s coloca tus barcos en el tablero\n",jugador);
     for(int i = 0; i < 3; i++){
        printf("\n---Ingresa las coordenadas de tu barco %d---\n",i+1);
        printf("\nIngrese la coordenada x (0-4):");
            scanf("%d",&x);
        printf("\nIngrese la coordenada y (0-4):");
            scanf("%d",&y);

 if(x >= 0 && x < 5 && y >= 0 && y < 5){
    if(tablero[x][y]== 0){
        tablero[x][y] = i+1;
    }else{
        printf("Ya existe un barco ahi\n");
        i--;
    }
}else{
    printf("Coordenada no valida\n");
    i--;
}
}
//0=vacio
//1,2,3=barcos
//4=aciertoo
//5=fallo
//Esto para dejar los nombres de los barcos

    do{
    // Pedir disparo
        printf("\nTurno de %s",jugador);
        printf("Ingrese la fila y la columna en donde desea disparar (0-4) :\n");
        printf("Fila: ");
        scanf("%d", &fila);
        printf("Columna: ");
        scanf("%d", &columna);
      if(fila < 0 || fila >= 5 || columna < 0 || columna >= 5){
        printf("---La coordenada no es valida---\n");
      }
        if(tablero[fila][columna] == 1){
            printf("%sha disparado a la Pinta!\n",jugador);
            tablero[fila][columna] = 4;
            tabc[fila][columna] = 'X';
            barcos--;
            b_encontrados++;
            intentos++;

        }else if (tablero[fila][columna] == 2){
            printf("%sha disparado a el Titanic!\n",jugador);
            tablero[fila][columna] = 4;
            tabc[fila][columna] = 'X';
            barcos--;
            b_encontrados++;
            intentos++;

        }else if (tablero[fila][columna] == 3){
            printf("%sha disparado a la Santa Maria !\n\n",jugador);
            tablero[fila][columna] = 4;
            tabc[fila][columna] = 'X';
            barcos--;
            b_encontrados++;
            intentos++;

        }else if(tablero[fila][columna] == 0){
            printf("Fallaste! Su disparo ha aterrizado en agua\n\n");
            tablero[fila][columna] = 5;
            tabc[fila][columna] = 'o';
            intentos++;

        }else if(tablero[fila][columna] == 5 || tablero[fila][columna]==4){
            printf("Jaja Ya habias disparado aqui antes...\n");
        }


        for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%c ", tabc[i][j]);

        }
            printf("\n");
        }

    if(barcos==0){
        bandera=0;}
    } while(bandera == 1);

     for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%c ", tabc[i][j]);
        fprintf(archivo, "%c ", tabc[i][j]);}
        printf("\n");
        fprintf(archivo,"\n");
     }
        fprintf(archivo,"\nFelicidades %shas encontrado los %i barcos que habia!!",jugador,b_encontrados);
        fprintf(archivo,"\nTe tomo %i intentos en poder encontrarlos.", intentos);
         fclose(archivo);

printf("\nFelicidades %shas encontrado los %i barcos que habia!!",jugador,b_encontrados);
printf("\nTe tomo %i intentos en poder encontrarlos.", intentos);

    return 0;
}

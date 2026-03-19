#include <stdio.h>
#include <string.h>

void InicializarTableros(int tablero1[5][5], int tablero2[5][5]){
    //inicializar tableros.
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            tablero1[i][j] = 0;
            tablero2[i][j] = 0;
        }
    }
}
void colocarbarcos(char name[20], int tablero[5][5], char barcosn[3][15]){
    int x, y;
    printf("%sColoca tus barcos", name);
        for(int i = 0; i < 3; i ++){
            printf("Ingrese las cordenadas del %s", barcosn[i]);
            printf("\nIngrese la coordenada x (0-4):");
            scanf("%d", &x);
            printf("\nIngrese la coordenada y (0-4):");
            scanf("%d", &y);

            if(x >= 0 && x < 5 && y >= 0 && y < 5){
                if(tablero[x][y] == 0){
                tablero[x][y] = i + 1;
                } else {
                printf("Ya hay un barco ahi\n");
                i--;
                }
            }else{
                printf("\nCoordenada no valida\n");
            }
        }
}
void imprimirtablero(char tabc[5][5]){
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%c ", tabc[i][j]);
        }
            printf("\n");
    }

}

void disparo(char name[20], int tablero[5][5], char tabc[5][5], int *tries, int *b_total, char Barcosn[3][15]){
    int fila, columna, fin = 1;
    while(1){
    printf("\nTurno de %s\n", name);
    printf("\nTu tablero es el siguiente:\n");
    imprimirtablero(tabc);
    printf("Ingrese la fila y la columna en donde desea disparar (0-4):\n");
    printf("Fila: ");
    scanf("%d", &fila);
    printf("Columna: ");
    scanf("%d", &columna);

    if(fila < 0 || fila >= 5 || columna < 0 || columna >= 5){
    printf("Coordenada inválida\n");
    }
    if(tablero[fila][columna] >= 1 && tablero[fila][columna] <= 3){
        int boat = tablero[fila][columna] - 1;
        printf("%sha disparado al barco %s!\n", name, Barcosn[boat]);
        tablero[fila][columna] = 5;
        tabc[fila][columna] = 'X';
        (*b_total) --;
        (*tries) ++;
        if((*b_total) == 0){
            break;
        }
    }else if(tablero[fila][columna] == 0){
        printf("Fallaste! Su disparo ha aterrizado en agua\n");
        tablero[fila][columna] = 4;
        tabc[fila][columna] = 'o';
        (*tries) ++;
        fin = 0;
    }else if(tablero[fila][columna] == 2){
        printf("Jaja Ya habias disparado aqui antes...");
    }

    if(fin == 0){
        break;
    }

    }
}


int main()
{

    int tablero1[5][5], tablero2[5][5];
    char tabc1[5][5], tabc2[5][5];
    char Barcosn[3][15] = {"fragata", "Destructor", "Submarino"};
    int fila, columna, x, y;
    int b_total1 = 3, b_total2 = 3, tries1 = 0, tries2 = 0;
    char name1[20], name2[20];


    printf("---BIENVENIDO AL JUEGO DE BATALLA NAVAL---\n");

    printf("Ingrese el nombre del primer jugador:  ");
    fgets(name1, sizeof(name1), stdin);
    printf("Ingrese el nombre del segundo jugador: ");
    fgets(name2, sizeof(name2), stdin);

    InicializarTableros(tablero1, tablero2);

    colocarbarcos(name1, tablero1, Barcosn);
    colocarbarcos(name2, tablero2, Barcosn);




    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            tabc1[i][j] = '~';
            tabc2[i][j] = '~';
        }

    }
    do{
    // Pedir disparo

    disparo(name1, tablero2, tabc2, &tries1, &b_total1, Barcosn);
    if(b_total1 == 0){
        printf("Felicidades %sHas ganado!!", name1);
        printf("\nTe tomo %i intentos encontrarlos.", tries1);
        break;
    }
    disparo(name2, tablero1, tabc1, &tries2, &b_total2, Barcosn);
    if(b_total2 == 0){
        printf("Felicidades %sHas ganado!!", name2);
        printf("\nTe tomo %i intentos encontrarlos.", tries2);
        break;
    }


    } while(1);



    return 0;
}

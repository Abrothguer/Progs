//MINESWEEPER (V1 - 12/11/16)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

typedef struct square{
    char show;
    int hide;
}Square;

typedef struct coord0{
    int x;
    int y;
}Coord0;

void makemat(int lin, int col, int mine, Square matrix[SIZE][SIZE]);
int qtdmine(int lin, int col);
void matshow(int lin, int col, Square matrix[SIZE][SIZE]);
int game(int lin, int col, int mine, Square matrix[SIZE][SIZE]);
void mark(int lin, int col, int x, int y, int *win, int *minecontrol, int choice, Square matrix[SIZE][SIZE]);
int validation(int choice, int lin, int col, int x, int y, Square matrix[SIZE][SIZE]);
void reveal(int lin, int col, int x, int y, int *win, Square matrix[SIZE][SIZE]);
void revealzeros(int lin, int col, int x, int y, Square matrix[SIZE][SIZE], Coord0 vet[lin*col], int *tam, int *posvet);

int main(){
    system("cls");
    int lin, col, i, j, mine, win, new;
    printf("Please type the number of lines and collums of the field (Ex: 10 10):\n");
    scanf("%d %d", &lin, &col);
    mine = qtdmine(lin, col);
    Square matrix[30][30];
    makemat(lin, col, mine, matrix);
    win = game(lin, col, mine, matrix);
    system("cls");
    printf("Minesweeper\n");
    printf("Field of size %dx%d\n", lin, col);
    printf("Total of mines: %d\n", mine);
    matshow(lin, col, matrix);
    if(win == 1){
    	printf("You successfully disarmed all mines!\n");
    	printf("Congratulations, You Won!!!\n");
    } 
    else{
    	printf("Oh No! You stepped on a mine!\n");
    	printf("Game Over!\n");
    } 
    printf("New game?\n");
    printf("[1]. Yes\n");
    printf("[2]. No\n");
    scanf("%d", &new);
    if(new == 1) main();
    else return 0;
}

int game(int lin, int col, int mine, Square matrix[SIZE][SIZE]){
    int minecontrol, x, y, choice, win, valid;
    minecontrol = mine;
    win = 0;
    while(1){
        x = y = -1;
        system("cls");
        printf("Minesweeper\n");
        printf("Field of size %dx%d\n", lin, col);
        printf("Mines left on the field : %d\n", minecontrol);
        matshow(lin, col, matrix);
        do{
            printf("\nPlease type a valid coordinate (line and collum) of a square(Ex: 0 0):\n");
            scanf("%d %d", &x, &y);
        }while(x < 0 || y < 0 || x > lin || y > col);
        printf("What do you want do now?\n");
        printf("[1]. Reveal the square (%d,%d).\n", x, y);
        printf("[2]. Mark the square (%d,%d) as a mine.\n", x, y);
        printf("[3]. Unmark the square (%d,%d).\n");
        printf("[4]. Do Nothing.\n");
        scanf("%d", &choice);
        valid = validation(choice, lin, col, x,  y, matrix);
        if(valid == 1){
            if(choice == 2 || choice == 3) mark(lin, col, x, y, &win, &minecontrol, choice, matrix);
            else reveal(lin, col, x, y, &win, matrix);
        }
        if(win == mine || win == -1){
            break;
        }
    }
    if(win == mine) return 1;
    else return 0;
}

void reveal(int lin, int col, int x, int y, int *win, Square matrix[SIZE][SIZE]){
    int aux = *win;
    if(matrix[x][y].hide == 9){
        matrix[x][y].show = 207;
        aux = -1;
        *win = aux;
    }
    else{
        if(matrix[x][y].hide == 0){
        	int tam = 0;
    		int posvet = 0;
    		Coord0 vet[lin*col];
        	matrix[x][y].show = ' ';
        	revealzeros(lin, col, x, y, matrix, vet, &tam, &posvet);
        	tam = 0;
        	posvet = 0;
        }
        else if(matrix[x][y].hide == 1) matrix[x][y].show = '1';
        else if(matrix[x][y].hide == 2) matrix[x][y].show = '2';
        else if(matrix[x][y].hide == 3) matrix[x][y].show = '3';
        else if(matrix[x][y].hide == 4) matrix[x][y].show = '4';
        else if(matrix[x][y].hide == 5) matrix[x][y].show = '5';
        else if(matrix[x][y].hide == 6) matrix[x][y].show = '6';
        else if(matrix[x][y].hide == 7) matrix[x][y].show = '7';
        else if(matrix[x][y].hide == 8) matrix[x][y].show = '8';
    }
    return;
}

void mark(int lin, int col, int x, int y, int *win, int *minecontrol, int choice, Square matrix[SIZE][SIZE]){
    int aux = *win;
    int auxmine = *minecontrol;
    if(choice == 2){
        matrix[x][y].show = '!';
        --auxmine;
        if(matrix[x][y].hide == 9) ++aux;
    }
    else if(choice == 3){
        matrix[x][y].show = 254;
        ++auxmine;
        if(matrix[x][y].hide == 9) --aux;
    }
    *win = aux;
    *minecontrol = auxmine;
    return;
}

int qtdmine(int lin, int col){
    int mine;
    system("cls");
    printf("Select the number of mines: \n");
    printf("[1] Hard - %d Mines\n", lin*col/2);
    printf("[2] Medium - %d Mines\n", lin*col/4);
    printf("[3] Easy - %d Mines\n", lin*col/10);
    scanf("%d", &mine);

    if(mine == 1) mine = lin*col/2;
    else if(mine == 2) mine = lin*col/4;
    else if(mine == 3) mine = lin*col/10;
    else{
        printf("Select a valid option!\n");
        system("pause");
        qtdmine(lin, col);
    }
    return mine;
}

void makemat(int lin, int col, int mine, Square matrix[SIZE][SIZE]){
    int i, j, l, k, xrand, yrand;  
    for(i = 0; i < lin; i++){
        for(j = 0 ; j < col; j++){
            matrix[i][j].hide = 0;
            matrix[i][j].show = 254;
        }
    }
    srand(time(NULL));
    for(i = 0; i < mine; i++){
        xrand = rand()%lin;
        yrand = rand()%col;
        //printf("xrand = %d e yrand = %d\n", xrand, yrand);
        if(matrix[xrand][yrand].hide == 9){
            --i;
        }
        else{
            for(l = -1; l < 2; l++){
                for(k = -1; k < 2; k++){
                    if(l == 0 && k == 0) matrix[xrand+l][yrand+k].hide = 9;
                    else if(matrix[xrand+l][yrand+k].hide != 9 && xrand+l >= 0 && yrand+k >= 0 && xrand+l < lin && yrand+k < col){
                        matrix[xrand+l][yrand+k].hide++;
                    }
                }
            }
        }
    }
    return;
}

void matshow(int lin, int col, Square matrix[SIZE][SIZE]){
    int i, j;
    for(i = -1; i < lin; i++){
        for(j = -1; j < col; j++){
            if(j == -1 && i == -1) printf("  M");
            else if(j == -1) printf("%3d", i);
            else if(i == -1) printf("%3d", j);
            else printf("%3c", matrix[i][j].show);
        }
        printf("\n");
    }
    return;
}

int validation(int choice, int lin, int col, int x, int y, Square matrix[SIZE][SIZE]){
    int valid;
    if(x < 0 || y < 0 || x >= lin || y >= col){
    	printf("Please type valid coordinates!\n");
    	valid = 0;
    }
    else if(choice == 1){
        if(matrix[x][y].show == '!'){
            printf("You can't reveal a square that is marked as a mine!\n");
            printf("Obs.: If you want to reveal it, Unmark it first.\n");
            valid = 0;
        }
        else if(matrix[x][y].show == -2){
            valid = 1;
        }
        else{
            printf("The square (%d,%d) has already been revealed!\n", x, y);
            valid = 0;
        }
    }
    else if(choice == 2){
        if(matrix[x][y].show == '!'){
            printf("The square (%d,%d) has already been marked as a mine!\n", x, y);
            valid = 0;
        }
        else if(matrix[x][y].show == -2){
            valid = 1;
        }
        else{
            printf("You can't mark a square that has already been revealed!\n");
            valid = 0;
        }
    }
    else if(choice == 3){
        if(matrix[x][y].show == -2){
            printf("You can't unmark a square that was not marked as a mine!\n");
            valid = 0;
        }
        else if(matrix[x][y].show == '!'){
            valid = 1;
        }
        else{
            printf("You can't unmark a square that has already been revealed!\n");
            valid = 0;
        }
    }
    else if(choice == 4) valid = 0;
    else{
        printf("Please select a valid option next time!\n");
        valid = 0;
    }
    system("pause");
    return valid;
}

void revealzeros(int lin, int col, int x, int y, Square matrix[SIZE][SIZE], Coord0 vet[lin*col], int *tam, int *posvet){
    int i, j, l, valid, auxpos, auxtam;
    auxpos = *posvet;
    auxtam = *tam;
    vet[auxpos].x = x;
    vet[auxpos].y = y;
    ++auxtam;
    (*tam)++;
    (*posvet)++;
    valid = 1;
    for(i = -1; i < 2; i++){
        for(j = -1; j < 2; j++){
            for(l = 0; l < auxtam; l++){
                if(x+i == vet[l].x && y+j == vet[l].y){
                    valid = 0;
                    break;
                }
            }
            if(valid == 1){
                if(x+i >= 0 && x+i < lin && y+j >= 0 && y+j < col && (j != 0 || i != 0)){
                if(matrix[x+i][y+j].hide == 0){
                    matrix[x+i][y+j].show = ' ';
                    revealzeros(lin, col, i+x, j+y, matrix, vet, tam, posvet);
                }
                else if(matrix[x+i][y+j].hide == 1) matrix[x+i][y+j].show = '1';
                else if(matrix[x+i][y+j].hide == 2) matrix[x+i][y+j].show = '2';
                else if(matrix[x+i][y+j].hide == 3) matrix[x+i][y+j].show = '3';
                else if(matrix[x+i][y+j].hide == 4) matrix[x+i][y+j].show = '4';
                else if(matrix[x+i][y+j].hide == 5) matrix[x+i][y+j].show = '5';
                else if(matrix[x+i][y+j].hide == 6) matrix[x+i][y+j].show = '6';
                }
            }   
            valid = 1;
        }
    }
    return;
}

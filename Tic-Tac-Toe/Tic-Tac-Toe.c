#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

int m[3][3];
char PLAYER1='X';
char PLAYER2='O';
char COMPUTER='O';

void resetboard ();
void printBoard ();
int freespace ();
char checkwinner ();
void player1move ();
void player2move ();

int main () {

char winner=' ';
char again;

    do
    {   resetboard();
        winner=' ';

        while (winner==' ' && freespace()!=0)
        {   
            printBoard();
            player1move();
            printBoard();
            winner=checkwinner();
            if (winner!=' ')
            {
                break;
            }
            player2move();
            winner=checkwinner();
        }

        if (winner=='X')
        {
            printf("P1 WIN !\n");
        }
        else if (winner =='O')
        {
            printf("P2 WIN !\n");
        }
        else
        {
            printf("ITS A DRAW!\n");
        }
        printf("\nDO YOU WANT TO PLAY AGAIN ? (Y/N):");
        scanf(" %c",&again);
        again=toupper(again);
        
    } while (again=='Y');
    

}

void resetboard () {

    for (int i = 0; i < 3; i++)
    {   
        for (int j = 0; j < 3; j++)
        {
            m[i][j]=' ';
        }
    }
    
}


void printBoard () {
    printf("  %c     |      %c     |     %c \n",m[0][0],m[0][1],m[0][2]);
    printf("--------|------------|--------\n");
    printf("  %c     |      %c     |     %c \n",m[1][0],m[1][1],m[1][2]);
    printf("--------|------------|--------\n");
    printf("  %c     |      %c     |     %c \n",m[2][0],m[2][1],m[2][2]);
}


void player1move () {
    int x,y;

    do
    {   printf("P1 ENTER LINE AND COLUMN (1-3) :");
        scanf("%d %d",&x,&y);
        x--;
        y--;
    } while (x < 0 || x > 2 || y < 0 || y > 2 || m[x][y] != ' ');

    m[x][y]='X';
}


void player2move () {
        int x,y;

    do
    {   printf("P2 ENTER LINE AND COLUMN (1-3) :");
        scanf("%d %d",&x,&y);
        x--;
        y--;
    } while (x>2 && y>3 && m[x][y]!=' ');
    
    m[x][y]='O';
}


int freespace () {
    int space=9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m[i][j]!=' ')
            {
                space--;
            }
        }
    }
    return space;
}


char checkwinner () {
    for (int i = 0; i < 3; i++)
    {
       if (m[0][i]==m[1][i] && m[2][i]==m[0][i])
       {
        return m[0][i];
       }

       if (m[i][0]==m[i][1] && m[i][2]==m[i][0])
       {
        return m[i][0];
       }
    }
    if (m[0][0]==m[1][1] && m[0][0]==m[2][2])
    {
        return m[0][0];
    }

    if (m[0][2]==m[1][1] && m[0][2]==m[2][0])
    {
        return m[0][2];
    }
    return ' ';
}
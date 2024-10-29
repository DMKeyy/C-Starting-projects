#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<time.h>

char m[6][7];
int height[7];
char p1='#';
char p2='@';


void printboard ();
void resetboard ();
void player1move ();
void player2move ();
void computermove ();
int freespace ();
char checkwinner ();


int main () {
    char winner=' ';
    char again;



    do
    {   winner=' ';
        resetboard();
        printboard();
        while (winner==' ' && freespace()!=0)
        {
            player1move();
            printboard();
            winner=checkwinner();
            if (winner!=' ')
            {
                break;
            }
            player2move();
            printboard();
            winner=checkwinner();
        }
        
        if (winner==' ')
        {
            printf("ITS A DRAW !\n");
        }

        if (winner==p1)
        {
            printf("P1 WON !\n");
        }

        if (winner==p2)
        {
            printf("P2 WON !\n");
        }

        printf("\nPLAY AGAIN ? (Y/N) : ");
        scanf(" %c",&again);
        again=toupper(again);

    } while (again=='Y');
    
    return 0;
}


void printboard () {
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("( %c )\t",m[i][j]);
        }
        printf("\n");
    }
    printf("*****************************************************\n");
    printf("  1       2       3       4       5       6       7      ");
    
}


void resetboard () {

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            m[i][j]=' ';
        }
    }
    for (int i = 0; i < 7; i++)
    {
        height[i]=5;
    }
    
}


void player1move () {
    int x;

    do
    {
        printf("\nENTER YOUR COLUMN (1-7) : ");
        scanf("%d",&x);
        x--;
    } while ((x<1 || x>6) && height[x] < 0 );

    m[height[x]][x]=p1;
    height[x]--;
}


void player2move () {
    int x;

    do
    {
        printf("\nENTER YOUR COLUMN (1-7) : ");
        scanf("%d",&x);
        x--;
    } while ((x<1 || x>6) && height[x] < 0 );

    m[height[x]][x]=p2;
    height[x]--;
}


int freespace () {
    int space=7;

    for (int i = 0; i < 7; i++)
    {
        if (m[0][i]!=' ')
        {
            space--;
        }
    }
    return space;
}


char checkwinner () {
    for (int i = 0; i < 4; i++) //ligne
    {
        for (int j = 0; j < 6; j++)
        {
            if (m[j][i]==m[j][i+1] && m[j][i]==m[j][i+2] && m[j][i]==m[j][i+3]  && m[j][i] !=' ')
                {
                    return m[j][i];
                }
        }   
    }

    for (int i = 0; i < 3; i++) //column
    {
        for (int j = 0; j < 7; j++)
        {
            if (m[i][j]==m[i+1][j] && m[i][j]==m[i+2][j] && m[i][j]==m[i+3][j] && m[i][j] !=' ')
                {
                    return m[i][j];
                }
        }  
    }
    
    for (int k = 0; k < 3  ; k++) //vertical /
    {
        for (int l = 0; l < 4; l++)
            {
            if (m[k][l]==m[k+1][l+1] && m[k][l]==m[k+2][l+2] && m[k][l]==m[k+3][l+3]  && m[k][l] !=' ')
                {
                    return m[k][l];
                }        
            }        
    }

    for (int k = 6; k > 2  ; k--)//vertical '\'
    {
        for (int l = 0; l < 4 ; l++)
            {
            if (m[k][l]==m[k-1][l+1] && m[k][l]==m[k-2][l+2] && m[k][l]==m[k-3][l+3] && m[k][l] !=' ')
                {
                    return m[k][l];
                }        
            }        
    }
    return ' ';
    
}

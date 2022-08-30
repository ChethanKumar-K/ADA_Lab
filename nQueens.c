#include <stdio.h>
#include <math.h>       //  To calculate absolute value

int board[100];         //  Board stores the columns in the which the queens are placed in a row

void queen(int row,int n);  //  row represents in which row the queen must be placed and n denotes number of queens

int place (int row , int column);   //  returns true if a queen can be placed in particular row and column

void printConfig(int n);

int configs = 0;    //  To keep track of total number of configurations

int main(){
    int n;      //  Number of queens
    printf("Enter the number of queens : ");
    scanf("%d",&n);
    
    for(int i=1; i <= n ; i++){
        board[i] = 0;       //  Intialising
    }
    
    queen(1,n);         //  Start placing the queen from row 1
    
    return 0;
}

void queen(int row , int n){
    int column;
    
    for(column = 1 ; column <= n ; column++){
        if(place(row,column)){
            board[row] = column;
            if(row == n){
                //  All queens are placed print the configuration 
                printConfig(n);
            }
            else{
                queen(row+1,n);
            }
        }
    }
}


int place(int row, int column){
    int i;
    
    for(i = 1; i <= row - 1; i++){
        if(board[i] == column){
            return 0;
        }
        else{
            if( abs(board[i] - column) == abs(row - i)){
                return 0;
            }
        }
    }
    
    return 1;
}

void printConfig(int n){
    int i,j,pos;
    i = 1;
    j = 1;
    printf("\nConfiguration %d\n\n",++configs);
    for(i = 1 ; i <= n ; i++){
        pos = board[i];
        for(j = 1; j <= n ; j++){
            if(j == pos){
                printf(" Q | ");
            }
            else{
                printf("   | ");
            }
        }
        printf("\n");
        for(int k= 1 ; k <= n; k++){
            printf(" --  ");
        }
        printf("\n");
    }
    printf("\n");
}


//      Sample Output

Enter the number of queens : 4

Configuration 1

   |  Q |    |    |
 --   --   --   --
   |    |    |  Q |
 --   --   --   --
 Q |    |    |    |
 --   --   --   --
   |    |  Q |    |
 --   --   --   --


Configuration 2

   |    |  Q |    |
 --   --   --   --
 Q |    |    |    |
 --   --   --   --
   |    |    |  Q |
 --   --   --   --
   |  Q |    |    |
 --   --   --   --

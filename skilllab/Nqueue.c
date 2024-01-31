#include<stdio.h>
#include<stdbool.h>
#define N 4
int board [N][N];
void printBoard()
{
    for (int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%c",board[i][j]? 'Q': '_');
        }
        printf("\n");
    }
    printf("\n");
}
bool issafe(int row,int col)
{
    for(int i=0;i<col; i++)
    if(board[row][i])
    return false;
    for(int i=row,j=col;i>=0 && j>=0; i--,j--)
    if(board[i][j])
    return false;
    for(int i =row,j=col;i<N && j>=0;i++,j--)
    if(board[i][j])
    return false;
    return true;
}
bool sloveNQueens(int col)
{
    if (col==N){
        printBoard();
        return true ;
    }
    bool res =false;
    for(int i =0;i<N;i++){
        if(issafe(i,col))
        {
            board[i][col]=1;
            res=sloveNQueens(col+1)||res;
            board[i][col]=0;
        }
    } 
    return res;
    }
    int main()
    {
        for (int i =0;i<N;i++)
        for(int j=0;j<N;j++)
        board[i][j]=0;
        sloveNQueens(0);
        return 0;
    }
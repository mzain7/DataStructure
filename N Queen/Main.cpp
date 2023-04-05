#include <iostream>
int main(int argc, char const *argv[])
{
    int size =4;
    int arr [4][4] = {0};

    int queenRow= 2,queenCol= 2;

    arr[queenRow][queenCol] = 1;


    int temp1 =queenRow, temp2 =queenCol;
    while(temp1 >0 &&  temp2>0){
        arr[--temp1][--temp2] = 2;
    }
    temp1 =queenRow, temp2 =queenCol;
    while(temp1 < size-1 &&  temp2<size-1){
        arr[++temp1][++temp2] = 2;
    }

    temp1 = queenRow, temp2 =queenCol;
    while(temp1>0 && temp2 < size-1){
        arr[--temp1][++temp2]=2;
    }

    temp1 = queenRow, temp2 =queenCol;
    while(temp1 < size-1 && temp2>0){
        arr[++temp1][--temp2]=2;
    }
    
    temp1 = queenRow, temp2 =queenCol;
    while(temp2>0){
        arr[temp1][--temp2]=2;
    }
    
    temp1 = queenRow, temp2 =queenCol;
    while(temp1 > 0){
        arr[--temp1][temp2]=2;
    }
    


    // for (int i = size; i >=0 ; i--)
    // {
    //     queenRow-size;
    // }
    

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout<< arr[i][j];
        }
        std::cout<<std::endl;
        
    }
    
    return 0;
}

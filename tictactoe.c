#include <stdio.h>
#include <conio.h>

char grid[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin();
void board();

int main()
{
    int p = 1, i, c;

    char mark;
    do
    {
        board();
        p = (p % 2) ? 1 : 2;

        printf("p %d, enter a number:  ", p);
        scanf("%d", &c);

        mark = (p == 1) ? 'X' : 'O';

        if (c == 1 && grid[1] == '1')
            grid[1] = mark;
            
        else if (c == 2 && grid[2] == '2')
            grid[2] = mark;
            
        else if (c == 3 && grid[3] == '3')
            grid[3] = mark;
            
        else if (c == 4 && grid[4] == '4')
            grid[4] = mark;
            
        else if (c == 5 && grid[5] == '5')
            grid[5] = mark;
            
        else if (c == 6 && grid[6] == '6')
            grid[6] = mark;
            
        else if (c == 7 && grid[7] == '7')
            grid[7] = mark;
            
        else if (c == 8 && grid[8] == '8')
            grid[8] = mark;
            
        else if (c == 9 && grid[9] == '9')
            grid[9] = mark;
            
        else
        {
            printf("Invalid move ");

            p--;
            getch();
        }
        i = checkwin();

        p++;
    }while (i ==  - 1);
    
    board();
    
    if (i == 1)
        printf("==>\ap %d win ", --p);
    else
        printf("==>\aGame draw");

    getch();

    return 0;
}

int checkwin()
{
    if (grid[1] == grid[2] && grid[2] == grid[3])
        return 1;
        
    else if (grid[4] == grid[5] && grid[5] == grid[6])
        return 1;
        
    else if (grid[7] == grid[8] && grid[8] == grid[9])
        return 1;
        
    else if (grid[1] == grid[4] && grid[4] == grid[7])
        return 1;
        
    else if (grid[2] == grid[5] && grid[5] == grid[8])
        return 1;
        
    else if (grid[3] == grid[6] && grid[6] == grid[9])
        return 1;
        
    else if (grid[1] == grid[5] && grid[5] == grid[9])
        return 1;
        
    else if (grid[3] == grid[5] && grid[5] == grid[7])
        return 1;
        
    else if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3' &&
        grid[4] != '4' && grid[5] != '5' && grid[6] != '6' && grid[7] 
        != '7' && grid[8] != '8' && grid[9] != '9')

        return 0;
    else
        return  - 1;
}

void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("p 1 (X)  -  p 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", grid[1], grid[2], grid[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", grid[4], grid[5], grid[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", grid[7], grid[8], grid[9]);

    printf("     |     |     \n\n");
}
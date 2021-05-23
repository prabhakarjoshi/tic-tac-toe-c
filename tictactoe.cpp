#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<string.h>
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char name1[10],name2[10];
char order[2][10],askName[10];
int checkwin();
void board();
void swapName();
void regisUser();
int main()
{
    int player = 1, i, choice;
    char mark;
    regisUser();
    printf("\nEnter name of player to play First:");
    scanf("%s",askName);
   if(!strcmp(askName,name1) || !strcmp(askName,name2))
   {
    do
    {
        board();
        player = (player % 2) ? 1 : 2;
        swapName();
        printf("Player %d %s, enter a number:  ", player,order[player-1]);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = checkwin();

        player++;
    }while (i ==  - 1);

    board();

    if (i == 1)
        printf("==>\aPlayer %s win",order[player-2]);//printf("==>\aPlayer %d win ", --player);   // order[player]
    else
        printf("==>\aGame draw");
 }
 else
  printf("Invalid User");
  getch();
  return 0;
}




int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}





void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}



void regisUser()
{
 printf("Enter name of player X:");
 scanf("%s",name1);
 printf("\nEnter name of player Y:");
 scanf("%s",name2);
}




void swapName()
{
  int j;
  for(j=0;j<strlen(askName);j++)
      order[0][j]=askName[j];
  if(!strcmp(askName,name1))
     {
      for(j=0;j<strlen(name2);j++)
       order[1][j]=name2[j];
     }
  else
     {
      for(j=0;j<strlen(name1);j++)
       order[1][j]=name1[j];
     }
}

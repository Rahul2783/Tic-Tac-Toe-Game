#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int row, column;
bool draw = false;

void display_table()
{
    system("cls");
    cout << "\t Tik tac Toe Game" << endl;
    cout << " \t\t player1 [X] \n\t\t player2[O] \n\n";

    cout << "\t     |     |     " << endl;
    cout << "\t " << board[0][0] << "   |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t " << board[1][0] << "   |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t " << board[2][0] << "   |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
    cout << "\t     |     |     " << endl;
}
void player_turn()
{
    int choice;

    if (turn == 'X')
        cout << "\n\tplayer1 [X] Turn:";
    if (turn == 'O')
        cout << "\n\tplayer2 [O] Turn:";

    cin >> choice;

    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;

    default:
        cout << "Invalid Choice" << endl;
        break;
    }
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "Box already filled! \n Please try again";
        player_turn();
    }

    display_table();
}
bool gameover()
{

    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    draw = true;
    return false;
}
int main()
{

    while (gameover())
    {
        display_table();
        player_turn();
        // display_table();
        gameover();
    }
    if (turn == 'X' && draw == false)
        cout << "player2 [O] Wins !!" << endl;
    else if (turn == 'O' && draw == false)
        cout << "player[X] Wins!!" << endl;
    else
        cout << "Game Over" << endl;
}
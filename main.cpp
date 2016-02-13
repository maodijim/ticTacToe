#include <iostream>
#include <vector>

using namespace std;

void display_board();

void player_turn();

int game_result();

char turn;
bool draw = false;
char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

int main() {
        cout << "Tic Tac Toe Game\n";
        cout << "Player 1 [X] --- Player 2 [O]\n";
        turn = 'X';
        int i =0;
        while(game_result() == 1) {
            display_board();
            player_turn();
        }
        return 0;
}

void display_board() {
    cout << "---------------------" << endl << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl;
}

void player_turn(){
    int choice;
    int row,col;
    if(turn =='X'){
        cout << "player X please enter your choice:";
    }else{
        cout << "player O please enter your choice:";
    }//end if
    cin >> choice;
    switch(choice){
        case 1:
            row=0;
            col=0;
            break;
        case 2:
            row=0;
            col=1;
            break;
        case 3:
            row=0;
            col=2;
            break;
        case 4:
            row=1;
            col=0;
            break;
        case 5:
            row=1;
            col=1;
            break;
        case 6:
            row=1;
            col=2;
            break;
        case 7:
            row=2;
            col=0;
            break;
        case 8:
            row=2;
            col=1;
            break;
        case 9:
            row=2;
            col=2;
            break;
        default:
            //default case
            cout << "invalid input!! please try again\n";
            player_turn();
            break;
    }

    if( turn == 'X' && board[row][col]!= 'X' && board[row][col]!='O'){
        board[row][col] = 'X';
        game_result();
        turn ='O';
    }else if( turn == 'O' && board[row][col]!='X' && board[row][col]!='O') {
        board[row][col] = 'O';
        game_result();
        turn = 'X';
    }else {
        cout << "The cell you choose is invalid";
    }



}// player_turn end

int game_result(){
    char one= board[0][0];
    char two= board[0][1];
    char three= board[0][2];
    char four= board[1][0];
    char five= board[1][1];
    char six= board[1][2];
    char sev= board[2][0];
    char eight= board[2][1];
    char nine= board[2][2];
    if ((one == five && one == nine)||
        (one == two && one == three)||
        (one == four && one == sev)||
        (two == five && two == eight)||
        (three == five && three == sev)||
        (three == six && six == nine)||
        (four == five && four == six)||
        (sev == eight && sev == nine)){

            display_board();
            cout << "Player " << turn << " Win.\n";
            exit(0);// game ended
    }else
    return 1;
}//game_result end

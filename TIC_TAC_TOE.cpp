#include<iostream>
using namespace std;


char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int currentPlayer;
char currentMarker;

void display_board(){
    cout << "-------------\n";
    cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << "\n";
    cout << "----|---|----\n";
    cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" <<"\n";
    cout << "----|---|----\n";
    cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" <<"\n";
    cout << "-------------\n";
}

bool isNotSelected(int slot){
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if(board[row][col] != 'X' && board[row][col] != 'O'){
        return true;
    }
    return false;
}

int winner()
{
    for(int i = 0; i < 3; i++)
    {
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])){
                return currentPlayer;
            }
    }

    if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
   (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
    {
    return currentPlayer;
    }
    return 0;
}

void swap_player(){
    if(currentPlayer == 1){
        currentPlayer = 2;
    }
    else
    {
        currentPlayer = 1;
    }

    if(currentMarker == 'X')
    {
        currentMarker = 'O';
    }
    else
    {
        currentMarker = 'X';
    }
}

void game(){
    cout<<"Player 1 ,  choose one symbol 'X' or 'O' : ";
    char MarkerP1;
    cin>>MarkerP1;

    if(MarkerP1 != 'X' && MarkerP1 != 'O') {
        cout << "Invalid marker. Please choose 'X' or 'O'.\n";
        return;
    }

    currentMarker = MarkerP1;
    currentPlayer = 1;

    display_board();
    int playerWon;
    for(int i = 0; i < 9; i++){
        int slot;
        cout<<"Player "<<currentPlayer<<"'s turn!"<<endl;
        cout<<"Enter the slot : ";
        cin>>slot;
        int row = (slot - 1) / 3;
        int col = (slot - 1) % 3;
        if(slot < 1 || slot > 9){
            cout<<"The entered slot is Invalid , Please try again."<<endl;
            i--;
            continue;
        }
        else if(!isNotSelected(slot)){
            cout<<"The slot is already Occupied , Try AGAIN."<<endl;
            i--;
            continue;
        }
        else
        {
            board[row][col] = currentMarker;
        }

        display_board();

        playerWon = winner();
        
        if(playerWon == 1 || playerWon == 2){
            cout<<playerWon<<" WON THE GAME "<<endl;
            return;
        }

        swap_player();
    }
    if(playerWon == 0){
        cout<<"It's a DRAW..!";
    }
}

int main()
{
game();
return 0;
}
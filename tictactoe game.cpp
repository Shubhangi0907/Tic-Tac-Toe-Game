//Tic Tac Toe Game
#include <iostream>

using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

int current_player;
char current_marker;

void boardDraw ()
{
    
    cout<<" "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  " << board[0][2]<< endl;
    cout<<" ______________\n";
   
    cout<<" "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  " << board[1][2]<< endl;
    cout<<" ______________\n";
   
    cout<<" "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  " << board[2][2]<< endl;
    
}
    
    
    
bool markerPlace(int slot)
{
    int row = slot/3;
    int col;
    
    if(slot % 3 == 0) 
    {
        row= row ;
        col = 2;
    }    
     col= (slot % 3) - 1;
     if(board[row][col] != 'X' && board[row][col] != 'O') 
     {
         board[row][col]= current_marker;
         return true;
     }
     else return false;
}   
     
 int winner()
 {
     for(int i=0;i<3;i++)
     {
     
         // rows
         if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
         
         //columns
         if(board[0][i]== board[1][i] && board[1][i] == board[2][i]) return current_player;
     }     
         //diagonals
         if(board[0][0]== board[1][1] && board[1][1] == board[2][2]) return current_player;
         if(board[0][2]== board[1][1] && board[1][1] == board[2][0]) return current_player;
         
         return 0;
     
 }
 
 void swap_marker_and_player()
 {
     if (current_marker=='X') current_marker = 'O';
     else current_marker = 'X';
     
     if (current_player== 1) current_player = 2;
     else current_player = 1;
 }
 
 void game()
 {
    cout<<"Player 1, choose your marker (X or O) :";
    char marker_p1;
    cin>> marker_p1;
    
    current_player=1;
    current_marker= marker_p1;
    
    boardDraw();
    
    int player_won;
    
    for(int i=0; i<9; i++)
    {
        cout<<"It's player" << current_player << "'s turn. Enter your slot : ";
        int slot;
        cin>> slot;
       
       if(slot<1 || slot>9)
       {
         cout<< "That's invalid slot. Try another slot."; 
         i--; 
         continue;  
       }
       
       if(!markerPlace(slot)) 
       { 
           cout<< "That's occupied. Try another slot."; 
           i--; 
           continue; 
           
       }
        boardDraw();       
        player_won = winner();
        
        if (player_won == 1) { cout<< "Player 1 won! Congratulations!!"; break; }
        if (player_won == 2) { cout<< "Player 2 won! Congratulations!!"; break; }
        
        swap_marker_and_player();
        
        
    
    }
    
    if(player_won == 0) cout<< " That is a tie";
 }
 
 
   int main ()
{
    game();
}   




/*Tic Tac Toe


Represent the board
2D   int board[3][3]
1D    int board[9]
integer int board;
*/
//C does not initalize varaibles
#include <iostream>
using namespace std;
#include <cassert>
class game{

    char board[3][3];
// 
public:

game(){
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        board[i][j]='_';
}
void set(int r, int c, char player){
	assert(r<3 && r>=0 && c<3 && c>=0);
	board[r][c]=player;

}
char get(int r, int c, char player){
	assert(r<3 && r>=0 && c<3 && c>=0);
	return board[r][c];
}
void print(){
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++)
        cout << board[i][j] << " ";
        
    
    }
    cout <<"\t";
   
    if(checkX() == true){
        cout << "X wins";
    }else if(checkO() == true){
        cout << "O wins";
    }else if(inProgress() == true){
        cout << "in progress";
    }else if(draw() == true){
        cout << "draw";
    }else if(invalid() == true){
        cout << "invalid";
    }
    cout << "\n";
}

void generate_boards(int index){
    if(index==9){
        //print board
        print();
        return;
    }
    int r=index/3;
    int c=index%3;
    board[r][c]='X';
    generate_boards(index+1);
    board[r][c]='O';
    generate_boards(index+1);
    board[r][c]='-';
    generate_boards(index+1);
}

void generate_all_board(){
    generate_boards(0);
}
bool checkX(){
//if X winning 
for(int i = 0; i < 3; i++){
    if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && (board[i][0] == 'X' )) return true; //verticle line
    if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && (board[0][i] == 'X')) return true;//horizontal line
}
//diagnal
if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && (board[0][0] == 'X')){
    return true;
}
else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && (board[0][2] == 'X')){

    return true;
}

    return false;
}

// if O is winning 
bool checkO(){
for(int i = 0; i < 3; i++){
    if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && (board[i][0] == 'O' )) return true; //verticle line
    if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && (board[0][i] == 'O')) return true;//horizontal line
}
//diagnal
if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && (board[0][0] == 'O')){
    return true;
}
else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && (board[0][2] == 'O')){ //diagnal
    return true;
}
    return false;
}

//to if board is full and no winner
bool isFilled(){
for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
        if(board[i][j] == '_')
        return false;
    }
}
return true;
}
 
//draw is when board is complete and their are no winners 
bool draw(){
    if(isFilled() && !checkX() && !checkO()){ //! is not check for false
    return true;
    }else{
        return false;
    }
}

//count for x
int countX(){
    int count = 0;
    for(int i= 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            count++;
        }
    }
    return count;
}

//count for O
int countO(){
    int count = 0; 
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            count++;
        }
    }
    return count;
}

//invalid method
bool invalid(){
    if(countX() - countO() == 0 || countX() - countO() == 1){
        return  false;
    }
    else{
        return true;
    }
}

bool inProgress(){
    if(!invalid() && !isFilled() && !checkX() && !checkO()){
        return true;
    }
    return false;

}



};

int main(){
game g;
g.generate_all_board();
}
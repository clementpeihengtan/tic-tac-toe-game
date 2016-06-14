#include <iostream>
#include <cstdlib>
#include "board.h"

using namespace std;


Board::Board(){
}

void Board::playgame(){

      clearboard();
      char player1 = 'X';
      char player2 = 'O';

      char currentplayer = 'X';
      bool isDone = false;

      int x,y, turn = 0;

      while(isDone == false){
        printboard();
        x = getxcord();
        y = getycord();


        if(marker(x, y, currentplayer) == false){
          cout << "That spot is occupied!";
        }else{
          turn ++;
          if(checkvictory(currentplayer) == true){              //check if the player has won
            std::system("clear");                               //clean the gameboard out
            printboard();                                       //print the gameboard out
            cout << "The game is over!" << currentplayer << " has won!\n";
            isDone = true;
          }else if(turn ==9){                                   //check whether it is a tie
            std::system("clear");                               //clear the gameboard
            printboard();                                       //print the gameboard out
            cout << "Is a tie game\n";
            isDone = true;
          }
          //switch player
          if(currentplayer == player1){
            currentplayer = player2;
          }else{
            currentplayer = player1;
          }
        }
        if(isDone == false){
          std::system("clear");                                   //display the latest result only
        }
      }
}

//check whether the place put is valid?
bool Board::marker(int x, int y, char currentplayer){
  if(gameboard[y][x] != ' '){
    return false;
  }
  gameboard[y][x] = currentplayer;
  return true;
}

//check whether we got victory or not
bool Board::checkvictory(char currentplayer){
  //check the row
  for(int i =0; i<3; i++){
    if((gameboard[i][0]==currentplayer)&& gameboard[i][0] == gameboard[i][1] && gameboard[i][1] == gameboard[i][2] ){
      return true;
    }
  }
  //check column
  for(int i =0; i<3; i++){
    if((gameboard[0][i] == currentplayer)&&gameboard[0][i] == gameboard[1][i] && gameboard[1][i] == gameboard[2][i] ){
      return true;
    }
  }
  //check top left diagonal
  if((gameboard[0][0] == currentplayer)&& gameboard[0][0]==gameboard[1][1] && gameboard[1][1] == gameboard[2][2] ){
    return true;
  }
  //check right diagonal
  if((gameboard[2][0] == currentplayer)&& gameboard[2][0] == gameboard[1][1] && gameboard[1][1] == gameboard[0][2] ){
    return true;
  }

  return false;
}


//get x coordinate
int Board::getxcord(){
  bool isInputBad = true;
  int x;
  while(isInputBad == true){
    cout << "Enter the x coordinate: ";
    cin >> x;

    if(x < 1 || x > 3){
      cout <<"Invalid coordinate";
    }else{
      isInputBad = false;
    }
  }
      return x - 1;
}


//get y coordinate
int Board::getycord(){
  bool isInputBad = true;
  int y;
  while(isInputBad == true){
    cout << "Enter the y coordinate: ";
    cin >> y;

    if(y < 1 || y > 3){
      cout <<"Invalid coordinate";
    }else{
      isInputBad = false;
    }
  }
      return y - 1;
}


//clear the board to restart
void Board::clearboard(){
  for(int i = 0; i < 3 ; i++){
    for(int j = 0; j < 3; j++){
      gameboard[i][j] = ' ';
    }
  }
}

//print the latest result of the board
void Board::printboard(){
  cout<<endl;
  cout<<" |1 2 3|\n";
  for(int i = 0; i < 3 ; i++){
    cout << "--------\n";
    cout << i+1 << "|" << gameboard[i][0] <<"|"<< gameboard[i][1] << "|" << gameboard[i][2] << "|" <<endl;
  }
  cout << "--------\n";
}

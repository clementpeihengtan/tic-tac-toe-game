#include "board.h"
#include <iostream>

using namespace std;

int main(){
  char input;
  bool isDone = false;
  Board board;
  board.playgame();

  while(isDone == false){
    cout << "would you like to play again? (Y/N):";
    cin >> input;

    if(input == 'N' || input =='n'){
      isDone = true;
    }
    else{
      board.playgame();
    }
  }
  return 0;
}

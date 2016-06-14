#define Board_H

class Board{
  public:
     Board();
     //start the game
     void playgame();

  private:
    int getxcord();
    int getycord();
    bool marker(int x, int y, char currentplayer);

    bool checkvictory(char currentplayer);
    char gameboard[3][3];
    //clear the board
    void clearboard();
    //Prints the board
    void printboard();
};

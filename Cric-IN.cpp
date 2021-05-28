#include "GameHeader.h"
#include <iostream>
using namespace std;

int main(){
   string pool[] = { "Virat","Rohit","Dhawan","Pant","Karthik","Rahul","Jadeja","Hardik","Bumrah","BKumar","Ishant" };
    Game cricket;
    cricket.setPlayers(11,pool);
    cricket.welcomeScreen();
    cricket.gamePlay(1);
    cricket.playingGame();
}

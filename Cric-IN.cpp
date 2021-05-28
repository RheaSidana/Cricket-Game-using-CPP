//custom header file to develop this game
#include "GameHeader.h"

#include <iostream>
using namespace std;

int main(){
    // pool of players
    string pool[] = { "Virat","Rohit","Dhawan","Pant","Karthik","Rahul","Jadeja","Hardik","Bumrah","BKumar","Ishant" };
    
    //create game object 
    Game cricket;
    
    //set the the player array
    cricket.setPlayers(11,pool);
    
    // game begins: welcome message, creating team, toss and initialize first player of the the First inning
    cricket.welcomeScreen();
    
    //playing the game
    cricket.playingGame();
}

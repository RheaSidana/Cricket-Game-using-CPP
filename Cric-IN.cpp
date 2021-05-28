#include "GameHeader.h"
#include <iostream>
using namespace std;

int main(){
    string pool[] = { "Virat","Rohit","Dhawan","Pant","Karthik","Rahul","Jadeja","Hardik","Bumrah","BKumar","Ishant" };
    Game cricket;
    cricket.setPlayers(11,pool);
    cricket.welcomeScreen();
    //cricket.assignPlayersToTeams();
    //cricket.performToss();

    /*string team1[] = { "Virat","Rohit","Dhawan","Pant","Karthik" };
    string team2[] = { "Rahul","Jadeja","Hardik","Bumrah","BKumar" };*/
    
    //cricket.gamePlay(1);
    cricket.playingGame();
    /*Team teamA;
    teamA.assignPlayers(5,team1);
    Team teamB;
    teamB.assignPlayers(5, team2);*/
    //Game cricket;
    //cricket.finalScoreCard();
    /*int runs = cricket.getRunsScored();
    cout << "\n Runs " << runs;*/
}

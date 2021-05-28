#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
using namespace std;

//class to make custom output layout 
class ScreenHeadings {
	//output layout of the content 
	void contenting(string content, int dash);
	//display custom blank line 
	void blank(int dash);
	//layout corner
	void corner();
	//add n number of spaces to for display layout
	void space(int n);
	//display dash : dash times
	void dashing(int dash);
	//display equal in the layot heading 
	void equaling(int equal);
public:
	//polymorphism to display in different styles
	void screenOutput(string head, int n, string strArr[]);
	void screenOutput(string head, string content);
	void screenOutput(string head, string strArr[], int n);
	// display heading with and without equal sign 
	void heading(string head, int dash, int equal);
	void heading(string head, int dash);
	//display final scroe board
	void finalScore(string head, string strArr[], int n);
	//function overloading content style 
	void contenting(int dash, string content);
};

//enum for batting and bowling 
enum Activity {
	batting = 1, bowling = 2
};

//class to display score of a team and players indivually
class Score {
	int batBalls,bowlBalls;
	int runs;
	int wickets;
	float overs;
public:
	//initialising the values of private data members 
	//can also be done using constructor
	void init();
	//set and get the value of bat balls 
	void setBatBalls(int ball);
	int getBatBalls();
	//set and get the value of bowl balls 
	void setBowlBalls(int ball);
	int getBowlBalls();
	//set the value of runs 
	int getRuns();
	void setRuns(int runs);
	//get and set of wickets
	int getWickets();
	void setWickets(int wicket);
	//get and set of Overs 
	float getOvers();
	void setOvers(float over);
};

//class Team to play the game
class Team {
	//array of players of the team
	string players[5];
	//number of players in a team
	int playersCount;
	//has played the game in the batting or bowling
	int hasPlayed1[5], hasPlayed2[5];
	//batting or bowling 
	Activity activity1, activity2;
	//custom display layout
	ScreenHeadings screenDisplay;
public:
	//score of team and players individually
	Score playerScore[5], teamScore;
	// assigning players to the team
	void assignPlayers(int n, string members[]);
	//display team players
	void displayTeamMembers(string teamName);
	// select actitvity  after toss
	int selectActivity();
	// string return the selected activity
	string getActivity(int no);
	//set both the activities
	void setActivity(int actNo, int ch);
	//display first Player selected for both the innings 
	void selectFirstPlayerDisplay(string heading);
	// returns the name of the currently playing player of a particular activity
	string getPlayingPlayer(int actNo);
	//set particular player as playing
	void setPlayingPlayer(int n,int actNo);
	//displays players available to play
	void playersToPlay(int actNo);
	//assign playing player as played
	void nextPlayer(int actNo);
	//initialse the scores of both the team and players 
	void initTeamScore();
	//return the playing player's id 
	int playingPlayerId(int actNo);
	//return the string of the scor of the playing player in a particular activity
	string playingPlayersScore(int id,int actNo);
	//check if players left to play  
	bool isPlayerAvailable(int actNo);
	//assign next player to the game 
	void assignNextPlayer(int actNo);
	//display the team score for the final score board
	void displayTeamScore();
};

//class Game to Play
class Game {
	//print custom layout output
	ScreenHeadings screenDisplay;
	// array of players
	string players[11];
	// array to display available players
	int hasAddedToTeam[11];
	//count of number of players to play
	int totalPlayers;
	// teams for creating teams 
	Team teamA, teamB;
	//check if first inning is over
	bool isInningsOver;
public:
	//display instructions 
	void welcomeScreen();
	//assign the player to play the game
	void setPlayers(int n, string members[]);
	//display pool of players
	void poolOfPlayers();
	//creating Teams
	void assignPlayersToTeams();
	//display the Pool of Players for creating team
	void displayPlayers();
	//toss to start the game 
	void performToss();
	//game play
	void gamePlay(int actNo);
	//display the score board
	void displayScoreBoard(int actNo);
	//return runs scored = (0,1,2,3,4,6)
	int getRunsScored();
	//playing both the innings 
	void playingGame();
	//display inning board
	void inningBoard();
	//display final score board
	void finalScoreCard();
};

#endif

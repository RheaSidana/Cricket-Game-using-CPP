#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
using namespace std;

class ScreenHeadings {
	void contenting(string content, int dash);
	void blank(int dash);
	void corner();
	void space(int n);
	void dashing(int dash);
	void equaling(int equal);
public:
	void screenOutput(string head, int n, string strArr[]);
	void screenOutput(string head, string content);
	void screenOutput(string head, string strArr[], int n);
	void heading(string head, int dash, int equal);
	void heading(string head, int dash);
	void finalScore(string head, string strArr[], int n);
	void contenting(int dash, string content);
};

enum Activity {
	batting = 1, bowling = 2
};

class Score {
	int batBalls,bowlBalls;
	int runs;
	int wickets;
	float overs;
public:
	void init();
	void setBatBalls(int ball);
	int getBatBalls();
	void setBowlBalls(int ball);
	int getBowlBalls();
	int getRuns();
	void setRuns(int runs);
	int getWickets();
	void setWickets(int wicket);
	float getOvers();
	void setOvers(float over);
};

class Team {
	string players[5];
	int playersCount;
	int hasPlayed1[5], hasPlayed2[5];
	Activity activity1, activity2;
	ScreenHeadings screenDisplay;
public:
	Score playerScore[5], teamScore;
	void assignPlayers(int n, string members[]);
	void displayTeamMembers(string teamName);
	int selectActivity();
	string getActivity(int no);
	void setActivity(int actNo, int ch);
	void selectFirstPlayerDisplay(string heading);
	string getPlayingPlayer(int actNo);
	void setPlayingPlayer(int n,int actNo);
	void playersToPlay(int actNo);
	void nextPlayer(int actNo);
	void initTeamScore();
	int playingPlayerId(int actNo);
	string playingPlayersScore(int id,int actNo);
	bool isPlayerAvailable(int actNo);
	void assignNextPlayer(int actNo);
	void displayTeamScore();
};

class Game {
	ScreenHeadings screenDisplay;
	string players[11];
	int hasAddedToTeam[11];
	int totalPlayers, totalAssigned;
	Team teamA, teamB;
	bool isInningsOver;
public:
	void welcomeScreen();
	void setPlayers(int n, string members[]);
	void poolOfPlayers();
	void assignPlayersToTeams();
	void displayPlayers();
	//toss
	void performToss();
	//game play
	void gamePlay(int actNo);
	void displayScoreBoard(int actNo);
	//runs scored
	int getRunsScored();
	void playingGame();
	void inningBoard();
	void finalScoreCard();
};

#endif

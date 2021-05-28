#include "GameHeader.h"
#include <iostream>
#include <string>
using namespace std;

void Game :: welcomeScreen() {
	system("cls");
	string heading = " Cric - IN ";
	string welcomeMsg = " Welcome to Virtual Cricket Game ";
	screenDisplay.screenOutput(heading, welcomeMsg);
	
	cout << "\n\n\n";

	string instr = " Instructions ";
	string rule[] = {"Create 2 teams (Team-A and Team-B with 5 players each) form given pool of 11 players. ",
			"Lead the toss and decide bowling or batting. ",
			"Select which player should bat or bowl first. "};
	screenDisplay.screenOutput(instr, rule,3);

	cout << "\n\n";
	system("pause");

	poolOfPlayers();
}

void Game::setPlayers(int n,string members[]) {
	totalPlayers = n;
	for (int i = 0; i < n; i++) {
		players[i]=members[i];
		hasAddedToTeam[i] = 0;
	}
}

void Game :: poolOfPlayers() {
	system("cls");
	string pool = " Pool of Players ";
	screenDisplay.screenOutput(pool, players,totalPlayers);

	cout << "\n\n";
	system("pause");

	//create team
	assignPlayersToTeams();
}

void Game :: displayPlayers() {
	string pool = " Pool of Players ";
	string myPlayers[11];
	string str;
	for (int i = 0; i < totalPlayers; i++) {
		if (hasAddedToTeam[i] == 0)
			myPlayers[i] = players[i];
		else myPlayers[i] = players[i] + " X";
	}

	screenDisplay.screenOutput(pool, myPlayers, totalPlayers);

}

void Game :: assignPlayersToTeams() {
	string createTeam = " Create Team A and B ";
	int len = createTeam.length();
	//cout << "\n Team Length : " << len << endl;

	int equal = (50 - 2 - len) / 2;
	//cout << " equal : " << equal << endl;
	//screenDisplay.heading(createTeam, 50, equal);

	int teamPlayersCount = 5;
	int teamAPlayer=0, teamBPlayer=0;
	string team1[5] = {}, team2[5] ;
	for (int i = 0; i < teamPlayersCount; i++) {
		system("cls");
		screenDisplay.heading(createTeam, 50, equal);
		cout << endl;
		displayPlayers();
		cout << endl << endl;
		cout << " Enter Team A Player "<<i+1<<": ";
		cin>> teamAPlayer;
		cout << " Enter Team B Player " << i + 1 << ": ";
		cin>>teamBPlayer;
		if (hasAddedToTeam[teamAPlayer - 1] == 1 || hasAddedToTeam[teamBPlayer - 1]) {
			cout << "One/Both player/s already chosen. \n\n";
			i--;
			system("pause");
			continue;
		}
		hasAddedToTeam[teamAPlayer - 1] = 1;
		hasAddedToTeam[teamBPlayer - 1] = 1;
		team1[i] = players[teamAPlayer - 1];
		team2[i] = players[teamBPlayer - 1];
	}
	system("cls");
	teamA.assignPlayers(teamPlayersCount,team1);
	teamB.assignPlayers(teamPlayersCount, team2);

	cout << endl;
	teamA.displayTeamMembers("Team A");
	cout << endl << endl;
	teamB.displayTeamMembers("Team B");

	cout << endl<<endl;
	system("pause");

	//toss 
	performToss();
}

void Game :: performToss() {
	int choice;
	string heading = " Let's Toss ";
	int len = heading.length();
	//cout << " heading length : " << len<<endl;
	system("cls");
	int dash = 30;
	int equal = (dash - 2 - len) / 2;
	screenDisplay.heading(heading, dash, equal);

	cout << "\n\nTossing the coin .... \n\n";
	srand(time(0));
	int toss = 0;
	while (toss == 0 ) {
		toss=rand() % 3;
	}
	//cout << "Random : " << toss<<endl;

	if (toss == 1) {
		cout << "Team A won the toss\n\n";
		choice = teamA.selectActivity();
		cout << "\n\nTeam A won the toss and elected to " << teamA.getActivity(1) << " first \n\n";
		//cout <<"Choice 1 : "<< choice;
		teamB.setActivity(2, choice);
		if (choice == 1) choice = 2;
		else if (choice == 2) choice = 1;
		//cout << "Choice 2 : " << choice;
		teamA.setActivity(2, choice);
		teamB.setActivity(1, choice);
	}
	else {
		cout << "Team B won the toss\n\n";
		choice = teamB.selectActivity();
		cout << "\n\nTeam B won the toss and elected to " << teamB.getActivity(1) << " first \n\n";
		//cout << "Choice 1 : " << choice;
		teamA.setActivity(2, choice);
		if (choice == 1) choice = 2;
		else if (choice == 2) choice = 1;
		//cout << "Choice 2 : " << choice;
		teamB.setActivity(2, choice);
		teamA.setActivity(1, choice);
	}

	system("pause");
	gamePlay(1);
}

void Game :: gamePlay(int actNo) {
	int team1, team2;
	system("cls");
	string teamAFirst = teamA.getActivity(actNo);
	string teamAHeading = "Team A selects a player to "+teamAFirst;
	teamA.selectFirstPlayerDisplay(teamAHeading);

	cout << endl;
	cin >> team1;

	string teamBFirst = teamB.getActivity(actNo);
	string teamBHeading = "Team B selects a player to " + teamBFirst;
	teamB.selectFirstPlayerDisplay(teamBHeading);

	cout << endl;
	cin >> team2;

	teamA.setPlayingPlayer(team1, actNo);
	teamB.setPlayingPlayer(team2, actNo);

	string temp;
	if (teamAFirst.length() == 4) {
		temp = "ing";
	}
	else temp = "ting";
	cout << "\nTeam A - " << teamA.getPlayingPlayer(actNo) << " is " << teamA.getActivity(actNo) << temp << endl;

	if (teamBFirst.length() == 4) {
		temp = "ing";
	}
	else temp = "ting";
	cout << "\nTeam B - " << teamB.getPlayingPlayer(actNo) << " is " << teamB.getActivity(actNo) << temp << endl;

	if (actNo == 1) {
		teamA.initTeamScore();
		teamB.initTeamScore();
	}

	//display scoreBoard
	displayScoreBoard(actNo);
	isInningsOver = false;
	system("pause");

}

int Game :: getRunsScored() {
	srand(time(0));
	int runs = 0;
	while (true) {
		runs = rand()%7;
		if (runs >= 0 && runs <= 6 && runs != 5) break;
	}
	return runs;
}

void Game :: displayScoreBoard(int actNo) {
	string temp;
	if (teamA.getActivity(actNo) == "Bat") {
		temp = "Team A " + to_string(teamA.teamScore.getRuns()) + " - " + to_string(teamA.teamScore.getWickets()) + " ( "
			+ to_string(teamA.teamScore.getOvers())+" )  | "+teamA.getPlayingPlayer(actNo) +" "+ teamA.playingPlayersScore(teamA.playingPlayerId(actNo), actNo)+ " "
			+teamB.getPlayingPlayer(actNo) + " " +teamB.playingPlayersScore(teamB.playingPlayerId(actNo),actNo);
	}
	else if (teamB.getActivity(actNo) == "Bat") {
		temp = "Team B " + to_string(teamB.teamScore.getRuns()) + " - " + to_string(teamB.teamScore.getWickets()) + " ( "
			+ to_string(teamB.teamScore.getOvers()) + " )  | " + teamB.getPlayingPlayer(actNo) + " " + teamB.playingPlayersScore(teamB.playingPlayerId(actNo), actNo) + " "
			+ teamA.getPlayingPlayer(actNo)+" "+ teamA.playingPlayersScore(teamA.playingPlayerId(actNo), actNo);
	}

	string heading = "Score Board";
	//cout << "Temp len" << temp.length()<<endl;
	//cout << "headin len" << heading.length() << endl;
	int dash = temp.length() + 8;
	//cout << "Dash : " << dash<<endl;
	int equal = (dash - 2-heading.length()) / 2;
	screenDisplay.heading(heading, dash, equal);
	cout << endl;
	screenDisplay.heading(temp, dash);
	cout << endl<<endl;
}

void Game :: playingGame() {
	system("cls");
	int run,scoredRun;
	int actNo = 1;
	bool res;
	int ball;
	char ch;
	float over,teamOver;
	int wicket;
	int x = getchar();

	while (actNo < 3) {
		cout << "Enter to bowl....\n";
		x = getchar();
		cout << "Bowling\n\n";
		run = getRunsScored();
		if (run == 0) {
			if (teamA.getActivity(actNo) == "Bat") {
				cout << teamB.getPlayingPlayer(actNo) << " to " << teamA.getPlayingPlayer(actNo) << " OUT !\n\n";
				wicket = teamA.teamScore.getWickets();
				teamA.teamScore.setWickets(++wicket);
				wicket = teamB.playerScore[teamB.playingPlayerId(actNo)].getWickets();
				teamB.playerScore[teamB.playingPlayerId(actNo)].setWickets(++wicket);

				ball = teamB.playerScore[teamB.playingPlayerId(actNo)].getBowlBalls();
				ball++;
				teamB.playerScore[teamB.playingPlayerId(actNo)].setBowlBalls(ball);

				over = (float)ball / 6;
				teamB.playerScore[teamB.playingPlayerId(actNo)].setOvers(over);

				ball = teamA.teamScore.getBatBalls();
				ball++;
				over = (float)ball / 6;
				teamOver = teamA.teamScore.getOvers();
				teamOver += (float)(over);
				teamA.teamScore.setOvers(teamOver);

				teamA.nextPlayer(actNo);
				res = teamA.isPlayerAvailable(actNo);
				if (res == true) {
					cout << "\n Team A next Player \n";
					teamA.assignNextPlayer(actNo);
				}
				else {
					isInningsOver = true;
					cout << "\n Team A no Player left\n";
					if (actNo == 1)
						inningBoard();
					else finalScoreCard();
					actNo++;
					if (actNo <= 2)
						gamePlay(actNo);
					continue;
					//do something
				}
			}
			else {
				cout << teamA.getPlayingPlayer(actNo) << " to " << teamB.getPlayingPlayer(actNo) << " OUT !\n\n";
				wicket = teamB.teamScore.getWickets();
				teamB.teamScore.setWickets(++wicket);
				wicket = teamA.playerScore[teamA.playingPlayerId(actNo)].getWickets();
				teamA.playerScore[teamA.playingPlayerId(actNo)].setWickets(++wicket);

				ball = teamA.playerScore[teamA.playingPlayerId(actNo)].getBowlBalls();
				ball++;
				teamA.playerScore[teamA.playingPlayerId(actNo)].setBowlBalls(ball);

				over = (float)ball / 6;
				teamA.playerScore[teamA.playingPlayerId(actNo)].setOvers(over);

				ball = teamA.teamScore.getBatBalls();
				ball++;
				over = (float)ball / 6;
				teamOver = teamB.teamScore.getOvers();
				teamOver += (float)(over);
				teamB.teamScore.setOvers(teamOver);

				teamB.nextPlayer(actNo);
				res = teamB.isPlayerAvailable(actNo);
				if (res == true) {
					cout << "\n Team B next Player \n";
					teamB.assignNextPlayer(actNo);
				}
				else {
					isInningsOver = true;
					cout << "\n Team B no Player \n";
					if (actNo == 1)
						inningBoard();
					else finalScoreCard();
					actNo++;
					if(actNo <=2)
					gamePlay(actNo);
					continue;
					//do something
				}
			}
		}
		else {
			if (teamA.getActivity(actNo) == "Bat") {
				cout << teamB.getPlayingPlayer(actNo) << " to " << teamA.getPlayingPlayer(actNo) << " " << run << " runs !";
				cout << endl<<endl;
				
				scoredRun = teamA.teamScore.getRuns();
				scoredRun += run;
				teamA.teamScore.setRuns(scoredRun);

				scoredRun = teamA.playerScore[teamA.playingPlayerId(actNo)].getRuns();
				scoredRun += run;
				teamA.playerScore[teamA.playingPlayerId(actNo)].setRuns(scoredRun);

				//batting team player balls update
				ball = teamA.playerScore[teamA.playingPlayerId(actNo)].getBatBalls();
				ball++;
				teamA.playerScore[teamA.playingPlayerId(actNo)].setBatBalls(ball);

				//bowling team player balls update
				ball = teamB.playerScore[teamB.playingPlayerId(actNo)].getBowlBalls();
				ball++;
				teamB.playerScore[teamB.playingPlayerId(actNo)].setBowlBalls(ball);

				over = (float)ball / 6;
				teamB.playerScore[teamB.playingPlayerId(actNo)].setOvers(over);

				ball = teamA.teamScore.getBatBalls();
				ball++;
				over = (float)ball / 6;
				teamOver = teamA.teamScore.getOvers();
				teamOver += (float)(over);
				teamA.teamScore.setOvers(teamOver);

				displayScoreBoard(actNo);
			}
			else {
				cout << teamA.getPlayingPlayer(actNo) << " to " << teamB.getPlayingPlayer(actNo) << " " << run << " runs !";
				cout << endl << endl;

				scoredRun = teamB.teamScore.getRuns();
				scoredRun += run;
				teamB.teamScore.setRuns(scoredRun);

				scoredRun = teamB.playerScore[teamB.playingPlayerId(actNo)].getRuns();
				scoredRun += run;
				teamB.playerScore[teamB.playingPlayerId(actNo)].setRuns(scoredRun);

				ball = teamB.playerScore[teamB.playingPlayerId(actNo)].getBatBalls();
				ball++;
				teamB.playerScore[teamB.playingPlayerId(actNo)].setBatBalls(ball);

				ball = teamA.playerScore[teamA.playingPlayerId(actNo)].getBowlBalls();
				ball ++;
				teamA.playerScore[teamA.playingPlayerId(actNo)].setBowlBalls(ball);

				over = (float)ball / 6;
				teamA.playerScore[teamA.playingPlayerId(actNo)].setOvers(over);

				ball = teamB.teamScore.getBatBalls();
				ball++;
				over = (float)ball / 6;
				teamOver = teamB.teamScore.getOvers();
				teamOver += (float)over;
				teamB.teamScore.setOvers(teamOver);

				displayScoreBoard(actNo);
			}
		}

		if (teamA.getActivity(actNo) == "Bowl") {
			if (teamA.playerScore[teamA.playingPlayerId(actNo)].getBowlBalls() % 6 == 0) {
				teamA.nextPlayer(actNo);
				res = teamA.isPlayerAvailable(actNo);
				if (res == false) {
					isInningsOver = true;
					cout << "\n Team A no Player \n";
					if (actNo == 1)
						inningBoard();
					else finalScoreCard();
					actNo++;
					if (actNo <= 2)
						gamePlay(actNo);
					continue;
				}
				else {
					cout << "\n Team A next Player \n";
					teamA.assignNextPlayer(actNo);
				}
			}
			/*else {
				ball = teamA.playerScore[teamA.playingPlayerId(actNo)].getBatBalls();
				ball++;
				teamA.playerScore[teamA.playingPlayerId(actNo)].setBowlBalls(ball);
			}*/
		}
		else {
			if (teamB.playerScore[teamB.playingPlayerId(actNo)].getBowlBalls() % 6 == 0) {
				teamB.nextPlayer(actNo);
				res = teamB.isPlayerAvailable(actNo);
				if (res == false) {
					isInningsOver = true;
					cout << "\n Team B no Player \n";
					if (actNo == 1)
						inningBoard();
					else finalScoreCard();
					actNo++;
					if (actNo <= 2)
						gamePlay(actNo);
					continue;
				}
				else {
					cout << "\n Team B next Player \n";
					teamB.assignNextPlayer(actNo);
				}
			}
			/*else {
				ball = teamB.playerScore[teamB.playingPlayerId(actNo)].getBatBalls();
				ball++;
				teamB.playerScore[teamA.playingPlayerId(actNo)].setBowlBalls(ball);
			}*/
		}

		if (actNo == 2) {
			if (teamA.getActivity(actNo - 1) == "Bat") {
				if (teamA.teamScore.getRuns() < teamB.teamScore.getRuns()) {
					//display final board
					finalScoreCard();
				}
			}
			else {
				if (teamB.teamScore.getRuns() < teamA.teamScore.getRuns()) {
					//display final board
					finalScoreCard();
				}
			}
		}
	}
}

void Game :: inningBoard() {
	string boardHeading = " Inning Over ";
	string battingTeam, bowlingTeam;

	if (teamA.getActivity(1) == "Bat") {
		battingTeam = "Team A score " + to_string(teamA.teamScore.getRuns()) + " - " + to_string(teamA.teamScore.getWickets()) + " ( "
			+ to_string(teamA.teamScore.getOvers()) + " )";
		bowlingTeam = "Team B needs " + to_string(teamA.teamScore.getRuns()+1) + " runs to win";
	}
	else {
		battingTeam = "Team B score " + to_string(teamB.teamScore.getRuns()) + " - " + to_string(teamB.teamScore.getWickets()) + " ( "
			+ to_string(teamB.teamScore.getOvers()) + " )";
		bowlingTeam = "Team A score " + to_string(teamB.teamScore.getRuns() + 1) + " runs to win";
	}

	string con[] = { battingTeam,bowlingTeam };

	screenDisplay.screenOutput(boardHeading, con, 2);
	cout << endl;

	system("pause");
}

void Game :: finalScoreCard() {
	system("cls");
	string heading = "\t Final Board Score \t";
	int dash = heading.length() + 8 + 7;
	screenDisplay.heading(heading, dash);
	cout << endl;

	if (teamA.getActivity(1) == "Bat") {
		if (teamA.teamScore.getRuns() < teamB.teamScore.getRuns()) {
			cout << "\n Team B won the match !! \n";
		}
		else {
			cout << "\n Team A won the match !! \n";
		}
	}
	else {
		if (teamB.teamScore.getRuns() < teamA.teamScore.getRuns()) {
			cout << "\n Team A won the match !! \n";
		}
		else {
			cout << "\n Team B won the match !! \n";
		}
	}

	cout << "\n Team A " << teamA.teamScore.getRuns() << " - " << teamA.teamScore.getWickets() << " (" << teamA.teamScore.getOvers() << ") \n";
	teamA.displayTeamScore();
	cout << "\n\n Team B " << teamB.teamScore.getRuns() << " - " << teamB.teamScore.getWickets() << " (" << teamB.teamScore.getOvers() << ") \n";
	teamB.displayTeamScore();
	cout << endl << endl;
	exit(0);
}
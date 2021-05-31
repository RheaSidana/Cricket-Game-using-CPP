#include "GameHeader.h"
#include <iostream>
#include <string>
using namespace std;

//assign players to the team
void Team :: assignPlayers(int n, string members[]) {
	playersCount = n;
	for (int i = 0; i < n; i++) {
		players[i] = members[i];
		hasPlayed1[i] = 0;
		hasPlayed2[i] = 0;
	}
}

//display the players on the screen
void Team::displayTeamMembers(string teamName) {
	screenDisplay.screenOutput(teamName, players, playersCount);
}

//return the activty number chosen and assign the first activity to the team
int Team :: selectActivity() {
	int ch;
	while (true) {
		cout << "\nEnter the option below: ";
		cout << endl << "1. Bat";
		cout << endl << "2. Bowl\n";
		cin >> ch;
		if (ch == 1 || ch == 2)break;
		else cout << "\nEnter valid option";
	}
	switch (ch) {
	case 1: activity1 = Activity::batting;
		break;
	case 2: activity1 = Activity::bowling;
		break;
	}
	return ch;
}

//return the activity as string 
string Team ::  getActivity(int no) {
	string retStr;
	if (no == 1) {
		switch(activity1){
		case batting: retStr= "Bat";
			break;
		case bowling: retStr = "Bowl";
			break;
		}
	}
	else if (no == 2) {
		switch (activity2) {
		case batting: retStr = "Bat";
			break;
		case bowling: retStr = "Bowl";
			break;
		}
	}
	return retStr;
}

//display to select the first player display
void Team :: selectFirstPlayerDisplay(string heading) {
	screenDisplay.screenOutput(heading, playersCount, players);
}

//set the activity 1 or 2 on the basis of the activity number 
void Team::setActivity(int actNo,int ch) {
	switch (ch) {
	case 1: switch (actNo) {
		case 1: activity1 = Activity::batting;
			break;
		case 2: activity2 = Activity::batting;
			break;
		}
		break;
	case 2: switch (actNo) {
		case 1:activity1 = Activity::bowling;
			break;
		case 2: activity2 = Activity::bowling;
			break;
		}
		break;
	}
}

//set the new player as playing
void Team ::  setPlayingPlayer(int n,int actNo) {
	while (true) {
		if (actNo == 1 && hasPlayed1[n - 1] != -1 && hasPlayed1[n - 1] != 1) {
			hasPlayed1[n - 1] = 1;
			break;
		}
		else if (actNo == 2 && hasPlayed2[n - 1] != -1 && hasPlayed2[n - 1] != 1) {
			hasPlayed2[n - 1] = 1;
			break;
		}
		else {
			cout << "Player already played. Choose another : ";
			cin >> n;
		}
	}
}

//return the name of the playing player 
string Team :: getPlayingPlayer(int actNo) {
	string playerName;
	for (int i = 0; i < playersCount; i++) {
		if (actNo == 1 && hasPlayed1[i] == 1) {
			playerName = players[i];
			break;
		}
		else if (actNo == 2 && hasPlayed2[i] == 1) {
			playerName = players[i];
			break;
		}
	}
	return playerName;
}

//display the players available to play
void Team::playersToPlay(int actNo) {
	string str[5];
	for (int i = 0; i < playersCount; i++) {
		if (actNo == 1 && hasPlayed1[i] == -1) {
			str[i] = players[i] + "  X";
		}
		else if (actNo == 2 && hasPlayed2[i] == -1) {
			str[i] = players[i] + "  X";
		}
		else {
			str[i] = players[i];
		}
	}

	string heading = " Select the player to play ";

	screenDisplay.screenOutput(heading, str, 5);
}

//set the currently player player as played
void Team::nextPlayer(int actNo) {
	int id = playingPlayerId(actNo);
	if (actNo == 1 ) {
		hasPlayed1[id] = -1;
	}
	else if (actNo == 2 ) {
		hasPlayed2[id] = -1;
	}
}

//initialize the score of team and players resplectively
void Team:: initTeamScore() {
	teamScore.init();
	for (int i = 0; i < playersCount; i++) {
		playerScore[i].init();
	}
}

//return the array element id of the playing player
int Team::playingPlayerId(int actNo) {
	int id=-1;
	for (int i = 0; i < playersCount; i++) {
		if (actNo == 1 && hasPlayed1[i] == 1) {
			id= i;
			break;
		}
		else if (actNo == 2 && hasPlayed2[i] == 1) {
			id = i;
			break;
		}
	}
	return id;
}

//return the playing player's score according to the activity
string Team :: playingPlayersScore(int id,int actNo) {
	string str;
	//int id = playingPlayerId(actNo);
	if (actNo == 1) {
		if (activity1 == Activity::batting) {
			str = to_string(playerScore[id].getRuns()) + " ( " + to_string(playerScore[id].getBatBalls()) + " ) | ";
		}
		else if (activity1 == Activity::bowling) {
			str = to_string(playerScore[id].getOvers()) + " - " + to_string(playerScore[id].getBowlBalls()) + " - " + to_string(playerScore[id].getWickets());
		}
	}
	else if (actNo == 2) {
		if (activity2 == Activity::batting) {
			str = to_string(playerScore[id].getRuns()) + " ( " + to_string(playerScore[id].getBatBalls()) + " ) | ";
		}
		else if (activity2 == Activity::bowling) {
			str = to_string(playerScore[id].getOvers()) + " - " + to_string(playerScore[id].getBowlBalls()) + " - " + to_string(playerScore[id].getWickets());
		}
	}

	return str;
}

//return the availability of players to play 
bool Team::isPlayerAvailable(int actNo) {
	bool res=false;
	for (int i = 0; i < playersCount; i++) {
		if (actNo == 1 && hasPlayed1[i] == 0) {
			res = true;
			break;
		}
		else if (actNo == 2 && hasPlayed2[i] == 0) {
			res = true;
			break;
		}
	}
	return res;
}

//assigning next player to play
void Team :: assignNextPlayer(int actNo) {
	playersToPlay(actNo);

	cout << endl;
	int id;
	cin >> id;

	setPlayingPlayer(id, actNo);
}

//display team score for final scroe board
void Team :: displayTeamScore() {
	string heading = " PLAYER   BATTING       BOWLING ";

	//screenDisplay.heading(heading, (heading.length() + 10));
	string str[5];
	for (int i = 0; i < playersCount; i++) {
		str[i] = players[i] + "   " + to_string(playerScore[i].getRuns())+ " ( " + to_string(playerScore[i].getBatBalls()) + " )    "+ to_string(playerScore[i].getOvers()) + " - " + to_string(playerScore[i].getBowlBalls()) + " - " + to_string(playerScore[i].getWickets());
		//cout << endl;
		//screenDisplay.heading(str[i], (str[i].length() + 10));
	}
	//HEAD ARR N

	screenDisplay.finalScore(heading,str,playersCount);

}




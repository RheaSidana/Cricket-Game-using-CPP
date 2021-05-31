#include "GameHeader.h"
#include <iostream>
#include <string>
using namespace std;

//returns the count of ball of the batting player
int Score :: getBatBalls() {
	return batBalls;
}

//initialise the data members 
void Score::init() {
	runs = batBalls = bowlBalls = wickets = 0;
	overs = 0;
}

//set the count of balls of the batting player 
void Score::setBatBalls(int ball) {
	batBalls = ball;
}

//set the count of balls of the bowling player 
void Score::setBowlBalls(int ball) {
	bowlBalls = ball;
}

//return the count of balls of the bowling player 
int Score::getBowlBalls() {
	return bowlBalls;
}

//return count of runs of the batting player 
int  Score::getRuns() {
	return runs;
}

//set count of runs of the batting player 
void Score::setRuns(int run) {
	runs = run;
}

//return count of wicket of the bowling player 
int Score:: getWickets() {
	return wickets;
}

//return count of wicket of the bowling player 
void Score::setWickets(int wicket) {
	wickets = wicket;
}

//return count of overs of the bowling player 
float Score::getOvers() {
	return overs;
}

//return count of overs of the bowling player 
void Score::setOvers(float over) {
	overs = over;
}


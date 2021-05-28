#include "GameHeader.h"
#include <iostream>
#include <string>
using namespace std;

int Score :: getBatBalls() {
	return batBalls;
}

void Score::init() {
	runs = batBalls = bowlBalls = wickets = 0;
	overs = 0;
}

void Score::setBatBalls(int ball) {
	batBalls = ball;
}

void Score::setBowlBalls(int ball) {
	bowlBalls = ball;
}

int Score::getBowlBalls() {
	return bowlBalls;
}

int  Score::getRuns() {
	return runs;
}

void Score::setRuns(int run) {
	runs = run;
}

int Score:: getWickets() {
	return wickets;
}

void Score::setWickets(int wicket) {
	wickets = wicket;
}

float Score::getOvers() {
	return overs;
}

void Score::setOvers(float over) {
	overs = over;
}


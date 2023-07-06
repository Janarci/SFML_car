#pragma once
#include <SFML/System.hpp>
#include <iostream>
#include "AComponent.h"
#include <unordered_map>

class GamestateManager :
	public AComponent
{
public:

	GamestateManager(std::string name);

	void perform() override;

	void update(sf::Time deltaTime);
	void addScore(int toAdd);
	int getScore();
	float getTimeRemaining();
	void setWinCondition(int winCon);
	void setTotalTime(float time);
	void reset();


private:

	int score = 0;
	int winCondition = 50;
	float ticks = 0;
	float secondsPassed = 1.0f;
	float totalTime = 3.0f;


};


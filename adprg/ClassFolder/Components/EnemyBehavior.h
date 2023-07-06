#pragma once
#include "AComponent.h"


class EnemyBehavior : public AComponent
{
public:
	enum EnemyMovementType { Delay = 0, Forward = 1, SlowForward = 2, Side = 3};

	EnemyBehavior(std::string name);
	void perform() override;
	void configure(float delay);
	void reset();
	void leftLane();
	void rightLane();
private:
	float SPEED_MULT = 200.0f;
	EnemyMovementType movementType = Forward;
	float ticks = 0.0f;
	float delay = 0.0f;
	float forwardDuration = 0.0f;
	int type;

	



};


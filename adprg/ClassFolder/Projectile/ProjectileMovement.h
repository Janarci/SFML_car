#pragma once
#include "../Components/AComponent.h"


class ProjectileMovement : public AComponent
{

public:
	ProjectileMovement(std::string name);
	void perform() override;;
	void reset();

private:
	const float SPEED_MULTIPLIER = 500.0f;
	float ticks = 0.0f;

};


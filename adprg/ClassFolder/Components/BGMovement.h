#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include "AComponent.h"
class BGMovement :
    public AComponent
{
public:
    BGMovement(std::string name);
    ~BGMovement();
    void perform() override;

private:
    sf::Sprite* sprite;
    const float SPEED_MULTIPLIER = 900.0f;


};


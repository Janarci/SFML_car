#pragma once
#include "AGameObject.h"
#include "Physics/Collider.h"

class AirplanePlayer :
    public AGameObject, public CollisionListener
{
public:

    AirplanePlayer(std::string name);
    void initialize() override;
    //void processInput(sf::Event event) override;
    //void update(sf::Time deltaTime) override;

    void onCollisionEnter(AGameObject* gameObject) override;
    void onCollisionExit(AGameObject* gameObject) override;
private:
    Collider* collider;

    const float SPEED_MULT = 300.0f;
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
};


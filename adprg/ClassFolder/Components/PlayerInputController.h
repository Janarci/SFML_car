#pragma once
#include "GenericInputController.h"
class PlayerInputController :
    public GenericInputController
{
public:
    PlayerInputController(std::string name);
    ~PlayerInputController();
    void perform() override;
    const float SPEED_MULT = 400.0f;

    bool isUp();
    bool isDown();
    bool isLeft();
    bool isRight();
    bool isBoosting();;
    bool hasFired();;
    

private:
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
    bool boosting = false;
    bool fire = false;
};


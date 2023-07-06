#pragma once
#include <SFML/Window.hpp>
#include "AComponent.h"

class GenericInputController :
    public AComponent
{
public:

    GenericInputController(std::string name);
    ~GenericInputController();

    void perform() override;;
    void assignEvent(sf::Event event);

protected:
    sf::Event event;


};


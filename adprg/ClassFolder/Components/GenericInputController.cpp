#include "GenericInputController.h"

GenericInputController::GenericInputController(std::string name) : AComponent(name, Input)
{

}

GenericInputController::~GenericInputController()
{

	//???
}
  
void GenericInputController::perform()
{

}

void GenericInputController::assignEvent(sf::Event event)
{
	this->event = event;
}

#include "UIButtonInputController.h"
#include <iostream>

UIButtonInputController::UIButtonInputController(std::string name, ButtonListener* buttonListener)
: GenericInputController(name)
{
	this->buttonListener = buttonListener;
}

UIButtonInputController::~UIButtonInputController()
{
}

void UIButtonInputController::perform() {

	UIButton* button = (UIButton*)this->getOwner();
	if (this->event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && this->pressed) {
		this->pressed = false;
		button->changeButtonToNormal();
		this->buttonListener->onButtonReleased(button);

	}

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		//check if button is within mouse coord
		sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
		sf::FloatRect bounds = button->getGlobalBounds();	//returns the rect

		if (bounds.contains(mousePos)) {
			this->pressed = true;
			button->changeButtonToPressed();
			this->buttonListener->onButtonClick(button);
		}
	}


}
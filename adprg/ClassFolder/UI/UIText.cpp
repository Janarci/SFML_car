#include "UIText.h"
#include "../../FontManager.h"
#include "../Components/Renderer.h"

UIText::UIText(std::string name) : AGameObject(name)
{
	this->text = new sf::Text();
}

UIText::~UIText()
{
	delete this->text;

}

void UIText::initialize()
{
	sf::Font* font = FontManager::getInstance()->getFont("default");
	text->setFont(*font);
	text->setFillColor(sf::Color::White);
	text->setOutlineColor(sf::Color::Black);
	text->setOutlineThickness(4.0f);
	this->setSize(40);
	this->setText("<Using placeholder!>");

	Renderer* renderer = new Renderer("Button");
	renderer->assignDrawable(text);
	this->attachComponents(renderer);
}

void UIText::setText(std::string text)
{
	this->text->setString(text);
	sf::FloatRect bounds = this->text->getLocalBounds();
	// Align center, you can put other alignment here
	this->text->setOrigin(bounds.width / 2, bounds.height / 2);
}

std::string UIText::getText()
{
	return this->text->getString();
}

void UIText::setSize(unsigned size)
{
	this->text->setCharacterSize(size);
}

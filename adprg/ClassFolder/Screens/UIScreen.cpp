#include "UIScreen.h"
#include "MainMenuScreen.h"
#include "PopUpScreen.h"
#include "../TextureManager.h"
#include "../../ApplicationManager.h"
#include "../Components/Renderer.h"
#include "../../game.h"


UIScreen::UIScreen(std::string name) : AGameObject(name), ButtonListener()
{
}

UIScreen::~UIScreen()
{
}

void UIScreen::initialize()
{
	AGameObject::initialize();/*
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("ui_bg"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->getTransformable()->setScale(.3f, .1f);

	Renderer* renderer = new Renderer("SidebarPanel");
	renderer->assignDrawable(sprite);
	this->attachComponents(renderer);
	*/
	float posX = 1200 /2;
	float posY = game::WINDOW_HEIGHT/2;
	this->setPosition(0, 0);


	this->gasText = new UIText("gasText");
	this->attachChild(this->gasText);
	this->gasText->setPosition(1200 * .80, 300);
	this->gasText->setSize(50);
	gasText->setText("Boost: ");

	this->timeText = new UIText("timeText");
	this->attachChild(this->timeText);
	this->timeText->setPosition(1200 * .80, 100);
	this->timeText->setSize(50);
	timeText->setText("Time: ");
}

void UIScreen::setClcked(bool click)
{
	this->clicked = click;
}

void UIScreen::setGas(std::string gas)
{
	gasText->setText("Boost: " + gas);

}

void UIScreen::setTime(std::string time)
{
	timeText->setText("Time: " + time);

}

void UIScreen::onButtonClick(UIButton* button)
{
}

void UIScreen::onButtonReleased(UIButton* button)
{
	if (button->getName() == "button_2" && !ApplicationManager::getInstance()->isPaused())
	{
		PopUpScreen* PauseScreen = new PopUpScreen("PauseScreen");
		GameObjectManager::getInstance()->addObject(PauseScreen);
		ApplicationManager::getInstance()->pauseApplication();
	}
}

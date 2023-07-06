#include "Sidebar.h"

#include "MainMenuScreen.h"
#include "PopUpScreen.h"
#include "../TextureManager.h"
#include "../../ApplicationManager.h"
#include "../Components/Renderer.h"
#include "../../game.h"


Sidebar::Sidebar(std::string name) : AGameObject(name), ButtonListener()
{
}

Sidebar::~Sidebar()
{
}

void Sidebar::initialize()
{
	AGameObject::initialize();
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("ui_bg"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->getTransformable()->setScale(.3f, .1f);

	Renderer* renderer = new Renderer("SidebarPanel");
	renderer->assignDrawable(sprite);
	this->attachComponents(renderer);

	float posX = 1200 * .80;
	float posY = game::WINDOW_HEIGHT - 50;
	this->setPosition(posX, posY);


	this->button2 = new UIButton("button_2", TextureManager::getInstance()->getTexture("btn_normal"), TextureManager::getInstance()->getTexture("btn_pressed"));
	this->attachChild(this->button2);
	button2->setPosition(150, 0);
	button2->getTransformable()->setScale(1.0f, 4.0f);

	this->button2_text = new UIText("button2_text");
	this->button2->attachChild(button2_text);
	this->button2_text->setPosition(0, -20);
	this->button2_text->setSize(64);
	button2_text->setText("Quit");
	this->button2->setButtonListener(this);
}

void Sidebar::setClcked(bool click)
{
	this->clicked = click;
}

void Sidebar::onButtonClick(UIButton* button)
{
}

void Sidebar::onButtonReleased(UIButton* button)
{
	if (button->getName() == "button_2" && !ApplicationManager::getInstance()->isPaused())
	{
		PopUpScreen* PauseScreen = new PopUpScreen("PauseScreen");
		GameObjectManager::getInstance()->addObject(PauseScreen);
		ApplicationManager::getInstance()->pauseApplication();
	}
}

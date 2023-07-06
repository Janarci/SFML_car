#include "LoseScreen.h"
#include "../TextureManager.h"
#include "../../ApplicationManager.h"
#include "../Components/Renderer.h"
#include "../../game.h"
#include "../SceneManager.h"


LoseScreen::LoseScreen(std::string name) : AGameObject(name), ButtonListener()
{
}

LoseScreen::~LoseScreen()
{
	//delete this->button1;
	//delete this->button1_text;
}

void LoseScreen::initialize()
{//change text based on which scene is loaded
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("ui_bg"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	Renderer* renderer = new Renderer("WinScreen");
	renderer->assignDrawable(sprite);
	this->attachComponents(renderer);

	float posX = game::WINDOW_WIDTH / 2;
	float posY = game::WINDOW_HEIGHT / 2;
	this->setPosition(posX, posY);

	this->WinText = new UIText("LoseText");
	this->attachChild(WinText);
	this->WinText->setText("Level Failed!");
	this->WinText->setSize(35);
	this->WinText->setPosition(40, 0);

	this->button1 = new UIButton("button_1", TextureManager::getInstance()->getTexture("btn_normal"), TextureManager::getInstance()->getTexture("btn_pressed"));
	this->attachChild(this->button1);
	this->button1->setPosition(-150, 150);
	this->button1->getTransformable()->setScale(.7f, .7f);

	this->button1_text = new UIText("restart_text");
	this->button1->attachChild(button1_text);
	this->button1_text->setPosition(0, -20);
	this->button1_text->setSize(64);
	this->button1_text->setText("Restart");
	this->button1->setButtonListener(this);

	this->button2 = new UIButton("button_2", TextureManager::getInstance()->getTexture("btn_normal"), TextureManager::getInstance()->getTexture("btn_pressed"));
	this->attachChild(this->button2);
	this->button2->setPosition(150, 150);
	this->button2->getTransformable()->setScale(.7f, .7f);

	this->button2_text = new UIText("quit_text");
	this->button2->attachChild(button2_text);
	this->button2_text->setPosition(0, -20);
	this->button2_text->setSize(64);
	this->button2_text->setText("Quit");
	this->button2->setButtonListener(this);

}

void LoseScreen::onButtonClick(UIButton* button)
{

}

void LoseScreen::onButtonReleased(UIButton* button)
{
	if (button->getName() == "button_1")//restart
	{
		//GameObjectManager::getInstance()->deleteObjectByName("MainMenuScreen");
		//SceneManager::getInstance()->unloadScene();
		//SceneManager::getInstance()->unloadScene();
		SceneManager::getInstance()->reloadScene();
		//ApplicationManager::getInstance()->resumeApplication();



	}
	//SceneManager::getInstance()->isSceneLoaded("Level3")
	if (button->getName() == "button_2")//quit
	{
		//SceneManager::getInstance()->loadScene("Level1");

		//GameObjectManager::getInstance()->deleteObjectByName("PauseScreen");
		SceneManager::getInstance()->loadScene("MainMenuScene");

		//ApplicationManager::getInstance()->resumeApplication();
	}

}

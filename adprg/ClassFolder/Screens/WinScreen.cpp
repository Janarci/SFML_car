#include "WinScreen.h"
#include "../TextureManager.h"
#include "../../ApplicationManager.h"
#include "../Components/Renderer.h"
#include "../../game.h"
#include "../SceneManager.h"


WinScreen::WinScreen(std::string name) : AGameObject(name), ButtonListener()
{
}

WinScreen::~WinScreen()
{
	//delete this->button1;
	//delete this->button1_text;
}

void WinScreen::initialize()
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

	this->WinText = new UIText("WinText");
	this->attachChild(WinText);
	this->WinText->setText("Do you want to continue to the next level?");
	this->WinText->setSize(35);
	this->WinText->setPosition(40, 0);

	this->button1 = new UIButton("button_1", TextureManager::getInstance()->getTexture("btn_normal"), TextureManager::getInstance()->getTexture("btn_pressed"));
	this->attachChild(this->button1);
	this->button1->setPosition(-150, 150);
	this->button1->getTransformable()->setScale(.7f, .7f);

	this->button1_text = new UIText("yes_text");
	this->button1->attachChild(button1_text);
	this->button1_text->setPosition(0, -20);
	this->button1_text->setSize(64);
	this->button1_text->setText("Yes");
	this->button1->setButtonListener(this);

	this->button2 = new UIButton("button_2", TextureManager::getInstance()->getTexture("btn_normal"), TextureManager::getInstance()->getTexture("btn_pressed"));
	this->attachChild(this->button2);
	this->button2->setPosition(150, 150);
	this->button2->getTransformable()->setScale(.7f, .7f);

	this->button2_text = new UIText("no_text");
	this->button2->attachChild(button2_text);
	this->button2_text->setPosition(0, -20);
	this->button2_text->setSize(64);
	this->button2_text->setText("No");
	this->button2->setButtonListener(this);

}

void WinScreen::onButtonClick(UIButton* button)
{

}

void WinScreen::onButtonReleased(UIButton* button)
{
	if (button->getName() == "button_1")//yes
	{
		//GameObjectManager::getInstance()->deleteObjectByName("MainMenuScreen");
		//SceneManager::getInstance()->unloadScene();
		//SceneManager::getInstance()->unloadScene();
		
		if (SceneManager::getInstance()->isSceneLoaded("Level1"))
		{
			SceneManager::getInstance()->loadScene("Level2");

		}
		else if (SceneManager::getInstance()->isSceneLoaded("Level2"))
		{
			SceneManager::getInstance()->loadScene("Level3");

		}
		else if (SceneManager::getInstance()->isSceneLoaded("Level3"))
		{
			SceneManager::getInstance()->loadScene("MainMenuScene");

		}
		//ApplicationManager::getInstance()->resumeApplication();



	}
	//SceneManager::getInstance()->isSceneLoaded("Level3")
	if (button->getName() == "button_2")//no
	{
		//SceneManager::getInstance()->loadScene("Level1");

		//GameObjectManager::getInstance()->deleteObjectByName("PauseScreen");
		SceneManager::getInstance()->loadScene("MainMenuScene");

		//ApplicationManager::getInstance()->resumeApplication();
	}

}

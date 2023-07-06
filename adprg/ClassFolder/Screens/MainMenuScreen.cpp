#include "MainMenuScreen.h"

#include "PopUpScreen.h"
#include "Sidebar.h"
#include "../TextureManager.h"
#include "../SceneManager.h"
#include "../../ApplicationManager.h"
#include "../Components/Renderer.h"
#include "../../game.h"
class Sidebar;

MainMenuScreen::MainMenuScreen(std::string name) : AGameObject(name), ButtonListener()
{
}

MainMenuScreen::~MainMenuScreen()
{
	//delete this->button1;
	//delete this->button1_text;
}

void MainMenuScreen::initialize()
{
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("race_bg"));
	sprite->setScale(0.8f, 1.2f);
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	Renderer* renderer = new Renderer("MainMenuScreen");
	renderer->assignDrawable(sprite);
	this->attachComponents(renderer);

	float posX = 1200 / 2;//game::WINDOW_WIDTH / 2;
	float posY = game::WINDOW_HEIGHT / 2;
	this->setPosition(posX, posY);

	/*remove text
	this->quitText = new UIText("QuitText");
	this->attachChild(quitText);
	this->quitText->setText("Are you sure you want to quit the game?");
	this->quitText->setSize(35);
	this->quitText->setPosition(40, 0);
	*/
	this->button1 = new UIButton("button_1", TextureManager::getInstance()->getTexture("btn_normal"), TextureManager::getInstance()->getTexture("btn_pressed"));
	this->attachChild(this->button1);
	button1->setPosition(-150, 150);
	button1->getTransformable()->setScale(1.0f, 1.0f);

	this->button1_text = new UIText("button1_text");
	this->button1->attachChild(button1_text);
	this->button1_text->setPosition(button1->getTransformable()->getOrigin().x, button1->getTransformable()->getOrigin().y);
	this->button1_text->setSize(35);
	button1_text->setText("Quit");
	this->button1->setButtonListener(this);

	this->button2 = new UIButton("button_2", TextureManager::getInstance()->getTexture("btn_normal"), TextureManager::getInstance()->getTexture("btn_pressed"));
	this->attachChild(this->button2);
	button2->setPosition(150, 150);
	button2->getTransformable()->setScale(1.0f, 1.0f);

	this->button2_text = new UIText("button2_text");
	this->button2->attachChild(button2_text);
	this->button2_text->setPosition(button2->getTransformable()->getOrigin().x, button2->getTransformable()->getOrigin().y);
	this->button2_text->setSize(35);
	button2_text->setText("Play Game");
	this->button2->setButtonListener(this);
}

void MainMenuScreen::onButtonClick(UIButton* button)
{
	
}

void MainMenuScreen::onButtonReleased(UIButton* button)
{
	if (button->getName() == "button_1" && !ApplicationManager::getInstance()->isPaused())
	{
		ApplicationManager::getInstance()->applicationQuit();
		/*PopUpScreen* PauseScreen = new PopUpScreen("PauseScreen");
		GameObjectManager::getInstance()->addObject(PauseScreen);
		ApplicationManager::getInstance()->pauseApplication();*/
		//SceneManager::getInstance()->loadScene("MainMenuScene");

		//SceneManager::getInstance()->loadScene("MainMenuScreen");
	}

	if (button->getName() == "button_2" && !ApplicationManager::getInstance()->isPaused())
	{
		//GameObjectManager::getInstance()->deleteObjectByName("MainMenuScreen");

		//SceneManager::getInstance()->unloadScene();
		std::cout << "clicking" << std::endl;

		SceneManager::getInstance()->loadScene("Level1");
	}

}

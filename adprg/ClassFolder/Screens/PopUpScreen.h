#pragma once
#include "../AGameObject.h"
#include "../UI/UIButton.h"
#include "../UI/UIText.h"
class ApplicationManager;

class PopUpScreen : public AGameObject, public ButtonListener
{
public:
	PopUpScreen(std::string name);
	~PopUpScreen();

	void initialize();

private:
	UIButton* button1;
	UIButton* button2;
	UIText* button1_text;
	UIText* button2_text;
	UIText* quitText;
	void onButtonClick(UIButton* button) override;
	void onButtonReleased(UIButton* button) override;
};



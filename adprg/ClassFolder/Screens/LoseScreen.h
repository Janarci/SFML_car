#pragma once
#include "../AGameObject.h"
#include "../UI/UIButton.h"
#include "../UI/UIText.h"

class ApplicationManager;

class LoseScreen : public AGameObject, public ButtonListener
{

public:
	LoseScreen(std::string name);
	~LoseScreen();

	void initialize();

private:
	UIButton* button1;
	UIButton* button2;
	UIText* button1_text;
	UIText* button2_text;
	UIText* WinText;
	void onButtonClick(UIButton* button) override;
	void onButtonReleased(UIButton* button) override;
};



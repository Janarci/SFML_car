#pragma once
#include "../AGameObject.h"
#include "../UI/UIButton.h"
#include "../UI/UIText.h"

class ApplicationManager;

class UIScreen : public AGameObject, public ButtonListener
{
public:
	UIScreen(std::string name);
	~UIScreen();

	void initialize();
	void setClcked(bool click);
	void setGas(std::string gas);
	void setTime(std::string time);

private:
	UIButton* button2;
	UIText* gasText;
	UIText* timeText;
	bool clicked = false;

	void onButtonClick(UIButton* button) override;
	void onButtonReleased(UIButton* button) override;
};


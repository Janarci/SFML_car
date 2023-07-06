#pragma once
#include "../AGameObject.h"
#include "../UI/UIButton.h"
#include "../UI/UIText.h"

class ApplicationManager;

class Sidebar : public AGameObject, public ButtonListener
{
public:
	Sidebar(std::string name);
	~Sidebar();

	void initialize();
	void setClcked(bool click);

private:
	UIButton* button2;
	UIText* button2_text;
	bool clicked = false;

	void onButtonClick(UIButton* button) override;
	void onButtonReleased(UIButton* button) override;
};


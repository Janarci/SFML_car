#pragma once
#include "../Components/AComponent.h"
#include "CollisionListener.h"
class Collider : public AComponent
{
public:
	Collider(std::string name);

	void setCollisionListener(CollisionListener* listener);

	void setChecked(bool flag);
	bool isChecked();

	bool willCollide(Collider* another);
	bool alreadyCollided();
	void setAlreadyCollided(bool flag);

	sf::FloatRect getGlobalBOunds();
	void setLocalBounds(sf::FloatRect localBounds);

	void collisionEnter(AGameObject* gameObjects);
	void collisionExit(AGameObject* gameObjects);

	void perform() override;

private:
	bool collided = false;
	bool checked = false;
	sf::FloatRect localBOunds;

	CollisionListener* listener;

};


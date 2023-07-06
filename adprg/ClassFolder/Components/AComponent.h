#pragma once
#include <string>
#include <SFML/System/Time.hpp>

class AGameObject;

class AComponent
{
public:
	enum ComponentType { NotSet = -1, Script = 0, Renderer = 1, Input = 2, Sound = 3, Physics = 4};

	AComponent(std::string name, ComponentType type);
	virtual  ~AComponent();

	void attachOwner(AGameObject* owner);
	void detachOwner();
	AGameObject* getOwner();
	ComponentType getType();
	std::string getName();

	void setDeltaTime(sf::Time deltaTime);
	virtual void perform() = 0;



protected:
	AGameObject* owner;
	ComponentType type;
	std::string name;
	sf::Time deltaTime;
};


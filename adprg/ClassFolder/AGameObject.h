#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Components/AComponent.h"
#include "Components/GenericInputController.h"
#include "Components/Renderer.h"

class AGameObject
{

public:
	AGameObject(std::string name);
	virtual ~AGameObject();
	void clearGameObject();

	virtual void initialize() = 0;
	virtual void processInput(sf::Event event);
	virtual void update(sf::Time deltaTime);
	virtual void draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates);
	std::string getName();

	void attachChild(AGameObject* child);
	void dettachChild(AGameObject* child);
	void setPosition(float x, float y);
	void attachComponents(AComponent* component);
	void detachComponents(AComponent* component);

	AComponent* findComponentByName(std::string name);
	AComponent* findComponentByType(AComponent::ComponentType type, std::string name);
	std::vector<AComponent*> getComponentsOfType(AComponent::ComponentType type);
	//std::vector<AComponent*> getComponentsOfTypeRecursive(AComponent::ComponentType type);

	sf::Transformable* getTransformable();

	sf::Transform getGlobalTransform();

	sf::Sprite* getSprite();
	AGameObject* getParent();

	void setEnabled(bool flag);
	bool isEnabled();

protected: 
	void setParent(AGameObject* parent);

	sf::Transformable transformable;
	std::string name;
	sf::Sprite* sprite;
	sf::Texture* texture;
	std::vector<AGameObject*> childList;
	std::vector<AComponent*> componentList;

private:
	AGameObject* mParent;
	bool enabled = true;



};
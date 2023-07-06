#include "AGameObject.h"

#include <iostream>



AGameObject::AGameObject(std::string name)
{
	this->name = name;

}
AGameObject::~AGameObject()
{
	if (this->sprite != NULL)
	{
		delete this->sprite;
	}
	if (!childList.empty())
	{
		for (int i = 0; i < childList.size(); i++)
		{

			delete childList[i];

		}
		childList.clear();
		childList.shrink_to_fit();
	}
	if (!componentList.empty())
	{
		for (int i = 0; i < componentList.size(); i++)
		{
			delete componentList[i];

		}
		componentList.clear();
		componentList.shrink_to_fit();
	}
	
}

void AGameObject::clearGameObject()
{
	

	
	
}

void AGameObject::initialize()
{
}

void AGameObject::processInput(sf::Event event)
{
	if (!this->enabled)
	{
		return;
	}

	std::vector<AComponent*> componentList = this->getComponentsOfType(AComponent::ComponentType::Input);
	for (int i = 0; i < componentList.size(); ++i)
	{
		((GenericInputController*)componentList[i])->assignEvent(event);
		componentList[i]->perform();

	}
	for (int i = 0; i < childList.size(); ++i)
	{
		childList[i]->processInput(event);
	}

}

void AGameObject::update(sf::Time deltaTime)
{
	if (!this->enabled)
	{
		return;
	}
	std::vector<AComponent*> componentList = this->getComponentsOfType(AComponent::ComponentType::Script);
	for (int i = 0; i < componentList.size(); ++i)
	{
		componentList[i]->setDeltaTime(deltaTime);
		componentList[i]->perform();
	}
	for (int i = 0; i < childList.size(); ++i)
	{
		childList[i]->update(deltaTime);

	}
}


void AGameObject::draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates)
{
	if(!this->enabled)
	{
		return;
	}
	std::vector<AComponent*> componentList = this->getComponentsOfType(AComponent::ComponentType::Renderer);

	renderStates.transform = renderStates.transform * this->transformable.getTransform();

	//targetWindow->draw(*sprite, renderStates);
	for (int i = 0; i < componentList.size(); ++i)
	{
		Renderer* renderer = (Renderer*)componentList[i];
		renderer->assignTargetWindow(targetWindow);
		renderer->setRenderStates(renderStates);
		renderer->perform();
	}
	for (int i = 0; i < childList.size(); ++i)
	{
		AGameObject* child = this->childList[i];
		child->draw(targetWindow, renderStates);
	}
}

std::string AGameObject::getName()
{
	return name;
}

void AGameObject::attachChild(AGameObject* child)
{
	this->childList.push_back(child);
	child->setParent(this);
	child->initialize();
}

void AGameObject::dettachChild(AGameObject* child)
{
	int index = -1;
	for (int i = 0; i < this->childList.size(); ++i)
	{
		if(this->childList[i] == child)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		this->childList.erase(this->childList.begin() + index);
	}
}

void AGameObject::setPosition(float x, float y)
{
	this->transformable.setPosition(x, y);

}

void AGameObject::attachComponents(AComponent* component)
{
	this->componentList.push_back(component);
	component->attachOwner(this);

}

void AGameObject::detachComponents(AComponent* component)
{
	int index = -1;
	for (int i = 0; i < this->componentList.size(); ++i)
	{
		if(this->componentList[i] == component)
		{
			index = i;
			this->componentList[i]->detachOwner();
			break;

		}
	}
	if (index != -1)
	{
		this->componentList.erase(this->componentList.begin() + index);

	}
}

AComponent* AGameObject::findComponentByName(std::string name)
{
	for (int i = 0; i < this->componentList.size(); ++i)
	{
		if (this->componentList[i]->getName() == name)
		{
			return this->componentList[i];
		}
	}
	return NULL;

}

AComponent* AGameObject::findComponentByType(AComponent::ComponentType type, std::string name)
{
	for (int i = 0; i < this->componentList.size(); ++i)
	{
		if(this->componentList[i]->getName() == name && this->componentList[i]->getType() == type)
		{
			return this->componentList[i];
		}
	}
	return NULL;
}

std::vector<AComponent*> AGameObject::getComponentsOfType(AComponent::ComponentType type)
{
	std::vector<AComponent*> foundList;
	for (int i = 0; i < this->componentList.size(); ++i)
	{
		if (this->componentList[i]->getType() == type)
		{
			foundList.push_back(this->componentList[i]);
		}
	}
	return foundList;
}

sf::Transformable* AGameObject::getTransformable()
{
	return &this->transformable;
}

sf::Transform AGameObject::getGlobalTransform()
{
	AGameObject* parentObj = this;
	std::vector<AGameObject*> parentList;

	while (parentObj != NULL)
	{
		parentList.push_back(parentObj);
		parentObj = parentObj->getParent();
	}

	sf::Transform transform = sf::Transform::Identity;

	int startIdx = parentList.size() - 1;
	//int startIdx = 1;
	for (int i = startIdx; i >= 0; i--)
	{
		transform = transform * parentList[i]->getTransformable()->getTransform();

	}
	return transform;
}


sf::Sprite* AGameObject::getSprite()
{
	return this->sprite;
}

AGameObject* AGameObject::getParent()
{
	return this->mParent;
}

void AGameObject::setEnabled(bool flag)
{
	this->enabled = flag;
}

bool AGameObject::isEnabled()
{
	return this->enabled;
}

void AGameObject::setParent(AGameObject* parent)
{
	this->mParent = parent;

}



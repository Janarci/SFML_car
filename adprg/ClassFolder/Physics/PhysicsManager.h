#pragma once
#include <vector>

#include "Collider.h"
#include "../Components/AComponent.h"
#include "../AGameObject.h"
#include <SFML/Graphics.hpp>

typedef std::vector<Collider*> CollisionList;

class PhysicsManager : public AComponent, sf::NonCopyable
{
public:

	static void initialize(std::string name, AGameObject* parent);
	static void destroy();
	static PhysicsManager* getInstance();

	~PhysicsManager() override;

	void trackObject(Collider* object);
	void untrackObject(Collider* object);

	void perform() override;
	CollisionList trackedObjects;
	Collider* playerCollider;

private:

	PhysicsManager(std::string name) : AComponent(name, Script) {  };
	static PhysicsManager* sharedInstance;

	CollisionList forCleaningObjects;

	void cleanUpObjects();
};


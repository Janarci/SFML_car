#pragma once
#include "ProjectileMovement.h"
#include "../ObjectPooling/APoolable.h"
#include "../Physics/CollisionListener.h"
#include "../Physics/Collider.h"
#include "../Physics/PhysicsManager.h"
#include "../TextureManager.h"
#include "../AirplanePlayer.h"
#include "../GameObjectManager.h"
#include "../ObjectPooling/GameObjectPool.h"
#include "../ObjectPoolHolder.h"



class ProjectileObject : public APoolable, public CollisionListener
{

public:
	ProjectileObject(std::string name);
	~ProjectileObject();
	void initialize() override;
	void onRelease() override;
	void onActivate() override;

	APoolable* clone() override;

	void onCollisionEnter(AGameObject* contact) override;
	void onCollisionExit(AGameObject* contact) override;


private:
	ProjectileMovement* projectileMovement;
	Collider* collider;
	bool hasHit = false;


};


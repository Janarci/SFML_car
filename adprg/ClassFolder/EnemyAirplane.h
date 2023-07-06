#pragma once
#include "ObjectPooling/APoolable.h"
#include "../game.h"
#include "AGameObject.h"

#include "TextureManager.h"
#include "Components/EnemyBehavior.h"
#include "Physics/Collider.h"
#include "Physics/CollisionListener.h"

class EnemyAirplane :
    public APoolable, public CollisionListener
{

public:
    EnemyAirplane(std::string name);
    ~EnemyAirplane();

    void initialize() override;/**/
    void onRelease() override;
    void onActivate() override;

    void onCollisionEnter(AGameObject* gameObject) override;
    void onCollisionExit(AGameObject* gameObject) override;

	APoolable* clone();
   

private:
    void textureRandomizer();
    int test = 0;
    sf::Sprite* sprite = new sf::Sprite();
    Collider* collider;
    int SPAWN_RANGE = 160;
    int counter = 0;
};


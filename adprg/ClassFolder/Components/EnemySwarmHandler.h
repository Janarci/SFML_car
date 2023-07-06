#pragma once
#include "AComponent.h"
#include "../ObjectPooling/GameObjectPool.h"
#include "../ObjectPoolHolder.h"
#include "../EnemyAirplane.h"
#include "../EmptyGameObject.h"
#include "../Components/GamestateManager.h"

class EnemySwarmHandler :
    public AComponent
{

public:
    EnemySwarmHandler(int numEnemies, std::string name);

    ~EnemySwarmHandler();
	void perform() override;
    void changeSpawnInterval(float value);



private:
    GameObjectPool* enemyPool;
	float SPAWN_INTERVAL = 1.0f;
    float ticks = 0.0f;
};


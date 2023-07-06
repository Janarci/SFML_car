#pragma once
#include "AScene.h"
#include "../GameObjectManager.h"
#include "../AirplanePlayer.h"
#include "../AirplaneSupport.h"
#include "../EmptyGameObject.h"
#include "../BGObject.h"
#include "../Components/EnemySwarmHandler.h"
#include "../Screens/Sidebar.h"
#include "../Screens/UIScreen.h"
#include "../Screens/MainMenuScreen.h"
#include "../Physics/PhysicsManager.h"
#include "../Projectile/ProjectileObject.h"


class Level3Scene :
    public AScene
{
public:
    Level3Scene();
    ~Level3Scene();

    void onLoadResources() override;
    void onLoadObjects() override;

    void onUnloadObjects() override;

    GameObjectPool* projectilePool;
};


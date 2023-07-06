#pragma once
#include "AScene.h"

class MainMenuScene :
    public AScene
{
public:

    MainMenuScene();
    ~MainMenuScene();

    void onLoadResources() override;
    void onLoadObjects() override;


};


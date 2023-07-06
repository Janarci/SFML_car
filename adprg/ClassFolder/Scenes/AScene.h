#pragma once
#include <string>
#include "../AGameObject.h"
#include "../GameObjectManager.h"
#include "../SfxManager.h"

class AScene
{
public:
	AScene(std::string sceneName);
	~AScene();
	virtual void onLoadResources() = 0;
	virtual void onLoadObjects() = 0;


	virtual void onUnloadResources();
	virtual void onUnloadObjects();

	std::string getSceneName();

protected:
	void registerObject(AGameObject* object);
	std::string sceneName;
};

#pragma once

#include  "APoolable.h"
#include  "../GameObjectManager.h"
#include <vector>

typedef std::vector<APoolable*> ObjectList;

class GameObjectPool
{
public:
	GameObjectPool(std::string tag, APoolable* poolableCopy, int poolableSize, AGameObject* parent);
	~GameObjectPool();
	void initialize();
	bool hasObjectAvailable(int requestSize);
	APoolable* requestPoolable();
	ObjectList requestPoolableBatch(int size);

	void releasePoolable(APoolable* poolableObject);
	void releasePooableBatch(ObjectList objectList);

	ObjectList getAvailableObjects();
	ObjectList getUsedObjects();

	std::string getTag();

private:
	std::string tag;
	APoolable* objectCopy = NULL;
	AGameObject* parent = NULL;
	int maxPoolSize = 20;
	ObjectList availableObjects;
	ObjectList usedObjects;
	void setEnabled(APoolable* poolableObject, bool flag);


};


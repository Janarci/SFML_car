#include "GameObjectPool.h"

#include  <iostream>

GameObjectPool::GameObjectPool(std::string tag, APoolable* poolableCopy, int poolableSize, AGameObject* parent)
{
	this->tag = tag;
	this->objectCopy = poolableCopy;
	this->maxPoolSize = poolableSize;
	this->parent = parent;

}

GameObjectPool::~GameObjectPool()
{
	//delete this->objectCopy;
	this->objectCopy = NULL;
	this->parent = NULL;

}

void GameObjectPool::initialize()
{
	for (int i = 0; i < this->maxPoolSize; ++i)
	{
		APoolable* poolableObject = this->objectCopy->clone();
		if (this->parent != NULL)
		{
			this->parent->attachChild(poolableObject);

		}
		else
		{
			GameObjectManager::getInstance()->addObject(poolableObject);

		}
		poolableObject->setEnabled(false);
		this->availableObjects.push_back(poolableObject);

	}
}

bool GameObjectPool::hasObjectAvailable(int requestSize)
{
	return requestSize <= this->availableObjects.size();

}

APoolable* GameObjectPool::requestPoolable()
{
	if (this->hasObjectAvailable(1))
	{
		APoolable* poolableObject = this->availableObjects[this->availableObjects.size() - 1];
		this->availableObjects.erase(this->availableObjects.begin() + this->availableObjects.size() - 1);
		this->usedObjects.push_back(poolableObject);

		//std::cout << "Requested object. Available: " << this->availableObjects.size() << " || Used: " << this->usedObjects.size() << std::endl;
		this->setEnabled(poolableObject, true);
		return poolableObject;
	}

	else
	{
		//std::cout << "No more poolable " << this->objectCopy->getName() << " available" << std::endl;
		return NULL;
	}
}

ObjectList GameObjectPool::requestPoolableBatch(int size)
{
	ObjectList returnList;
	if (this->hasObjectAvailable(size))
	{
		for (int i = 0; i < size; ++i)
		{
			returnList.push_back(this->requestPoolable());
		}
	}
	else
	{
		std::cout << "Insufficient " + this->objectCopy->getName() << "available in pool."
		<< "Count is: " << this->availableObjects.size()
		<< " While requested is: " << size << std::endl;

	}
	return returnList;

}

void GameObjectPool::releasePoolable(APoolable* poolableObject)
{
	this->setEnabled(poolableObject, false);

	for (int i = 0; i < usedObjects.size(); ++i)
	{
		if (!usedObjects[i]->isEnabled())
		{
			usedObjects.erase(usedObjects.begin() + i);
			break;
		}
	}

	this->availableObjects.push_back(poolableObject);


	//make a loop to find inactive object
	//std::cout << usedObjects.size()<< std::endl;

}

void GameObjectPool::releasePooableBatch(ObjectList objectList)
{
	for (int i = 0; i < objectList.size(); ++i)
	{
		this->releasePoolable(objectList[i]);
	}
}

ObjectList GameObjectPool::getAvailableObjects()
{
	return this->availableObjects;
}

ObjectList GameObjectPool::getUsedObjects()
{
	return this->usedObjects;
}


std::string GameObjectPool::getTag()
{
	return this->tag;
}

void GameObjectPool::setEnabled(APoolable* poolableObject, bool flag)
{

	if (flag)
	{
		poolableObject->setEnabled(true);
		poolableObject->onActivate();
	}
	else
	{
		poolableObject->setEnabled(false);
		poolableObject->onRelease();
	}
}

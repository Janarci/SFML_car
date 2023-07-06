#include "SfxManager.h"

#include <iostream>

SfxManager* SfxManager::sharedInstance = NULL;

SfxManager* SfxManager::getInstance()
{
	if (sharedInstance == NULL)
	{
		sharedInstance = new SfxManager();

	}
	return sharedInstance;
}

void SfxManager::loadAll()
{
	//loadBuffer("gunfire", "res/audio/EnemyGunfire.wav");
	//loadBuffer("explode1", "res/audio/Explosion1.wav");
	//loadBuffer("explode2", "res/audio/Explosion2.wav");
	loadBuffer("carSlow", "res/audio/carslow.wav");
	loadBuffer("carFast", "res/audio/carfast.wav");
	//loadBuffer("launchMissile", "res/audio/LaunchMissile.wav");
	music.openFromFile("res/audio/bgm.wav");
	
}

sf::SoundBuffer* SfxManager::getBuffer(std::string key)
{
	if (BufferMap[key] != NULL)
	{
		return BufferMap[key];
	}
	else {

		std::cerr << "error" << std::endl;
		return NULL;
	}
}

void SfxManager::loadBuffer(std::string key, std::string path)
{
	sf::SoundBuffer* texture = new sf::SoundBuffer;
	texture->loadFromFile(path);
	BufferMap[key] = texture;
	sf::Sound* sound = new sf::Sound;
	sf::SoundBuffer* m_soundBuffer;
	m_soundBuffer = SfxManager::getInstance()->getBuffer(key);
	sound->setBuffer(*m_soundBuffer);
	soundList.push_back(sound);
}

void SfxManager::playBGM()
{
		music.play();
}
void SfxManager::stopAllMusic()
{
	music.stop();
	for (int i = 0; i < soundList.size(); ++i)
	{
		soundList[i]->stop();

	}
}

void SfxManager::createSound(std::string key)
{
	sf::Sound* sound = new sf::Sound;
	sf::SoundBuffer* m_soundBuffer;
	m_soundBuffer = SfxManager::getInstance()->getBuffer(key);
	sound->setBuffer(*m_soundBuffer);
	soundList.push_back(sound);
}

std::vector<sf::Sound*> SfxManager::getSoundList()
{
	return this->soundList;
}

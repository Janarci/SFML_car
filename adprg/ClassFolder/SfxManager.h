#pragma once
#include <SFML/Audio.hpp>
#include <unordered_map>

class SfxManager
{
public:

	static  SfxManager* getInstance();
	void loadAll();
	sf::SoundBuffer* getBuffer(std::string);
	void playBGM();
	void stopAllMusic();
	void createSound(std::string key);
	std::vector<sf::Sound*> getSoundList();

private:
	SfxManager() {};

	static SfxManager* sharedInstance;
	void loadBuffer(std::string, std::string);
	std::unordered_map<std::string, sf::SoundBuffer*> BufferMap;
	sf::Music music;
	std::vector<sf::Sound*> soundList;


};
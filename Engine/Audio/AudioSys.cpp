#include "AudioSys.h"
#include <fmod.hpp>
#include <iterator>

namespace en
{
	void AudioSys::Init()
	{
		FMOD::System_Create(&_fmod_system);

		void* extradriverdata = nullptr;
		_fmod_system->init(32, FMOD_INIT_NORMAL, extradriverdata);
	}

	void AudioSys::Shutdown()
	{
		for (auto &sound : _sounds)
		{
			sound.second->release();
		}

		_sounds.clear();
		_fmod_system->close();
		_fmod_system->release();
	}

	void AudioSys::Update()
	{
		_fmod_system->update();
	}

	void AudioSys::newAudio(const std::string& name, const std::string& filename)
	{
		auto iter = _sounds.find(name);
		if (iter == _sounds.end())
		{
			FMOD::Sound* sound = nullptr;
			_fmod_system->createSound(filename.c_str(), FMOD_DEFAULT, 0, &sound);
			_sounds[name] = sound;
		}
	}

	void AudioSys::playAudio(const std::string& name, bool loop)
	{
		auto iter = _sounds.find(name);
		if (iter != _sounds.end())
		{
			FMOD::Sound* sound = iter->second;
			loop ? sound->setMode(FMOD_LOOP_NORMAL) : sound->setMode(FMOD_LOOP_OFF);

			FMOD::Channel* channel;
			_fmod_system->playSound(sound, 0, false, &channel);
		}
	}

	void AudioSys::stopAudio(const std::string& name)
	{
		auto iter = _sounds.find(name);
		if (iter != _sounds.end())
		{
			iter->second->setMode(FMOD_LOOP_OFF);
		}
	}
}
#ifndef _AUDIO_SYS_H
#define _AUDIO_SYS_H

#include <string>
#include <map>

namespace FMOD
{
	class System;
	class Sound;
}

namespace en
{
	class AudioSys
	{
	public:
		AudioSys() = default;
		~AudioSys() = default;

		void Init();
		void Shutdown();

		void Update();

		void newAudio(const std::string& name, const std::string& filename);

		void playAudio(const std::string& name, bool loop = false);
		void stopAudio(const std::string& name);

	private:
		FMOD::System* _fmod_system = nullptr;
		std::map<std::string, FMOD::Sound*> _sounds;

	};
}

#endif // _AUDIO_SYS_H
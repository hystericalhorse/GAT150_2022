#ifndef _COMPONENT_AUDIO_H
#define _COMPONENT_AUDIO_H

#include "Framework/Component.h"
#include <string>

namespace en
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent() = default;

		void Update() override;
		void Play();
		void Stop();

	public:
		std::string _sound;
		bool _playOnWake;
		bool _loop = false;
		float _volume = 0.5f;
		float _pitch = 0.5f;

	};
}

#endif _COMPONENT_AUDIO_H

#include "AudioComponent.h"
#include "Engine.h"

namespace en
{
	void AudioComponent::Update()
	{

	}

	void AudioComponent::Play()
	{
		if (_sound != "") __audiosys.playAudio(_sound);
	}

	void AudioComponent::Stop()
	{

	}
}
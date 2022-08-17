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

	bool AudioComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool AudioComponent::Read(const rapidjson::Value& value)
	{
		return true;
	}
}
#include "SpriteComponent.h"
#include "Renderer/Renderer.h"

#include <iostream>

namespace en
{
	void SpriteComponent::Update()
	{

	}

	void SpriteComponent::Draw(Renderer& renderer)
	{	
		renderer.Draw(_texture, _owner->_Transform());
	}

	bool SpriteComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool SpriteComponent::Read(const rapidjson::Value& value)
	{
		return true;
	}
}
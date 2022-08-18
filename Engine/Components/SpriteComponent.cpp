#include "SpriteComponent.h"
#include "Engine.h"

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
		std::string texture;
		READ_DATA(value, texture);

		_texture = en::__registry.Get<en::Texture>(texture, __renderer);

		return true;
	}
}
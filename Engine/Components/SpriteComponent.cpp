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
}
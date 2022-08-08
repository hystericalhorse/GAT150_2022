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
		std::cout << _texture.get() << std::endl; // Identifies a Normal Block listed in Memory Leaks
		
		renderer.Draw(_texture, _owner->_Transform());
	}
}
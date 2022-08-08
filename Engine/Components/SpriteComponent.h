#ifndef _COMPONENT_SPRITE_H
#define _COMPONENT_SPRITE_H

#include "RenderComponent.h"
#include "Renderer/Texture.h"

namespace en
{
	class Texture;

	class SpriteComponent : public RenderComponent
	{
	public:
		SpriteComponent() = default;

		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

	public:
		std::shared_ptr<Texture> _texture = std::make_shared<Texture>();

	};
}

#endif // _COMPONENT_SPRITE_H
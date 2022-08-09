#ifndef _COMPONENT_SPRITE_H
#define _COMPONENT_SPRITE_H

#include "RenderComponent.h"
#include "Renderer/Texture.h"

namespace en
{
	class SpriteComponent : public RenderComponent
	{
	public:
		SpriteComponent() = default;

		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

	public:
		std::shared_ptr<en::Texture> _texture = std::make_shared<en::Texture>();

	};
}

#endif // _COMPONENT_SPRITE_H
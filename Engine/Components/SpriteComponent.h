#ifndef _COMPONENT_SPRITE_H
#define _COMPONENT_SPRITE_H

#include "RenderComponent.h"

namespace en
{
	class Texture;

	class SpriteComponent : public RenderComponent
	{
	public:
		SpriteComponent() = default;

		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		std::shared_ptr<Texture> _texture;
	protected:


	};
}

#endif // _COMPONENT_SPRITE_H
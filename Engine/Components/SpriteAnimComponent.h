#ifndef _COMPONENT_ANIMATED_SPRITE_H
#define _COMPONENT_ANIMATED_SPRITE_H

#include "RenderComponent.h"
#include "Renderer/Texture.h"
#include "Math/Rect.h"

namespace en
{
	class SpriteAnimComponent : public RenderComponent
	{
	public:
		SpriteAnimComponent() = default;

		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		float fps = 0.0f;
		int columns, rows = 0;
		
		int start_frame, end_frame = 0;
		int frame = 0;
		float frameTime = 0.0f;

		std::shared_ptr<en::Texture> _texture = std::make_shared<en::Texture>();
		Rect source;

	};
}

#endif // _COMPONENT_ANIMATED_SPRITE_H
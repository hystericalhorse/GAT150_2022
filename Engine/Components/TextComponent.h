#ifndef _COMPONENT_TEXT_H
#define _COMPONENT_TEXT_H

#include "RenderComponent.h"
#include "Math/Color.h"
#include "Math/Vector2.h"
#include <memory>

namespace en
{
	class Font;
	class Texture;

	class TextComponent : public RenderComponent
	{
	public:
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		void setText(const std::string& text);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	private:
		std::string text;
		std::string font_name;
		int fontSize;
		en::Vector2 registration;
		en::Color color;

		std::shared_ptr<en::Font> _font;
		std::shared_ptr<en::Texture> _texture;
	};
}

#endif // _COMPONENT_TEXT_H
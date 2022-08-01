#include "Drawable.h"

namespace en
{
	Drawable::Drawable(const Transform& transform, const Model& model) : GameObject(transform)
	{
		_drawabletype = DrawableType::MODEL;

		_model = model;
	}

	Drawable::Drawable(const Transform& transform, Color& color) : GameObject(transform)
	{
		_drawabletype = DrawableType::POINT;

		_color = color;
	}

	Drawable::Drawable(const Transform& transform, float radius, Color& color) : GameObject(transform)
	{
		_drawabletype = DrawableType::CIRCLE;

		_r = radius;
		_color = color;
	}

	void Drawable::Draw(Renderer& renderer, const Vector2& offset)
	{
		switch (_drawabletype)
		{
		case Drawable::DrawableType::MODEL:
		{
			_model.draw(renderer, _transform.position + offset, _transform.rotation, _transform.scale);

			break;
		}
		case Drawable::DrawableType::POINT:
		{
			const Vector2 _p = _transform.position;
			renderer.drawPoint(_p + offset, _color);

			break;
		}
		case Drawable::DrawableType::CIRCLE:
		{
			renderer.drawCircle(_transform.position, _r, _color);

			break;
		}
		}
	}
}
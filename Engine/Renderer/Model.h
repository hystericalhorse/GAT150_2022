#ifndef _MODEL_H
#define _MODEL_H
#include <vector>
#include <string>
#include "Renderer.h"

namespace en
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<en::Vector2>& points, const en::Color& color)
			: _points{ points }, _color{color}
		{}
		Model(const std::string& filename);
		Model(const std::string& filename, const en::Color& color);
		~Model() = default;

		void Draw(Renderer& renderer, const Vector2& position, float& angle, const Vector2& scale = Vector2{1, 1});
		void Draw(Renderer& renderer, const Transform& transform);
		bool Create(const std::string& filename);
		bool Load(const std::string& filename);
		float findRadius();

		Color& getColor() { return _color; }
		float getRadius() { return _radius; }
	private:
		en::Color _color {255, 255, 255, 255};
		std::vector<en::Vector2> _points;
		std::string _name;

		float _radius = 0.0f;
	};
}

#endif _MODEL_H

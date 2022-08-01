#include "Model.h"
#include "../Core/File.h"
#include <fstream>
#include <sstream>
#include <iostream>

namespace en
{
	Model::Model(const std::string& filename)
	{
		load(filename);
		_radius = find_radius();
	}

	Model::Model(const std::string& filename, const en::Color& color)
	{
		load(filename);
		_radius = find_radius();
		_color = color;
	}

	void Model::draw(Renderer& renderer, const Vector2& position, float& angle, float& scale)
	{
		if (_points.size() == 1)
		{
			renderer.drawPoint(position, _color);
			return;
		}

		for (size_t i = 0; i < _points.size() - 1; i++)
		{
			renderer.drawLine(Vector2::rotate(_points[i] * scale, angle) + position, Vector2::rotate(_points[i + 1] * scale, angle) + position, _color);
		}
	}

	void Model::load(const std::string& filename)
	{
		std::string buffer;
		en::readFile(filename, buffer);

		std::istringstream stream(buffer);
		stream >> _color;

		std::string line;
		std::getline(stream, line);

		size_t points = std::stoi(line); // get the number of points
		for (size_t i = 0; i < points; i++)
		{
			Vector2 point;

			stream >> point; // read points

			_points.push_back(point);
		}
	}

	float Model::find_radius()
	{
		float r = 0.0f;

		for (auto point : _points)
		{
			if (point.length() > r) r = point.length();
		}

		return r;
	}
}
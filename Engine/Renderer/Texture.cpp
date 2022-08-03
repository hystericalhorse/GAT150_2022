#include "Texture.h"
#include "Renderer.h"
#include "Core/Logger.h"
#include <SDL_image.h>

namespace en
{
	Texture::~Texture()
	{
		if (_texture != nullptr) SDL_DestroyTexture(_texture);
	}

	bool Texture::Create(Renderer& renderer, const std::string& filename)
	{
		SDL_Surface* _surface = IMG_Load(filename.c_str());
		if (_surface == nullptr) en::__logger.Log("error loading file %s", filename.c_str());
		_texture = SDL_CreateTextureFromSurface(renderer._renderer, _surface);
		SDL_FreeSurface(_surface);

		return true;
	}

	en::Vector2 Texture::getSize() const
	{
		SDL_Point point;
		SDL_QueryTexture(_texture, nullptr, nullptr, &point.x, &point.y);

		return Vector2{ point.x , point.y };
	}
}
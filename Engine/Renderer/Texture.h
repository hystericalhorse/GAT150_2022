#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "../Math/Vector2.h"
#include <string>

struct SDL_Texture;

namespace en
{
	class Renderer;

	class Texture
	{
	public:
		Texture() = default;
		~Texture();

		bool Init(Renderer& renderer, const std::string& filename);

		Vector2 getSize() const;

		friend class Renderer;
	private:
		SDL_Texture* _texture = nullptr;

	};
}

#endif // _TEXTURE_H
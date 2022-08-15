#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "Math/Vector2.h"
#include "Resource/Resource.h"
#include <string>

struct SDL_Texture;

namespace en
{
	class Renderer;

	class Texture : public Resource
	{
	public:
		Texture() = default;
		~Texture();

		bool Create(Renderer& renderer, const std::string& filename);
		bool Create(std::string filename, ...);

		Vector2 getSize() const;

		friend class Renderer;
		friend class Component;
	protected:
		SDL_Texture* _texture = nullptr;

	};
}

#endif // _TEXTURE_H
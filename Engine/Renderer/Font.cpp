#include "Font.h"
#include <SDL_ttf.h>

namespace en
{
	Font::Font(const std::string& filename, int fontSize)
	{
		this->load(filename, fontSize);
	}

	Font::~Font()
	{
		if (_font)
		{
			TTF_CloseFont(_font);
		}
	}

	void Font::load(const std::string& filename, int fontSize)
	{
		this->_font = TTF_OpenFont(filename.c_str(), fontSize);
	}
}
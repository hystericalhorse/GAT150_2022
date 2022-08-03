#ifndef _FONT_H
#define _FONT_H

#include <string>

struct _TTF_Font;

namespace en
{
	class Font
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		void load(const std::string& filename, int fontSize);

		friend class Text;

	private:
		_TTF_Font* _font = nullptr;
	};
}

#endif // _FONT_H
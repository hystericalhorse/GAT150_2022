#ifndef _COLOR_H
#define _COLOR_H

#include <istream>
#include <string>

namespace en
{
	using u8_t = unsigned char;

	struct Color
	{
		Color() = default;
		Color(u8_t r, u8_t g, u8_t b, u8_t a) :
			r {r}, g{g}, b{b}, a{a}
		{}

		inline Color operator = (const Color& c)
		{
			this->r = c.r;
			this->g = c.g;
			this->b = c.b;
			this->a = c.a;

			return *this;
		}

		inline bool operator == (const Color& c)
		{
			if (this->r != c.r) return false;
			if (this->g != c.g) return false;
			if (this->b != c.b) return false;
			if (this->a != c.a) return false;

			return true;
		}

		inline bool operator != (const Color& c)
		{
			if (this->r != c.r) return true;
			if (this->g != c.g) return true;
			if (this->b != c.b) return true;
			if (this->a != c.a) return true;

			return false;
		}

		u8_t r, g, b, a;
	};

	

	inline std::istream& operator >> (std::istream& stream, Color& c)
	{
		std::string line;
		std::getline(stream, line);

		// format is {r###, g###, b###, a###}
		std::string r = line.substr(line.find("r") + 1, line.find(",") - (line.find("r") + 1));
		std::string g = line.substr(line.find("g") + 1, line.find(",") - (line.find("g") + 1));
		std::string b = line.substr(line.find("b") + 1, line.find(",") - (line.find("b") + 1));
		std::string a = line.substr(line.find("a") + 1, line.find("}") - (line.find("a") + 1));

		c.r = (u8_t) stof(r);
		c.g = (u8_t) stof(g);
		c.b = (u8_t) stof(b);
		c.a = (u8_t) stof(a);

		return stream;
	}
}

#endif // _COLOR_H
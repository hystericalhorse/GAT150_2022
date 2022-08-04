#include "Color.h"

namespace en
{
	std::istream& operator >> (std::istream& stream, Color& c)
	{
		std::string line;
		std::getline(stream, line);

		// format is {r###, g###, b###, a###}
		std::string r = line.substr(line.find("r") + 1, line.find(",") - (line.find("r") + 1));
		std::string g = line.substr(line.find("g") + 1, line.find(",") - (line.find("g") + 1));
		std::string b = line.substr(line.find("b") + 1, line.find(",") - (line.find("b") + 1));
		std::string a = line.substr(line.find("a") + 1, line.find("}") - (line.find("a") + 1));

		c.r = (u8_t)stof(r);
		c.g = (u8_t)stof(g);
		c.b = (u8_t)stof(b);
		c.a = (u8_t)stof(a);

		return stream;
	}
}
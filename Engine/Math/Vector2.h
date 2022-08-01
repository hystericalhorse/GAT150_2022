#ifndef _VECTOR2_H
#define _VECTOR2_H
#include <cmath>
#include <istream>
#include <string>

namespace en
{
	struct Vector2
	{
		Vector2() = default;
		Vector2(float x, float y) :
			x{x}, y{y}
		{}
		Vector2(float v) :
			x{v}, y{v}
		{}
		Vector2(int x, int y)
		{
			this->x = (float) x;
			this->y = (float) y;
		}

		void set(float x, float y) { this->x = x; this->y = y; }

		Vector2 operator + (const Vector2& v) const { return Vector2(this->x + v.x, this->y + v.y); }
		Vector2 operator - (const Vector2& v) const { return Vector2(this->x - v.x, this->y - v.y); }
		Vector2 operator * (const Vector2& v) const { return Vector2(this->x * v.x, this->y * v.y); }
		Vector2 operator / (const Vector2& v) const { return Vector2(this->x / v.x, this->y / v.y); }

		Vector2 operator += (const Vector2& v) { this->x += v.x; this->y += v.y; return *this; }
		Vector2 operator -= (const Vector2& v) { this->x -= v.x; this->y -= v.y; return *this; }
		Vector2 operator *= (const Vector2& v) { this->x *= v.x; this->y *= v.y; return *this; }
		Vector2 operator /= (const Vector2& v) { this->x /= v.x; this->y /= v.y; return *this; }

		Vector2 operator + (float s) const { return Vector2(this->x + s, this->y + s); }
		Vector2 operator - (float s) const { return Vector2(this->x - s, this->y - s); }
		Vector2 operator * (float s) const { return Vector2(this->x * s, this->y * s); }
		Vector2 operator / (float s) const { return Vector2(this->x / s, this->y / s); }

		Vector2 operator += (float s) { this->x += s; this->y += s; return *this; }
		Vector2 operator -= (float s) { this->x -= s; this->y -= s; return *this; }
		Vector2 operator *= (float s) { this->x *= s; this->y *= s; return *this; }
		Vector2 operator /= (float s) { this->x /= s; this->y /= s; return *this; }

		Vector2 operator - () const { return Vector2{ -x, -y }; }

		bool operator == (const Vector2& v) const { return (this->x == v.x && this->y == v.y); }
		bool operator != (const Vector2& v) const { return (this->x != v.x || this->y != v.y); }

		inline float length() { return std::sqrt(x * x + y * y); }
		inline float length_sqr() { return x * x + y * y; }

		inline float distance(const Vector2& v) { return (*this - v).length(); }
		inline float distance_sqr(const Vector2& v) { return (*this - v).length_sqr(); }

		inline Vector2 normalised()
		{
			float l = length();
			return Vector2(this->x/l, this->y/l);
		}

		inline void normalise()
		{
			(*this) /= length();
		}

		inline float angle()
		{
			return std::atan2(y, x);
		}

		inline static Vector2 rotate(const Vector2& v, float t)
		{
			float x = v.x * std::cos(t) - v.y * std::sin(t);
			float y = v.x * std::sin(t) + v.y * std::cos(t);

			return Vector2(x, y);
		}

		friend std::istream& operator >> (std::istream& stream, Vector2& v);

		float x, y;
	};

	inline std::istream& operator >> (std::istream& stream, Vector2& v)
	{
		std::string line;
		std::getline(stream, line);

		std::string x = line.substr(line.find("{") + 1, line.find(",") - (line.find("{") + 1));
		std::string y = line.substr(line.find(",") + 1, line.find("}") - (line.find(",") + 1));

		v.x = std::stof(x);
		v.y = std::stof(y);

		return stream;
	}

}

#endif // _VECTOR2_H
#ifndef _SERIALIZER_H
#define _SERIALIZER_H

#include "JSON.h"

namespace en
{
	class Serializable
	{
	public:
		virtual ~Serializable() {};

		virtual void Write(const rapidjson::Value& value) const = 0;
		virtual void Read(const rapidjson::Value& value) = 0;
	};
}

#endif // _SERIALIZER_H
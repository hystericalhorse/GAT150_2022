#ifndef _INTERFACE_SERIALIZABLE_H
#define _INTERFACE_SERIALIZER_H

#include "JSON.h"

namespace en
{
	class Serializable
	{
	public:
		virtual ~Serializable() {};

		virtual bool Write(const rapidjson::Value& value) const = 0;
		virtual bool Read(const rapidjson::Value& value) = 0;
	};
}

#endif // _INTERFACE_SERIALIZER_H
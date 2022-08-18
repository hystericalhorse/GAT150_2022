#ifndef _FACTORY_H
#define _FACTORY_H

#include "Singleton.h"

#include <memory>
#include <string>
#include <map>

namespace en
{
	class GameObject;

	class FactoryFloor // Base Class
	{
	public:
		virtual std::unique_ptr<GameObject> Create() = 0;
	};

	template <typename T>
	class Creator : public FactoryFloor
	{
	public:
		std::unique_ptr<GameObject> Create() override
		{
			return std::make_unique<T>();
		}
	};

	class Factory : public Singleton<Factory>
	{
	public:
		template <typename T>
		void Register(const std::string& key)
		{
			_fregist[key] = std::make_unique<Creator<T>>();
		}

		template <typename T>
		std::unique_ptr<T> Retrieve(const std::string& key)
		{
			auto iter = (_fregist.find(key));
			if (iter != _fregist.end())
			{
				return std::unique_ptr<T>(dynamic_cast<T*>(iter->second->Create().release()));
			}

			return nullptr;
		}

	private:
		std::map<std::string, std::unique_ptr<FactoryFloor>> _fregist;

	};
}

#endif // _FACTORY_H
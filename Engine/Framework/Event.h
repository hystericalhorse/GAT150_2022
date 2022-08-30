#ifndef _EVENT_H
#define _EVENT_H

#include <functional>
#include <variant>

namespace en
{
	class GameObject;

	class Event
	{
	public:
		using eventptr = std::function<void(const Event&)>;

	public:
		std::string name;
		GameObject* reciever = nullptr;

		std::variant<int, bool, float, std::string, void*> data;
	};
}

#endif // _EVENT_H
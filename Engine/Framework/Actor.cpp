#include "Actor.h"

namespace en
{
	void Actor::Update()
	{
		for (auto &component : _components)
		{
			component->Update();
		}
	}

	void Actor::addComponent(std::unique_ptr<Component> component)
	{
		component->_owner = this;
		_components.push_back(std::move(component));
	}
	
	void Actor::Draw(Renderer& renderer)
	{
		for (auto& component : _components)
		{

		}
	}
}


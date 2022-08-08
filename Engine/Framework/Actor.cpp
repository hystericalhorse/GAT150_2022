#include "Actor.h"
#include "Components/RenderComponent.h"

namespace en
{
	Actor::~Actor()
	{
		for (auto& component : _components)
		{
			component.reset();
		}
	}

	void Actor::Update()
	{
		auto component = _components.begin();
		while (component != _components.end())
		{
			(*component)->Update();
			component++;
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
			auto r = dynamic_cast<RenderComponent*>(component.get());
			if (r)
			{
				r->Draw(renderer);
			}
		}
	}
}


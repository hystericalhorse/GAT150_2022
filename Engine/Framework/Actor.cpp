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

		if (_parent != nullptr) delete _parent;
	}

	void Actor::Update()
	{
		auto component = _components.begin();
		while (component != _components.end())
		{
			(*component)->Update();
			component++;
		}

		auto child = _children.begin();
		while (child != _children.end())
		{
			(*child)->Update();
			child++;
		}

		if (_parent) _transform.update(_parent->_transform.matrix);
		else _transform.update();
	}

	void Actor::addComponent(std::unique_ptr<Component> component)
	{
		component->_owner = this;
		_components.push_back(std::move(component));
	}
	void Actor::addChild(std::unique_ptr<Actor> child)
	{
		child->_parent = this;
		_children.push_back(std::move(child));
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

		for (auto& child : _children)
		{
			child.get()->Draw(renderer);
		}
	}
}


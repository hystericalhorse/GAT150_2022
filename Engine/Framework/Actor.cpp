#include "Actor.h"
#include "Components/RenderComponent.h"
#include "Core/Logger.h"
#include "Factory.h"

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

	void Actor::Init()
	{
		for (auto& component : _components)
		{
			component->Init();
		}

		for (auto& child : _children)
		{
			child->Init();
		}
	}

	void Actor::Update()
	{
		for (auto& component : _components)
		{
			component->Update();
		}

		for (auto& child : _children)
		{
			child->Update();
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

	bool Actor::Write(const rapidjson::Value& value) const
	{


		return true;
	}

	bool Actor::Read(const rapidjson::Value& value)
	{
		std::string& name = _name;
		std::string& tag = _tag;

		READ_DATA(value, name);
		READ_DATA(value, tag);
		_transform.Read(value["transform"]);

		if (value.HasMember("components") && value["components"].IsArray())
		{
			for (auto& aut : value["components"].GetArray())
			{
				std::string type;
				READ_DATA(aut, type);

				auto component = Factory::Instance().Retrieve<en::Component>(type);
				if (!component->Read(aut))
				{
					LOG("ERROR: Problem reading component data.");
				}
				addComponent(std::move(component));
			}
		}

		return true;
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


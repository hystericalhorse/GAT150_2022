#include "Scene.h"
#include "Factory.h"
#include "Renderer/Renderer.h"
#include "Core/Logger.h"

#include <iostream>

namespace en
{
	void Scene::Update()
	{
		auto iter = _actors.begin();
		while (iter != _actors.end())
		{
			(*iter)->Update();
			if (!(*iter)->_living) iter = _actors.erase(iter);
			else iter++;
		}

		for (auto iter_ = _actors.begin(); iter_ != _actors.end(); iter_++)
		{
			for (auto _iter = _actors.begin(); _iter != _actors.end(); _iter++)
			{
				if (iter_ == _iter) continue;

				float r = (*iter_)->get_radius() + (*_iter)->get_radius();
				float d = (*iter_)->_transform.position.distance((*_iter)->_transform.position);

				if (d <= r)
				{
					(*iter_)->OnCollision((*_iter).get());
					(*_iter)->OnCollision((*iter_).get());
				}
			}
		}
	}

	void Scene::Draw(Renderer& renderer)
	{
		for (auto& actor : _actors)
		{
			actor->Draw(renderer);
		}
	}

	bool Scene::Write(const rapidjson::Value& value) const
	{


		return true;
	}

	bool Scene::Read(const rapidjson::Value& value)
	{
		if (!value.HasMember("actors") || !value["actors"].IsArray())
		{
			LOG("ERROR: Could not find 'actors' component in level file.");
			return false;
		}

		for (auto& aut : value["actors"].GetArray())
		{
			std::string type;
			READ_DATA(aut, type);

			auto actor = Factory::Instance().Retrieve<en::Actor>(type);
			if (!actor)
			{
				LOG("ERROR: Did not find type 'Actor' in actor object.");
				return false;
			}

			actor->Read(aut);
		}

		return true;
	}

	void Scene::Add(std::unique_ptr<Actor> actor)
	{
		actor->_scene = this;
		_actors.push_back(std::move(actor));
	}
}
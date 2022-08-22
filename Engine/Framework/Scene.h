#ifndef _SCENE_H
#define _SCENE_H

#include "Actor.h"

#include <list>
#include <memory>

namespace en
{
	class Actor; // forward declaration for Actor
	class Renderer; // forward declaration for Renderer

	class Scene : public GameObject, public Serializable
	{
	public:
		Scene() = default;
		~Scene() = default;

		void Init() override;
		void Update() override;
		void Draw(Renderer& renderer);

		// Inheritance
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void addActor(std::unique_ptr<Actor> actor);
		void Remove() {}

		template<typename T>
		inline T* getActor()
		{
			for (auto& actor : _actors)
			{
				T* a = dynamic_cast<T*>(actor.get());
				if (a) return a;
			}

			return nullptr;
		}

	private:
		std::list<std::unique_ptr<Actor>> _actors;

	};
}

#endif // _SCENE_H
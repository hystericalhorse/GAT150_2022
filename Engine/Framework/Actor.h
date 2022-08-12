#ifndef _ACTOR_H
#define _ACTOR_H

#include "GameObject.h"
#include "Component.h"

#include <vector>
#include <memory>

namespace en
{
	class Scene;
	class Renderer;
	class Component;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		~Actor();
		Actor(const Transform& transform) :
			_transform{ transform }
		{}

		virtual void Update() override;
		virtual void Draw(Renderer& renderer);

		void addComponent(std::unique_ptr<Component> component);
		void addChild(std::unique_ptr<Actor> child);

		virtual void OnCollision(Actor* other) {}
		float get_radius() { return 0; /*_model.get_radius() * std::max(_transform.scale.x, _transform.scale.y);*/ }

		Transform& _Transform() { return this->_transform; }

		template<typename T>
		inline T* getComponent()
		{
			for (auto& component : _components)
			{
				T* a = dynamic_cast<T*>(component.get());
				if (a) return a;
			}

			return nullptr;
		}
		
		friend class Scene;
		Transform _transform;
	protected:
		bool _living = true;

		Scene* _scene = nullptr;
		Actor* _parent = nullptr;

		std::vector<std::unique_ptr<Component>> _components;
		std::vector<std::unique_ptr<Actor>> _children;
	};
}

#endif // _ACTOR_H
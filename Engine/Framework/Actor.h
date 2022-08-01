#ifndef _ACTOR_H
#define _ACTOR_H
#include "GameObject.h"
#include "../Renderer/Model.h"
#include <iostream>

namespace en
{
	class Scene;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Model& model, const Transform& transform) :
			_model{model},
			GameObject(transform)
		{}
		~Actor() = default;

		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);

		virtual void OnCollision(Actor* other) {}

		float get_radius() { return _model.get_radius(); }

		friend class Scene;
	protected:
		bool _living = true;
		Vector2 _velocity = 0;
		Scene* _scene = nullptr;
		Model _model;

	private:


	};
}

#endif // _ACTOR_H
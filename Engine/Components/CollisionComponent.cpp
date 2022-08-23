#include "CollisionComponent.h"
#include "Engine.h"

namespace en
{
	void CollisionComponent::Init()
	{
		auto component = _owner->getComponent<en::RigidBodPhysicsComponent>();
		if (component)
		{
			en::__physics.SetCollisionBox(nullptr, data);
		}

	}

	void CollisionComponent::Update()
	{

	}

	bool CollisionComponent::Write(const rapidjson::Value& value) const
	{


		return true;
	}

	bool CollisionComponent::Read(const rapidjson::Value& value)
	{
		Vector2 size{ 0, 0 };
		float density = 1.0;
		float friction = 1.0;
		float restitution = 0.3f;
		bool is_trigger = false;

		READ_DATA(value, size);
		READ_DATA(value, density);
		READ_DATA(value, friction);
		READ_DATA(value, restitution);
		READ_DATA(value, is_trigger);

		return true;
	}

	void CollisionComponent::OnCollisionBegin(Actor* other)
	{

	}

	void CollisionComponent::OnCollisionEnd(Actor* other)
	{

	}
}
#include "CollisionComponent.h"
#include "Engine.h"

namespace en
{
	void CollisionComponent::Init()
	{
		auto component = _owner->getComponent<en::RigidBodPhysicsComponent>();
		if (component)
		{
			en::__physics.SetCollisionBox(component->_body, data, _owner);
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
		Vector2& size = data.size;
		float& density = data.density;
		float& friction = data.friction;
		float& restitution = data.restitution;
		bool& is_trigger = data.is_trigger;

		READ_DATA(value, size);
		READ_DATA(value, density);
		READ_DATA(value, friction);
		READ_DATA(value, restitution);
		READ_DATA(value, is_trigger);

		return true;
	}

	void CollisionComponent::OnCollisionBegin(Actor* other)
	{
		// cout << other->getName() << endl;
	}

	void CollisionComponent::OnCollisionEnd(Actor* other)
	{

	}
}
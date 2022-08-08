#include "PhysicsComponent.h"
#include "Engine.h"

namespace en
{
	void PhysicsComponent::Force(const Vector2& direction, const float& magnitude)
	{
		_acceleration = direction * magnitude;
	}

	void PhysicsComponent::Update()
	{
		_velocity += _acceleration * __time.ci_time;
		_owner->_Transform().position += _velocity * __time.ci_time;

		_velocity *= _damping;

		_acceleration = Vector2::zero;
	}
}
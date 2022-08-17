#include "PlayerComponent.h"
#include "Engine.h"

namespace en
{
	void PlayerComponent::Update()
	{
		auto physics = (_owner->getComponent<en::PhysicsComponent>());

		if (en::__inputsys.getKeyDown(en::key_left))
		{
			if (_owner->_Transform().position.x > 0)
			{
				if (physics) physics->Force(Vector2::left, _max_velocity);
			}
		}

		if (en::__inputsys.getKeyDown(en::key_right))
		{
			if (_owner->_Transform().position.x < __renderer.get_window_width())
			{
				if (physics) physics->Force(Vector2::right, _max_velocity);
			}
		}

		if (en::__inputsys.getKeyDown(en::key_up))
		{
			if (_owner->_Transform().position.y > 0)
			{
				if (physics) physics->Force(Vector2::up, _max_velocity);
			}
		}

		if (en::__inputsys.getKeyDown(en::key_down))
		{
			if (_owner->_Transform().position.y < __renderer.get_window_height())
			{
				if (physics) physics->Force(Vector2::down, _max_velocity);
			}
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		float& speed = _max_velocity;
		READ_DATA(value, speed);

		return true;
	}
}

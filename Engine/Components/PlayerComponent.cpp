#include "PlayerComponent.h"

#include "CollisionComponent.h"
#include "Engine.h"

#include <functional>
#include <iostream>

namespace en
{
	void PlayerComponent::Init()
	{
		CharacterComponent::Init();
	}
	
	void PlayerComponent::Update()
	{
		auto physics = (_owner->getComponent<en::PhysicsComponent>());

		if (en::__inputsys.getKeyDown(en::key_left))
		{
			_direction = en::Vector2::left;
			if (physics) physics->Force(Vector2::left * _speed);
		}

		if (en::__inputsys.getKeyDown(en::key_right))
		{
			_direction = en::Vector2::right;
			if (physics) physics->Force(Vector2::right * _speed);
		}

		if (en::__inputsys.getKeyState(en::key_up) == en::InputSystem::KeyState::PRESSED)
		{
			_direction = en::Vector2::up;
			if (physics) physics->Force(Vector2::up * _jump_multiplier * 100);
		}

		auto camera = _owner->getScene()->getActor("Camera");
		if (camera)
		{
			camera->_Transform().position = en::lerp(camera->_Transform().position, _owner->_Transform().position, 2 * en::__time.ci_time);
		}

		auto anim = (_owner->getComponent<en::SpriteAnimComponent>());
		if (anim)
		{
			//if (_direction.x != 0) anim->Flip(_direction.x < 0);

			if (std::fabs(_direction.x) > 0)
			{
				anim->setSequence("running");
			}
		}
	}

	void PlayerComponent::OnCollisionBegin(Actor* other)
	{
		if (other->getName() == "Coin")
		{
			Event event;
			event.name = "EVT_EXAMPLE";
			event.data = 1;

			en::__eventmanager.Notify(event);

			other->Destroy();
		}
	}

	void PlayerComponent::OnCollisionEnd(Actor* other)
	{
		// TODO
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		CharacterComponent::Read(value);
		
		float& jump_multiplier = _jump_multiplier;
		READ_DATA(value, jump_multiplier);

		return true;
	}

	void PlayerComponent::onNotification(const Event& event)
	{
		if (event.name == "EVENT_DAMAGE")
		{
			_health -= std::get<float>(event.data);
		}
	}
}

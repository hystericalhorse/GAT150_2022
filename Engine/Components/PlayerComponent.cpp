#include "PlayerComponent.h"

#include "CollisionComponent.h"
#include "Engine.h"

#include <functional>
#include <iostream>

using namespace std::placeholders;

namespace en
{
	void PlayerComponent::Init()
	{
		auto component = _owner->getComponent<en::CollisionComponent>();
		if (component)
		{
			component->setCollisionEnter(std::bind(&PlayerComponent::OnCollisionBegin, this, _1));
			component->setCollisionExit(std::bind(&PlayerComponent::OnCollisionEnd, this, _1));
		}
	}
	
	void PlayerComponent::Update()
	{
		auto physics = (_owner->getComponent<en::PhysicsComponent>());

		if (en::__inputsys.getKeyDown(en::key_left))
		{
			if (physics) physics->Force(Vector2::left * _speed);
		
		}

		if (en::__inputsys.getKeyDown(en::key_right))
		{
			
			if (physics) physics->Force(Vector2::right * _speed);
			
		}

		if (en::__inputsys.getKeyState(en::key_up) == en::InputSystem::KeyState::PRESSED)
		{
			if (physics) physics->Force(Vector2::up * _jump_multiplier * 100);
		}
	}

	void PlayerComponent::OnCollisionBegin(Actor* other)
	{
		
	}

	void PlayerComponent::OnCollisionEnd(Actor* other)
	{
		
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		float& speed = _speed;
		float& jump_multiplier = _jump_multiplier;
		READ_DATA(value, speed);
		READ_DATA(value, jump_multiplier);

		return true;
	}
}

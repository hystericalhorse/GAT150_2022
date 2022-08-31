#include "EnemyComponent.h"

void EnemyComponent::Init()
{
    CharacterComponent::Init();
}

void EnemyComponent::Update()
{
    auto actor = _owner->getScene()->getActor("Player");
    if (actor)
    {
        en::Vector2 direction = actor->_Transform().position - _owner->_Transform().position;
        en::Vector2 force = direction.normalised() * _speed;

        auto component = _owner->getComponent<en::PhysicsComponent>();
        if (component) component->Force(force);
    }
}

void EnemyComponent::OnCollisionBegin(en::Actor* other)
{
    int damage = (int)_damage;

    if (other->getTag() == "Player")
    {
        en::Event event;
        event.name = "EVENT_DAMAGE";
        event.data = _damage;
        event.reciever = other;

        en::__eventmanager.Notify(event);
    }
}

void EnemyComponent::OnCollisionEnd(en::Actor* other)
{
}

void EnemyComponent::onNotification(const en::Event& event)
{
    if (event.name == "EVENT_DAMAGE")
    {
        _health -= std::get<float>(event.data);
        if (_health <= 0)
        {
            _owner->Destroy();
        }
    }
}

bool EnemyComponent::Write(const rapidjson::Value& value) const
{
    return true;
}

bool EnemyComponent::Read(const rapidjson::Value& value)
{
    CharacterComponent::Read(value);

    return true;
}
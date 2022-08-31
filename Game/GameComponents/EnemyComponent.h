#pragma once
#include "Engine.h"

class EnemyComponent : public en::CharacterComponent
{
	CLONE(EnemyComponent)

	void Init() override;
	void Update() override;

	virtual bool Write(const rapidjson::Value& value) const override;
	virtual bool Read(const rapidjson::Value& value) override;

	virtual void OnCollisionBegin(en::Actor* other) override;
	virtual void OnCollisionEnd(en::Actor* other) override;

	virtual void onNotification(const en::Event& event) override;

public:
	en::Vector2 _direction = en::Vector2::zero;
	float _jump_multiplier = 1.0;
};
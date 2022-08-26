#pragma once

#include "Engine.h"

class Gaem : en::Game
{
public:
	void Init() override;
	void Shutdown() override;
	void Update() override;
	void Draw(en::Renderer& renderer) override;
};
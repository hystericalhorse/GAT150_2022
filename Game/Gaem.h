#pragma once

#include "Engine.h"

class Gaem : en::Game
{
public:
	enum class gameState
	{
		GameTitle, GameStart, Game, GameOver, GameCredits
	};

public:
	void Init() override;
	void Shutdown() override;
	void Update() override;
	void Draw(en::Renderer& renderer) override;

	void exampleEvent(const en::Event& event);
	void exampleEvent2(const en::Event& event);

protected:
	gameState _gamestate = gameState::GameTitle;
	float _gamestate_timer = 0.0;
};
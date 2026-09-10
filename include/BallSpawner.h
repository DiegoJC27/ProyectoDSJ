#pragma once
#include <vector>
#include "Ball.h"
#include "EventBus.h"

namespace engPro {
	class BallSpawner : EventListener
	{
	public:
		BallSpawner() = default;
		~BallSpawner() = default;

		void Init();
		void TurnOff();
		void Draw();
		void Update();

		void OnBallCollison();
		std::vector<Ball*>* ballsVector;
	private:
		float curDeg{ 0 };
		int inicialBallQuant{ 10 };
		Vector2 ballSpawnPoint{ 0,0 };

		float ballCurSpeed{1.f};
		float const plusBallSpeed{ 0.15f };
		float const ballMaxSpeed{3.f};
		float const ballInitialSpeed{1.f};
		int const maxBallCount{ 20 };
		void OnEvent(EventData data) override;
	};
}
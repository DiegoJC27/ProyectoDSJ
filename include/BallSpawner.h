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
		void Draw();
		void Update();

		void OnBallCollison();
		std::vector<Ball*>* ballsVector;
	private:
		float curDeg{ 0 };
		int inicialBallQuant{ 10 };
		Vector2 ballSpawnPoint{ 0,0 };

		void OnEvent(EventData data) override;
	};
}
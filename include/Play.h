#pragma once
#include "Scene.h"
#include "Ball.h"
#include <vector>
#include "EventBus.h"
#include "ScoreManager.h"
#include "Ship.h"
#include "EntityManager.h"
#include "ResourceManager.h"
#include "BallSpawner.h"


namespace engPro {
    class Play :
        public Scene, EventListener
    {
    public:
        Play();
        ~Play();
        void OnEnter() override;
        void OnExit() override;
        void Update() override;
        void Draw() override;
        void CheckCollisions();

        void OnEvent(EventData eData) override;
    private: 
        BallSpawner ballSpawner;

		Ship* playerShip;
		EntityManager entityManager;
        Music bgm;
    };
}
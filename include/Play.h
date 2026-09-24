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
       

		Ship* playerShip;
        std::vector<Bullet*>* bulletPool;
		EntityManager entityManager;
        Music bgm;

        //BULLETS
        int iniPoolSize{ 10 };

        void Shoot();
        Bullet* GetBulletFromPool();

        //ASTEROIDS
        void OnBallCollison();

        std::vector<Ball*>* ballsVector;
        float curDeg{ 0 };
        int inicialBallQuant{ 10 };
        Vector2 ballSpawnPoint{ 0,0 };

        float ballCurSpeed{ 1.f };
        float const plusBallSpeed{ 0.15f };
        float const ballMaxSpeed{ 3.f };
        float const ballInitialSpeed{ 1.f };
        int const maxBallCount{ 20 };
    };
}
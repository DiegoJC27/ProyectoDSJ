#pragma once
#include "Scene.h"
#include "Ball.h"
#include <vector>
#include "EventBus.h"
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

        void OnEvent(EventData eData) override;
    private: 
        std::vector<Ball*>* ballsVector;
        int ballQuantity;
    };
}
#pragma once
#include "Scene.h"
#include "Ball.h"
#include <vector>
namespace engPro {
    class Play :
        public Scene
    {
    public:
        Play();
        ~Play();
        void OnEnter() override;
        void OnExit() override;
        void Update() override;
        void Draw() override;
    private: 
        std::vector<Ball*>* ballsVector;
        int ballQuantity;
    };
}
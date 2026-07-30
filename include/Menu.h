#pragma once
#include "Scene.h"
namespace engPro {
    class Menu :
        public Scene
    {
    public: 
        Menu();
        ~Menu();
        void OnEnter() override;
        void OnExit() override;
        void Update() override;
        void Draw() override;
    };
}

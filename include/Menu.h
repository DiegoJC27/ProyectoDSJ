#pragma once
#include "Scene.h"
#include "EngGUI.h"
#include "EventBus.h"
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

    private:
        MenuUI* menuUI;
    };
}

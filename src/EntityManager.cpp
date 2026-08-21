#include "EntityManager.h"

namespace engPro {
	void EntityManager::AddEntity(Entity* entity) {
		if (entity != nullptr)
			entities.push_back(entity);
	}

	void EntityManager::Clear()
	{
		entities.clear();
	}

	void EntityManager::Update() {
		for (Entity* entity : entities) {
			if (entity != nullptr)
				entity->Update();
		}
	}

	void EntityManager::Draw() {
		for (Entity* entity : entities) {
			if (entity != nullptr)
				entity->Draw();
		}
	}
}
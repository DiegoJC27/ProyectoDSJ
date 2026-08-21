#pragma once
#include <vector>
#include "Entity.h"
namespace engPro
{
	class EntityManager
	{
	public:
		std::vector<Entity*> entities;

		EntityManager() = default;
		~EntityManager() = default;

		void AddEntity(Entity* entity);
		void Clear();

		void Update();
		void Draw();	
	};
}

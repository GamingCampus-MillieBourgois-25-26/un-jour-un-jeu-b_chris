#pragma once
#include "Component.h"

namespace Match_3 
{
	class TileMatch : public Component
	{
	public:
		void Start() override;
		void Update(float deltaTime) override;
		void Render(sf::RenderWindow* window) override;
	};
}



#pragma once
#include <memory>

#include "Component.h"
#include "InputModule.h"
#include "SquareCollider.h"
#include "BulletHell/Bullet.h"

namespace BulletHell
{
	class EnemyBulletHell : public Component
	{
	private:
		sf::Clock cooldown;
		float positionX;
		float positionY;
	public:
		EnemyBulletHell(float _positionX, float _positionY)
		{
			positionX = _positionX;
			positionY = _positionY;
		}

		void Start() override {
			cooldown.restart();
			GetOwner()->SetPosition({ positionX, positionY });
		}

		void Update(const float _delta_time) override
		{
			if (cooldown.getElapsedTime().asSeconds() >= 10000.f) {
				Logger::Log(ELogLevel::Debug, "Bullet ennemi tirer");
				cooldown.restart();
			}
		}

		float speed = 250.0f;
	};
}
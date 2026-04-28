#pragma once

#include "Core/Component.h"
#include "InputModule.h"
#include "SquareCollider.h"
#include "Bullet.h"
#include <memory>
#include <AssetsModule.h>
#include <SpriteRenderer.h>

namespace BulletHell
{
	class PlayerBulletHell : public Component
	{
	private:
		sf::Clock cooldown;
		int bulletCount;
		float positionX;
		float positionY;
	public:
		PlayerBulletHell(float _positionX, float _positionY)
		{
			positionX = _positionX;
			positionY = _positionY;
		}

		void Start() override {
			cooldown.restart();
			GetOwner()->SetPosition({ positionX, positionY });
		}

		void Update(const float _delta_time) override;

		float speed = 250.0f;
	};
}

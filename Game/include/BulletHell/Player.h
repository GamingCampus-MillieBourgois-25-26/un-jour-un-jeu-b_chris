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
	class Player : public Component
	{
	private:
		sf::Clock cooldown;
		int bulletCount;
		float positionX;
		float positionY;
	public:
		Player(float _positionX, float _positionY)
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
			Maths::Vector2<float> position = GetOwner()->GetPosition();

			if (InputModule::GetKey(sf::Keyboard::Key::D))
			{
				position.x += speed * _delta_time;
			}
			if (InputModule::GetKey(sf::Keyboard::Key::Q))
			{
				position.x -= speed * _delta_time;
			}

			if (InputModule::GetKey(sf::Keyboard::Key::Z))
			{
				position.y -= speed * _delta_time;
			}
			if (InputModule::GetKey(sf::Keyboard::Key::S))
			{
				position.y += speed * _delta_time;
			}

			GetOwner()->SetPosition(position);

			if (InputModule::GetKeyDown(sf::Keyboard::Key::Escape))
			{
				Engine::GetInstance()->RequestQuit();
			}

			if (InputModule::GetMouseButton(sf::Mouse::Button::Left) && cooldown.getElapsedTime().asSeconds() >= 0.09f) {
				Logger::Log(ELogLevel::Debug, "Bullet tirer");

				AssetsModule* assets_module = Engine::GetInstance()->GetModuleManager()->GetModule<AssetsModule>();
				Texture* textureBullet = assets_module->GetAsset<Texture>("BulletHell/Bullet_Small.png");

				GameObject* bullet = GetOwner()->GetScene()->CreateGameObject("Bullet");
				bullet->CreateComponent<SpriteRenderer>(textureBullet);
				bullet->CreateComponent<Bullet>(300.f, 400.f, 400.f); // Gère le déplacement de la bullet.
				bullet->SetPosition({ GetOwner()->GetPosition().x, GetOwner()->GetPosition().y - 30.f });
				cooldown.restart();
			}
		}

		float speed = 250.0f;
	};
}

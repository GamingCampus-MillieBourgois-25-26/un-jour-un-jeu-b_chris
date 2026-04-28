#include "BulletHell/EnemyBulletHell.h"

void BulletHell::EnemyBulletHell::Update(const float _delta_time)
{
	Maths::Vector2f OwnerPosition = GetOwner()->GetPosition();

	if (OwnerPosition.x > 550.f)
	{
		speed = -250.f;
	}

	if (OwnerPosition.x < 50.f)
	{
		speed = 250.f;
	}

	GetOwner()->SetPosition({ OwnerPosition.x + speed * _delta_time, OwnerPosition.y });

	if (cooldown.getElapsedTime().asSeconds() >= 0.25f) {
		Logger::Log(ELogLevel::Debug, "Bullet tirer");

		AssetsModule* assets_module = Engine::GetInstance()->GetModuleManager()->GetModule<AssetsModule>();
		Texture* textureBullet = assets_module->GetAsset<Texture>("BulletHell/Bullet_Small.png");

		GameObject* bullet = GetOwner()->GetScene()->CreateGameObject("Bullet");
		SpriteRenderer* spriteBullet = bullet->CreateComponent<SpriteRenderer>(textureBullet);
		bullet->SetRotation(sf::degrees(180));
		bullet->CreateComponent<Bullet>(-300.f, 400.f, 400.f); // Gère le déplacement de la bullet.
		bullet->SetPosition({ GetOwner()->GetPosition().x, GetOwner()->GetPosition().y + 30.f });
		cooldown.restart();
	}
}

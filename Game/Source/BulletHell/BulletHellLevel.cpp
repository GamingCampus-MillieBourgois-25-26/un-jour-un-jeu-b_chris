#include "BulletHell/BulletHellLevel.h"
#include <BulletHell/Player.h>

BulletHell::BulletHellLevel::BulletHellLevel() : Scene("BulletHellLevel")
{
	WindowModule* window_module = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>();
	window_module->SetSize({ 800, 800 });

	AssetsModule* assets_module = Engine::GetInstance()->GetModuleManager()->GetModule<AssetsModule>();
	Texture* texturePlayer = assets_module->LoadAsset<Texture>("playerShip.png");

	GameObject* player = CreateGameObject("Player");
	player->CreateComponent<SpriteRenderer>(texturePlayer);
	player->CreateComponent<Player>(300.f, 550.f);

	GameObject* enemy = CreateGameObject("Enemy");
	enemy->CreateComponent<SpriteRenderer>(texturePlayer);
	enemy->SetPosition({ 300.f, 50.f });
	enemy->SetRotation(sf::degrees(180));
}

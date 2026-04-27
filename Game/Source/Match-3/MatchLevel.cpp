#include "Match-3/MatchLevel.h"
#include <SquareCollider.h>


Match_3::MatchLevel::MatchLevel() : Scene("MatchLevel")
{
	WindowModule* windowModule = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>();
	AssetsModule* assetModule = Engine::GetInstance()->GetModuleManager()->GetModule<AssetsModule>();
	Texture* texture_TileCow = assetModule->LoadAsset<Texture>("Match_3/cow.png");
	Texture* texture_TileSnake = assetModule->LoadAsset<Texture>("Match_3/snake.png");
	Texture* texture_TileBear = assetModule->LoadAsset<Texture>("Match_3/bear.png");

	textures[0] = texture_TileCow;
	textures[1] = texture_TileSnake;
	textures[2] = texture_TileBear;

	windowModule->SetSize({ 800, 800 });

	GameObject* player = CreateGameObject("Player");
	player->CreateComponent<PlayerMatch>();
	SquareCollider* playerCollider = player->CreateComponent<SquareCollider>();
	playerCollider->SetHeight(5.f);
	playerCollider->SetWidth(5.f);

	int id = 0;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{

			std::string id_str = std::to_string(id);
			GameObject* tile = CreateGameObject("Tile" + id_str);
			SpriteRenderer* spriteTile = tile->CreateComponent<SpriteRenderer>(textures[rand() % 3]);

			SquareCollider* collisionTile = tile->CreateComponent<SquareCollider>();
			collisionTile->SetWidth(TEXTURE_SIZE);
			collisionTile->SetHeight(TEXTURE_SIZE);

			tile->SetPosition({ TEXTURE_SIZE * j + 190.f, TEXTURE_SIZE * i + 200.f });
			Tiles[i][j] = tile;
			id++;
		}
	}
}

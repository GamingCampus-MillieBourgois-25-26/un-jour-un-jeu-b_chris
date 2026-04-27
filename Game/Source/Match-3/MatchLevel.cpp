#include "Match-3/MatchLevel.h"

Match_3::MatchLevel::MatchLevel() : Scene("MatchLevel")
{
	WindowModule* windowModule = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>();
	AssetsModule* assetModule = Engine::GetInstance()->GetModuleManager()->GetModule<AssetsModule>();
	Texture* texture;

	windowModule->SetSize({ 800.f, 800.f });

	GameObject* player = CreateGameObject("Player");
	player->CreateComponent<PlayerMatch>();
}

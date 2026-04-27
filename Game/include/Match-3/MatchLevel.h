#pragma once
#include "Scene.h"
#include <AssetsModule.h>
#include <WindowModule.h>
#include <SpriteRenderer.h>
#include <RectangleShapeRenderer.h>
#include <Match-3/PlayerMatch.h>

namespace Match_3
{
	class MatchLevel : public Scene
	{
	private:
		const float TEXTURE_SIZE = 45.f;
		static const int BOARD_SIZE = 6;

		std::vector<GameObject> gameObjects;
		GameObject* Tiles[BOARD_SIZE][BOARD_SIZE];
		Texture* textures[3];

	public:
		MatchLevel();
	};
}



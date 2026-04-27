#pragma once
#include "Scene.h"
#include <AssetsModule.h>
#include <WindowModule.h>
#include <SpriteRenderer.h>
#include <Match-3/PlayerMatch.h>

namespace Match_3
{
	class MatchLevel : public Scene
	{
	private:
		std::vector<GameObject> gameObjects;
	public:
		MatchLevel();
	};
}



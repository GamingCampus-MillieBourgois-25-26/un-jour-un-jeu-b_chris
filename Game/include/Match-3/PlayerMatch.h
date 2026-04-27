#pragma once
#include "Component.h"
#include <InputModule.h>
#include <SquareCollider.h>
#include "Scene.h"

class PlayerMatch : public Component
{
private:
	SquareCollider* ownerCollider;
	Scene* sceneOwner;
	int id = 0;
	const int BOARD_SIZE = 2;

	bool isDragging = false;
	Maths::Vector2i clickPosition;
	SquareCollider* selectedTile = nullptr;

public:
	void Start() override;
	void Update(float deltaTime) override;

	SquareCollider* ReturnTileName(int id);
};


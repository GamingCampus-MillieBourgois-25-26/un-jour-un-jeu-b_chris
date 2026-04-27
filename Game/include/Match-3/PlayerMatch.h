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
public:
	void Start() override;
	void Update(float deltaTime) override;

	SquareCollider* ReturnTileName(int id);
};


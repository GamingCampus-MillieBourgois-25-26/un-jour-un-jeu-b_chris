#pragma once
#include "Component.h"
#include <InputModule.h>

class PlayerMatch : public Component
{
public:
	void Update(float deltaTime) override;
};


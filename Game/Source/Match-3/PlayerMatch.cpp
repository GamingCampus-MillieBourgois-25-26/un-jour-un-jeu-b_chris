#include "Match-3/PlayerMatch.h"


void PlayerMatch::Start()
{
	sceneOwner = GetOwner()->GetScene();
	ownerCollider = GetOwner()->GetComponent<SquareCollider>();
}

void PlayerMatch::Update(float deltaTime)
{
	float mousePositionX = InputModule::GetMousePosition().x;
	float mousePositionY = InputModule::GetMousePosition().y;

	GetOwner()->SetPosition({ mousePositionX - 40.f, mousePositionY - 40.f });

	if (InputModule::GetMouseButton(sf::Mouse::Button::Left)) 
	{
		if (id == 36) { id = 0; }
		// Logger::Log(ELogLevel::Debug, "clic gauche");
		SquareCollider* tileCollider = ReturnTileName(id);
		// GetOwner()->GetComponent<SquareCollider>()->IsColliding(*GetOwner()->GetComponent<SquareCollider>(), *tileCollider);

		bool isHoverTile = ownerCollider->IsColliding(*ownerCollider, *tileCollider);

		if (isHoverTile) {
			Logger::Log(ELogLevel::Debug, "la collision marche");
			// Inverse la tuile actuelle et la tuile gauche
		}
		else if (InputModule::GetMousePosition().x > mousePositionX + 45.f && isHoverTile) {
			// Inverse la tuile actuelle et la tuile droite
		}
		else if (InputModule::GetMousePosition().y < mousePositionX - 45.f && isHoverTile) {
			// Inverse la tuile actuelle et la tuile bas
		}
		else if (InputModule::GetMousePosition().y > mousePositionX + 45.f && isHoverTile) {
			// Inverse la tuile actuelle et la tuile haut
		}

		id++;
	}
}

SquareCollider* PlayerMatch::ReturnTileName(int id)
{
	return sceneOwner->FindGameObject("Tile" + std::to_string(id))->GetComponent<SquareCollider>();
}

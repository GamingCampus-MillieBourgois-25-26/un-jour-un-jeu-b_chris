#include "Match-3/PlayerMatch.h"

void PlayerMatch::Update(float deltaTime)
{
	if (InputModule::GetMouseButton(sf::Mouse::Button::Left)) 
	{
		float mousePositionX = InputModule::GetMousePosition().x;
		float mousePositionY = InputModule::GetMousePosition().y;

		if (InputModule::GetMousePosition().x < mousePositionX - 20.f) {
			// Inverse la tuile actuelle et la tuile gauche
		}
		else if (InputModule::GetMousePosition().x > mousePositionX + 20.f) {
			// Inverse la tuile actuelle et la tuile droite
		}
		else if (InputModule::GetMousePosition().y < mousePositionX - 20.f) {
			// Inverse la tuile actuelle et la tuile bas
		}
		else if (InputModule::GetMousePosition().y > mousePositionX + 20.f) {
			// Inverse la tuile actuelle et la tuile haut
		}
	}
}

#include "BulletHell/Bullet.h"

void BulletHell::Bullet::Update(const float _delta_time)
{
	bool OutOfWindow = GetOwner()->GetPosition().y <= 0.f;
	GetOwner()->SetPosition({ GetOwner()->GetPosition().x, GetOwner()->GetPosition().y + speedBullet * _delta_time * -1});

	if (OutOfWindow) {
		GetOwner()->MarkForDeletion();
	}
}

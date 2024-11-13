#include "Projectile.h"

Projectile::Projectile() : mSpeed(10), Entity(4, sf::Color::Cyan){}

void Projectile::Move() {

	SetPosition(GetPosition().x + mSpeed, GetPosition().y);

}

void Projectile::OnCollision(Entity* collideWith) {

	if (collideWith->IsTag(1))
		collideWith->ToDestroy();

}
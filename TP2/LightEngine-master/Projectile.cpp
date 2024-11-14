#include "Projectile.h"

Projectile::Projectile(int b_radius, sf::Color b_color) : mSpeed(10), Entity(b_radius, b_color){}

void Projectile::Move() {

	SetPosition(GetPosition().x - mSpeed, GetPosition().y);

}

void Projectile::OnCollision(Entity* collideWith) {

	if (collideWith->IsTag(1))
		collideWith->ToDestroy();

}

void Projectile::OnUpdate() {

	Move();
	

}
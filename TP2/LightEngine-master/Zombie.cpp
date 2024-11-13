#include "Zombie.h"

Zombie::Zombie(int b_radius, sf::Color b_color) : mHp(150),mDamage(10), Entity(b_radius, b_color) {
	SetPosition(0, 0);
	SetSpeed(2);
	SetTag(1);
}

void Zombie::TakeDamage(int damage) {
	mHp -= damage;
}

void Zombie::Walk() {
	//
	SetPosition(GetPosition().x + mSpeed, GetPosition().y);

}

void Zombie::Attack(Entity* attacked) {
	
	// à faire dans les dernières heures

	return;
}

void Zombie::OnCollision(Entity* collideWith) {

	if(collideWith->IsTag(0))
		Attack(collideWith);

}

void Zombie::OnUpdate() {

	Walk();

}
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
	
	// � faire dans les derni�res heures

	return;
}

void Zombie::OnCollision(Entity* collideWith) {

	if(collideWith->IsTag(0))
		Attack(collideWith);
	if (collideWith->IsTag(2))
		TakeDamage(50);


}

void Zombie::OnUpdate() {

	if (mHp == 0)
		mToDestroy = true;
	Walk();

}
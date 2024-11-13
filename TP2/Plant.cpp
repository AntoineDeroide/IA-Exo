#include "Plant.h"
#include "Debug.h"

Plant::Plant(int b_radius, sf::Color b_color) : mHp(100), Entity(b_radius, b_color) {
	SetPosition(300, 0);
	SetTag(0);
}

void Plant::Shoot() {

	mProjectile = new Projectile();

	mProjectile->Move();

}

void Plant::Reload() {



}

void Plant::OnUpdate() {

	std::cout << "Plant coords : " << GetPosition().x << GetPosition().y << std::endl;
	return;

}
#include "Plant.h"
#include "./LightEngine/GameManager.h"
#include "./LightEngine/Scene.h"

Plant::Plant(int b_radius, sf::Color b_color) : mRadius(b_radius), mHp(100), Entity(b_radius, b_color) {
	SetPosition(300, 0);
	SetTag(0);
}

void Plant::Shoot() {

	std::cout << "Bang \n";
	mProjectile = CreateEntity<Projectile>(5, sf::Color::Cyan);


	mProjectile->SetPosition(GetPosition().x, GetPosition().y);

	mProjectile->Move();

}

void Plant::Reload() {



}

void Plant::OnUpdate() {

	std::cout << "Plant coords : " << GetPosition().x << GetPosition().y << std::endl;
	return;

}
#include "Plant.h"
#include "../LightEngine-master/LightEngine/Entity.h"
#include "./LightEngine/Scene.h"
#include "Projectile.h"

Plant::Plant(int b_radius, sf::Color b_color) : mRadius(b_radius), mHp(100), Entity(b_radius, b_color) {
	SetPosition(300, 0);
	SetTag(0);
}

void Plant::Shoot() {

	std::cout << "Bang \n";
	mProjectile = GetScene()->CreateEntity<Projectile>(5, sf::Color::White);

	mProjectile->SetPosition(GetPosition().x, GetPosition().y + mRadius - 5);

	mProjectile->Move();

}

void Plant::Reload() {



}

void Plant::OnUpdate() {

	if (mAmmo == 0)
		Reload();
	
	return;

}
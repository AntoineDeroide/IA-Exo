#include "./PvZScene.h"

#include "Plant.h"
#include "Zombie.h"

#include "Debug.h"

void PvZScene::Initialize()
{
	// Init Lanes
	sf::FloatRect lane1(sf::Vector2f(0, 0), sf::Vector2f(1280, 240));
	sf::FloatRect lane1(sf::Vector2f(0, 240), sf::Vector2f(1280, 240));
	sf::FloatRect lane1(sf::Vector2f(0, 480), sf::Vector2f(1280, 240));


	// Init Plantes
	pPlant1 = CreateEntity<Plant>(50, sf::Color::Green); pPlant1->SetPosition(1180, 50);
	pPlant2 = CreateEntity<Plant>(50, sf::Color::Green); pPlant2->SetPosition(1180, 250);
	pPlant3 = CreateEntity<Plant>(50, sf::Color::Green); pPlant3->SetPosition(1180, 450);
	
	// Init Zombies
	pZombie1 = CreateEntity<Zombie>(40, sf::Color::Red); pZombie1->SetPosition(0, 60);
	pZombie2 = CreateEntity<Zombie>(40, sf::Color::Red); pZombie2->SetPosition(0, 260);
	pZombie3 = CreateEntity<Zombie>(40, sf::Color::Red); pZombie3->SetPosition(0, 460);

	pEntitySelected = nullptr;
}

void PvZScene::HandleInput(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		TrySetSelectedEntity(pPlant1, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pPlant2, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pPlant3, event.mouseButton.x, event.mouseButton.y);
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (pEntitySelected != nullptr) 
		{
			if (pEntitySelected->IsTag(0)){}
				// Changement d'état de la plante de Idle à Shooting
				//pPlant1->TransitionTo(Plant::stateList::Shooting);
			//pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 10.f);
		}
	}
}

void PvZScene::TrySetSelectedEntity(Plant* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
		return;

	pEntitySelected = pEntity;
}

void PvZScene::Update()
{
	// Si une entité est sélectionnée
	if(pEntitySelected != nullptr)
	{
		sf::Vector2f position = pEntitySelected->GetPosition(0.5f, 0.5f);
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}

	// Si un zombie se trouve sur une lane / en face d'une plante
	if(lane1.contains(pZombie1->GetShape()->getGlobalBounds()))
		pPlant1->TransitionTo()
}
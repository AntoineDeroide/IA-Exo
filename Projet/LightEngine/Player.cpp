#include "Player.h"
#include "PlayerState.h"
#include "Behaviour.h"


Player::Player(int b_radius, sf::Color b_color) : mStateMachine(this, STATE_COUNT) Entity(b_radius, b_color), mSpeed(5), mBoostDuration(2.5),
mInvincibilityDuration(1.5), mPassDelayDuration(2) 
{

	// IDLE
	Behaviour<Player>* pIdle = mStateMachine.CreateBehaviour(playerState::Idle);
	pIdle->AddAction(new IdleState());

	// Transition --> HasBall
	{
		// On fait la transition de Idle à HasBall quand le joueur récupère la balle
		auto transition = pIdle->CreateTransition(playerState::HasBall);
		auto condition = transition->AddCondition<HasBallCondition>();
		condition->expected = false;
	}
	// Transition --> TeamHasBall
	{
		// On fait la transition de Idle à TeamHasBall quand l'équipe récupère la balle
		auto transition = pIdle->CreateTransition(playerState::TeamHasBall);
		auto condition = transition->AddCondition<TeamHasBallCondition>();
		condition->expected = false;
	}
	// Transition --> EnemyTeamHasBall
	{
		auto transition = pIdle->CreateTransition(playerState::EnemyTeamHasBall);
		auto condition = transition->AddCondition<EnemyTeamHasBallCondition>();
		condition->expected = false;
	}
}






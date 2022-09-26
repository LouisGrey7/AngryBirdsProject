#include "Enemy.h"

void Enemy::TakeDamage()
{

	m_health--;

}

void Enemy::Destroy()
{

	if (m_health <= 0)
	{

	}
}

void Enemy::StartContact(Object* other)
{
	TakeDamage();
}

void Enemy::EndContact(Object* other)
{


}

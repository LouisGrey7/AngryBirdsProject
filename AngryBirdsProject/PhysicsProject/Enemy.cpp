#include "Enemy.h"

void Enemy::TakeDamage()
{

	m_health--;

}

void Enemy::Destroy()
{

	if (m_health <= 0)
	{

		//m_body->GetWorld()->DestroyBody(m_body);

	}
}

void Enemy::StartContact(Object* other)
{
	TakeDamage();
	std::cout << m_health << "\n";
}

void Enemy::EndContact(Object* other)
{


}

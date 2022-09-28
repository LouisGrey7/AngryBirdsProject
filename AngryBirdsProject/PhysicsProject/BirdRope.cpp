#include "BirdRope.h"
BirdRope::BirdRope(float _SpringConstant, float _RestLength, Bird* _Anchor, Bird* _Bob)
{
	m_SpringConstant = _SpringConstant;
	m_RestLength = _RestLength;
	m_Anchor = _Anchor;
	m_Bob = _Bob;

	line[0].position = sf::Vector2f(m_Anchor->GetBody()->GetPosition().x, m_Anchor->GetBody()->GetPosition().y);
	line[0].color = sf::Color::White;
	line[1].position = sf::Vector2f(m_Bob->GetBody()->GetPosition().x + 50, m_Bob->GetBody()->GetPosition().y + 50);
	line[1].color = sf::Color::White;

}

void BirdRope::Update()
{
	//Spring Force
	sf::Vector2f Force = sf::Vector2f(m_Bob->GetBody()->GetPosition().x - m_Anchor->GetBody()->GetPosition().x,
										m_Bob->GetBody()->GetPosition().y - m_Anchor->GetBody()->GetPosition().y);
	float x = length(Force) - m_RestLength;
	Force = Normalize(Force) * m_SpringConstant * x;

	m_Anchor->GetBody()->ApplyLinearImpulse(b2Vec2(Force.x, Force.y), m_Anchor->GetBody()->GetPosition(), true);
	Force *= -1.0f;
	m_Bob->GetBody()->ApplyLinearImpulse(b2Vec2(Force.x, Force.y), m_Bob->GetBody()->GetPosition(), true);

}


void BirdRope::Render(sf::RenderWindow& _window)
{
	line[0].position = sf::Vector2f(m_Anchor->GetBody()->GetPosition().x, m_Anchor->GetBody()->GetPosition().y);
	line[1].position = sf::Vector2f(m_Bob->GetBody()->GetPosition().x, m_Bob->GetBody()->GetPosition().y);
	_window.draw(line, 4, sf::Lines);
}
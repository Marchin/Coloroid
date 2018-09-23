#include "Shot/ShotPool.h"
#include "Constants.h"

namespace shotSys {

ShotPool::ShotPool(const sf::View* pView, unsigned int amount) 
	: m_pView(pView) {
	
	m_shots = std::vector<Shot>(amount);
}

unsigned int ShotPool::GetSize() const {
	return m_shots.size();
}

Shot* ShotPool::operator[](unsigned int index) {
	return &(m_shots[index]);
}

bool ShotPool::Request(const float angle, const sf::Color& color,
	Shot** requested) {

	ISprite* shot = nullptr;
	if (IsAvailable(shot)) {
		ResetPosition(shot);
		shot->SetColor(color);
		sf::Vector2f direction (
			(float)std::sin(angle * constant::RAD2DEG) * 11.f,
			(float)-std::cos(angle * constant::RAD2DEG) * 11.f);
		shot->SetPosition(shot->GetPosition() + direction);
		shot->SetDirection(angle);
		shot->Enable();
		if (requested != nullptr) {
			*requested = static_cast<Shot*>(shot);
		}
		return true;
	} else {
		return false;
	}
}

void ShotPool::Update(const float deltaTime) {
	for (unsigned int i = 0; i < m_shots.size(); i++) {
		m_shots[i].Update(deltaTime);
		if (OutOfBound(&m_shots[i])) {
			m_shots[i].Disable();
		}
	}
}

void ShotPool::draw(sf::RenderTarget& target,
	sf::RenderStates states) const {
;
	for (Shot shot : m_shots) {
		shot.draw(target, states);
	}
}

bool ShotPool::IsAvailable(ISprite*& pRequester){
	bool isAvailable = false;
	for (unsigned int i = 0; i < m_shots.size(); i++) {
		if (m_shots[i].IsAvailable()) {
			pRequester = &m_shots[i];
			isAvailable = true;
			break;
		}
	}
	return isAvailable;
}

void ShotPool::ResetPosition(ISprite*& shot) {
	sf::Vector2f screenCenter(
		m_pView->getSize().x / 2.f, m_pView->getSize().y / 2.f);
	shot->SetPosition(screenCenter);
}

bool ShotPool::OutOfBound(const ISprite* const& shot) const{
	return ((shot->GetPosition().x < 0.f) || 
		(shot->GetPosition().x > m_pView->getSize().x) ||
		(shot->GetPosition().y < 0.f) || 
		(shot->GetPosition().y > m_pView->getSize().y)
		);
}

}
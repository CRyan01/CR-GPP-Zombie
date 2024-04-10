#include "Grenade.h"
#include "TextureHolder.h"

// Constructor
Grenade::Grenade(Vector2f position, Vector2f target) {
	// Set the grenades sprite
	m_Sprite.setTexture(TextureHolder::GetTexture("graphics/grenade.png"));
	m_Sprite.setOrigin(TextureHolder::GetTexture("graphics/grenade.png").getSize().x / 2, TextureHolder::GetTexture("graphics/grenade.png").getSize().y / 2);
	m_Sprite.setScale(0.14f, 0.14f);
	m_Sprite.setPosition(position);

	m_TargetPosition = target; // Set the grenades target position
	m_HasExploded = false; // Set the flag to indicate the grenade has not exploded yet
	m_Destroy = false; // Set the flag to ensure the grenade is not cleaned up early
	m_ExplosionTime = 0.2f; // Set the time amount of time the explosion is active
	m_TimeElapsed = 0.0; // Counter to track time since the explosion
	m_Timer = 3.0f; // Time until the grenade explodes once thrown
}

// Update function, handles grenade movement and fuse time
void Grenade::update(float dt) {
	// Check if the grenade has exploded
	if (m_HasExploded) {
		// If it has track the time
		m_TimeElapsed += dt;

		// Once the explosion time threshold is met mark the grenade for cleanup
		if (m_TimeElapsed >= m_ExplosionTime) {
			m_Destroy = true;
		}
		return;
	}
	m_Timer -= dt; // decrement the fuse timer

	if (m_Timer <= 0) { // If the timer has already expired do nothing
		return;
	}

	// Update movement if the grenade hasnt exploded
	if (!m_HasExploded) {
		Vector2f currentPosition = m_Sprite.getPosition();
		Vector2f distanceToTarget = m_TargetPosition - currentPosition;

		float movementProgress = dt * (2.0f / m_Timer);
		Vector2f distanceToMove = distanceToTarget * movementProgress;

		m_Sprite.move(distanceToMove);
	}
}
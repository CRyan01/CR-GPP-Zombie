#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Grenade {
public:
	Sprite m_Sprite; // The grenades sprite
	Vector2f m_TargetPosition; // The position vector the grenade travels towards
	bool m_HasExploded; // Flag to indicate if the grenade has exploded
	bool m_Destroy; // Flag to mark the grenade for cleanup
	float m_ExplosionTime; // The time the explosion stays active for
	float m_TimeElapsed; // The time elapsed since the grenade exploded
	float m_Timer; // The fuse time until the grenade explodes

	// Constructor
	Grenade(Vector2f position, Vector2f target);

	// Method to update the grenades position and fuse timer
	void update(float dt);

};
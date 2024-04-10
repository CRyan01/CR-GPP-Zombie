#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Zombie
{
private:
	// How fast is each zombie type?
	const float BLOATER_SPEED = 40;
	const float CHASER_SPEED = 80;
	const float CRAWLER_SPEED = 20;
	const float SPITTER_SPEED = 30;
	const float RUNNER_SPEED = 100;

	// How tough is each zombie type
	const float BLOATER_HEALTH = 5;
	const float CHASER_HEALTH = 1;
	const float CRAWLER_HEALTH = 3;
	const float SPITTER_HEALTH = 2;
	const float RUNNER_HEALTH = 1;

	// Make each zombie vary its speed slightly
	const int MAX_VARRIANCE = 30;
	const int OFFSET = 101 - MAX_VARRIANCE;

	// Where is this zombie?
	Vector2f m_Position;

	// A sprite for the zombie
	Sprite m_Sprite;

	// How fast can this one run/crawl?
	float m_Speed;

	// How much health has it got?
	float m_Health;

	// Is it still alive?
	bool m_Alive;

	// What type of zombie is it
	int m_Type = 0;

	// Public prototypes go here	
public:

	// Handle when a bullet hits a zombie
	bool hit();

	// Find out if the zombie is alive
	bool isAlive();

	// Returns the type of zombie
	int getType();

	// Sets the type of zombie
	void setType(int type);

	// Spawn a new zombie
	void spawn(float startX, float startY, int type, int seed);

	// Return a rectangle that is the position in the world
	FloatRect getPosition();

	// Get a copy of the sprite to draw
	Sprite getSprite();

	// Update the zombie each frame
	void update(float elapsedTime, Vector2f playerLocation);

	// Reduce the zombies health if they were hit by a grenades explosion
	bool hitByGrenade();

	// Where is the center of the zombie
	Vector2f getCenter();
};



#include "Particle.h"

Particle::Particle()
{

}

Particle::Particle(Vector2 l, ofImage* _image)
{
	position = l;
	acceleration = Vector2(0, 0);
	velocity = Vector2(0, 0);
	lifespan = 255;
	mass = 1;

	ApplyForce(Vector2(ofRandom(-1, 1), ofRandom(0, -1)));

	image = _image;
}


void Particle::Update()
{
	
	velocity += acceleration;
	position += velocity;
	acceleration = Vector2(0, 0);
	
	lifespan -= 2.0f;
}

void Particle::Draw()
{
	Update();
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofSetColor(255, 255, 255, lifespan);
	image->draw(position, 80, 80);
}

bool Particle::isDead()
{
	if (lifespan < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Particle::ApplyForce(Vector2 _force)
{
	Vector2 force = _force;
	force /= mass;
	acceleration += force;
}

Particle::~Particle()
{
}

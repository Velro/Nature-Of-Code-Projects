#include "Repeller.h"

Repeller::Repeller()
{

}

Repeller::Repeller(Vector2 _position)
{
	position = _position;
	radius = 10;
	strength = 150;
}

void Repeller::Update()
{
	ofSetColor(122);
	ofDrawSphere(position, radius);
}

Vector2 Repeller::Repel(Particle p)
{
	Vector2 repelForce = Vector2(0, 0);

	Vector2 direction = position - p.position;
	float directionMagnitude = direction.length();
	directionMagnitude = (directionMagnitude < 100) ? directionMagnitude : 100;//max
	directionMagnitude = (directionMagnitude > 5) ? directionMagnitude : 5;//min
	direction.normalize();
	float force = (-1 * strength) / (directionMagnitude * directionMagnitude);

	repelForce = direction * force;

	return repelForce;
}

Repeller::~Repeller()
{

}
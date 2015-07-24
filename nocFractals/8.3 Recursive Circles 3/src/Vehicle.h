#include "Defines.h"
#include "ofMain.h"

class Vehicle
{
public:
	Vehicle();
	Vehicle(Vector2 startingPosition);

	void Update();
	void Seek(Vector2 target);
	void ApplyForce(Vector2 force);
	void Display();

	void VehicleSteerWithWalls();

	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;

	float maxSpeed;
	float maxForce;

	float r;
};
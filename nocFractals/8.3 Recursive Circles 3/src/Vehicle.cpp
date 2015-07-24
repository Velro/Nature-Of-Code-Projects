include "Vehicle.h"

Vehicle::Vehicle()
{

}

Vehicle::Vehicle(Vector2 startingPosition)
{
	acceleration = Vector2(0, 0);
	velocity = Vector2(0, 0);
	position = startingPosition;

	r = 3.0f;
	maxSpeed = 4.0f;
	maxForce = 0.1f;
}

void Vehicle::Display()
{
	float theta = velocity.angle(Vector2(0, 1)) + PI / 2;
	ofSetColor(0, 255, 0);
	ofPushMatrix();
	{
		ofTranslate(position.x, position.y);
		ofRotateZ(theta);
		ofDrawCone(15, 50);
	}
	ofPopMatrix();
	ofSetColor(255, 0, 0);
	ofDrawArrow(position, position + (velocity*10),0.1f);
}

void Vehicle::Update()
{
	velocity += acceleration;
	velocity.limit(maxSpeed);
	position += velocity;
	acceleration = Vector2(0, 0);
	Display();
}

void Vehicle::Seek(Vector2 target)
{
	Vector2 desired = target - position;
	float d = desired.length();
	desired.normalize();
	desired *= maxSpeed;
	if (d < 100)
	{
		float m = ofMap(d, 0, 100, 0, maxSpeed);
		desired *= m;
	}


	Vector2 steer = desired - velocity;

	steer.limit(maxForce);

	ApplyForce(steer);
}

void Vehicle::VehicleSteerWithWalls()
{

}

void Vehicle::ApplyForce(Vector2 force)
{
	acceleration += force;
}
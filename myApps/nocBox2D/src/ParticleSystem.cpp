#include "ParticleSystem.h"

float startingOffsetFromCenter = 0;
float chanceOfConfetti = 0.5f;
ParticleSystem::ParticleSystem()
{

}

ParticleSystem::ParticleSystem(Vector2 _startPos)
{
	startPos = _startPos;
	particleImage.loadImage("particle.png");

}

void ParticleSystem::Setup()
{
	i = 100;
	pointer = &i;
	imagePointer = &particleImage;
	for (int i = 0; i < particleCount; i++)
	{

	Vector2 v = Vector2(ofRandom(-1, 1) * startingOffsetFromCenter + startPos.x,
		ofRandom(-1, 1) * startingOffsetFromCenter + startPos.y);

	//	if (ofRandom(0.0f, 1.0f) > chanceOfConfetti)
	{
		Particle *particle = new Particle(v, imagePointer);
		particleList.push_back(particle);
	}
	//	else
	//	{
	//		Confetti *confetti = new Confetti(v);
	//		particleList.push_back(confetti);
	//	}
	}
}

void ParticleSystem::Update()
{	
	Vector2 v = Vector2(ofRandom(-1, 1) * startingOffsetFromCenter + startPos.x,
		ofRandom(-1, 1) * startingOffsetFromCenter + startPos.y);
	//if (ofRandom(0.0f, 1.0f) > chanceOfConfetti)
	{
		Particle *particle = new Particle(v, imagePointer);
		particleList.push_back(particle);
	}
	//else
	//{
	//	Confetti *confetti = new Confetti(v);
	//	particleList.push_back(confetti);
	//}
	
	for (int i = particleList.size()-1; i > 0; i--)
	{
		particleList[i]->Draw();

		if (particleList[i]->isDead())
		{
			particleList.erase(
				particleList.begin(),
				particleList.begin() + i);
		}
	}
}

void ParticleSystem::ApplyForce(Vector2 force)
{
	for (int i = 0; i < particleList.size(); i++)
	{
		particleList[i]->ApplyForce(force);
	}
}

void ParticleSystem::ApplyRepeller(Repeller repeller)
{
	for (int i = 0; i < particleList.size(); i++)
	{
		Vector2 repelForce = repeller.Repel(*particleList[i]);
		particleList[i]->ApplyForce(repelForce);
	}
}



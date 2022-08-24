#include "ContactListener.h"

#include "Framework/Actor.h"

namespace en
{
	void ContactListener::BeginContact(b2Contact* contact)
	{
		b2Fixture* fixA = contact->GetFixtureA();
		b2Fixture* fixB = contact->GetFixtureB();

		if (fixA->GetUserData().pointer && fixB->GetUserData().pointer)
		{
			Actor* actorA = (Actor*)(fixA->GetUserData().pointer);
			Actor* actorB = (Actor*)(fixB->GetUserData().pointer);
		}
	}

	void ContactListener::EndContact(b2Contact* contact)
	{
		b2Fixture* fixA = contact->GetFixtureA();
		b2Fixture* fixB = contact->GetFixtureB();

		if (fixA->GetUserData().pointer && fixB->GetUserData().pointer)
		{
			Actor* actorA = (Actor*)(fixA->GetUserData().pointer);
			Actor* actorB = (Actor*)(fixB->GetUserData().pointer);
		}
	}
}
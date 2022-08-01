#include "Actor.h"

namespace en
{
	void Actor::Draw(Renderer& renderer)
	{
		_model.draw(renderer, _transform.position, _transform.rotation, _transform.scale);
	}
}


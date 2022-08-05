#ifndef _COMPONENT_RENDER_H
#define _COMPONENT_RENDER_H

#include "Framework/Component.h"

namespace en
{
	class Renderer;

	class RenderComponent : public Component
	{
	public:
		RenderComponent() = default;

		virtual void Draw(Renderer& renderer) = 0;

	private:

	};
}

#endif // _COMPONENT_RENDER_H
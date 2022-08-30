#ifndef _COMPONENT_RENDER_H
#define _COMPONENT_RENDER_H

#include "Framework/Component.h"
#include "Math/Rect.h"
#include <memory>

namespace en
{
	class Renderer;

	class RenderComponent : public Component
	{
	public:
		virtual void Draw(Renderer& renderer) = 0;

		virtual Rect& _Source() { return _source; }
	private:
		Rect _source {1, 1, 1, 1};

	};
}

#endif // _COMPONENT_RENDER_H
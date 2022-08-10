#ifndef _COMPONENT_MODEL_H
#define _COMPONENT_MODEL_H

#include "Framework/Component.h"

namespace en
{
	class ModelComponent : public Component
	{
	public:
		ModelComponent() = default;
		~ModelComponent() = default;

		void Update() override;

	public:


	};
}

#endif // _COMPONENT_MODEL_H
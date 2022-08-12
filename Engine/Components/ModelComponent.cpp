#include "ModelComponent.h"
#include "Renderer/Model.h"
#include "Framework/Actor.h"

namespace en
{
	void ModelComponent::Update()
	{

	}

	void ModelComponent::Draw(Renderer& renderer)
	{
		_model->Draw(renderer, _owner->_Transform());
	}
}
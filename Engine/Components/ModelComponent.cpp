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

	bool ModelComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool ModelComponent::Read(const rapidjson::Value& value)
	{
		return true;
	}
}
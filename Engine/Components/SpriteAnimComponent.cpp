#include "SpriteAnimComponent.h"
#include "Engine.h"

namespace en
{
	void SpriteAnimComponent::Update()
	{
		frameTime += __time.ci_time;
		if (frameTime >= 1.0f / fps)
		{
			frameTime = 0;
			frame++;
			if (frame > end_frame)
			{
				frame = start_frame;
			}
		}

		Vector2 cellSize = _texture->getSize() / Vector2 { columns, rows };

		int column = (frame - 1) % columns;
		int row = (frame - 1) / columns;

		source.x = (int) (column * cellSize.x);
		source.y = (int) (row * cellSize.y);
		source.w = (int) (cellSize.x);
		source.h = (int) (cellSize.y);
	}

	void SpriteAnimComponent::Draw(Renderer& renderer)
	{
		renderer.Draw(_texture, source, _owner->_Transform());
	}

	bool SpriteAnimComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool SpriteAnimComponent::Read(const rapidjson::Value& value)
	{
		std::string texture;

		READ_DATA(value, texture);
		_texture = en::__registry.Get<en::Texture>(texture, __renderer);
		
		READ_DATA(value, fps);
		READ_DATA(value, columns);
		READ_DATA(value, rows);
		READ_DATA(value, start_frame);
		READ_DATA(value, end_frame);		

		return true;
	}
}
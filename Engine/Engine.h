#ifndef _ENGINE_H
#define _ENGINE_H

#include "Input/InputSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Framework/Background.h"
#include "Framework/Scene.h"
#include "Framework/Game.h"

#include "Audio/AudioSys.h"

#include <iostream>
#include <memory>
#include <vector>
#include <list>

namespace en
{
	extern InputSystem __inputsys;
	extern Time __time;
	extern Renderer __renderer;
	extern AudioSys __audiosys;
}
#endif // _ENGINE_H
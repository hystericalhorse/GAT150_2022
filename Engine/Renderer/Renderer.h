#ifndef _RENDERER_H
#define _RENDERER_H
#include "../Math/Vector2.h"
#include "../Math/Color.h"

struct SDL_Renderer; // Forward Declaration
struct SDL_Window; // Forward Declaration

namespace en
{
	class Renderer
	{
	public:
		Renderer() = default;
		~Renderer() = default;

		void Init();
		void Shutdown();

		void newWindow(const char* title, int width, int height);
		void beginFrame();
		void endFrame();
		void setClearColor(const Color& color) { _clearcolor = color; }
		Color& getClearColor() { return _clearcolor; }

		void drawLine(float x1, float y1, float x2, float y2, const Color& color);
		void drawLine(const Vector2& v1, const Vector2& v2, const Color& color);

		void drawPoint(float x, float y, const Color& color);
		void drawPoint(const Vector2& vector, const Color& color); // Pass by value

		void drawCircle(float x, float y, float radius, const Color& color);
		void drawCircle(Vector2& position, float radius, const Color& color);

		int get_window_width() { return width; }
		int get_window_height() { return height; }

		friend class Text;

	private:
		SDL_Renderer* _renderer{ nullptr };
		SDL_Window* _window{ nullptr };

		int width = 0;
		int height = 0;

		Color _clearcolor{0, 0, 0, 255};
	};
}

#endif // _RENDERER_H
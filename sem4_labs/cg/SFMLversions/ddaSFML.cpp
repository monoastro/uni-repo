#include <SFML/Graphics.hpp>
using namespace sf;

#define WIDTH 1000
#define HEIGHT 1000

void drawDDALine(RenderWindow& window, int x1, int y1, int x2, int y2)
{

	int dx = x2 - x1;
	int dy = y2 - y1;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	VertexArray points(Points, steps + 1);

	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;

	float X = x1;
	float Y = y1;
	

	for (int i = 0; i < steps + 1; i++)
	{
		//"set" the pixel
		points[i].position = Vector2f((int)X, (int)Y);

		X += Xinc;
		Y += Yinc;

		//constrain to window size
		if( X > WIDTH || X < 0 || Y > HEIGHT) break;
	}

	window.draw(points);
}


int main()
{
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "DDA demo", Style::Titlebar);

	int x1 = 0, y1 = 0;
	int x2 = 1000, y2 = 1000;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
		}

		//detect keypress and change x1 and y1; constrain them to window size
		if (Keyboard::isKeyPressed(Keyboard::Left) && x1 > 0) x1--;
		else if (Keyboard::isKeyPressed(Keyboard::Right) && x1 < WIDTH) x1++;
		if (Keyboard::isKeyPressed(Keyboard::Up) && y1 > 0) y1--;
		else if (Keyboard::isKeyPressed(Keyboard::Down) && y1 < HEIGHT) y1++;

		window.clear();
		drawDDALine(window, x1, y1, x2, y2);
		window.display();
	}
	return 0;
}

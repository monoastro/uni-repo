//ball bouncing physics simulation
#include <SFML/Graphics.hpp>
#include <time.h>
#include <math.h>

using namespace sf;

#define acceleration 9.8f
#define WIDTH 1000
#define HEIGHT 1000

class Ball
{
public:
	Ball(float sx, float sy, float ux, float uy, float radius)
		:
			m_sx(sx), m_sy(sy), m_ux(ux), m_uy(uy), m_radius(radius)
	{
		circle.setRadius(m_radius);
		circle.setFillColor(Color::Green);
		circle.setPosition(m_sx, m_sy);
	}

	void update(float delta)
	{
		m_sx = m_ux * delta;
		m_sy = m_uy * delta + 0.5 * acceleration * delta * delta;
		m_uy += acceleration * delta;
	}
	
	void draw(RenderWindow& window)
	{
		circle.setPosition(m_sx, m_sy);
		window.draw(circle);
	}

private:
	sf::CircleShape circle;
	float m_sx, m_sy, m_ux, m_uy;
	float m_radius;
};


int main()
{  
    srand(time(0));
	Ball ballin(400, 400, 10, 0, 15);
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ball bouncing simulation");

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
		}

		window.clear(sf::Color::Black);

		ballin.update(0.07f);
		ballin.draw(window);

		window.display();
	}
	return 0;
}


#include <SFML/Graphics.hpp>
#include "Grid.hpp"
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(200, 200), "SFML works!");
    Grid grid(5,5);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        grid.drawTo(window);
        window.display();
    }

    return 0;
}
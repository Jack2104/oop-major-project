// will be replaced with student thingy


#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(2000, 2000), "Please work");
    CircleShape shape(10.0f);
    shape.setFillColor(Color::Green);
    shape.setOrigin(Vector2f(5, 5));

    while (window.isOpen()) {
        // get the current mouse position in the window
        Vector2i pixelPos = Mouse::getPosition(window);

        // convert it to world coordinates
        Vector2f worldPos = window.mapPixelToCoords(pixelPos);

        shape.setPosition(worldPos);

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            window.draw(shape);
            window.display();
        }

        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // window.clear();
        // window.draw(shape);
        // window.display();
    }

    return 0;
}

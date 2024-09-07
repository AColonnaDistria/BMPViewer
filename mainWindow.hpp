#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include "vector3d.hpp"
#include "vector2d.hpp"

#include "color.hpp"
#include "bmpReader.hpp"

#include <array>
#include <tuple>

class MainWindow {
    sf::RenderWindow* window;
    Image_BMP image;

public:
    MainWindow();
    int start();

private:
    void setup();
    void processInput();
    void render();

    void drawLine(Vertex2 v1, Vertex2 v2);

    void drawPixel(int x, int y, Color color);
};
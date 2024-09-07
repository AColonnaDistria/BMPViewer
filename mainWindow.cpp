#include "mainWindow.hpp"
#include "vector3d.hpp"
#include "vector2d.hpp"

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 800

#include "common.hpp"
#include "bmpReader.hpp"
#include <array>

MainWindow::MainWindow() {

}

int MainWindow::start() {
    this->setup();

    this->render();
    while (window->isOpen()) {
        this->processInput();
    }

    return 0;
}

void MainWindow::drawLine(Vertex2 v1, Vertex2 v2) {
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(v1.x * 250.0f + 400.0f, v1.y * 250.0f + 400.0f);
    line[0].color  = sf::Color::White;  

    line[1].position = sf::Vector2f(v2.x * 250.0f + 400.0f, v2.y * 250.0f + 400.0f);
    line[1].color = sf::Color::White;

    window->draw(line, 2, sf::Lines);
}

void MainWindow::drawPixel(int x, int y, Color color) {
    sf::RectangleShape pixel(sf::Vector2f(1.0f, 1.0f));

    pixel.setPosition(x, y);
    pixel.setFillColor(sf::Color(color.r, color.g, color.b, color.a));

    this->window->draw(pixel);
}

void MainWindow::setup() {
    this->window = new sf::RenderWindow(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), "Hello World!", sf::Style::Default);
    this->window->setFramerateLimit(60);

    image = Image_BMP("input.bmp");
}
void MainWindow::processInput() {
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window->close();
        }
    }
}
void MainWindow::render() {
    window->clear(sf::Color::Black);

    for (int x = 0; x < this->image.getWidth(); ++x) {
        for (int y = 0; y < this->image.getHeight(); ++y) {
            drawPixel(x, y, this->image.getPixel(x, y));
        }
    }

    window->display();
}
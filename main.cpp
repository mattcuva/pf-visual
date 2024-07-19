#include <SFML/Graphics.hpp>

#define WIDTH 810
#define HEIGHT 600
#define CELL_SIZE 10

#define COLS (WIDTH/CELL_SIZE)
#define ROWS (HEIGHT/CELL_SIZE)

int main() {

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "pf-visual", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(15);

    int grid[COLS][ROWS];
    for (int x = 0; x < COLS; x++) {
        for (int y = 0; y < ROWS; y++) {
            grid[x][y] = (x + y*COLS) % 2;
        }
    }

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // draw grid
        for (int x = 0; x < COLS; x++) {
            for (int y = 0; y < ROWS; y++) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                //cell.setFillColor(grid[x][y] ? sf::Color::Black : sf::Color::Magenta);
                cell.setFillColor(sf::Color::White);
                cell.setOutlineColor(sf::Color(0xBBBBBBFF)); // RRGGBBAA
                cell.setOutlineThickness(1);
                cell.setPosition(sf::Vector2f(x*CELL_SIZE, y*CELL_SIZE));
                window.draw(cell);
            }
        }

        window.display();
    }

    return 0;
}
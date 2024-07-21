#include <SFML/Graphics.hpp>

#define WIDTH 600
#define HEIGHT 400
#define CELL_SIZE 10

#define COLS (WIDTH/CELL_SIZE)
#define ROWS (HEIGHT/CELL_SIZE)

#define EMPTY 0
#define WALL  1

int main() {

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "pf-visual", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(15);

    int grid[COLS][ROWS] = {0};

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                int cellX = pos.x/CELL_SIZE;
                int cellY = pos.y/CELL_SIZE;
                int *cell = &grid[cellX][cellY];
                if (*cell == EMPTY) { 
                    *cell = WALL; // toggle wall/empty
                } else if (*cell == WALL) {
                    *cell = EMPTY;
                } else {
                    // change start/end?
                }
            }
        }

        window.clear();

        // draw grid
        for (int x = 0; x < COLS; x++) {
            for (int y = 0; y < ROWS; y++) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                sf::Color c;
                switch (grid[x][y]) {
                    case 0: // empty space
                        c = sf::Color::White;
                        break;
                    case 1: // wall
                        c = sf::Color::Black;
                        break;
                    default: // ??
                        c = sf::Color::Magenta;
                        break;
                }
                cell.setFillColor(c);
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
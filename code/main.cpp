#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#define LIM_VX   40.0f
#define LIM_VY   40.0f
#define SIZE_X 200.0
#define SIZE_Y 100.0
#define SHAPE_SIZE  6.0f
float clc_speed(float v, float a, float LIM)
{
    v += a;
    if (v < (LIM * (-1)))
        return  LIM * (-1);
    if (v > LIM)
        return LIM;
    return v;
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(SIZE_X, SIZE_Y), "SFML works!");
    sf::CircleShape shape(SHAPE_SIZE);
    shape.setFillColor(sf::Color::Green);
    float x = 0, y = 0, v_x = 0, v_y = 0, a_x = 800, a_y = 0;
    int fps = 0;
    sf::Clock clock;
    sf::Clock moveClock;
    int64_t elapsed = 0, movTime = 0;
    while (window.isOpen())
    {
        elapsed = clock.restart().asMicroseconds();
        sf::Event event;
        float a =  800 * elapsed;
        a = a/1000000.0f;
        if (a_x < 0)
            a_x = a * (-1);
        else
            a_x = a;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        v_x = clc_speed(v_x, a_x, LIM_VX);
        x += v_x*elapsed/1000000;
        if (x > SIZE_X - 2*SHAPE_SIZE)
        {
            x = SIZE_X - 2*SHAPE_SIZE;
            v_x = 0;
            a_x *=(-1);
            movTime = moveClock.restart().asMicroseconds();
            printf("%ld \r", movTime);
        }
        else if (x < 0)
        {
            x = 0;
            v_x = 0;
            a_x *=-1;
            movTime = moveClock.restart().asMicroseconds();
            printf("%ld \r", movTime);
        }
        shape.setPosition(x, y);
        //sf::sleep(sf::milliseconds(25));
        fflush(stdout);
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
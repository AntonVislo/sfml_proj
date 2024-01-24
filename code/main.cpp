#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <vector>
enum KeyState
    {
        FREE,
        PRESSED
    };
struct Key
{
    KeyState state = KeyState::FREE;
    sf::Keyboard::Key name;
    Key(KeyState st, sf::Keyboard::Key nm)
    {
        name = nm;
        state = st;
    }
};

class MyObject{
    private:
    struct 
    {
        float sizeHight = 100.0, sizeWidth = 100.0;
        float positionX = 100.0, positionY = 100.0;
        float speedX = 0.0, speedY = 0.0, speedLimX = 5.0, speedLimY = 5.0;
        float aX = 0.0, aY = 0.0;
    }physics;
    public:
    MyObject()
    {

    }
    void clc_speed(float time, int revers, char dir)
    {
        float *speed = &this->physics.speedX;
        float *a = &this->physics.aX;
        float *lim = &this->physics.speedLimX;  
        if (dir=='Y')
        {
            speed = &this->physics.speedY;
            a = &this->physics.aY;
        }
        if(revers == -1)
            *a *=-1;
        *speed += *a;
        if(*speed > *lim)
            *speed = *lim;
        if(*speed < *lim* (-1))
            *speed = *lim* (-1);
    }
};

class MainDispatcher{

};

int main()
{
    sf::RenderWindow window(sf::VideoMode(100, 100), "SFML works!");
    std::vector<Key> KeyVector;
    window.setVerticalSyncEnabled(true);
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Green);
    int fps = 0;
    sf::Clock clock;
    sf::Clock moveClock;
    sf::Clock fpsClock;
    int64_t elapsed = 0, movTime = 0;
    KeyVector.push_back(Key(KeyState::FREE, sf::Keyboard::Left));
    KeyVector.push_back(Key(KeyState::FREE, sf::Keyboard::Right));
    while (window.isOpen())
    {
        elapsed = clock.getElapsedTime().asMilliseconds();
        if(elapsed > 10)
        {
            clock.restart();
            for(int i = 0; i<size(KeyVector); i++ )
            {
                Key *K = &KeyVector[i];
                if(sf::Keyboard::isKeyPressed(K->name))
                {
                    if(K->state ==KeyState::FREE)
                    {
                        std::cout<<K->name<<" pressed\n";
                        K->state = KeyState::PRESSED;
                    }
                }
                else if (K->state == KeyState::PRESSED)
                {
                    std::cout<<K->name<<" FREE\n";
                    K->state = KeyState::FREE;
                }
            }
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
        fps++;
        if(fpsClock.getElapsedTime().asMilliseconds() > 999)
        {
            fpsClock.restart();
            printf("fps: %d\r", fps);
            fps = 0;
        }
         fflush(stdout);
    }
    return 0;
}
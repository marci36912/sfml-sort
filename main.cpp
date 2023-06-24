#include <SFML/Graphics.hpp>
#include <vector>
#include <stdlib.h>
#include <time.h>

#define WINDOW_HEIGHT 300
#define WINDOW_WIDTH 600
#define NUMBER 15
#define DELAY 100

class sortItem{
    public:
        sortItem(){}
        sortItem(int h)
        {
            shape.setFillColor(sf::Color::White);
            shape.setOutlineColor(sf::Color::Black);
            shape.setOutlineThickness(1);

            heigth = h;
        }

        void showItem(sf::RenderWindow &w, int i)
        {
            shape.setPosition(sf::Vector2f(width*i -width, 300));
            w.draw(shape);
        }

        void setSize(int i)
        {
            shape.setSize(sf::Vector2f(width, heigth));
            sf::Vector2f v = shape.getSize();
            shape.setOrigin(-v.x, v.y);
        }

        int getHeigth()
        {
            return heigth;
        }

        void finished()
        {
            shape.setFillColor(sf::Color::Green);
        }

    private:
        sf::RectangleShape shape;
        int width = WINDOW_WIDTH/NUMBER;
        int heigth; 
};


int main()
{
    srand(time(NULL));
    std::vector<sortItem> items;

    for(int i = 0; i < NUMBER; i++)
    {
        items.push_back(sortItem(rand() % WINDOW_HEIGHT));
        items[i].setSize(i);
    }

    sf::Time t;
    sf::Clock c;
    int time = DELAY;
    int i = 0;
    int j = 0;
    sortItem tmp;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML sort");
    
    while (window.isOpen())
    {
        t = c.getElapsedTime();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for(int s = 0; s < NUMBER; s++)
        {
            items[s].showItem(window, s);
        }
        window.display();

        if (time <= 0) 
        {
            if(i < NUMBER)
            {
                if(j < NUMBER-1)
                {
                    if(items[j].getHeigth() > items[j+1].getHeigth())
                    {
                        tmp = items[j];
                        items[j] = items[j+1];
                        items[j+1] = tmp;
                    }
                    j++;
                }
                else
                {
                    i++;
                    j = 0;
                }
            }
            else
            {
                for(auto &a: items)
                {
                    a.finished();
                }
            }
            time = DELAY;
        }
        else
        {
            time -= t.asMicroseconds();
        }

        c.restart();
    }

    return 0;
}

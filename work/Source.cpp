#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(592, 272), "Parallax");
    window.setVerticalSyncEnabled(true);

    sf::Texture texture1;
    sf::Texture texture2;
    sf::Texture texture3;
    sf::Texture texture4;

    sf::Texture d3;
    sf::Texture d4;

    float pic0;
    float pic1;
    float pic0d;
    float pic1d;


    texture1.loadFromFile("../1.png");
    sf::Sprite sprite1(texture1);
    sprite1.setPosition(0, 0);

    texture2.loadFromFile("../2.png");
    sf::Sprite sprite2(texture2);
    sprite2.setPosition(0, 0);

    texture3.loadFromFile("../3.png");
    sf::Sprite sprite3(texture3);
    sprite3.setPosition(0, 0);
    pic0d = sprite3.getPosition().x;

    d3.loadFromFile("../3.png");
    sf::Sprite s3(d3);
    s3.setPosition(592, 0);
    pic0 = s3.getPosition().x;

    texture4.loadFromFile("../4.png");
    sf::Sprite sprite4(texture4);
    sprite4.setPosition(0, 0);
    pic1d = sprite4.getPosition().x;

    d4.loadFromFile("../4.png");
    sf::Sprite s4(d4);
    s4.setPosition(592, 0);
    pic1 = s4.getPosition().x;


    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }




        if (pic0 >= 0) {
            pic0 -= 0.4;
            s3.setPosition(pic0, 0);
        }
        else {
            pic0 = 592;
            s3.setPosition(pic0, 0);
        }
        if (pic0d >= -592) {
            pic0d -= 0.4;
            sprite3.setPosition(pic0d, 0);
        }
        else {
            pic0d = 0;
            sprite3.setPosition(pic0d, 0);
        }



        if (pic1 >= 0) {
            pic1 -= 0.8;
            s4.setPosition(pic1, 0);
        }
        else {
            pic1 = 592;
            s4.setPosition(pic1, 0);
        }
        if (pic1d >= -592) {
            pic1d -= 0.8;
            sprite4.setPosition(pic1d, 0);
        }
        else {
            pic1d = 0;
            sprite4.setPosition(pic1d, 0);
        }


        window.clear();
        window.draw(sprite1);
        window.draw(sprite2);



        window.draw(sprite3);
        window.draw(s3);

        window.draw(sprite4);
        window.draw(s4);

        window.display();

    }

    return EXIT_SUCCESS;
}
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;
Texture sff;
SoundBuffer sfult1;
Sound ko;
class ShadowFiend;

vector <ShadowFiend*> allsf;

class ShadowFiend {
public:
    Clock sfclock;
    float Timer = 0;
    Sound ult;
    Sprite sfs;
    Vector2f pos;
    void zxc() {
        Timer = sfclock.getElapsedTime().asSeconds();
        if (Timer >= 2.3) {
            ult.stop();

        }
    }
    ShadowFiend() {
        int x = (rand() % 1000) + 100;
        int y = (rand() % 550) + 50;
        pos = Vector2f(x, y);
        sfs.setTexture(sff);
        sfs.setPosition(pos);
        sfs.setScale(0.5, 0.5);
        allsf.push_back(this);
        ult.setBuffer(sfult1);
        ult.play();
        sfclock.restart();
    }
    ~ShadowFiend() {

        for (int i = 0; i < allsf.size(); i++) {
            if (allsf[i] == this) {
                allsf.erase(allsf.begin() + i);
            }
        }
    }

};
int main()
{
    
    srand(time(NULL));
    Vector2i m;

    sfult1.loadFromFile("sounds/sf.mp3");
    sff.loadFromFile("textures/sf.jpg");
    ko.setBuffer(sfult1);

    Sprite cross;
    Texture ch;
    ch.loadFromFile("textures/crosshair.png");
    cross.setTexture(ch);
    cross.setScale(0.08, 0.08);

    Sprite back;
    Texture bg;
    bg.loadFromFile("textures/mid.jpg");
    back.setTexture(bg);

    RenderWindow window(sf::VideoMode(1200, 630), "SFML works!");
    window.setMouseCursorVisible(false);
    ShadowFiend* sf1 = new ShadowFiend();
    
    while (window.isOpen())
    {
        
        m = Mouse::getPosition(window);
        cross.setPosition(m.x - 40, m.y - 40);
        window.setSize(Vector2u(1200,630));
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(back);
        window.draw(cross);
        window.display();
    }

    return 0;
}
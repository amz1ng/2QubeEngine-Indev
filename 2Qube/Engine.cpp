#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "fps.cpp"


using namespace sf;





/*
* �����������=======
* shape.setPosition(800, 500); ������ �������� ������������ �� ����������� , � ������ �������� �� ���������
* ��� �������� ������ ���� ��� ���� ������
* ��� �������� ����������� ���� ��� ����� ������
* ===================
*/











int main()
{
    //������
    Music music;
    music.openFromFile("audio/background.ogg");
    music.play();
    //����� ��� ������
    Font MainFont;
    MainFont.loadFromFile("fonts/Nevduplenysh.otf");
    //����� FPS
    Text FpsText("", MainFont, 35);
    FpsText.setPosition(17, 1);
    FPS fps;
    



    //������ ����
    RenderWindow window(sf::VideoMode(1600, 900), "2Qube");


 

    
    //������ ��������
    Texture groundTexture;
    groundTexture.loadFromFile("images/ground.png");

    //������ ����� ������
        Sprite groundSprite;
        //���������� ��������
        groundSprite.setTexture(groundTexture);
        //����������� � �������������
        groundSprite.setPosition(1, 650);
        groundSprite.setScale(1, 0.25f);

        //������ ��������
        Texture backgroundTexture;
        backgroundTexture.loadFromFile("images/background.jpg");

        //������ ����� ������
        Sprite backgroundSprite;
        //���������� ��������
        backgroundSprite.setTexture(backgroundTexture);
        //����������� � �������������
        backgroundSprite.setPosition(0, -430);
  
        //������ ��������
        Texture playerTexture;
        playerTexture.loadFromFile("images/player.png");

        //������ ����� ������
        Sprite playerSprite;
        //���������� ��������
        playerSprite.setTexture(playerTexture);
        //����������� � �������������
        playerSprite.setPosition(550, 555);
        playerSprite.setScale(0.1, 0.10f);





    //�������� ���
   /* CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(690,300);*/





    //������� ����
    while (window.isOpen())
    {

        fps.update();
        std::ostringstream ss;
        ss << fps.getFPS();
        FpsText.setString(ss.str() + " FPS");

     
        

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        //����������
        if (Keyboard::isKeyPressed(Keyboard::A)) { playerSprite.move(-0.7, 0); } //������ ���������� � ������������ =>��� �����
        if (Keyboard::isKeyPressed(Keyboard::D)) { playerSprite.move(0.7, 0); } //������ ���������� � ������������ =>��� ������
     











        
        window.clear();
        window.draw(groundSprite);
        window.draw(backgroundSprite);
        window.draw(playerSprite);
        window.draw(FpsText);
        window.display();
    }


    return 0;
}
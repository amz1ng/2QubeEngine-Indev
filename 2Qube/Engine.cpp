#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "fps.cpp"


using namespace sf;





/*
* Координация=======
* shape.setPosition(800, 500); Первый аргумент расположение по горизонтали , а второй аргумент по вертикали
* Чем значение высоты выше тем ниже обьект
* Чем значение горизонтали ниже тем левее обьект
* ===================
*/











int main()
{
    //Музыка
    Music music;
    music.openFromFile("audio/background.ogg");
    music.play();
    //Шрифт для текста
    Font MainFont;
    MainFont.loadFromFile("fonts/Nevduplenysh.otf");
    //Показ FPS
    Text FpsText("", MainFont, 35);
    FpsText.setPosition(17, 1);
    FPS fps;
    



    //Создал окно
    RenderWindow window(sf::VideoMode(1600, 900), "2Qube");


 

    
    //Создаю текстуру
    Texture groundTexture;
    groundTexture.loadFromFile("images/ground.png");

    //Создаю новый спрайт
        Sprite groundSprite;
        //Привязываю текстуру
        groundSprite.setTexture(groundTexture);
        //Масштабирую и позиционнирую
        groundSprite.setPosition(1, 650);
        groundSprite.setScale(1, 0.25f);

        //Создаю текстуру
        Texture backgroundTexture;
        backgroundTexture.loadFromFile("images/background.jpg");

        //Создаю новый спрайт
        Sprite backgroundSprite;
        //Привязываю текстуру
        backgroundSprite.setTexture(backgroundTexture);
        //Масштабирую и позиционнирую
        backgroundSprite.setPosition(0, -430);
  
        //Создаю текстуру
        Texture playerTexture;
        playerTexture.loadFromFile("images/player.png");

        //Создаю новый спрайт
        Sprite playerSprite;
        //Привязываю текстуру
        playerSprite.setTexture(playerTexture);
        //Масштабирую и позиционнирую
        playerSprite.setPosition(550, 555);
        playerSprite.setScale(0.1, 0.10f);





    //Тестовый код
   /* CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(690,300);*/





    //Главный цикл
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



        //Управление
        if (Keyboard::isKeyPressed(Keyboard::A)) { playerSprite.move(-0.7, 0); } //первая координата Х отрицательна =>идём влево
        if (Keyboard::isKeyPressed(Keyboard::D)) { playerSprite.move(0.7, 0); } //первая координата Х положительна =>идём вправо
     











        
        window.clear();
        window.draw(groundSprite);
        window.draw(backgroundSprite);
        window.draw(playerSprite);
        window.draw(FpsText);
        window.display();
    }


    return 0;
}

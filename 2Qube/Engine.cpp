/*
* Engine.cpp
* Вы просматриваете исходники 2D движка 2Qube  и можете свободно их использовать
* --AMAZING
* 
*/




#include <SFML/Graphics.hpp>
//#include "imgui/imgui.h"
//#include "imgui/imgui-SFML.h"
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






FPS fps;
//Сорздаю окно
RenderWindow window(VideoMode(1600, 900), "2Qube");




//Сценв 1 Главная сцена
int Scene1()
{
   /* ImGui::SFML::Init(window);*/
    //Отчистка экрана
    window.clear();
    //Шрифт для текста
    Font MainFont;
    MainFont.loadFromFile("fonts/Nevduplenysh.otf");
    Texture groundTexture;
    Texture playerTexture;
    Sprite playerSprite;
    Texture backgroundTexture;
    Sprite backgroundSprite;
    Sprite groundSprite;
    Clock deltaClock;
    //Музыка
    Music music;
    music.openFromFile("audio/background.ogg");
    music.play();
    
 
    //Показ FPS
    Text FpsText("", MainFont, 35);
    FpsText.setPosition(17, 1);
    
    //Загружаю текстуру пола
    groundTexture.loadFromFile("images/ground.png");

 

        //Привязываю текстуру
    groundSprite.setTexture(groundTexture);
    //Масштабирую и позиционнирую
    groundSprite.setPosition(1, 650);
    groundSprite.setScale(1, 0.25f);

    
    //Загружаю текстуру фона
    backgroundTexture.loadFromFile("images/background.jpg");

  

    //Привязываю текстуру
    backgroundSprite.setTexture(backgroundTexture);
    //Масштабирую и позиционнирую
    backgroundSprite.setPosition(0, -430);

    //Загружаю текстуру игрока
    playerTexture.loadFromFile("images/player.png");

 

    //Привязываю текстуру
    playerSprite.setTexture(playerTexture);
    //Масштабирую и позиционнирую
    playerSprite.setPosition(550, 555);
    playerSprite.setScale(0.1, 0.10f);

    //Главнфй цикл
    while (window.isOpen())
    {
        //Выволд FPS
        fps.update();
        std::ostringstream ss;
        ss << fps.getFPS();
        FpsText.setString(ss.str() + " FPS");




        sf::Event event;
        while (window.pollEvent(event))
        {
          /*  ImGui::SFML::ProcessEvent(event);*/
            if (event.type == sf::Event::Closed)
                window.close();
        }



        //Управление
        if (Keyboard::isKeyPressed(Keyboard::A)) { playerSprite.move(-0.7, 0); } //первая координата Х отрицательна =>идём влево
        if (Keyboard::isKeyPressed(Keyboard::D)) { playerSprite.move(0.7, 0); } //первая координата Х положительна =>идём вправо



     /*   ImGui::SFML::Update(window, deltaClock.restart());*/







        // Очистка экрана и вывод обьектов
        window.clear();
        window.draw(groundSprite);
        window.draw(backgroundSprite);
        window.draw(playerSprite);
        window.draw(FpsText);
        /*ImGui::SFML::Render(window); */
        window.display();
    }

    return 0;
}


//Сцена 2 Меню
int Scene2()
{
  /*  ImGui::SFML::Init(window);*/
    //Отчистка экрана
    window.clear();
    RectangleShape buttonplay(Vector2f(200, 50));
    buttonplay.setPosition(450, 450);
    //Шрифт для текста
    Font MainFont;
    MainFont.loadFromFile("fonts/Nevduplenysh.otf");
    //Текст на экране
    Text Title("2Qube Test Game", MainFont, 150);
    //Позиционирую
    Title.setPosition(350, 1);
    //Текст для FPS
    Text FpsText("", MainFont, 35);
    //Создаю текстуру фона меню
    Texture backgroundTexture;
    //Загружаю
    backgroundTexture.loadFromFile("images/background.jpg");

    //Создаю новый спрайт
    Sprite backgroundSprite;
    //Привязываю текстуру
    backgroundSprite.setTexture(backgroundTexture);
    Clock deltaClock;




    //Главный цикл
    while (window.isOpen())
    {
        //Вывод FPS
        fps.update();
        std::ostringstream ss;
        ss << fps.getFPS();
        FpsText.setString(ss.str() + " FPS");


     

        sf::Event event;
        while (window.pollEvent(event))
        {
           /* ImGui::SFML::ProcessEvent(event);*/
            if (event.type == sf::Event::Closed)
                window.close();
        }
       /* ImGui::SFML::Update(window, deltaClock.restart());*/



        //if (ImGui::Button("Update window title")) {
        //    // этот код выполняется, когда юзер жмёт на кнопку
        //    // здесь можно было бы написать 
        //    // if(ImGui::InputText(...))

        //}



         //Очистка экрана и вывод обьектов
        window.clear();
        window.draw(backgroundSprite);
        window.draw(FpsText);
        window.draw(Title);
   
       // window.draw(buttonplay);
      /*  ImGui::SFML::Render(window);*/
        window.display();
    }
    return 0;
}




int main()
{
    //Вызов сцен
 /* Scene1();*/    //Главная сцена
    Scene2();
  return 0;
}



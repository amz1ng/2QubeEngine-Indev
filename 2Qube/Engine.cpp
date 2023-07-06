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






//Переменная просчета FPS
FPS fps;
//Создаю окно с расширением 1600 на 900 и задаю название 2Qube
RenderWindow window(VideoMode(1600, 900), "2Qube");




//Сценв 1 Главная сцена
int Scene1()
{
   /* ImGui::SFML::Init(window);*/
    //Отчистка экрана
    window.clear();
    

    //Тут создаю переменные этой сцены
    //===========================================================
    //Шрифт для текста
    Font MainFont;
    //Загружаю шрифт
    MainFont.loadFromFile("fonts/Nevduplenysh.otf");
    //Создаю текстуру пола
    Texture groundTexture;
    //Создаю текстуру игрока
    Texture playerTexture;
    //Создаю спрайт игрока
    Sprite playerSprite;
    //Создаю текстуру фона
    Texture backgroundTexture;
    //Создаю спрайт фона
    Sprite backgroundSprite;
    //Создаю спрайт земли
    Sprite groundSprite;
    //Время
    Clock deltaClock;
    //Переменная типа Text , в которой будем храниться и выводиться FPS
    Text FpsText("", MainFont, 35);
    //Музыка
    Music music;
    //===========================================================
    


    //Здесь всё подгружаю
    //===========================================================
    //Подгружаю музыку
    music.openFromFile("audio/background.ogg");
    //Загружаю текстуру пола
    groundTexture.loadFromFile("images/ground.png");
    //Загружаю текстуру фона
    backgroundTexture.loadFromFile("images/background.jpg");
    //Загружаю текстуру игрока
    playerTexture.loadFromFile("images/player.png");
    //===========================================================
   
  
    //Здесь все позиционирую и масштабирую
    //===========================================================
    //Позиционирую текст для вывода FPS
    FpsText.setPosition(17, 1);
    //Масштабирую и позиционнирую пол
    groundSprite.setPosition(1, 650);
    groundSprite.setScale(1, 0.25f);
    //Позиционнирую фон
    backgroundSprite.setPosition(0, -430);
    //Позиционнирую и масштабирую игрока
    playerSprite.setPosition(550, 555);
    playerSprite.setScale(0.1, 0.10f);
    //===========================================================

    //Здесь привязываю текстуры к спрайтам
    //===========================================================
    //Привязываю текстуру пола
    groundSprite.setTexture(groundTexture);
    //Привязываю текстуру фона
    backgroundSprite.setTexture(backgroundTexture);
    //Привязываю текстуру игрока
    playerSprite.setTexture(playerTexture);
    
    

    //Главный цикл
    while (window.isOpen())
    {
        //Просчет FPS
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





        //Проигрываю музыку
        music.play();

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



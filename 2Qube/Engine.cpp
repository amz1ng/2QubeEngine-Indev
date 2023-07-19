#include <SFML/Graphics.hpp>
//#include "imgui/imgui.h"
//#include "imgui/imgui-SFML.h"
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "fps.cpp"
//#include "GUI/button.hpp"
#include "framework/Fube.h"
#include "map/map.h"


using namespace sf;
using namespace std;


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
extern RenderWindow window(VideoMode(1600, 900), "2Qube");


int Scene0()
{
 //Отчистка экрана
    window.clear(Color(66, 170, 255));
    //Тут создаю переменные этой сцены
    //===========================================================
    //Шрифт для текста
    Font MainFont;
    //Текст для FPS
    Text FpsText("", MainFont, 35);
    Clock deltaClock;
    //Создаю текстуру игрока
    Texture playerTexture2;
    //Создаю спрайт игрока
    Sprite playerSprite2;
    //Объект изображения для карты
    Image map_image;
    //Текстура карты
    Texture map;
    //Создаём спрайт для карты
    Sprite s_map;
    View view = window.getView();
   // View view = window.getView

    //===========================================================

    //Здесь всё подгружаю
    //===========================================================
     
    //Загружаю шрифт
    MainFont.loadFromFile("fonts/Nevduplenysh.otf");
    //Загружаем файл для карты
    map_image.loadFromFile("images/map.png");
    //Заряжаем текстуру картинкой
    map.loadFromImage(map_image);
    //Загркжаю текстуру игрока
    playerTexture2.loadFromFile("images/player.png");
    //===========================================================

    //Здесь привязываю текстуры к спрайтам
    //===========================================================
    //Привязываю текстуру карты к спрайту
    s_map.setTexture(map);
    //Привязываю текстуру игрока к спрайту
    playerSprite2.setTexture(playerTexture2);
    //===========================================================
     
    //Здесь все позиционирую и масштабирую
    //===========================================================
    //Позиционнирую и масштабирую игрока
    playerSprite2.setPosition(550, 765);
    playerSprite2.setScale(0.1, 0.10f);
    //===========================================================

    //Главный цикл
    while (window.isOpen())
    {
    

        //Вывод FPS
        fps.update();
        std::ostringstream ss;
        ss << fps.getFPS();
        FpsText.setString(ss.str() + " FPS");


        //Управление
        if (Keyboard::isKeyPressed(Keyboard::A)) { playerSprite2.move(-0.7, 0); } //первая координата Х отрицательна =>идём влево
        if (Keyboard::isKeyPressed(Keyboard::D)) { playerSprite2.move(0.7, 0); } //первая координата Х положительна =>идём вправо



        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();


           
        }

        float playerPosX = playerSprite2.getPosition().x;
        float playerPosY = playerSprite2.getPosition().y;

       
        view.setCenter(playerPosX,420);
        window.setView(view);

        //Очистка экрана и вывод обьектов
        window.clear(Color(66, 170, 255));
        for (int i = 0; i < HEIGHT_MAP; i++)
            for (int j = 0; j < WIDTH_MAP; j++)
            {
                if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(96, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
                
                if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик


                s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

                window.draw(s_map);//рисуем квадратики на экран
            }
        window.draw(playerSprite2);
        window.display();
    }
    return 0;
}




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



    createText("Hello World", MainFont, 35);

    music.play();
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


        // Очистка экрана и вывод обьектов
        window.clear();
        window.draw(groundSprite);
        window.draw(backgroundSprite);
        window.draw(playerSprite);
        window.draw(FpsText);
        //   window.draw(test);


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

    //Создание кнопки
    RectangleShape ButtonShape(Vector2f(200, 50));
    ButtonShape.setPosition(450, 450);
    ButtonShape.setFillColor(sf::Color(100, 250, 50));
    //Текст на кнопке
    Text TextButton("Play", MainFont,50);
    //Позиционирую
   TextButton.setPosition(520, 445);

    //Главный цикл
    while (window.isOpen())
    {
        //Получаю и записываю позицию мышки в Вектор
        Vector2i mousePos = Mouse::getPosition(window);


        //Вывод FPS
        fps.update();
        std::ostringstream ss;
        ss << fps.getFPS();
        FpsText.setString(ss.str() + " FPS");


      


        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();


            //Слушатель кнопки Play
          if(event.type==Event::MouseButtonPressed)
              if(event.key.code==Mouse::Left)
                if (ButtonShape.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                   Scene0();
                   
                }


        }
      
     


        //Очистка экрана и вывод обьектов
        window.clear();
        window.draw(backgroundSprite);
        window.draw(FpsText);
        window.draw(ButtonShape);
        window.draw(Title);
        window.draw(TextButton);

        window.display();
    }
    return 0;
}








int main()
{
    //Вызов сцен
 /* Scene1(); */   //Главная сцена
    Scene2();
    return 0;
}

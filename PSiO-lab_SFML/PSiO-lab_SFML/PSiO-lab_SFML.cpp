#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

int main() {
    // create the window
    const float WindowLenght = 800;
    const float WindowWidth = 600;
    sf::RenderWindow window(sf::VideoMode(WindowLenght, WindowWidth), "My window");
    
    // create some shapes
    sf::CircleShape circle(100.0f);
    circle.setPosition(100.0f, 300.0f);
    circle.setFillColor(sf::Color(100, 250, 50));

    
    const float rectangle_velocity_x = 10.f;
    const float rectangle_velocity_y = 15.f;
    const float rectangle_angular_velocity = 0.01f;
    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));
    //rectangle.move(rectangle_velocity_x,rectangle_velocity_y);


    
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);


    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen()) {
        
        sf::Time elapsed = clock.getElapsedTime();
        float lastTime = 0;
       
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased);
                //elapsed = clock.restart();
        }
        
        float currentTime = clock.restart().asMicroseconds();
       /* float fps = 1.f / (currentTime - lastTime);
        lastTime = currentTime;*/
        
        sf::Vector2f speed(rectangle_velocity_x, rectangle_velocity_y);//velocity of rectangle
        float distance_x = speed.x / currentTime;//distance= speed/time;
        float distance_y = speed.y / currentTime;
        
        rectangle.move(distance_x,distance_y);
        rectangle.rotate(rectangle_angular_velocity);
       
        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();
        if (rectangle.getPosition().x <= 0.f)
        {
            rectangle.move(distance_x, distance_y);

            rectangle.rotate(rectangle_angular_velocity);
            std::cout << "collision";
        }
       if (rectangle.getPosition().y <= 0.f)
        {
            rectangle.move(distance_x,distance_y);

            rectangle.rotate(rectangle_angular_velocity);
            //std::cout << "collision";
        }
       if (rectangle.getPosition().x + rectangle_bounds.width >= window.getSize().x);
        {
            rectangle.move(distance_x, distance_y);

            rectangle.rotate(rectangle_angular_velocity);
            std::cout << "collision" << std::endl;
        }
        if (rectangle.getPosition().y + rectangle_bounds.height >= window.getSize().y);
        {
            rectangle.move(distance_x, distance_y);

            rectangle.rotate(rectangle_angular_velocity);
            std::cout << "collision";
        }
        
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);
      //std::cout << " " << distance_x << " " << distance_y << std::endl;
       //std::cout << fps << std::endl;
        // end the current frame
        window.display();
    }

    return 0;
}
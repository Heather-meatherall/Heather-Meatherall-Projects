#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1940, 1080), "Screen Saver");
    window.setFramerateLimit(60); //sets the game loop to run 60 times per second

    vector<Vertex> dots;
    vector<Vector2f> speeds;
    vector<Vertex> dots2;
    vector<Vector2f> speeds2;
    vector<Vertex> dots3;
    vector<Vector2f> speeds3;
    vector<Vertex> dots4;
    vector<Vector2f> speeds4;


    //octagon1 bottom right
    dots.push_back(Vertex(Vector2f(970, 540), Color::Magenta)); //center
    dots.push_back(Vertex(Vector2f(995, 465), Color::Magenta)); //point 1
    dots.push_back(Vertex(Vector2f(945, 465), Color::Magenta)); //point 2
    dots.push_back(Vertex(Vector2f(895, 515), Color::Magenta)); //point 3
    dots.push_back(Vertex(Vector2f(895, 565), Color::Magenta)); //point 4
    dots.push_back(Vertex(Vector2f(945, 615), Color::Magenta)); //point 5
    dots.push_back(Vertex(Vector2f(995, 615), Color::Magenta)); //point 6
    dots.push_back(Vertex(Vector2f(1045, 565), Color::Magenta)); //point 7
    dots.push_back(Vertex(Vector2f(1045, 515), Color::Magenta)); //point 8
    dots.push_back(Vertex(Vector2f(995, 465), Color::Magenta)); //point 9 (same as point 1)


    speeds.push_back(Vector2f(2, 2));
    speeds.push_back(Vector2f(2, 2));
    speeds.push_back(Vector2f(2, 2));
    speeds.push_back(Vector2f(2, 2));
    speeds.push_back(Vector2f(2, 2));
    speeds.push_back(Vector2f(2, 2));
    speeds.push_back(Vector2f(2, 2));
    speeds.push_back(Vector2f(2, 2));
    speeds.push_back(Vector2f(2, 2));
    speeds.push_back(Vector2f(2, 2));
    speeds.push_back(Vector2f(2, 2));

    //octagon2 top left
    dots2.push_back(Vertex(Vector2f(970, 540), Color::Green)); //center
    dots2.push_back(Vertex(Vector2f(995, 465), Color::Green)); //point 1
    dots2.push_back(Vertex(Vector2f(945, 465), Color::Green)); //point 2
    dots2.push_back(Vertex(Vector2f(895, 515), Color::Green)); //point 3
    dots2.push_back(Vertex(Vector2f(895, 565), Color::Green)); //point 4
    dots2.push_back(Vertex(Vector2f(945, 615), Color::Green)); //point 5
    dots2.push_back(Vertex(Vector2f(995, 615), Color::Green)); //point 6
    dots2.push_back(Vertex(Vector2f(1045, 565), Color::Green)); //point 7
    dots2.push_back(Vertex(Vector2f(1045, 515), Color::Green)); //point 8
    dots2.push_back(Vertex(Vector2f(995, 465), Color::Green)); //point 9 (same as point 1)

    speeds2.push_back(Vector2f(-2, -2));
    speeds2.push_back(Vector2f(-2, -2));
    speeds2.push_back(Vector2f(-2, -2));
    speeds2.push_back(Vector2f(-2, -2));
    speeds2.push_back(Vector2f(-2, -2));
    speeds2.push_back(Vector2f(-2, -2));
    speeds2.push_back(Vector2f(-2, -2));
    speeds2.push_back(Vector2f(-2, -2));
    speeds2.push_back(Vector2f(-2, -2));
    speeds2.push_back(Vector2f(-2, -2));
    speeds2.push_back(Vector2f(-2, -2));

    //octagon3 top right
    dots3.push_back(Vertex(Vector2f(970, 540), Color::Yellow)); //center
    dots3.push_back(Vertex(Vector2f(995, 465), Color::Yellow)); //point 1
    dots3.push_back(Vertex(Vector2f(945, 465), Color::Yellow)); //point 2
    dots3.push_back(Vertex(Vector2f(895, 515), Color::Yellow)); //point 3
    dots3.push_back(Vertex(Vector2f(895, 565), Color::Yellow)); //point 4
    dots3.push_back(Vertex(Vector2f(945, 615), Color::Yellow)); //point 5
    dots3.push_back(Vertex(Vector2f(995, 615), Color::Yellow)); //point 6
    dots3.push_back(Vertex(Vector2f(1045, 565), Color::Yellow)); //point 7
    dots3.push_back(Vertex(Vector2f(1045, 515), Color::Yellow)); //point 8
    dots3.push_back(Vertex(Vector2f(995, 465), Color::Yellow)); //point 9 (same as point 1)

    speeds3.push_back(Vector2f(2, -2));
    speeds3.push_back(Vector2f(2, -2));
    speeds3.push_back(Vector2f(2, -2));
    speeds3.push_back(Vector2f(2, -2));
    speeds3.push_back(Vector2f(2, -2));
    speeds3.push_back(Vector2f(2, -2));
    speeds3.push_back(Vector2f(2, -2));
    speeds3.push_back(Vector2f(2, -2));
    speeds3.push_back(Vector2f(2, -2));
    speeds3.push_back(Vector2f(2, -2));
    speeds3.push_back(Vector2f(2, -2));

    //octagon4 bottom left
    dots4.push_back(Vertex(Vector2f(970, 540), Color::Cyan)); //center
    dots4.push_back(Vertex(Vector2f(995, 465), Color::Cyan)); //point 1
    dots4.push_back(Vertex(Vector2f(945, 465), Color::Cyan)); //point 2
    dots4.push_back(Vertex(Vector2f(895, 515), Color::Cyan)); //point 3
    dots4.push_back(Vertex(Vector2f(895, 565), Color::Cyan)); //point 4
    dots4.push_back(Vertex(Vector2f(945, 615), Color::Cyan)); //point 5
    dots4.push_back(Vertex(Vector2f(995, 615), Color::Cyan)); //point 6
    dots4.push_back(Vertex(Vector2f(1045, 565), Color::Cyan)); //point 7
    dots4.push_back(Vertex(Vector2f(1045, 515), Color::Cyan)); //point 8
    dots4.push_back(Vertex(Vector2f(995, 465), Color::Cyan)); //point 9 (same as point 1)

    speeds4.push_back(Vector2f(-2, 2));
    speeds4.push_back(Vector2f(-2, 2));
    speeds4.push_back(Vector2f(-2, 2));
    speeds4.push_back(Vector2f(-2, 2));
    speeds4.push_back(Vector2f(-2, 2));
    speeds4.push_back(Vector2f(-2, 2));
    speeds4.push_back(Vector2f(-2, 2));
    speeds4.push_back(Vector2f(-2, 2));
    speeds4.push_back(Vector2f(-2, 2));
    speeds4.push_back(Vector2f(-2, 2));
    speeds4.push_back(Vector2f(-2, 2));




    Clock cl;

    while (window.isOpen() && !Keyboard::isKeyPressed(Keyboard::Escape))     //the main game loop, exits if someone closes the window
    {
        //make the center of each ocatgon chnage colour every 20 seconds
        for (size_t i = 0; i < dots.size(); i++)
        {
            if (cl.getElapsedTime().asSeconds() / 17.8756 > 1)
            {
                dots[i].color = Color::Green;
                dots2[i].color = Color::Magenta;
                dots3[i].color = Color::Cyan;
                dots4[i].color = Color::Yellow;

                cl.restart();

            }
        }

        Event event; //creates an event object, events include mouse clicks, mouse movement, keyboard presses, etc..
        while (window.pollEvent(event)) //loop that checks for events
        {
            if (event.type == Event::Closed) //checks if window is closed
                window.close();
        }   //ends the event loop

        //moving octagon1
        for (size_t i = 0; i < dots.size(); i++)
        {
            dots[i].position = dots[i].position + speeds[i];
            //check boundaries
            if (dots[i].position.x > 1920) //left side
            {
                speeds[i].x = -speeds[i].x;
                dots[i].color = Color::Green;
            }
            if (dots[i].position.x < 0) //right side
            {
                speeds[i].x = -speeds[i].x;
                    dots[i].color = Color::Cyan;
            }
            if (dots[i].position.y > 1060) //bottom
            {
                speeds[i].y = -speeds[i].y;
                dots[i].color = Color::Yellow;
            }
            if (dots[i].position.y < 0) //top
            {
                speeds[i].y = -speeds[i].y;
                dots[i].color = Color::Magenta;
            }
        }

        //moving octagon2
        for (size_t i = 0; i < dots2.size(); i++)
        {
            dots2[i].position = dots2[i].position + speeds2[i];
            //check boundaries
            if (dots2[i].position.x > 1920) //left side
            {
                speeds2[i].x = -speeds2[i].x;
                dots2[i].color = Color::Magenta;
            }
            if (dots2[i].position.x < 0) //right side
            {
                speeds2[i].x = -speeds2[i].x;
                dots2[i].color = Color::Yellow;
            }
            if (dots2[i].position.y > 1060) //bottom
            {
                speeds2[i].y = -speeds2[i].y;
                dots2[i].color = Color::Cyan;
            }
            if (dots2[i].position.y < 0) //top
            {
                speeds2[i].y = -speeds2[i].y;
                dots2[i].color = Color::Green;
            }
        }

        //moving octagon3
        for (size_t i = 0; i < dots3.size(); i++)
        {
            dots3[i].position = dots3[i].position + speeds3[i];
            //check boundaries
            if (dots3[i].position.x > 1920) //left side
            {
                speeds3[i].x = -speeds3[i].x;
                dots3[i].color = Color::Cyan;
            }
            if (dots3[i].position.x < 0) //right side
            {
                speeds3[i].x = -speeds3[i].x;
                dots3[i].color = Color::Green;
            }
            if (dots3[i].position.y > 1060) //bottom
            {
                speeds3[i].y = -speeds3[i].y;
                dots3[i].color = Color::Yellow;
            }
            if (dots3[i].position.y < 0) //top
            {
                speeds3[i].y = -speeds3[i].y;
                dots3[i].color = Color::Magenta;
            }
        }

        //moving octagon4
        for (size_t i = 0; i < dots4.size(); i++)
        {
            dots4[i].position = dots4[i].position + speeds4[i];
            //check boundaries
            if (dots4[i].position.x > 1920) //left side
            {
                speeds4[i].x = -speeds4[i].x;
                dots4[i].color = Color::Yellow;
            }
            if (dots4[i].position.x < 0) //right side
            {
                speeds4[i].x = -speeds4[i].x;
                dots4[i].color = Color::Magenta;
            }
            if (dots4[i].position.y > 1060) //bottom
            {
                speeds4[i].y = -speeds4[i].y;
                dots4[i].color = Color::Cyan;
            }
            if (dots4[i].position.y < 0) //top
            {
                speeds4[i].y = -speeds4[i].y;
                dots4[i].color = Color::Green;
            }
        }



        window.clear(); //clears the screen
        window.draw(&dots[0], dots.size(), TriangleFan);
        window.draw(&dots2[0], dots2.size(), TriangleFan);
        window.draw(&dots3[0], dots3.size(), TriangleFan);
        window.draw(&dots4[0], dots4.size(), TriangleFan);
        window.display();   //displays everything on the video card to the monitor
    }   //ends the game loop

    return 0;
}
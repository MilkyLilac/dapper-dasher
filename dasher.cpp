/*
  This project is "Dapper Dasher"
  from the C++ Fundamentals: Game
  Programming For Beginners course
  on GameDev.tv
*/

#include "raylib.h"

int main()
{
    // window dimensions

    const int win_height{380};
    const int win_width{512};

    // rectangle dimensions
    const int rec_width{50};
    const int rec_height{80};

    int posY{win_height - rec_height};
    int velocity{0};
    bool isInAir{};

    // accerlation due to gravity (pixels/frame)
    const int gravity{1};
    const int jumpVel{-22};

    // initializing window

    InitWindow(win_width, win_height, "Zoooooooooooooooom");

    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground (WHITE);
        
        DrawRectangle((win_width/2), posY, rec_width, rec_height, PINK);
        
        
        // checking if on grounds
        if (posY >= (win_height - rec_height) )
        {
            velocity = 0; 
            isInAir = false;
        }

        else
        {
            //apply gravity
            velocity += gravity;
            isInAir = true; 
        }

        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
          velocity += jumpVel;
        }

        //update positiion
        posY += velocity;


        EndDrawing();
    }
    
    CloseWindow();

};
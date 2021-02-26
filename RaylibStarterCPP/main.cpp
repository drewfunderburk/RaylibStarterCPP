/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>

unsigned int DrewHash(unsigned char* data)
{
    unsigned int hash = 0;

    // Loop through every char
    for (unsigned char* i = data; *i != '\0'; i++)
    {
        // Multiply char by two and assign to hash
        hash = *i * 2;
        // Raise i to the power of it's size and add to hash
        hash += pow(*i, sizeof(i));
    }
    // Return hash bit shifted 10 to the left
    return (hash << 10);
}

unsigned int ElfHash(unsigned char* data)
{
    unsigned int hash = 0;
    unsigned int x = 0;

    for (unsigned char* i = data; *i != '\0'; i++)
    {
        hash = (hash << 4) + *i;
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }

    return (hash & 0x7FFFFFFF);
}

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    unsigned int checkSum = 0;
    unsigned char* input = new unsigned char[0];
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update
        //----------------------------------------------------------------------------------

        std::cin >> input;
        checkSum = DrewHash(input);
        std::cout << input << " | " << checkSum << std::endl;

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GetColor(checkSum));

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
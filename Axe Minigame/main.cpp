#include "raylib.h"
int main()
{
    int width{900};
    int height{400};

    //Draw Circle
    int circleRadius{25};
    int circleY{height / 2};
    int circleX{0 + circleRadius};

    //Circle Edges
    int leftCircleX{circleX - circleRadius};
    int rightCircleX{circleX + circleRadius};
    int upperCircleY{circleY - circleRadius};
    int underCircleY{circleY + circleRadius};

    //Draw Rectangles
    int rectangleLength{70};

    int rectangleX1{200};
    int rectangleY1{0};

    int rectangleX2{400};
    int rectangleY2{0};

    int rectangleX3{600};
    int rectangleY3{0};
    
    //Rectangle Edges
    int leftRectangleX2{rectangleX2};
    int rightRectangleX2{rectangleX2 + rectangleLength};
    int upperRectangleY2{rectangleY2};
    int underRectangleY2{rectangleY2 + rectangleLength};

    int leftRectangleX1{rectangleX1};
    int rightRectangleX1{rectangleX1 + rectangleLength};
    int upperRectangleY1{rectangleY1};
    int underRectangleY1{rectangleY1 + rectangleLength};

    int leftRectangleX3{rectangleX3};
    int rightRectangleX3{rectangleX3 + rectangleLength};
    int upperRectangleY3{rectangleY3};
    int underRectangleY3{rectangleY3 + rectangleLength};

    //Player Variables
    int speed{5};

    //Obstacle Variables
    int direction1{2};
    int direction2{4};
    int direction3{3};

    //Game Condition
    bool isDead = (underRectangleY1 >= upperCircleY) && 
    (upperRectangleY1 <= underCircleY) && 
    (rightRectangleX1 >= leftCircleX) && 
    (leftRectangleX1 <= rightCircleX) || 
    (underRectangleY2 >= upperCircleY) && 
    (upperRectangleY2 <= underCircleY) && 
    (rightRectangleX2 >= leftCircleX) && 
    (leftRectangleX2 <= rightCircleX) ||
    (underRectangleY3 >= upperCircleY) && 
    (upperRectangleY3 <= underCircleY) && 
    (rightRectangleX3 >= leftCircleX) && 
    (leftRectangleX3 <= rightCircleX);

    //Open Window
    InitWindow(width,height,"Axe's Window");

    while (WindowShouldClose() != true)
    {
        BeginDrawing();
        ClearBackground(RED);

        //Starts Game Logic
        DrawCircle(circleX, circleY ,circleRadius, BLUE);
        DrawRectangle(rectangleX1, rectangleY1, rectangleLength, rectangleLength, GREEN);
        DrawRectangle(rectangleX2, rectangleY2, rectangleLength, rectangleLength, GREEN);
        DrawRectangle(rectangleX3, rectangleY3, rectangleLength, rectangleLength, GREEN);

        if(isDead)
        {
            DrawText("Game Over", width/2 - 100, height/2, 40, YELLOW);

        }
        else
        {
            //Update Actors Limits
            int leftCircleX = circleX - circleRadius;
            int rightCircleX = circleX + circleRadius;
            int upperCircleY = circleY - circleRadius;
            int underCircleY = circleY + circleRadius;

            int leftRectangleX1 = rectangleX1;
            int rightRectangleX1 = rectangleX1 + rectangleLength;
            int upperRectangleY1 = rectangleY1;
            int underRectangleY1 = rectangleY1 + rectangleLength;

            int leftRectangleX2 = rectangleX2;
            int rightRectangleX2 = rectangleX2 + rectangleLength;
            int upperRectangleY2 = rectangleY2;
            int underRectangleY2 = rectangleY2 + rectangleLength;

            int leftRectangleX3 = rectangleX3;
            int rightRectangleX3 = rectangleX3 + rectangleLength;
            int upperRectangleY3 = rectangleY3;
            int underRectangleY3 = rectangleY3 + rectangleLength;

            //Update Collision with Obstacle
            isDead = (underRectangleY1 >= upperCircleY) && 
                    (upperRectangleY1 <= underCircleY) && 
                    (rightRectangleX1 >= leftCircleX) && 
                    (leftRectangleX1 <= rightCircleX) || 
                    (underRectangleY2 >= upperCircleY) && 
                    (upperRectangleY2 <= underCircleY) && 
                    (rightRectangleX2 >= leftCircleX) && 
                    (leftRectangleX2 <= rightCircleX) ||
                    (underRectangleY3 >= upperCircleY) && 
                    (upperRectangleY3 <= underCircleY) && 
                    (rightRectangleX3 >= leftCircleX) && 
                    (leftRectangleX3 <= rightCircleX);

            //Move Circle
            if(IsKeyDown(KEY_D) && circleX < width - circleRadius)
                circleX += speed;
            else if(IsKeyDown(KEY_A) && circleX > 0 + circleRadius)
                circleX -= speed;

            //Move Rectangles
            rectangleY1 += direction1;
            rectangleY2 += direction2;
            rectangleY3 += direction3;

            if(rectangleY1 > height - rectangleLength || rectangleY1 < 0)
                direction1 = -direction1;

            if(rectangleY2 > height - rectangleLength || rectangleY2 < 0)
            direction2 = -direction2;

            if(rectangleY3 > height - rectangleLength || rectangleY3 < 0)
            direction3 = -direction3;
        }

        EndDrawing();
    }
}
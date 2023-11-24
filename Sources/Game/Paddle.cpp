#include "Paddle.h"

void Paddle::createPaddle(float x, float y, float w, float h, sf::Color color, float speed, int gameWidth)
{
   paddlePosition.x = x;
   paddlePosition.y = y;
   paddleSize.x = w;
   paddleSize.y = h;
   paddleColor = color;
   paddleSpeed = speed;
   paddleDirection = 2;
   paddleShape.setSize(paddleSize);
   paddleShape.setFillColor(paddleColor);
   paddleShape.setPosition(paddlePosition); 
   paddleGameWidth = gameWidth;
}
sf::FloatRect Paddle::getPaddlePosition()
{
   return paddleShape.getGlobalBounds();
}
sf::RectangleShape Paddle::getPaddleShape()
{
   return paddleShape;
}
void Paddle::paddleMove(int direction)
{
   paddleDirection = direction;
}
void Paddle::updatePaddlePosition()
{
   if(paddleDirection == 0 && getPaddlePosition().left > 0) //Gauche
   {
      paddlePosition.x -= paddleSpeed; 
   }
   else if(paddleDirection == 1 && getPaddlePosition().left + getPaddlePosition().width < paddleGameWidth)//Droite
   {
      paddlePosition.x += paddleSpeed;
   }
   else if(paddleDirection == 2)//Stop
   {
      paddlePosition.x = paddlePosition.x;
   }
   paddleShape.setPosition(paddlePosition);
}
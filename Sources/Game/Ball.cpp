#include "Ball.h"

void Ball::createBall(float x, float y, float w, float h, sf::Color color, float speedX, float speedY)
{
   initialX = x;
   initialY = y;
   ballPosition.x = x;
   ballPosition.y = y;
   ballSize.x = w;
   ballSize.y = h;
   ballColor = color;
   ballSpeedX = speedX;
   ballSpeedY = speedY;
   ballShape.setSize(ballSize);
   ballShape.setFillColor(ballColor);
   ballShape.setPosition(ballPosition);
}
sf::FloatRect Ball::getBallPosition()
{
   return ballShape.getGlobalBounds();
}
sf::RectangleShape Ball::getBallShape()
{
   return ballShape;
}
void Ball::onCollisionDetected(int type)
{
   switch(type)
   {
      case 0: //Collision avec le bas de l'écran
      {
         ballPosition.x = initialX;
         ballPosition.y = initialY;
         ballSpeedX = -ballSpeedX;
         ballSpeedY = -ballSpeedY;
         break;
      }
      case 1: //Collision avec le haut du paddle
      {
         ballSpeedX = ballSpeedX;
         ballSpeedY = -ballSpeedY;
         break;
      }
      case 2: //Collision avec une brique
      {
         ballSpeedX = ballSpeedX;
         ballSpeedY = -ballSpeedY;
         break;
      }
      case 3: //Collision avec le haut de l'écran (si dégagé)
      {
         ballSpeedX = ballSpeedX; 
         ballSpeedY = -ballSpeedY;
         break;
      }
      case 4: //Collision avec la gauche ou la droite de l'écran
      {
         ballSpeedX = -ballSpeedX;
         ballSpeedY = ballSpeedY;
      }
      default: break;
   }
}
void Ball::updateBallPosition()
{
   ballPosition.x += ballSpeedX;
   ballPosition.y += ballSpeedY;
   ballShape.setPosition(ballPosition);
}
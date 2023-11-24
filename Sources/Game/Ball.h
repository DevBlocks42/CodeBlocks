#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

class Ball
{
   private:
      sf::Vector2f ballPosition;
      sf::Vector2f ballSize;
      sf::Color ballColor;
      sf::RectangleShape ballShape;
      float ballSpeedX;
      float ballSpeedY;
      float initialX;
      float initialY;
   public:
      void createBall(float x, float y, float w, float h, sf::Color color, float speedX, float speedY);
      sf::FloatRect getBallPosition();
      sf::RectangleShape getBallShape();
      void onCollisionDetected(int type);
      void updateBallPosition();
   
};

#endif
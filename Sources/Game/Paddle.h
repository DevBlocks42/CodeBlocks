#ifndef PADDLE_H_INCLUDED
#define PADDLE_H_INCLUDED

class Paddle
{
   private:
      sf::Vector2f paddlePosition;
      sf::Vector2f paddleSize;
      sf::Color paddleColor;
      sf::RectangleShape paddleShape;
      float paddleSpeed;
      int paddleDirection;
      int paddleGameWidth;
   public:
      void createPaddle(float x, float y, float w, float h, sf::Color color, float speed, int gameWidth);
      sf::FloatRect getPaddlePosition();
      sf::RectangleShape getPaddleShape();
      void paddleMove(int direction);
      void updatePaddlePosition();
};

#endif
#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

class Block
{
   private:
      sf::Vector2f blockPosition;
      sf::Vector2f blockSize;
      sf::RectangleShape blockShape;
      int blockHealth;
      bool isAlive;
   public:
      Block(int x, int y, int w, int h, sf::Color color, int health);
      sf::FloatRect getBlockPosition();
      sf::RectangleShape getBlockShape();
      bool isBlockAlive();
      void onCollisionDetected();
      void destroyBlock();
};

#endif
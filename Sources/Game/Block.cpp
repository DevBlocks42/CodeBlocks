#include "Block.h"

Block::Block(int x, int y, int w, int h, sf::Color color, int health)
{
   isAlive = true;
   blockPosition.x = x;
   blockPosition.y = y;
   blockSize.x = w;
   blockSize.y = h;
   blockHealth = health;
   blockShape.setSize(blockSize);
   blockShape.setFillColor(color);
   blockShape.setPosition(blockPosition);
}
sf::FloatRect Block::getBlockPosition()
{
   return blockShape.getGlobalBounds();
}
sf::RectangleShape Block::getBlockShape()
{
   return blockShape;
}
bool Block::isBlockAlive()
{
   return isAlive;
}
void Block::onCollisionDetected()
{
   blockHealth--;
   if(blockHealth <= 0)
   {
      destroyBlock(); 
   }  
}
void Block::destroyBlock()
{
   isAlive = false;
   blockPosition.x = - 200;
   blockPosition.y = - 200;
   blockSize.x = 0;
   blockSize.y = 0;
   blockShape.setSize(blockSize);
   blockShape.setPosition(blockPosition);
}
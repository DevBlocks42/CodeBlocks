#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Paddle.cpp"
#include "Ball.cpp"
#include "Block.cpp"

class Game
{
   private:
      int gameWidth;
      int gameHeight;
      sf::String gameTitle;
      sf::RenderWindow gameWindow;
      int gameMaxBlocks;
      int gameBlockWidth;
      int gameBlockHeight;
      sf::Texture gameBackgroundTexture;
      sf::Sprite gameBackgroundSprite;
      Paddle paddleObject;
      Ball ballObject;
      std::vector<Block> blockArray;
   public:
      Game(int width, int height, sf::String title, int maxBlocks, int blockWidth, int blockHeight);
      sf::Color getRandomColor();
      int getRandomBlockHealth();
      void setRandomBackgroundSprite();
      void initGameObjects();
      void gameUpdate(); 
      void eventUpdate();
      void renderUpdate();
      void collisionUpdate();
      
};

#endif
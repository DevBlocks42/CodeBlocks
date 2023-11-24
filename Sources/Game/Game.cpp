#include "Game.h"
#include <iostream>

Game::Game(int width, int height, sf::String title, int maxBlocks, int blockWidth, int blockHeight)
{
   srand(time(0));
   gameWidth = width;
   gameHeight = height;
   gameTitle = title;
   gameMaxBlocks = maxBlocks;
   gameBlockWidth = blockWidth;
   gameBlockHeight = blockHeight;
   gameWindow.create(sf::VideoMode(gameWidth, gameHeight), gameTitle);
   gameWindow.setVerticalSyncEnabled(true);
   setRandomBackgroundSprite();
   initGameObjects();
   gameUpdate();
}
void Game::setRandomBackgroundSprite()
{
   int backgroundIdentifier = rand() % 3 + 1;
   std::cout << backgroundIdentifier << std::endl;
   switch(backgroundIdentifier)
   {
      case 1:
      {
         gameBackgroundTexture.loadFromFile("../../Ressources/Images/background_sky.png");
         break;
      }
      case 2:
      {
         gameBackgroundTexture.loadFromFile("../../Ressources/Images/background_city.jpg");
         break;
      }
      case 3:
      {
         gameBackgroundTexture.loadFromFile("../../Ressources/Images/background_desert.jpg");
         break;
      }
      default: break;
   }
   gameBackgroundTexture.setRepeated(false);
   gameBackgroundSprite.setTexture(gameBackgroundTexture);
   gameBackgroundSprite.setTextureRect(sf::IntRect(0, 0, gameWidth, gameHeight));
}
sf::Color Game::getRandomColor()
{
   int colorIdentifier = rand() % 8;
   sf::Color color;
   switch(colorIdentifier)
   {
      case 0:
      {
         color = sf::Color::Black; 
         break;
      }
      case 1:
      {
         color = sf::Color::White; 
         break;
      }
      case 2:
      {
         color = sf::Color::Red; 
         break;
      }
      case 3:
      {
         color = sf::Color::Green; 
         break;
      }
      case 4:
      {
         color = sf::Color::Blue; 
         break;
      }
      case 5:
      {
         color = sf::Color::Yellow; 
         break;
      }
      case 6:
      {
         color = sf::Color::Magenta; 
         break;
      }
      case 7:
      {
         color = sf::Color::Cyan; 
         break;
      }
      default: break;
   }
   return color;
}
int getRandomBlockHealth()
{
   int health = rand() % 2 + 1;
   return health;
}
void Game::initGameObjects()
{
   blockArray.reserve(gameMaxBlocks);
   for(int i = 0; i < gameMaxBlocks; i++)
   {
      for(int y = 0; y < gameHeight / 2; y+=gameBlockHeight)
      {
         for(int x = 0; x < gameWidth; x+=gameBlockWidth)
         {
            Block block(x, y, gameBlockWidth, gameBlockHeight, getRandomColor(), 3);
            blockArray.push_back(block);
         }
      }
   }
   paddleObject.createPaddle(gameWidth / 2 - 32, gameHeight - 128, 64, 32, sf::Color::Green, 15.0f, gameWidth); 
   ballObject.createBall(gameWidth / 2, gameHeight / 2, 32, 32, sf::Color::White, 5.0f, 5.0f);  
}
void Game::gameUpdate()
{
   while(gameWindow.isOpen())
   {
      paddleObject.updatePaddlePosition();
      ballObject.updateBallPosition();
      eventUpdate();
      collisionUpdate();
      renderUpdate();
   }  
}
void Game::eventUpdate()
{
   sf::Event event;
   while(gameWindow.pollEvent(event))
   {
      if(event.type == sf::Event::Closed)
      {
         gameWindow.close();
      }
      else if(event.type == sf::Event::KeyPressed)
      {
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //&& paddleObject.getPaddlePosition().left > 0)
         {
            paddleObject.paddleMove(0);
         }
         else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) //&& paddleObject.getPaddlePosition().left + paddleObject.getPaddlePosition().width < gameWidth)
         {
            paddleObject.paddleMove(1);
         }
      }
      else if(event.type == sf::Event::KeyReleased)
      {
         paddleObject.paddleMove(2);
      }
   }
}
void Game::renderUpdate()
{
   gameWindow.clear(sf::Color::Black);
   gameWindow.draw(gameBackgroundSprite);
   gameWindow.draw(paddleObject.getPaddleShape());
   gameWindow.draw(ballObject.getBallShape());
   for(int i = 0; i < gameMaxBlocks; i++)
   {
      if(blockArray[i].isBlockAlive())
      {
         gameWindow.draw(blockArray[i].getBlockShape());
      }
   }
   gameWindow.display();
}
void Game::collisionUpdate()
{
   for(int i = 0; i < gameMaxBlocks; i++)
   {
      if(ballObject.getBallPosition().intersects(blockArray[i].getBlockPosition()))
      {
         blockArray[i].onCollisionDetected();
         ballObject.onCollisionDetected(2);
      }
   }
   if(ballObject.getBallPosition().top - ballObject.getBallPosition().height >= gameHeight)
   {
      ballObject.onCollisionDetected(0);
      //TODO: Enlever une vie au joueur quand l'objet Player sera implémenté
      //TODO: Si le joueur n'a plus de vie, relancer la boucle et réinitialiser le niveau. 
   }
   else if(ballObject.getBallPosition().intersects(paddleObject.getPaddlePosition()) && ballObject.getBallPosition().top <= paddleObject.getPaddlePosition().top)
   {
      ballObject.onCollisionDetected(1);
   }
   else if(ballObject.getBallPosition().top < 0)
   {
      ballObject.onCollisionDetected(3);
   }
   else if(ballObject.getBallPosition().left < 0 || ballObject.getBallPosition().left + ballObject.getBallPosition().width > gameWidth)
   {
      ballObject.onCollisionDetected(4);
   }
}
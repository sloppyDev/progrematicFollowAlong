#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"

#include "FlappyTwitch/Flapper.h"
#include "FlappyTwitch/InputManager.h"
#include "FlappyTwitch/Pipe.h"
#include "FlappyTwitch/PipeManager.h"

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
   std::cout << "Hello, twitch!" << std::endl;
   srand(time(NULL));
   
   Engine engine;
   char windowName[] = "Twitch!";
   engine.Initialize(windowName);

   Sprite testSprite = Sprite("Assets/Art/Biplane.png", Vector3((float)(Engine::SCREEN_WIDTH / 2), (float)(Engine::SCREEN_HEIGHT / 2), 0));
   testSprite.SetScale(0.15f);


   Flapper player(testSprite);

   Pipe::Initialize();
   PipeManager pipeManager;

   InputManager im(&player);

   while (true)
   {
      engine.Update();
      player.Update();
      pipeManager.Update();
      bool isColliding = pipeManager.CheckCollision(player);
      //cout << (isColliding ? "COLLIDING!!!!!!" : ".....") << endl; 
      im.Update();

      engine.BeginRender();
      player.Render();
      pipeManager.Render();
      engine.EndRender();
   }

   return 0;
}

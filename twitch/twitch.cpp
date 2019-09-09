#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"

#include "FlappyTwitch/Flapper.h"
#include "FlappyTwitch/InputManager.h"
#include "FlappyTwitch/Pipe.h"

#include <iostream>
using namespace std;

int main()
{
   std::cout << "Hello, twitch!" << std::endl;
   
   Engine engine;
   char windowName[] = "Twitch!";
   engine.Initialize(windowName);

   Sprite testSprite = Sprite("Assets/Art/Biplane.png", Vector3((float)(Engine::SCREEN_WIDTH / 2), (float)(Engine::SCREEN_HEIGHT / 2), 0));
   testSprite.SetScale(0.15f);


   Flapper player(testSprite);

   Pipe::Initialize();
   Pipe pipe(Vector3(0, 0, 0));

   InputManager im(&player, &pipe);

   while (true)
   {
      engine.Update();
      player.Update();
      pipe.Update();
      bool isColliding = (RigidBody::IsColliding(player.GetRb(), pipe.GetTopRb()) || RigidBody::IsColliding(player.GetRb(), pipe.GetBotRb()));
      //cout << (isColliding ? "COLLIDING!!!!!!" : ".....") << endl; 
      im.Update();

      engine.BeginRender();
      player.Render();
      pipe.Render();
      engine.EndRender();
   }

   return 0;
}

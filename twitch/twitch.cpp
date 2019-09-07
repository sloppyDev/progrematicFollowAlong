#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"

#include <iostream>
using namespace std;

int main()
{
   std::cout << "Hello, twitch!" << std::endl;
   
   Engine engine;
   char windowName[] = "Twitch!";
   engine.Initialize(windowName);

   Sprite testSprite = Sprite("Assets/Art/Biplane.png", -100, -100);
   while (true)
   {
      engine.Update();
      testSprite.Update();

      engine.BeginRender();
      testSprite.Render();
      engine.EndRender();
   }

   return 0;
}

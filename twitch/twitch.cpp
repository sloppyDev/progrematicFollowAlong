#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"

#include "FlappyTwitch/Flapper.h"

#include <iostream>
using namespace std;

int main()
{
   std::cout << "Hello, twitch!" << std::endl;
   
   Engine engine;
   char windowName[] = "Twitch!";
   engine.Initialize(windowName);

   Sprite testSprite = Sprite("Assets/Art/Biplane.png", Vector3(-100, -100, 0));
   testSprite.SetScale(0.25);

   Flapper player(testSprite);

   while (true)
   {
      engine.Update();
      player.Update();

      //testSprite.SetPos((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY());

      if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
      {
         player.GetSprite().RotateBy(10);
      }

      if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT))
      {
         player.GetSprite().RotateBy(-10);
      }

      if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
      {
         player.GetSprite().RotateBy(10);
      }

      if (Keyboard::Key(GLFW_KEY_W))
      {
         player.GetRb().AddForce(Vector3(0, 2, 0));
      }

      if (Keyboard::Key(GLFW_KEY_S))
      {
         player.GetRb().AddForce(Vector3(0, -2, 0));
      }

      if (Keyboard::Key(GLFW_KEY_A))
      {
         player.GetRb().AddForce(Vector3(-200, 0, 0));
      }

      if (Keyboard::Key(GLFW_KEY_D))
      {
         player.GetRb().AddForce(Vector3(200, 0, 0));
      }

      engine.BeginRender();
      player.Render();
      engine.EndRender();
   }

   return 0;
}

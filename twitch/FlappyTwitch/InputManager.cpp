#include "InputManager.h"

InputManager::InputManager(Flapper* _flapper)
{
   flapper = _flapper;
}

InputManager::~InputManager()
{

}

void InputManager::Update()
{
   if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
   {
      flapper->Flap();
   }
}
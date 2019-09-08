#ifndef TWITCH_SPRITE
#define TWITCH_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"

#include <iostream>;
#include <string>;

using namespace std;

class Sprite
{
public:
   Sprite();
   Sprite(string imagePath);
   Sprite(string imagePath, float _xPos, float _yPos);
   ~Sprite();

   void Update();
   void Render();

   void MoveTo(float x, float y);
   void MoveBy(float x, float y);

   void MoveLeft();
   void MoveRight();
   void MoveUp();
   void MoveDown();

   void SpeedTo(float s);
   void SpeedBy(float s);

   void RotateTo(float _rot);
   void RotateBy(float _rot);

   void SetScale(float x);
   void SetScale(float x, float y);

private:
   Texture texture;
   float xPos{};
   float yPos{};
   float rot{};
   float xScale{};
   float yScale{};
   float speed{};

};

#endif

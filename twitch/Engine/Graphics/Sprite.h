#ifndef TWITCH_SPRITE
#define TWITCH_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../Math/Vector3.h"

#include <iostream>
#include <string>

using namespace std;

class Sprite
{
public:
   Sprite();
   Sprite(string imagePath);
   Sprite(string imagePath, Vector3 _pos);
   ~Sprite();

   void Update();
   void Render();

   void MoveTo(Vector3 vec);
   void MoveBy(Vector3 vec);

   void MoveLeft();
   void MoveRight();
   void MoveUp();
   void MoveDown();

   void SpeedTo(float s);
   void SpeedBy(float s);

   void RotateTo(float _rot);
   void RotateBy(float _rot);

   void SetScale(float x);
   void SetScale(Vector3 vec);

   void FlipHorizontal();
   void FlipVertical();

   Vector3* GetPos();
   float* GetRot();
   Vector3* GetScale();
   Vector3* GetSize();

private:
   Texture texture;

   Vector3 pos;
   float speed{};
   float rot{};
   Vector3 scale;
   Vector3 size;
};

#endif
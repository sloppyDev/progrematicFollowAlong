#ifndef TWITCH_FLAPPER
#define TWITCH_FLAPPER

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/RigidBody.h"
#include "../Engine/Math/Rectangle.h"

class Flapper
{
public:
   Flapper();
   Flapper(Sprite _sprite);
   ~Flapper();

   void Update();
   void Render();

   void Flap();

   Sprite& GetSprite();
   RigidBody& GetRb();

private:
   Sprite sprite;
   RigidBody rb;

   bool flapIsComplete;
   float maxFlapAngle;
   float minFlapAngle;
   float flapVel;
   float velAtFlap;
};

#endif

#include "Flapper.h"

#include "../Engine/Engine.h"
#include "../Engine/Math/Rectangle.h"

#include <iostream>

Flapper::Flapper()
{
   maxFlapAngle = 45;
   minFlapAngle = -70;
   flapVel = 1000;
   velAtFlap = 0;
   flapIsComplete = true;
}

Flapper::Flapper(Sprite _sprite) : Flapper()
{
   sprite = _sprite;

   Rectangle boundingRect = Rectangle();
   Vector3 sizeScale(0.8f, 0.6f, 1);
   boundingRect.SetSize(*sprite.GetSize() * *sprite.GetScale() * sizeScale);

   rb.Initialize(0.90f, -1.0f, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize(), boundingRect);

}

Flapper::~Flapper()
{

}

void Flapper::Update()
{
   sprite.Update();
   rb.Update();

   float rotAngle = maxFlapAngle * (rb.GetVel().y / flapVel);
   if (rotAngle < minFlapAngle)
   {
      rotAngle = minFlapAngle;
   }

   if (!flapIsComplete)
   {
      sprite.RotateBy(velAtFlap*0.0005f);
   }
   else
   {
      sprite.RotateTo(rotAngle);
   }

   if (*sprite.GetRot() >= rotAngle)
   {
      flapIsComplete = true;
   }
}

void Flapper::Render()
{
   sprite.Render();
   rb.Render(Vector3(0, 0, 0));
}

void Flapper::Flap()
{
   rb.SetVel(Vector3(0, flapVel, 0));
   flapIsComplete = false;
   velAtFlap = rb.GetVel().y;
}

Sprite& Flapper::GetSprite()
{
   return sprite;
}

RigidBody& Flapper::GetRb()
{
   return rb;
}
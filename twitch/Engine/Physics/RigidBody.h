#ifndef TWITCH_RIGIDBODY
#define TWITCH_RIGIDBODY

#include "../Math/Vector3.h"
#include "../Math/Rectangle.h"

class RigidBody
{
public:

   static bool IsColliding(const RigidBody& rbA, const RigidBody& rbbB);

   RigidBody();
   ~RigidBody();

   void Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size, Rectangle _boundingRect);

   void Update();
   void Render(Vector3 color);

   void AddForce(Vector3 force);
   void SetVel(Vector3 _vel);

   Vector3 GetVel();

private:
   Vector3* pos;
   float* rot;
   float lastRot;
   Vector3* scale;
   Vector3* size;

   float gravity;
   float friction;
   Vector3 vel;

   Rectangle boundingRect;
};

#endif
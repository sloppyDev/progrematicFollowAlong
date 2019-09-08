#ifndef TWITCH_RIGIDBODY
#define TWITCH_RIGIDBODY

#include "../Math/Vector3.h"

class RigidBody
{
public:
   RigidBody();
   ~RigidBody();

   void Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size);

   void Update();
   void Render(Vector3 color);

   void AddForce(Vector3 force);

private:
   Vector3* pos;
   float* rot;
   Vector3* scale;
   Vector3* size;

   float gravity;
   float friction;
   Vector3 vel;
};

#endif
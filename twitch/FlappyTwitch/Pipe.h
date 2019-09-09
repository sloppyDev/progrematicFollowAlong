#ifndef TWITCH_PIPE
#define TWITCH_PIPE

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/RigidBody.h"
#include "../Engine/Math/Vector3.h"

class Pipe
{
public:
   static Sprite* pipeSprite;
   static void Initialize();

   Pipe();
   Pipe(Vector3 _pos);
   ~Pipe();

   void SetGap(float _gap);

   void Update();
   void Render();

   void MoveTo(Vector3 vec);
   void MoveBy(Vector3 vec);

   RigidBody GetTopRb();
   RigidBody GetBotRb();

   float GetX();
   float GetWidth();

private:
   void UpdatePos();

   Sprite topSprite;
   Sprite botSprite;

   RigidBody topRb;
   RigidBody botRb;

   Vector3 pos;

   float gap;
   float speed;
};

#endif

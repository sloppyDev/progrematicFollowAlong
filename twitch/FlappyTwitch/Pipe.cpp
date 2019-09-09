#include "Pipe.h"
#include "../Engine/Math/Rectangle.h"
#include "../Engine/Math/Math.h"
#include "../Engine/Engine.h"

Sprite* Pipe::pipeSprite = NULL;

void Pipe::Initialize()
{
   pipeSprite = new Sprite("Assets/Art/Pipe.png");
   pipeSprite->SetScale(Vector3(0.1f, 0.35f, 1));
}

Pipe::Pipe()
{
   if (!pipeSprite)
   {
      cout << "Trying to instantiate a Pipe without having called the Initialize method!" << endl;
   }

   topSprite = Sprite(*pipeSprite);
   botSprite = Sprite(*pipeSprite);

   gap = 350;
   speed = 10;
}

Pipe::Pipe(Vector3 _pos) : Pipe()
{
   if (!pipeSprite)
   {
      return;
   }

   pos = _pos;

   UpdatePos();

   // Top Pipe
   Vector3 topPos = pos;

   topSprite.MoveTo(topPos);
   topSprite.FlipVertical();

   Rectangle topRect = Rectangle();
   topRect.SetSize(Vector3(Math::Abs(topSprite.GetSize()->x * topSprite.GetScale()->x), Math::Abs(topSprite.GetSize()->y * topSprite.GetScale()->y), 1));
   topRb = RigidBody();
   topRb.Initialize(0, 0, topSprite.GetPos(), topSprite.GetRot(), topSprite.GetScale(), topSprite.GetSize(), topRect);

   // Bottom Pipe
   Vector3 botPos = pos;
   botSprite.MoveTo(botPos);

   Rectangle botRect = Rectangle();
   botRect.SetSize(Vector3(Math::Abs(botSprite.GetSize()->x * botSprite.GetScale()->x), Math::Abs(botSprite.GetSize()->y * botSprite.GetScale()->y), 1));
   botRb = RigidBody();
   botRb.Initialize(0, 0, botSprite.GetPos(), botSprite.GetRot(), botSprite.GetScale(), botSprite.GetSize(), botRect);
}

Pipe::~Pipe()
{

}

void Pipe::Update()
{
   topSprite.MoveBy(Vector3(-speed * Engine::GetDt(), 0, 0));
   botSprite.MoveBy(Vector3(-speed * Engine::GetDt(), 0, 0));
   topRb.Update();
   botRb.Update();
}

void Pipe::Render()
{
   topSprite.Render();
   botSprite.Render();
   topRb.Render(Vector3(255,0,0));
   botRb.Render(Vector3(0,0,255));
}

void Pipe::MoveTo(Vector3 vec)
{
   pos = vec;
   UpdatePos();
}

void Pipe::MoveBy(Vector3 vec)
{
   pos = pos + vec;
   UpdatePos();
}

RigidBody Pipe::GetTopRb()
{
   return topRb;
}

RigidBody Pipe::GetBotRb()
{
   return botRb;
}

void Pipe::UpdatePos()
{
   Vector3 topPos = pos;
   topPos.y += (gap / 2) + Math::Abs(topSprite.GetSize()->y * topSprite.GetScale()->y) / 2;
   topSprite.MoveTo(topPos);

   Vector3 botPos = pos;
   botPos.y -= (gap / 2) + Math::Abs(botSprite.GetSize()->y * botSprite.GetScale()->y) / 2;
   botSprite.MoveTo(botPos);
}
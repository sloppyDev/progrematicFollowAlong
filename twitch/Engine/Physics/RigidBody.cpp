#include "RigidBody.h"
#include "../Engine.h"

RigidBody::RigidBody()
{
   friction = 1;
   gravity = 0;
}

RigidBody::~RigidBody()
{

}

void RigidBody::Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size)
{
   friction = _friction;
   gravity = _gravity;

   pos = _pos;
   rot = _rot;
   scale = _scale;
   size = _size;
}

void RigidBody::Update()
{
   vel.x *= friction;
   vel.y += gravity;

   *pos = *pos + (vel * Engine::GetDt());
}

void RigidBody::Render(Vector3 color)
{
   glLoadIdentity();

   // Translate -> Rotate -> Scale
   glTranslatef(pos->x, pos->y, pos->z);
   glRotatef(*rot, 0, 0, 1);
   glScalef(scale->x, scale->y, scale->z);

   // Rendering
   glColor4f(color.x, color.y, color.z, 1);
   glBegin(GL_LINES);
   {
      glVertex2i(0, 0);
      glVertex2i((int)size->x, 0);

      glVertex2i((int)size->x, 0);
      glVertex2i((int)size->x, (int)size->y);

      glVertex2i((int)size->x, (int)size->y);
      glVertex2i(0, (int)size->y);

      glVertex2i(0, (int)size->y);
      glVertex2i(0, 0);
   }
   glEnd();
}

void RigidBody::AddForce(Vector3 force)
{
   vel = vel + force;
}
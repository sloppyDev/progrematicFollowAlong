#include "RigidBody.h"
#include "../Engine.h"

#include "../Math/Math.h"

#include <vector>
using namespace std;

RigidBody::RigidBody()
{
   friction = 1;
   gravity = 0;
}

RigidBody::~RigidBody()
{

}

void RigidBody::Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size, Rectangle _boundingRect)
{
   friction = _friction;
   gravity = _gravity;

   pos = _pos;
   rot = _rot;
   lastRot = *rot;
   scale = _scale;
   size = _size;

   boundingRect = _boundingRect;
}

void RigidBody::Update()
{
   vel.x *= friction;
   vel.y += gravity;

   *pos = *pos + (vel * Engine::GetDt());

   if (lastRot != *rot)
   {
      boundingRect.lowLeftVertex  = Math::RotatePoint(boundingRect.lowLeftVertex, Vector3(0), *rot - lastRot);
      boundingRect.lowRightVertex = Math::RotatePoint(boundingRect.lowRightVertex, Vector3(0), *rot - lastRot);
      boundingRect.upLeftVertex   = Math::RotatePoint(boundingRect.upLeftVertex, Vector3(0), *rot - lastRot);
      boundingRect.upRightVertex  = Math::RotatePoint(boundingRect.upRightVertex, Vector3(0), *rot - lastRot);

      lastRot = *rot;
   }
}

void RigidBody::Render(Vector3 color)
{
   glLoadIdentity();

   // Translate
   glTranslatef(pos->x, pos->y, pos->z);

   // Rendering
   glColor4f(color.x, color.y, color.z, 1);
   glLineWidth(2.5);
   glBegin(GL_LINES);
   {
      glVertex2f(boundingRect.lowLeftVertex.x, boundingRect.lowLeftVertex.y);
      glVertex2f(boundingRect.lowRightVertex.x, boundingRect.lowRightVertex.y);

      glVertex2f(boundingRect.lowRightVertex.x, boundingRect.lowRightVertex.y);
      glVertex2f(boundingRect.upRightVertex.x, boundingRect.upRightVertex.y);

      glVertex2f(boundingRect.upRightVertex.x, boundingRect.upRightVertex.y);
      glVertex2f(boundingRect.upLeftVertex.x, boundingRect.upLeftVertex.y);

      glVertex2f(boundingRect.upLeftVertex.x, boundingRect.upLeftVertex.y);
      glVertex2f(boundingRect.lowLeftVertex.x, boundingRect.lowLeftVertex.y);
   }
   glEnd();
}

void RigidBody::AddForce(Vector3 force)
{
   vel = vel + force;
}

void RigidBody::SetVel(Vector3 _vel)
{
   vel = _vel;
}

Vector3 RigidBody::GetVel()
{
   return vel;
}

bool RigidBody::IsColliding(const RigidBody& rbA, const RigidBody& rbB)
{
   Rectangle rcA = rbA.boundingRect;
   Rectangle rcB = rbB.boundingRect;

   Vector3 aUR = rcA.upRightVertex + *rbA.pos;
   Vector3 aUL = rcA.upLeftVertex + *rbA.pos;
   Vector3 aLR = rcA.lowRightVertex + *rbA.pos;
   Vector3 aLL = rcA.lowLeftVertex + *rbA.pos;

   Vector3 bUR = rcB.upRightVertex + *rbB.pos;
   Vector3 bUL = rcB.upLeftVertex + *rbB.pos;
   Vector3 bLR = rcB.lowRightVertex + *rbB.pos;
   Vector3 bLL = rcB.lowLeftVertex + *rbB.pos;


   float aMax{};
   float aMin{};
   float bMax{};
   float bMin{};

   Vector3 axis1 = aUR - aUL;
   Vector3 axis2 = aUR - aLR;
   Vector3 axis3 = bUL - bLL;
   Vector3 axis4 = bUL - bUR;

   vector<Vector3> axes;
   axes.push_back(axis1);
   axes.push_back(axis2);
   axes.push_back(axis3);
   axes.push_back(axis4);
   axes.push_back(axis1);

   for (unsigned int i{ 0 }; i < axes.size(); i++)
   {
      Vector3 aUpRightProj  = Vector3::Project(aUR, axes[i]);
      Vector3 aUpLeftProj   = Vector3::Project(aUL, axes[i]);
      Vector3 aLowRightProj = Vector3::Project(aLR, axes[i]);
      Vector3 aLowLeftProj  = Vector3::Project(aLL, axes[i]);

      Vector3 bUpRightProj  = Vector3::Project(bUR, axes[i]);
      Vector3 bUpLeftProj   = Vector3::Project(bUL, axes[i]);
      Vector3 bLowRightProj = Vector3::Project(bLR, axes[i]);
      Vector3 bLowLeftProj  = Vector3::Project(bLL, axes[i]);

      float aUpRightScalar  = Vector3::Dot(aUpRightProj, axes[i]);
      float aUpLeftScalar   = Vector3::Dot(aUpLeftProj, axes[i]);
      float aLowRightScalar = Vector3::Dot(aLowRightProj, axes[i]);
      float aLowLeftScalar  = Vector3::Dot(aLowLeftProj, axes[i]);

      float bUpRightScalar  = Vector3::Dot(bUpRightProj, axes[i]);
      float bUpLeftScalar   = Vector3::Dot(bUpLeftProj, axes[i]);
      float bLowRightScalar = Vector3::Dot(bLowRightProj, axes[i]);
      float bLowLeftScalar  = Vector3::Dot(bLowLeftProj, axes[i]);

      vector<float> aScalars;
      aScalars.push_back(aUpRightScalar);
      aScalars.push_back(aUpLeftScalar);
      aScalars.push_back(aLowRightScalar);
      aScalars.push_back(aLowLeftScalar);
      aMax = Math::Max(aScalars);
      aMin = Math::Min(aScalars);

      vector<float> bScalars;
      bScalars.push_back(bUpRightScalar);
      bScalars.push_back(bUpLeftScalar);
      bScalars.push_back(bLowRightScalar);
      bScalars.push_back(bLowLeftScalar);
      bMax = Math::Max(bScalars);
      bMin = Math::Min(bScalars);

      if (!(bMin <= aMax && bMax >= aMin))
      {
         return false;
      }
   }
   return true;
}
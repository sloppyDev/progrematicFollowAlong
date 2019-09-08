#include "Sprite.h"
#include "../Engine.h"

Sprite::Sprite()
{
   pos = Vector3(0);
   rot = 0;
   speed = 100;
   texture = Texture();
}

Sprite::Sprite(string imagePath)
{
   texture = Texture(imagePath);
   pos = Vector3(0);
   rot = 0;
   speed = 100;
}

Sprite::Sprite(string imagePath, Vector3 vec)
{
   texture = Texture(imagePath);
   pos = vec;
   rot = 0;
   speed = 100;
}

Sprite::~Sprite()
{

}

void Sprite::Update()
{

}

void Sprite::Render()
{
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture.GetID());
   glLoadIdentity();

   // Translate -> Rotate -> Scale
   glTranslatef(pos.x, pos.y, 0);
   glRotatef(rot, 0, 0, 1);
   glScalef(scale.x, scale.y, 1);

   // Rendering
   glColor4f(1, 1, 1, 1);
   glBegin(GL_QUADS);
   glTexCoord2f(0, 0);   glVertex2i(0, 0);
   glTexCoord2f(1, 0);   glVertex2i(texture.GetWidth(), 0);
   glTexCoord2f(1, 1);   glVertex2i(texture.GetWidth(), texture.GetHeight());
   glTexCoord2f(0, 1);   glVertex2i(0, texture.GetHeight());
   glEnd();

   glDisable(GL_TEXTURE_2D);
}

void Sprite::MoveTo(Vector3 vec)
{
   pos = vec;
}

void Sprite::MoveBy(Vector3 vec)
{
   pos = pos + vec;
}

void Sprite::MoveLeft()
{
   pos.x -= (speed * Engine::GetDt());
}

void Sprite::MoveRight()
{
   pos.x += (speed * Engine::GetDt());
}

void Sprite::MoveUp()
{
   pos.y += (speed * Engine::GetDt());
}

void Sprite::MoveDown()
{
   pos.y -= (speed * Engine::GetDt());
}

void Sprite::SpeedTo(float s)
{
   speed = s;
}

void Sprite::SpeedBy(float s)
{
   speed += s;
}

void Sprite::RotateTo(float _rot)
{
   rot = rot;
}

void Sprite::RotateBy(float _rot)
{
   rot += _rot;
}

void Sprite::SetScale(float x)
{
   scale = Vector3(x);
}

void Sprite::SetScale(Vector3 vec)
{
   scale = vec;
}
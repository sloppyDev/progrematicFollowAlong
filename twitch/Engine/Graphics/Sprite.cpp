#include "Sprite.h"
#include "../Engine.h"

Sprite::Sprite()
{
   xPos = 0;
   yPos = 0;
   rot = 0;
   speed = 100;
   texture = Texture();
}

Sprite::Sprite(string imagePath)
{
   texture = Texture(imagePath);
   xPos = 0;
   yPos = 0;
   rot = 0;
   speed = 100;
}

Sprite::Sprite(string imagePath, float _xPos, float _yPos)
{
   texture = Texture(imagePath);
   xPos = _xPos;
   yPos = _yPos;
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
   glTranslatef(xPos, yPos, 0);
   glRotatef(rot, 0, 0, 1);
   glScalef(xScale, yScale, 1);

   // Rendering
   glColor4f(1, 1, 1, 1);
   glBegin(GL_QUADS);
   glTexCoord2f(0, 0);   glVertex2f(0, 0);
   glTexCoord2f(1, 0);   glVertex2f((float)texture.GetWidth(), 0);
   glTexCoord2f(1, 1);   glVertex2f((float)texture.GetWidth(), (float)texture.GetHeight());
   glTexCoord2f(0, 1);   glVertex2f(0, (float)texture.GetHeight());
   glEnd();

   glDisable(GL_TEXTURE_2D);
}

void Sprite::MoveTo(float x, float y)
{
   xPos = x;
   yPos = y;
}

void Sprite::MoveBy(float x, float y)
{
   xPos += x;
   yPos += y;
}

void Sprite::MoveLeft()
{
   xPos -= (speed * Engine::GetDt());
}

void Sprite::MoveRight()
{
   xPos += (speed * Engine::GetDt());
}

void Sprite::MoveUp()
{
   yPos += (speed * Engine::GetDt());
}

void Sprite::MoveDown()
{
   yPos -= (speed * Engine::GetDt());
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
   xScale = x;
   yScale = x;
}

void Sprite::SetScale(float x, float y)
{
   xScale = x;
   yScale = y;
}
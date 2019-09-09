#include "Rectangle.h"
#include <sstream>

Rectangle::Rectangle()
{
   pos = Vector3(0);
   size = Vector3(0);
   UpdateVertices();
}

Rectangle::Rectangle(Vector3 _size) : Rectangle()
{
   pos = Vector3(0);
   size = _size;
   UpdateVertices();
}

Rectangle::Rectangle(Vector3 _pos, Vector3 _size) : Rectangle(_size)
{
   pos = _pos;
   UpdateVertices();
}

Rectangle::~Rectangle()
{

}

void Rectangle::MoveBy(Vector3 by)
{
   pos = pos + by;
   UpdateVertices();
}

void Rectangle::MoveTo(Vector3 to)
{
   pos = to;
   UpdateVertices();
}

void Rectangle::SetSize(Vector3 _size)
{
   size = _size;
   UpdateVertices();
}

string Rectangle::ToString()
{
   stringstream ss;
   ss << "Pos(" << pos.x << ", " << pos.y << ", " << pos.z << ") - Size(" << size.x << ", " << size.y << ", " << size.z << ")" << endl;
   ss << "LL.X: " << lowLeftVertex.x << "\tY: " << lowLeftVertex.y << endl;
   ss << "UR.X: " << upRightVertex.x << "\tY: " << upRightVertex.y << endl;

   return ss.str();
}
void Rectangle::UpdateVertices()
{
   lowLeftVertex  = Vector3(pos.x - (size.x / 2), pos.y - (size.y / 2), 0);
   lowRightVertex = Vector3(pos.x + (size.x / 2), pos.y - (size.y / 2), 0);
   upLeftVertex   = Vector3(pos.x - (size.x / 2), pos.y + (size.y / 2), 0);
   upRightVertex  = Vector3(pos.x + (size.x / 2), pos.y + (size.y / 2), 0);
}
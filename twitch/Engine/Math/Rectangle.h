#ifndef TWITCH_RECTANGLE
#define TWITCH_RECTANGLE

# include "Vector3.h"
#include <string>

using namespace std;

class Rectangle
{
public:
   Rectangle();
   Rectangle(Vector3 _size);
   Rectangle(Vector3 _pos, Vector3 _size);
   ~Rectangle();

   void MoveBy(Vector3 by);
   void MoveTo(Vector3 to);

   void SetSize(Vector3 _size);

   string ToString();

   Vector3 upLeftVertex;
   Vector3 upRightVertex;
   Vector3 lowLeftVertex;
   Vector3 lowRightVertex;

private:
   void UpdateVertices();

   Vector3 pos;
   Vector3 size;
};

#endif

#include "Math.h"

#include <math.h>

namespace Math
{
   double DegToRad(double deg)
   {
      return (deg * PI) / 180.0f;
   }

   double RadToDeg(double rad)
   {
      return (rad * 180.0f) / PI;
   }

   Vector3 RotatePoint(Vector3 point, Vector3 pivot, float rot)
   {
      double radRot = DegToRad((double)rot);
      double s = sin(radRot);
      double c = cos(radRot);

      point = point - pivot;

      float newX = (float)(point.x * c - point.y * s);
      float newY = (float)(point.x * s + point.y * c);

      point.x = newX;
      point.y = newY;

      return point;
   }
}

float Math::Min(vector<float> x)
{
   float retVal{ x[0] };

   for (int i = 1; i < x.size(); i++)
   {
      if (x[i] < retVal)
      {
         retVal = x[i];
      }
   }
   return retVal;
}

float Math::Max(vector<float> x)
{
   float retVal{ x[0] };

   for (int i = 1; i < x.size(); i++)
   {
      if (x[i] > retVal)
      {
         retVal = x[i];
      }
   }
   return retVal;
}

float Math::Abs(float x)
{
   if (x < 0)
   {
      return -x;
   }
   return x;
}
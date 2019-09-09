#ifndef TWITCH_PIPEMANAGER
#define TWITCH_PIPEMANAGER

#include "Pipe.h"
#include "Flapper.h"

#include <vector>
using namespace std;

class PipeManager
{
public:
   PipeManager();
   ~PipeManager();

   void Update();
   void Render();

   bool CheckCollision(Flapper& flapper);

private:

   void CreatePipe();

   vector<Pipe*> pipes;

   int pipeXGap;
   int pipeYGap;

   int minXGap;
   int minYGap;
   int minYSpawn;
   int maxYSpawn;

   int xRampUp;
   int yRampUp;

   int totalPipes;
};
#endif

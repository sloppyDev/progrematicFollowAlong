#include "PipeManager.h"

#include "../Engine/Engine.h"
#include "../Engine/Physics/RigidBody.h"

PipeManager::PipeManager() :
   pipeXGap{ 800 },
   pipeYGap{ 500 },
   minXGap{ 200 },
   minYGap{ 300 },
   xRampUp{ 10 },
   yRampUp{ 10 },
   minYSpawn{ pipeYGap / 2 + 50 },
   maxYSpawn{ Engine::SCREEN_HEIGHT - (pipeYGap / 2 + 50) },
   totalPipes{ 0 }
{
   CreatePipe();
}

PipeManager::~PipeManager()
{
   for (unsigned int i{ 0 }; i < pipes.size(); i++)
   {
      delete pipes[i];
   }
}

void PipeManager::Update()
{
   minYSpawn = pipeYGap / 2 + 50;
   maxYSpawn = Engine::SCREEN_HEIGHT - (pipeYGap / 2 + 50);

   vector<int> pipesToDelete;
   for (unsigned int i{ 0 }; i < pipes.size(); i++)
   {
      pipes[i]->Update();
      if (pipes[i]->GetX() < -pipes[i]->GetWidth() / 2)
      {
         pipesToDelete.push_back(i);
      }

      if (i == pipes.size() - 1)
      {
         if (pipes[i]->GetX() < Engine::SCREEN_WIDTH - pipeXGap)
         {
            CreatePipe();
         }
      }
   }
   for (unsigned int i{ 0 }; i < pipesToDelete.size(); i++)
   {
      delete pipes[pipesToDelete[i]];
      pipes.erase(pipes.begin() + pipesToDelete[i]);
   }
}

void PipeManager::Render()
{
   for (unsigned int i{ 0 }; i < pipes.size(); i++)
   {
      pipes[i]->Render();
   }
}

bool PipeManager::CheckCollision(Flapper& flapper)
{
   bool isColliding{ false };

   for (unsigned int i{ 0 }; i < pipes.size(); i++)
   {
      isColliding |= RigidBody::IsColliding(flapper.GetRb(), pipes[i]->GetTopRb()) || 
                    RigidBody::IsColliding(flapper.GetRb(), pipes[i]->GetBotRb());
   }
   return isColliding;
}

void PipeManager::CreatePipe()
{
   int spawnY = rand() % (maxYSpawn - minYSpawn) + minYSpawn;
   Pipe* pipe = new Pipe(Vector3((float)Engine::SCREEN_WIDTH, (float)spawnY, 0));
   pipe->SetGap((float)pipeYGap);

   pipes.push_back(pipe);
   totalPipes++;

   if (totalPipes % 2 == 0)
   {
      if (pipeXGap > minXGap + xRampUp)
      {
         pipeXGap -= xRampUp;
      }

      if (pipeYGap > minYGap + yRampUp)
      {
         pipeYGap -= yRampUp;
      }
   }
}
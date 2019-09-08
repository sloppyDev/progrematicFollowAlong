#include "Engine.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"

int Engine::SCREEN_WIDTH{1024};
int Engine::SCREEN_HEIGHT{768};
float Engine::dt{0};

GLFWwindow* Engine::window = NULL;

Engine::Engine()
{
   
}

Engine::~Engine()
{

}

bool Engine::Initialize(char* windowTitle)
{
   if (!glfwInit())
   {
      cout << "Error initializing GLFW!" << endl;
      return false;
   }

   window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
   
   if (window == NULL)
   {
      cout << "Error creating window" << endl;
      return false;
   }

   
   // IO Callbacks
   // Mouse
   glfwSetCursorPosCallback(window, Mouse::MousePosCallback);
   glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);

   // Keyboard
   glfwSetKeyCallback(window, Keyboard::KeyCallback);

   // GLFW Setup
   glfwMakeContextCurrent(window);
   int width{};
   int height{};
   glfwGetFramebufferSize(window, &width, &height);
   glfwSwapInterval(1);

   const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
   int xPos{ (mode->width - SCREEN_WIDTH) / 2 };
   int yPos{ (mode->height - SCREEN_HEIGHT) / 2 };
   glfwSetWindowPos(window, xPos, yPos);
   
   // GL Setup
   // Viewport
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, width, 0, height, -10, 10);
   glDepthRange(-10, 10);
   glMatrixMode(GL_MODELVIEW);

   //Alpha Blending
   glEnable(GL_ALPHA_TEST);
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

   lastTime = (float)glfwGetTime();

   return true;
}

void Engine::Update()
{
   float now{ (float)glfwGetTime() };
   dt = now - lastTime;
   lastTime = now;

   glfwPollEvents();
}

void Engine::BeginRender()
{
   // Clearing out back buffer
   glClearColor(0, 1, 0, 1);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::EndRender()
{
   // Swapping buffers
   glfwSwapBuffers(window);
}

float Engine::GetDt()
{
   return dt;
}
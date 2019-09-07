#include "Engine.h"

int Engine::SCREEN_WIDTH{1024};
int Engine::SCREEN_HEIGHT{768};

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

   // OpenGL Setup
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

}

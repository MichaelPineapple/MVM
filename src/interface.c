#include <GLFW/glfw3.h>
#include <stdio.h>

#include "headers/interface.h"
#include "headers/interfaceFunctions.h"

#define WIN_WIDTH 500
#define WIN_HEIGHT 500

int pixels[WIN_WIDTH][WIN_HEIGHT];

void error_callback(int error, const char* description)
{
    printf("Error: %s\n", description);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void clearScreen(int val)
{
    for (int i = 0; i < WIN_WIDTH; i++)
    {
        for (int j = 0; j < WIN_HEIGHT; j++) pixels[i][j] = val;
    }
}

void setPixel(int x, int y, int val)
{
    pixels[x][y] = val;
}

int interfaceStart()
{
    clearScreen(1);
    
    glfwSetErrorCallback(error_callback);
    
    if (!glfwInit()) return -1;
    
    GLFWwindow* window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Meowcle Machine", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }
    
    glfwSetKeyCallback(window, keyCallback);
    glfwMakeContextCurrent(window);
    
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, WIN_WIDTH, WIN_HEIGHT, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0f, 1.0f, 1.0f);
    
    while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glBegin(GL_POINTS);
        for (int i = 0; i < WIN_WIDTH; i++)
        {
            for (int j = 0; j < WIN_HEIGHT; j++)
            {
                if (pixels[i][j] > 0) glVertex2i(i, j);
            }
        }
        glEnd();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

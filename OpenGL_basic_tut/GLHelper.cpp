#include "GLHelper.h"
#include <iostream>


 GLFWwindow* GLHelper::initGL() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //return 0;

    // Create window
    GLFWwindow* window;
    window =  glfwCreateWindow(800, 600, "OpenGL_basic_tut", NULL, NULL);

    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Falied to initialize GLAD" << std::endl;
        return NULL;
    }

    glViewport(0, 0, 800, 600);

    return window; 
}

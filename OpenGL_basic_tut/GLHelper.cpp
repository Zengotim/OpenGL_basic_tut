#include "GLHelper.h"
#include <iostream>

//Helper class for openGL tasks
// Initial setup, window, context
 GLFWwindow* GLHelper::initGL() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

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

    return window; 
}

 void GLHelper::clearBuffer(float red, float green, float blue, float alpha) {

     glClearColor(red, green, blue, alpha);
     glClear(GL_COLOR_BUFFER_BIT);

 }


 //takes in vertx shader and fragment shader as char*
 //returns compiled shader program
 int GLHelper::createShaderProgram(const char* vertexShaderText, const char* fragmentShaderText) {


     // build and compile our shader program
 // ------------------------------------
 // vertex shader
     int vertexShader = glCreateShader(GL_VERTEX_SHADER);
     glShaderSource(vertexShader, 1, &vertexShaderText, NULL);
     glCompileShader(vertexShader);
     // check for shader compile errors
     int success;
     char infoLog[512];
     glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
     if (!success)
     {
         glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
         std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
     }
     // fragment shader
     int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
     glShaderSource(fragmentShader, 1, &fragmentShaderText, NULL);
     glCompileShader(fragmentShader);
     // check for shader compile errors
     glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
     if (!success)
     {
         glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
         std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
     }
     // link shaders
     int shaderProgram = glCreateProgram();
     glAttachShader(shaderProgram, vertexShader);
     glAttachShader(shaderProgram, fragmentShader);
     glLinkProgram(shaderProgram);
     // check for linking errors
     glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
     if (!success) {
         glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
         std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
     }
     glDeleteShader(vertexShader);
     glDeleteShader(fragmentShader);

     return shaderProgram;
 }

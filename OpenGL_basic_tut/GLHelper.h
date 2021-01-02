#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GLHelper
{
	public:
		static GLFWwindow* initGL();
		static  void clearBuffer();
		static int compileShader(char* shaderText, GLenum shaderType);

};


#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

//Helper class for openGL tasks
class GLHelper
{
	public:
		static GLFWwindow* initGL();
		static  void clearBuffer(float red, float green, float blue, float alpha);
		static int createShaderProgram(const char* vertexShaderText, const char* fragmentShaderText);
		//static int compileShader(char* shaderText, GLenum shaderType);

};


#include <stdio.h>
#include <stdlib.h>

#include "../../includes/glad/glad.h"
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 480

const char* vertexShaderSource = "#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main() {\n"
	"  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main() {\n"
	"  FragColor = vec4(0.8f, 0.8f, 0.8f, 1.0f);\n"
	"}\0";

void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int argc, char** argv)
{
	// Initialization
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Star - OpenGL", NULL, NULL);
	if (window == NULL)
	{
		printf("Failed to create a window.\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("Failed to initialize GLAD");
		return -1;
	}

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

	// Shader
	float vertices[] = {
		 0.0f,   0.9f,  0.0f,		// 0. Head
		-0.9f,   0.25f, 0.0f,		// 1. Left hand
		-0.2f,   0.25f, 0.0f,		// 2. Left shoulder
		 0.2f,   0.25f, 0.0f,		// 3. Right shoulder
		 0.9f,   0.25f, 0.0f,		// 4. Right hand
		-0.3f,  -0.12f,  0.0f,		// 5. Left hip
		 0.3f,  -0.12f,  0.0f,		// 6. Right hip
		 0.0f,  -0.4f,  0.0f,		// 7. Bottom
		-0.5f,  -0.9f,  0.0f,		// 8. Left foot
		 0.5f,  -0.9f,  0.0f		// 9. Right foot
	};

	unsigned int indices[] = {
		0, 2, 3,
		1, 2, 5,
		2, 5, 6,
		2, 3, 6,
		3, 4, 6,
		5, 6, 7,
		5, 8, 7,
		7, 9, 6
	};

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];
	
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		printf("Vertex shader compilation failed.\n%s\n", infoLog);
		return -1;
	}

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		printf("Fragment shader compilation failed.\n%s\n", infoLog);
		return -1;
	}

	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		printf("Failed to link shaders.\n%s\n", infoLog);
		return -1;
	}

	glUseProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	unsigned int VBO, VAO, EBO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Rendering
	while (!glfwWindowShouldClose(window))
	{

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

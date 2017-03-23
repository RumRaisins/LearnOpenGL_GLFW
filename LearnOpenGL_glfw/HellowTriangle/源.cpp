#include<iostream>

#define GLEW_STATIC
#include<glew.h>

#include<glfw3.h>

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);

const GLuint WIDTH = 800, HEIGHT = 600;

//�����汾 3.3
//layout �趨���������λ��
//in�ؼ��� ���� vec3 �ı���positon 
//out�ؼ��� ����vec3 �ı��� color
const GLchar* vertexShaderSource = "#version 330 core\n"
"layout(location =0) in vec3 position;\n"
"{\n"
"gl_Position =vect4(postion.x,position.y,position.z,1.0);\n"
"}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color =vec4(1.0f,0.5f,0.2f,1.0f);\n"
"}\n\0";

int main() {

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Hello Traingle", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, key_callback);

	glewExperimental = GL_TRUE;

	glewInit();

	glewInit();

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	//����GLSL
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	GLint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;

	}
	//����Shader
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//GLfloat vertices[] = {
	//	-0.5f,-0.5f,0.0f,  //left
	//	0.5f,-0.5f,0.0f,	//Right
	//	0.0f,0.5f,0.0f		//Top
	//};
	GLfloat vertices[] = {
	-0.9f, -0.5f, 0.0f,  // Left 
		-0.0f, -0.5f, 0.0f,  // Right
		-0.45f, 0.5f, 0.0f,  // Top 
							 // Second triangle
		0.0f, -0.5f, 0.0f,  // Left
		0.9f, -0.5f, 0.0f,  // Right
		0.45f, 0.5f, 0.0f   // Top 
	};
	//VAO �����������  ��VBO ���㻺�����
	GLuint VBO, VAO;
	//���û���ID
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//�Ȱ󶨶����������Ȼ��󶨲����ö��㻺����������ָ��
	glBindVertexArray(VAO);
	//���㻺����� ��������
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//�û���������ݸ��Ƶ���ǰ�󶨻���ĺ���,GL_STATIC_DRAW �����ݲ���򼸺�����ı䡣GL_DYNAMIC_DRAW�����ݻᱻ�ı�ܶࡣGL_STREAM_DRAW ������ÿ�λ���ʱ����ı�
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//layout(location=0) �����pisition�������Ե�λ��0�������С,����,�Ƿ��׼����0��-1���������������ڻ�������ʼλ�õ�ƫ����
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    //�Զ�������λ��ֵ��Ϊ���������ö�������
	glEnableVertexAttribArray(0);
	//�����
	glBindBuffer(GL_ARRAY_BUFFER, 0);	
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);

		glfwSwapBuffers(window);

	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VAO);
	
	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE &&action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
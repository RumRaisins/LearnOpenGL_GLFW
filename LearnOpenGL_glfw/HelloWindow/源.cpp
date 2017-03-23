#define GLEW_STATIC
#include<iostream>
#include<glew.h>
#include<glfw3.h>


void key_callback(GLFWwindow* window,int key,int scancode,int action,int mode) {
	//当用户按下Esc键，设置WindowShouldClose为true

	if (key == GLFW_KEY_ESCAPE&&action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

}



int main() {
	//初始化GLFW
	glfwInit();
	//设置主版本号（Major）
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//此版本号（Minor）  3 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//使用核心模式（Core-profile）
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//禁止用户更改窗口大小
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	

	GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Window!", nullptr, nullptr);

	if (window == nullptr) {
	   std::cout << "Failed to create GLFW window" << std::endl;
	   glfwTerminate();
	   return -1;

	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	//设置为true，那么glew知道用现代的方法来检索函数指针和扩展
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	//		左下角坐标，渲染窗口的宽度，高度
	glViewport(0, 0, width, height);
	
	while (!glfwWindowShouldClose(window)) {


		//检测触发时间（如鼠标移动事件
		glfwPollEvents();

		//渲染指令

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//交换颜色缓冲
		glfwSwapBuffers(window);
	}





	glfwTerminate();
	return 0;


}
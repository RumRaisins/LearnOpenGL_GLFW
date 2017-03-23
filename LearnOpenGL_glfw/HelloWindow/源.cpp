#define GLEW_STATIC
#include<iostream>
#include<glew.h>
#include<glfw3.h>


void key_callback(GLFWwindow* window,int key,int scancode,int action,int mode) {
	//���û�����Esc��������WindowShouldCloseΪtrue

	if (key == GLFW_KEY_ESCAPE&&action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

}



int main() {
	//��ʼ��GLFW
	glfwInit();
	//�������汾�ţ�Major��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//�˰汾�ţ�Minor��  3 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//ʹ�ú���ģʽ��Core-profile��
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//��ֹ�û����Ĵ��ڴ�С
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	

	GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Window!", nullptr, nullptr);

	if (window == nullptr) {
	   std::cout << "Failed to create GLFW window" << std::endl;
	   glfwTerminate();
	   return -1;

	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	//����Ϊtrue����ôglew֪�����ִ��ķ�������������ָ�����չ
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	//		���½����꣬��Ⱦ���ڵĿ�ȣ��߶�
	glViewport(0, 0, width, height);
	
	while (!glfwWindowShouldClose(window)) {


		//��ⴥ��ʱ�䣨������ƶ��¼�
		glfwPollEvents();

		//��Ⱦָ��

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//������ɫ����
		glfwSwapBuffers(window);
	}





	glfwTerminate();
	return 0;


}
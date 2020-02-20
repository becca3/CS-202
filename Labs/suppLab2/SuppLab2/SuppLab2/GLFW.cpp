#include <GLFW/glfw3.h>

#ifdef _WIN32 //Can also be _MSC_VER (uses Microsoft version)

//#pragma comment (lib, "glfw3.lib")
//#pragma comment (lib, "glfw3dll.lib")
#pragma comment (lib, "OpenGL32.lib")

#endif 

int main(void) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    void glClearColor(GLfloat red,
        GLfloat green,
        GLfloat blue,
        GLfloat alpha);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClearColor(0, 1, 0, 1);

        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
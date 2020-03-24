#include <GLFW/glfw3.h>
#include <cmath>

#ifdef _WIN32 //Can also be _MSC_VER (uses Microsoft version)

//#pragma comment (lib, "glfw3.lib")
//#pragma comment (lib, "glfw3dll.lib")
#pragma comment (lib, "OpenGL32.lib")

#endif 

int main(void) 
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 1000, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    //Resizes shapes after resizing of window 
    int w = 1;
    int h = 1;
    glfwGetWindowSize(window, &w, &h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double ar = (double)w / (double)h;
    glOrtho(-ar, ar, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    void glClearColor(GLfloat red,
        GLfloat green,
        GLfloat blue,
        GLfloat alpha);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) 
    {
        /* Render here */
        glClearColor(0.5f, 0.2f, 2.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //Draw a triangle.
        glBegin(GL_TRIANGLES);
        glColor3f(0.8f, 2.0f, 0.90f);
        glVertex3f(-1.0f, -1.0f, 0.0f); // bottom left
        glVertex3f(1.0f, -1.0f, 0.0f); // bottom right
        glVertex3f(0.0f, 1.0f, 0.0f); // middle top
        glEnd();


        //Draw a circle.
        glLoadIdentity();
        glBegin(GL_LINE_LOOP);
        for (float a = 0.0f; a < 360.0f; a += 1.0f) {
            float c = std::cos(a * 3.14159f / 180.0f);
            float s = std::sin(a * 3.14159f / 180.0f);
            glColor3f(std::abs(c), std::abs(s), 0.0f); //Rainbow circle.
            //glColor3f(1.0f, 4.0f, 1.0f); //Change colour of circle.
            glVertex3f(c, s, 0.0f);
        }
        glEnd();

        glLoadIdentity();
        //Add no. in front of (float) to make it spin faster or slower.
        float angle = 1.0*(float)glfwGetTime(); // This GLFW function returns the time in seconds as a double
        float c = 0.1f * std::cos(angle * 3.14159f / 180.0f);
        float s = 0.1f * std::cos(angle * 3.14159f / 180.0f);
        glTranslatef(c, s, 0.1f);
        glScalef(1 + c, 1 + s, 1.0f);
        glRotatef(angle * 30.0f, 0.0f, 0.0f, 1.0f);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
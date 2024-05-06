#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Circulo.h"
#include "Ventana.h"
#include <math.h>
#include <random>
const unsigned int SCR_WIDTH=800;
const unsigned int SCR_HEIGHT=600;

void processInput(GLFWwindow *windows, Circulo circulo,Ventana ventana)
{
    
    if(glfwGetKey(windows, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(windows, true);
    if(glfwGetKey(windows, GLFW_KEY_1) == GLFW_PRESS)circulo.change_Color(0.2f,0,0);
    if(glfwGetKey(windows, GLFW_KEY_2) == GLFW_PRESS)circulo.change_Color(0,0.2f,0);
    if(glfwGetKey(windows, GLFW_KEY_3) == GLFW_PRESS)circulo.change_Color(0,0,0.2f);
    if(glfwGetKey(windows, GLFW_KEY_4) == GLFW_PRESS)circulo.change_Color(-0.2f,0,0);
    if(glfwGetKey(windows, GLFW_KEY_5) == GLFW_PRESS)circulo.change_Color(0,-0.2f,0);
    if(glfwGetKey(windows, GLFW_KEY_6) == GLFW_PRESS)circulo.change_Color(0,0,-0.2f);
    if(glfwGetKey(windows, GLFW_KEY_A) == GLFW_PRESS)circulo.change_Size(0.2f,ventana.width,ventana.height,1);
    if(glfwGetKey(windows, GLFW_KEY_B) == GLFW_PRESS)circulo.change_Size(0.2f,ventana.width,ventana.height,2);
}

void framebuffer_size_callback(GLFWwindow* windows, int width, int height)
{   
    glViewport(0, 0,width,height);
}
float RC(){
    std::random_device rd;
    std::uniform_real_distribution<float> random(0.0,2.0);
    return random(rd);   
}
void Paint_Pixel(int x,int y,float red,float green,float blue){
    glPointSize(3);
    glColor3f(red,green,blue);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}
void Pintar_Circulo(Circulo circulo){
    double cirx,ciry;
    cirx= circulo.X;
    while(cirx<circulo.Radio){
        ciry= sqrt(pow(circulo.Radio,2)-pow(cirx,2));

        Paint_Pixel(cirx+circulo.A,ciry+circulo.H,circulo.Red,circulo.Green,circulo.Blue);
        Paint_Pixel(cirx+circulo.A,ciry+circulo.H,circulo.Red,circulo.Green,circulo.Blue);

        Paint_Pixel(-cirx+circulo.A,ciry+circulo.H,circulo.Red,circulo.Green,circulo.Blue);
        Paint_Pixel(-cirx+circulo.A,ciry+circulo.H,circulo.Red,circulo.Green,circulo.Blue);

        Paint_Pixel(cirx+circulo.A,-ciry+circulo.H,circulo.Red,circulo.Green,circulo.Blue);
        Paint_Pixel(cirx+circulo.A,-ciry+circulo.H,circulo.Red,circulo.Green,circulo.Blue);

        Paint_Pixel(-cirx+circulo.A,-ciry+circulo.H,circulo.Red,circulo.Green,circulo.Blue);
        Paint_Pixel(-cirx+circulo.A,-ciry+circulo.H,circulo.Red,circulo.Green,circulo.Blue);
        cirx++;
    }
    
}

int main(){

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    Ventana ventana{float(SCR_WIDTH),float(SCR_HEIGHT)};
    Circulo circulo(300.0,RC(),RC(),RC());
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    GLFWwindow* window = glfwCreateWindow(ventana.width,ventana.height,"LearnOpenGL",NULL,NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window,circulo,ventana);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        Pintar_Circulo(circulo);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

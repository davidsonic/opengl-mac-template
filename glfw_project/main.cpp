//
//  main.cpp
//  glfw_project
//
//  Created by 段佳利 on 4/3/19.
//  Copyright © 2019 battlefire. All rights reserved.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>
using namespace std;

const int steps = 100;
float angle = (3.1415926*2.f) / steps;
const float radius = 1.0f;

void drawCircle(float red, float green, float blue){
    float prevX = 0.f, prevY = 0.f - radius;
    
    for(int i=0;i<=steps;i++){
        glColor3f(red, green, blue);
        glBegin(GL_TRIANGLES);
        glVertex3f(0, 0, 0);
        glVertex3f(prevX, prevY, 0);
        float newX = radius * sin(angle*i);
        float newY = -radius * cos(angle*i);
        glVertex3f(newX, newY, 0);
        glEnd();
        prevX = newX;
        prevY = newY;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    GLFWwindow * window;
    if(!glfwInit())
    {
        std::cout<<"error init"<<std::endl;
        return -1;
    }
    
    window = glfwCreateWindow(800, 800, "hello", 0, 0);
    if(!window){
        std::cout<<"window error"<<std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(0.1, 0.1, 1);
    
    float angleEarth = 0;
    float angleMoon = 2;
    while(!glfwWindowShouldClose(window)){
        glClearColor(1., 1., 1., 1.);
        glClear(GL_COLOR_BUFFER_BIT);
        
        drawCircle(1., 1., 0);
        // draw earth
        {
            glPushMatrix();
            glRotatef(angleEarth, 0, 0, 1);
            glTranslatef(0, 5, 0);
            glScalef(0.5, 0.5, 0.5);
            drawCircle(0, 0, 1);
            angleEarth+=1;
            
            // draw Moon
            {
                glPushMatrix();
                glRotatef(angleMoon, 0, 0, 1);
                glTranslatef(0., 3, 0);
                glScalef(0.3, 0.3, 0.3);
                
                drawCircle(0, 1, 0);
                angleMoon+=1;
                glPopMatrix();
            }
            glPopMatrix();
        }
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

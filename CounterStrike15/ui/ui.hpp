#include <GLFW/glfw3.h>
#include <iostream>

#include "hacks/Lazer/Lazer.hpp"
#include "hacks/FlyHack/FlyHack.hpp"

void GetCoordinator(float x, float y, void *font, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

class Lazer {
int windowWidth = 800;
int windowHeight = 600;

// Button bounds
float btnX = 300, btnY = 230, btnW = 700, btnH = 200;
bool isHovered = false;

void drawLazer() {
    // # I want it to already draw as hover is enabled.
    glBegin(GL_QUADS);
    
    if (isHovered) {
        
        glColor3f(0.4f, 0.6f, 1.0f); 
    } else {
        glColor3f(0.2f, 0.5f, 0.8f); 
    }
    
    glVertex2f(1.15f, -.55f);
    glVertex2f(-1.15f, .55f);
    GetCoordinator(-0.25f, -0.05f, GLUT_BITMAP_HELVETICA_18, "Lazer");
 
    glEnd();
}

void drawFlyHack() {
    // # I want it to already draw as hover is enabled.
    glBegin(GL_QUADS);
    
    if (isHovered) {
        
        glColor3f(0.4f, 0.6f, 1.0f); 
    } else {
        glColor3f(0.2f, 0.5f, 0.8f); 
    }

    glVertex2f(-1.15f, 1.1f);
    glVertex2f(1.15f, -1.1f);
    GetCoordinator(-0.25f, -0.05f, GLUT_BITMAP_HELVETICA_18, "FlyHack");
 
    glEnd();
}

void mouse_button_callback_Lazer(GLFWwindow* window, int button, int action, int mods) {
    drawLazer();
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && isHovered) {
        Lazer();
    }
}

void mouse_button_callback_FlyHack(GLFWwindow* window, int button, int action, int mods) {
    drawFlyHack();
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && isHovered) {
        FlyHack();
    }
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    float mouseX = static_cast<float>(xpos);
    float mouseY = static_cast<float>(windowHeight - ypos); // Flip Y

    isHovered = (mouseX > btnX && mouseX < btnX + btnW &&
                 mouseY > btnY && mouseY < btnY + btnH);
}

class clazz {
DWORD64 Lazer() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Lazer", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glOrtho(0, windowWidth, 0, windowHeight, -1, 1);

    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        drawLazer();
        drawFlyHack();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
};
};

int gl_main(void) {
    Lazer clazzLaz;
    classLaz.clazz clazz;
    clazz.UI();

    
    
    return 0x0000;
}

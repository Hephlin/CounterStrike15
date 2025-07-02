#include <GLFW/glfw3.h>
#include <iostream>

#include "Source.hpp"

class Lazer {
int windowWidth = 800;
int windowHeight = 600;

// Button bounds
float btnX = 300, btnY = 230, btnW = 700, btnH = 200;
bool isHovered = false;

void drawButton() {
    // # I want it to already draw as hover is enabled.
    glBegin(GL_QUADS);
    if (isHovered)
        glColor3f(0.4f, 0.6f, 1.0f); 
    else
        glColor3f(0.2f, 0.5f, 0.8f); 
    glVertex2f(btnX, btnY);
    glVertex2f(btnX + btnW, btnY);
    glVertex2f(btnX + btnW, btnY + btnH);
    glVertex2f(btnX, btnY + btnH);
    glEnd();
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && isHovered) {
        // backend
        system("title UI");
        GetOffset();
        std::cout << "Damage Emitted!\n";
    }
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    float mouseX = static_cast<float>(xpos);
    float mouseY = static_cast<float>(windowHeight - ypos); // Flip Y

    isHovered = (mouseX > btnX && mouseX < btnX + btnW &&
                 mouseY > btnY && mouseY < btnY + btnH);
}

class clazz {
DWORD64 UI() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Emit_Damage", NULL, NULL);
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

        drawButton();

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
    classLaz.clazz clazz1;
    clazz1.UI();
}

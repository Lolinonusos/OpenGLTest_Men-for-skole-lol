#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>

#include "shader.h"
#include "camera.h"
#include "model.h"

#include "tetrahedon.h"
#include "visObject.h"
#include "xyz.h"
#include "cube.h"
#include "graph.h"
#include "triangleSurface.h"
#include "interactive.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;


// Time
float deltaTime = 0.0f; // Time between current and last frame
float lastFrame = 0.0f;


float mixValue = 0.2f;


// Camera stuff
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f)); // learnopengl camera
float lastX = SCR_WIDTH / 2;
float lastY = SCR_HEIGHT / 2;
bool firstMouse = true;

// Other input stuffs
Interactive intObj(glm::vec3(0.0f, 0.0f, 0.0f));
bool changeObj = true; // Change between controlling camera or other unspecified object

std::vector<visObject*> visObjects;

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow* window) {
    const float camSpeed = 2.0f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) { // FORWARD
        intObj.move(0.0f, 1.0f, 0.0f, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) { // BACKWARD
        intObj.move(0.0f, -1.0f, 0.0f, deltaTime);

    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) { // RIGHT
        intObj.move(1.0f, 0.0f, 0.0f, deltaTime);

    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) { // LEFT
        intObj.move(-1.0f, 0.0f, 0.0f, deltaTime);

    }

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) { // FORWARD
        if (changeObj) {
            // Camera
            camera.processKeyboard(FORWARD, deltaTime); 
        }
        else {
            // Other object
        }
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) { // BACKWARD
        if (changeObj) {
            // Camera
            camera.processKeyboard(BACKWARD, deltaTime); 
        }
        else {
            // Other object

        }
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) { // RIGHT
        if (changeObj) {
            // Camera
            camera.processKeyboard(RIGHT, deltaTime); 
        }
        else {
            // Other object

        }
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) { // LEFT
        if (changeObj) {
            // Camera
            camera.processKeyboard(LEFT, deltaTime); 
        }
        else {
            // Other object

        }
    }

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) { // LEFT
    
        //visObjects.push_back(new Cube);
    }

}

void mouse_callback(GLFWwindow*, double xPosIn, double yPosIn) {

    float xPos = static_cast<float>(xPosIn);
    float yPos = static_cast<float>(yPosIn);

    std::cout << "Mouse x:" << xPos << "    y:" << yPos << std::endl;
    if (firstMouse) {
        lastX = xPos;
        lastY = yPos;
        firstMouse = false;
    }

    float xOffset = xPos - lastX;
    float yOffset = lastY - yPos;// reversed since y-coordinates range from bottom to top

    lastX = xPos;
    lastY = yPos;

    camera.processMouseMovement(xOffset, yOffset);
}


void scroll_callback(GLFWwindow* window, double xOffset, double yOffset) {
    camera.ProcessMouseScroll(static_cast<float>(yOffset));
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


int main() {
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Skrankel Rankel Engine", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // Captures the mouse cursor within the center the window 
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    // build and compile our shader program
    //Shader ourShader("firstTexVertShader.vs", "firstTexFragShader.fs"); // you can name your shader files however you like
    Shader ourShader("SkolVert.vs", "SkolFrag.fs"); // you can name your shader files however you like


    glm::vec3 cubePositions[] = {
    glm::vec3(0.0f,  0.0f,  0.0f),
    glm::vec3(2.0f,  5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3(2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f,  3.0f, -7.5f),
    glm::vec3(1.3f, -2.0f, -2.5f),
    glm::vec3(1.5f,  2.0f, -2.5f),
    glm::vec3(1.5f,  0.2f, -1.5f),
    glm::vec3(-1.3f,  1.0f, -1.5f)
    };
    glEnable(GL_DEPTH_TEST);
    
    //###########################################################################
    // 
    // Programmer under her
    // Kall p? konstukt?r f?rst, deretter init funksjonen dens
    //
    //###########################################################################

  /*  int m = ourShader.setInt("model", m);
    int v;
    int p;*/

    XYZ xyz;
    xyz.init(1);

    Graph graph;
    graph.init(1);



    TriangleSurface triSur("Oppg2.txt", false);
    //cube.writefile("Data2.txt");
    triSur.init(1);

    //Cube kub;
    
    visObjects.push_back(new Cube());
    visObjects.push_back(new TriangleSurface());
    visObjects.push_back(new Cube());
    visObjects.push_back(new TriangleSurface());
    visObjects.push_back(new Cube());
    visObjects.push_back(new TriangleSurface());
    visObjects.push_back(new Cube());
    visObjects.push_back(new TriangleSurface());
    visObjects.push_back(new Cube());
    visObjects.push_back(new Tetrahedon());


    //kub.init(1);

    intObj.init(1);
    //cube.readFile("Data.txt");

    Tetrahedon tetra;
    tetra.init(1);

    //visObjects.push_back(tetra);

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    // render loop
    for (unsigned int i = 0; i < visObjects.size(); i++) {
        visObjects[i]->init(1);
    }
    while (!glfwWindowShouldClose(window)) {

        //###########################################################################
        // 
        // Denne while-loopen fungerer som renderWindow sin render funksjon
        // Kaotisk n?, men vi kan rydde opp i den senere
        //
        //###########################################################################

        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame; // Time between current frame and last frame
        lastFrame = currentFrame; // Time of last frame
        
        // input
        processInput(window);

        // Background colour
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        // Clean the back buffer and assign the new color to it
        glClear(GL_COLOR_BUFFER_BIT);
        // Clear depth buffer
        glClear(GL_DEPTH_BUFFER_BIT);
        // Can be written together like this
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
        // Which shader program we will use
        ourShader.use();
        
        // Projection matrix
        projection = glm::perspective(glm::radians(camera.zoom), (float)(SCR_WIDTH / SCR_HEIGHT), 0.1f, 100.0f);
        ourShader.setMat4("projection", projection);
        
    
        // View matrix 
        view = camera.getViewMatrix();
        ourShader.setMat4("view", view);

        
        for (int i = 0; i < visObjects.size(); i++) {

            model = glm::mat4(1.0f);
            //model = glm::translate(model, cubePositions[i]);

            visObjects[i]->alterTransformations(cubePositions[i]);
            float angle = 20.0f * 1 + i * 2;
            //model = glm::rotate(model, (float)glfwGetTime() * glm::radians(angle), glm::vec3(0.5f, 1.0f, 0.0f));
            //gldrawarrays(gl_triangles, 0, 36);
            ourShader.setMat4("model", model);
        
            //######################################################
            // Kalle p? draw funksjoner herifra og nedover
            visObjects[i]->draw();
        }

        for (unsigned int i = 0; i < visObjects.size(); i++) {
        }

        graph.alterTransformations(glm::vec3(0.0f, -5.0f, 0.0f), 90, glm::vec3(1.0f, 0.0f, 0.0f));

        xyz.draw();
        graph.draw();
        triSur.draw();
        //kub.draw();
        intObj.draw();
        tetra.draw();

        // Slutt ? kalle p? draw funksjoner
        //######################################################

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    // Kall p? dekonstrukt?rer og andre terminate funksjoner her
    triSur.~TriangleSurface();
    
    // Shader program
    ourShader.remove();
    
    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}


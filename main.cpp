//the code is from line 35 to 100
/*void drawCircle(){
    float steps = 100.0;
    float angle = 2.0 * 3.14159265 / 100;
    float radius = 0.25f, prevX = 0.0, prevY = 0.0;
    for (int i = 0; i <= steps; i++) {
        float newX = radius * sin(angle * i);
        float newY = radius * cos(angle * i);
        glPushMatrix();
        glBegin(GL_TRIANGLES);
        glColor4f(0.7, 0.0, 0.4, 0.0);
        glVertex3f(0.0, 0.14, 0.0);
        glColor4f(0.7, 0.0, 0.8, 0.5);
        glVertex3f(prevX, prevY+0.14, 0.0f);
        glColor4f(0.2, 0.0, 1.0, 1.0);
        glVertex3f(newX, newY+0.14,0.0f);
        glEnd();
        glPopMatrix();
        prevX = newX;
        prevY = newY;
    }
}
void drawBuilding(float x1,float x2,float x3,float x4,float y1,float y2,float y3,float y4,float color1,float color2, float color3, float color4, float color5,float color6, float color7,float color8, float color9,float color10, float color11, float color12){
    glBegin(GL_QUAD_STRIP);
    glColor4f(color1, color2, color3, 1.0);
    glVertex2f(x1,y1);
    glColor4f(color4, color5, color6, 0.75);
    glVertex2f(x2, y2);
    glColor4f(color7, color8, color9, 0.5);
    glVertex2f(x3, y3);
    glColor4f(color10, color11, color12, 0.25);
    glVertex2f(x4, y4);
    glEnd();
}*/
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
using namespace std;
GLuint VAO, VBO;
float move=0.0f;
void CreateBoat()
{
    //Assign vertices
    GLfloat vertices []= {
        move + -0.35f,0.15f,0.0f,
        move + -0.3f,0.15f,0.0f,
        move+ 0.0f,-0.1f,0.0f,
        move + 0.3f,0.15f,0.0f,
        move+ 0.35f,0.15f,0.0f,
        move +0.0f,0.4f,0.0f
    };
    
    
    //VAO--> VBO-->DATA-->Pointer to Data
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
}
int main()
{
    
    if(!glfwInit()){
        glfwTerminate();
        return 1;
    }
    GLFWwindow* mainWindow=glfwCreateWindow(800, 600, "Boat", NULL, NULL);
    if(!mainWindow){
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(mainWindow);
    if(glewInit()!=GLEW_OK){
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }
    glViewport(0, 0, 800, 600);
    while (!glfwWindowShouldClose(mainWindow)) {
        glfwPollEvents();
        glClearColor(0.0, 0.0, 1.0, 0.7);
        glClear(GL_COLOR_BUFFER_BIT);
        if (move > 1.0) {
            move = -1.0;
        }
        else {
            move += 0.002;
        }
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
        glfwSwapBuffers(mainWindow);
    }
    /*printf("Welcome to shaders ;) ");
    
    //init glfw
    if (!glfwInit())
    {
        printf("glfw error");
        glfwTerminate();
        return 1;
    }
    //setup and create window
    GLFWwindow* mainWindow = glfwCreateWindow(800, 600, "Shader1", NULL, NULL);
    if (!mainWindow)
    {
        printf("Window error");
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(mainWindow);
    
    if (glewInit() != GLEW_OK)
    {
        printf("glew error");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }
    
    
    //view
    glViewport(0, 0, 800, 600);
    //Opengl Loop
    
    CreateShape();
    while (!glfwWindowShouldClose(mainWindow))
    {
        //handlle events
        glfwPollEvents();
        
        //clear bg
        glClearColor(0.0, 0.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        //draw
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        //assign buffers
        glfwSwapBuffers(mainWindow);
    }*/
    return 0;
}


    
























/*#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

// Shaders
const GLchar* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
"}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

// The MAIN function, from here we start the application and run the game loop
int main()
{
    // Init GLFW
    glfwInit( );
    
    // Set all the required options for GLFW
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    
    glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );
    
    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow *window = glfwCreateWindow( WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr );
    
    int screenWidth, screenHeight;
    glfwGetFramebufferSize( window, &screenWidth, &screenHeight );
    
    if ( nullptr == window )
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate( );
        
        return EXIT_FAILURE;
    }
    
    glfwMakeContextCurrent( window );
    
    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if ( GLEW_OK != glewInit( ) )
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    
    // Define the viewport dimensions
    glViewport( 0, 0, screenWidth, screenHeight );
    
    
    // Build and compile our shader program
    // Vertex shader
    GLuint vertexShader = glCreateShader( GL_VERTEX_SHADER );
    glShaderSource( vertexShader, 1, &vertexShaderSource, NULL );
    glCompileShader( vertexShader );
    
    // Check for compile time errors
    GLint success;
    GLchar infoLog[512];
    
    glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &success );
    if ( !success )
    {
        glGetShaderInfoLog( vertexShader, 512, NULL, infoLog );
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    
    // Fragment shader
    GLuint fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource( fragmentShader, 1, &fragmentShaderSource, NULL );
    glCompileShader( fragmentShader );
    
    // Check for compile time errors
    glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &success );
    
    if ( !success )
    {
        glGetShaderInfoLog( fragmentShader, 512, NULL, infoLog );
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    
    // Link shaders
    GLuint shaderProgram = glCreateProgram( );
    glAttachShader( shaderProgram, vertexShader );
    glAttachShader( shaderProgram, fragmentShader );
    glLinkProgram( shaderProgram );
    
    // Check for linking errors
    glGetProgramiv( shaderProgram, GL_LINK_STATUS, &success );
    
    if ( !success )
    {
        glGetProgramInfoLog( shaderProgram, 512, NULL, infoLog );
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    
    glDeleteShader( vertexShader );
    glDeleteShader( fragmentShader );
    
    
    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices[] =
    {
        -0.5f, -0.5f, 0.0f, // Left
        0.5f, -0.5f, 0.0f, // Right
        0.0f,  0.5f, 0.0f  // Top
    };
    
    GLuint VBO, VAO;
    glGenVertexArrays( 1, &VAO );
    glGenBuffers( 1, &VBO );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO );
    
    glBindBuffer( GL_ARRAY_BUFFER, VBO );
    glBufferData( GL_ARRAY_BUFFER, sizeof( vertices ), vertices, GL_STATIC_DRAW );
    
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    
    glBindBuffer( GL_ARRAY_BUFFER, 0 ); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
    
    glBindVertexArray( 0 ); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
    
    // Game loop
    while ( !glfwWindowShouldClose( window ) )
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents( );
        
        // Render
        // Clear the colorbuffer
        glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );
        
        // Draw our first triangle
        glUseProgram( shaderProgram );
        glBindVertexArray( VAO );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray( 0 );
        
        // Swap the screen buffers
        glfwSwapBuffers( window );
    }
    
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays( 1, &VAO );
    glDeleteBuffers( 1, &VBO );
    
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate( );
    
    return EXIT_SUCCESS;
}*/
/*#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
int main(){
    GLFWwindow* window;
    if(!glfwInit()){
        std::cout << "Not working";
        return -1;
    }
    window=glfwCreateWindow(800, 600, "Rectangle try", NULL, NULL);
    if(!window){
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glBegin(GL_LINE_LOOP);
            for(int ii=0; ii<5;ii++){
                float theta=2.0f*3.1415926f*float(ii)/float(5);
                float x=0.2*cosf(theta);
                float y=0.2*sinf(theta);
                glVertex2f(x+0.5, y+0.5);
            }
            glEnd();
        }
    
    
    return 0;
}*/

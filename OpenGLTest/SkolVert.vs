#version 330 core

layout(location = 0) in vec4 positionIn;    // 1st attribute buffer = vertex positions
layout(location = 1) in vec4 colorIn;       // 2nd attribute buffer = colors
out vec4 color;                             //color sent to rest of pipeline
//uniform mat4 matrix;                        //the matrix for the model

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
   color = colorIn;                         //passing on the vertex color
   //color = vec4(0,0,1,0);
   gl_Position = projection * view * model * positionIn;       //calculate the position of the model
}
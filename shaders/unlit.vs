#version 400

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNormal;

out vec3 color;
uniform mat4 mvp;

void main()
{
/* lookfrom.x = r * cos(phi) * sin(theta);
        lookfrom.z = r * sin(phi) * sin(theta);
        lookfrom.y = r * cos(theta);
        transform = glm::mat4(1.0); // identity 

        //adding perspective projection 
        //glm::mat4 mvp = glm::perspective(45.0f, (GLfloat)2 / (GLfloat)2, 1.0f, 150.0f);
        glm::mat4 camera = glm::lookAt(lookfrom, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
        glm::mat4 mvp = projection * camera * transform;
        glUniformMatrix4fv(matrixParam, 1, GL_FALSE, &mvp[0][0]); */
        //help here ??
   color = 0.5 * (vNormal + vec3(1.0));
   gl_Position = mvp * vec4(vPos, 1.0);
}

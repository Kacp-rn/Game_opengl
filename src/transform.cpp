// #include"transform.h"

// void Transform::transorm_before_shader()
// {
//     transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//     transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
//     transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

// }

// void Transform::transform_after_shader()
// {
//     int transformLoc = glGetUniformLocation(shader.getProgramID(), "transform");
//     shader.use();
//     glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
// }
#include <iostream>
#include "shader_wrapper.h"
#include "shaderLoader.h"

ShaderWrapper::ShaderWrapper(const std::string &vertex_file_path,
                             const std::string &fragment_file_path) {
  shader_id_ = LoadShaders(vertex_file_path, fragment_file_path);
}

void ShaderWrapper::Use() const {
  glUseProgram(shader_id_);
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include "shader_wrapper.h"

ShaderWrapper::ShaderWrapper(const std::string &vs_path, const std::string &fs_path) {
  std::string raw_vs_code;
  std::string raw_fs_code;

  std::ifstream vs_code_src;
  std::ifstream fs_code_src;

  vs_code_src.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fs_code_src.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
    vs_code_src.open(kShadersFolderPath_ + vs_path);
    fs_code_src.open(kShadersFolderPath_ + fs_path);

    std::stringstream vs_stream, fs_stream;

    vs_stream << vs_code_src.rdbuf();
    fs_stream << fs_code_src.rdbuf();

    vs_code_src.close();
    fs_code_src.close();

    raw_vs_code = vs_stream.str();
    raw_fs_code = fs_stream.str();
  } catch (std::ifstream::failure &e) {
    std::cout << "ERROR::SHADER_LOADER: " << e.what() << std::endl;
  }
  const char *vertex_shader_code = raw_vs_code.c_str();
  const char *fragment_shader_code = raw_fs_code.c_str();

  GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, &vertex_shader_code, nullptr);
  glCompileShader(vertex_shader);
  CheckShaderCompileErrors_(vertex_shader, "VERTEX");

  GLuint fragment_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(fragment_shader, 1, &fragment_shader_code, nullptr);
  glCompileShader(fragment_shader);
  CheckShaderCompileErrors_(fragment_shader, "FRAGMENT");

  id_ = glCreateProgram();
  glAttachShader(id_, vertex_shader);
  glAttachShader(id_, fragment_shader);
  glLinkProgram(id_);
  CheckShaderCompileErrors_(id_, "PROGRAM");

  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);
}

void ShaderWrapper::Use() const {
  glUseProgram(id_);
}

void ShaderWrapper::SetBool(const std::string &name, bool value) const {
  glUniform1i(glGetUniformLocation(id_, name.c_str()), (int)value);
}
void ShaderWrapper::SetInt(const std::string &name, int value) const {
  glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
}
void ShaderWrapper::SetFloat(const std::string &name, float value) const {
  glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
}

void ShaderWrapper::CheckShaderCompileErrors_(GLuint shader_id, const std::string &type) const {
  int success;
  char info_log[1024];
  if (type != "PROGRAM") {
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    if (!success) {
      glGetShaderInfoLog(shader_id, 1024, nullptr, info_log);
      std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << info_log <<
      "\n -- --------------------------------------------------- -- " << std::endl;
    }
  } else {
    glGetProgramiv(shader_id, GL_LINK_STATUS, &success);
    if (!success) {
      glGetProgramInfoLog(shader_id, 1024, nullptr, info_log);
      std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << info_log
      << "\n -- --------------------------------------------------- -- " << std::endl;
    }
  }
}

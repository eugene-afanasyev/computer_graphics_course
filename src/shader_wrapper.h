#ifndef COMPUTER_GRAPHICS_COURSE_SRC_SHADER_WRAPPER_H_
#define COMPUTER_GRAPHICS_COURSE_SRC_SHADER_WRAPPER_H_

#include <GL/glew.h>
#include <string>

class ShaderWrapper {
 public:
   explicit ShaderWrapper(const std::string& vs_path, const std::string& fs_path);

  ~ShaderWrapper() = default;

  void Use() const;

  // utility uniform functions
  void setBool(const std::string &name, bool value) const;
  void setInt(const std::string &name, int value) const;
  void setFloat(const std::string &name, float value) const;
 private:
  GLuint id_;
  const std::string kShadersFolderPath_ = "/home/eugene/CLionProjects/computer-graphics-course/res/shaders";

  void CheckShaderCompileErrors_(GLuint shader_id, const std::string& type) const;
};

#endif //COMPUTER_GRAPHICS_COURSE_SRC_SHADER_WRAPPER_H_

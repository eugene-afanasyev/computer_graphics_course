#ifndef COMPUTER_GRAPHICS_COURSE_SRC_SHADER_WRAPPER_H_
#define COMPUTER_GRAPHICS_COURSE_SRC_SHADER_WRAPPER_H_

#include <GL/glew.h>
#include <string>

class ShaderWrapper {
 public:
   explicit ShaderWrapper(const std::string&, const std::string&);

  ~ShaderWrapper() = default;

  void Use() const;

 private:
  GLuint shader_id_;
};

#endif //COMPUTER_GRAPHICS_COURSE_SRC_SHADER_WRAPPER_H_

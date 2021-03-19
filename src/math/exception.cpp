#include "exception.hpp"
const char *cglm::OutOfRangeException::what() const noexcept {
  return "Attempted to access non-existent row or column";
}

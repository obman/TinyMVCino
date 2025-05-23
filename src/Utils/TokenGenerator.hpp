#pragma once

#include <array>
#include <string>
#include <esp_random.h>
#include "../Config/ServerConfig.hpp"

namespace TinyMVCino {
  class TokenGenerator {
    private:
    static std::string generateToken() {
      std::string token;
      token.reserve(TINYMVCINO_SERVER_MAX_TOKEN_LENGTH - 1);  // exclude space for '\0'

      const char charset[] = TINYMVCINO_SERVER_TOKEN_CHARS_AVAILABLE;
      const size_t charsetSize = sizeof(charset) - 1; // exclude null terminator

      for (size_t i = 0; i < TINYMVCINO_SERVER_MAX_TOKEN_LENGTH - 1; ++i) {
        token += charset[esp_random() % charsetSize];
      }

      return token;
    }
  
    public:
      TokenGenerator() = default;

      static std::string getToken() {
        return generateToken();
      };
  };
}
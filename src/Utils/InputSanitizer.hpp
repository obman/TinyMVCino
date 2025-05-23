#pragma once

#include <Arduino.h>

namespace TinyMVCino {
  class InputSanitizer {
    public:
      InputSanitizer() = delete;
      InputSanitizer(const InputSanitizer&) = delete;
      InputSanitizer& operator=(const InputSanitizer&) = delete;

      static void sanitizeSSID(String& input) {
        input.trim();
        input.replace("\"", "");
        input.replace(";", "");
        input.replace("<", "");
      };

      static void sanitizePassword(String& input) {
        input.trim();
        input.replace("\"", "");
      };

      static void sanitizeGeneric(String& input) {
        input.trim();
        input.replace("\"", "");
        input.replace(";", "");
        input.replace("<", "");
        input.replace(">", "");
        input.replace("&", "");
      };
  };
}
#pragma once

#include <memory>
#include <ArduinoJson.h>

namespace TinyMVCino {
  template<typename T>
  class IResource {
    public:
      virtual ~IResource() = default;
      virtual void createResource(JsonDocument& json, std::shared_ptr<T> dto = nullptr, const char* username = nullptr) = 0;
  };
}
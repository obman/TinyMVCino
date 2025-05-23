#pragma once

#include <string>

namespace TinyMVCino {

  class IControllerType {
  public:
    virtual std::string toString() const = 0;
    virtual ~IControllerType() = default;
  };

}

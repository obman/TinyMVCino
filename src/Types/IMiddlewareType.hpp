#pragma once

#include <string>

namespace TinyMVCino {

  class IMiddlewareType {
  public:
    virtual std::string toString() const = 0;
    virtual ~IMiddlewareType() = default;
  };

}

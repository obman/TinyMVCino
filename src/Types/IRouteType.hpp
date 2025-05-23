#pragma once

#include <string>

namespace TinyMVCino {

  class IRouteType {
  public:
    virtual std::string toString() const = 0;
    virtual ~IRouteType() = default;
  };

}

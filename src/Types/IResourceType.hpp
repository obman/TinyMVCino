#pragma once

#include <string>

namespace TinyMVCino {

  class IResourceType {
  public:
    virtual std::string toString() const = 0;
    virtual ~IResourceType() = default;
  };

}

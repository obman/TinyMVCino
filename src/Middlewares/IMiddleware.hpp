#pragma once

namespace TinyMVCino {
  class IMiddleware {
    public:
      virtual ~IMiddleware() = default;
      //virtual void setup() = 0; // just as example
      //virtual void handleRequest() = 0;
  };
}
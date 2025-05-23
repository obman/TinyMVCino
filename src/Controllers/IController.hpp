#pragma once

namespace TinyMVCino {
  class IController {
    public:
      virtual ~IController() = default;
      //virtual void setup() = 0; // just as example
      //virtual void handleRequest() = 0;
  };
}
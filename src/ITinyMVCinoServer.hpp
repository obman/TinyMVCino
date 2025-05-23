#pragma once

namespace TinyMVCino {
  class BaseServer {
    protected:
      virtual void registerServices() = 0;

    public:
      virtual ~BaseServer() = default;
      //virtual void setup() = 0; // just as example
  };
}
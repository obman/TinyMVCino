#pragma once

namespace TinyMVCino {
  class IRoute {
    public:
      virtual ~IRoute() = default;
      virtual void registerRoutes() = 0;
  };
}
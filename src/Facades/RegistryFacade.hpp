#pragma once

#include "../Registers/ControllerRegistry.hpp"
#include "../Registers/MiddlewareRegistry.hpp"

namespace TinyMVCino {

  class RegistryFacade {
    private:
      RegistryFacade() = default;

    public:
      static RegistryFacade& getInstance() {
        static RegistryFacade instance;
        return instance;
      }

      // Controllers
      ControllerRegistry& controllers() {
        return ControllerRegistry::getInstance();
      }

      // Middlewares
      MiddlewareRegistry& middlewaress() {
        return MiddlewareRegistry::getInstance();
      }

      // Resources

      // Routes
    };

}
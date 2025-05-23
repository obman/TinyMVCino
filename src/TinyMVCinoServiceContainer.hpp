#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <mutex>
#include "Facades/RegistryFacade.hpp"
#include "Middlewares/Auth/ApiGuardMiddleware.hpp"

namespace TinyMVCino {
  class ServiceContainer {
    private:
      std::unordered_map<std::string, std::shared_ptr<void>> services;
      mutable std::mutex mtx;

      template<typename T>
      static const char* typeKey() {
        // Unique string per type, no RTTI required
        static const char key = 0;
        return reinterpret_cast<const char*>(&key);
      }

    public:
        ServiceContainer(bool enableApiGuard = true) {
          auto facade = std::shared_ptr<RegistryFacade>(&RegistryFacade::getInstance(), [](RegistryFacade*) {});
          auto apiGuard = std::make_shared<ApiGuardMiddleware>();
          registerService<RegistryFacade>(facade);
          if (enableApiGuard) {
            registerService<ApiGuardMiddleware>(apiGuard);
          }
        }

        template<typename T>
        void registerService(std::shared_ptr<T> service) {
          std::lock_guard<std::mutex> lock(mtx);
          services[typeKey<T>()] = service;
        }

        template<typename T>
        std::shared_ptr<T> getService() const {
          std::lock_guard<std::mutex> lock(mtx);
          auto it = services.find(typeKey<T>());
          if (it != services.end()) {
            return std::static_pointer_cast<T>(it->second);
          }
          return nullptr;
        }

        // Shortcut to the facade
        std::shared_ptr<RegistryFacade> getRegistryFacade() const {
          return getService<RegistryFacade>();
        }
    
        virtual ~ServiceContainer() = default;
    };
}
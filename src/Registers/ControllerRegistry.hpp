#pragma once

#include <unordered_map>
#include <memory>
#include <mutex>
#include <string>
#include "../Types/IControllerType.hpp"
#include "TinyMVCino/Common/SharedObject.hpp"

namespace TinyMVCino {

  class ControllerRegistry {
  private:
    std::unordered_map<std::string, SharedObject> controllers;
    mutable std::mutex mtx;

    ControllerRegistry() = default;

  public:
    static ControllerRegistry& getInstance() {
      static ControllerRegistry instance;
      return instance;
    }

    template<typename T>
    void registerItem(const IControllerType& type, std::shared_ptr<T> controller) {
      std::lock_guard<std::mutex> lock(mtx);
      controllers[type.toString()] = SharedObject(controller);
    }

    template<typename T>
    std::shared_ptr<T> getItem(const IControllerType& type) const {
      std::lock_guard<std::mutex> lock(mtx);
      auto it = controllers.find(type.toString());
      if (it != controllers.end()) {
        return it->second.cast<T>();
      }
      return nullptr;
    }

  };

}
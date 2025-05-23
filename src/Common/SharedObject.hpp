#pragma once

#include <memory>

namespace TinyMVCino {

  class SharedObject {
  public:
    SharedObject() = default;

    template<typename T>
    SharedObject(std::shared_ptr<T> ptr)
      : holder(std::make_shared<HolderImpl<T>>(std::move(ptr))) {}

    template<typename T>
    std::shared_ptr<T> cast() const {
      if (!holder) return nullptr;
      return holder->cast<T>();
    }

    bool valid() const {
      return holder != nullptr;
    }

  private:
    struct IHolder {
      virtual ~IHolder() {}
      virtual std::shared_ptr<void> raw() const = 0;
      virtual const void* type_id() const = 0;

      template<typename T>
      std::shared_ptr<T> cast() const {
        if (type_id() == type_tag<T>()) {
          return std::static_pointer_cast<T>(raw());
        }
        return nullptr;
      }

      protected:
        template<typename T>
        static const void* type_tag() {
          static const char tag = 0;
          return &tag;
        }
    };
    std::shared_ptr<IHolder> holder;

    template<typename T>
    struct HolderImpl : IHolder {
      std::shared_ptr<T> value;
      explicit HolderImpl(std::shared_ptr<T> v) : value(std::move(v)) {}

      std::shared_ptr<void> raw() const override {
        return value;
      }

      const void* type_id() const override {
        return IHolder::type_tag<T>();
      }
    };
  };

}
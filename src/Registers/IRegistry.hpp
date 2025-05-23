#pragma once

namespace TinyMVCino {
  template <typename KeyT, typename ValueT>
  class IRegistry {
    public:
      virtual void registerItem(const KeyT& key, std::shared_ptr<ValueT> value) = 0;
      virtual std::shared_ptr<ValueT> getItem(const KeyT& key) const = 0;
      virtual ~IRegistry() = default;
  };
}
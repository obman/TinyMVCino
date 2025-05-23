#pragma once

#include <Preferences.h>

namespace TinyMVCino {
  class IDal {
    protected:
        mutable Preferences preferences;
        const char* prefNamespace;

        void open() {
            preferences.begin(prefNamespace, false);
        }
        void close() {
            preferences.end();
        }
    
    public:
        IDal(const char* ns) : prefNamespace(ns) {};
        virtual ~IDal() = default;
    };
}
  
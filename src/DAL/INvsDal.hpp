#pragma once

#include <Preferences.h>
#include "IDal.hpp"

namespace TinyMVCino {
  class INvsDal : public IDal {
    protected:
        mutable Preferences preferences;
        const char* prefNamespace;

        void open() override {
            this->preferences.begin(prefNamespace, false);
        }
        void close() override {
            this->preferences.end();
        }

        String getDalDataString(const char* key, const String& defaultVal) override {
            open();
            String value = this->preferences.getString(key, defaultVal);
            close();
            return value;
        }

        int getDalDataInt(const char* key, int defaultVal) override {
            open();
            int value = this->preferences.getInt(key, defaultVal);
            close();
            return value;
        }

        float getDalDataFloat(const char* key, float defaultVal) override {
            open();
            float value = this->preferences.getFloat(key, defaultVal);
            close();
            return value;
        }

        double getDalDataDouble(const char* key, double defaultVal) override {
            open();
            double value = this->preferences.getDouble(key, defaultVal);
            close();
            return value;
        }

        bool getDalDataBool(const char* key, bool defaultVal) override {
            open();
            bool value = this->preferences.getBool(key, defaultVal);
            close();
            return value;
        }

        // Save
        bool storeDalDataString(const char* key, const char* const& value) override {
            open();
            bool result = this->preferences.putString(key, value);
            close();
            return result;
        }

        bool storeDalDataInt(const char* key, int value) override {
            open();
            bool result = this->preferences.putInt(key, value);
            close();
            return result;
        }

        bool storeDalDataFloat(const char* key, float value) override {
            open();
            bool result = this->preferences.putFloat(key, value);
            close();
            return result;
        }

        bool storeDalDataDouble(const char* key, double value) override {
            open();
            bool result = this->preferences.putDouble(key, value);
            close();
            return result;
        }

        bool storeDalDataBool(const char* key, bool value) override {
            open();
            bool result = this->preferences.putBool(key, value);
            close();
            return result;
        }
    
    public:
        INvsDal(const char* ns) : prefNamespace(ns) {};
        virtual ~INvsDal() = default;
    };
}
  
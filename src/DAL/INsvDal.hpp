#pragma once

#include <Preferences.h>
#include "IDal.hpp"

namespace TinyMVCino {
  class INsvDal : public IDal {
    protected:
        mutable Preferences preferences;
        const char* prefNamespace;

        void open() override {
            this->preferences.begin(prefNamespace, false);
        }
        void close() override {
            this->preferences.end();
        }

        String getValue(const char* key, const String& defaultValue = "") {
            return this->preferences.getString(key, defaultValue);
        }
        int getValue(const char* key, const int& defaultValue) {
            return this->preferences.getInt(key, defaultValue);
        }
        bool getValue(const char* key, const bool& defaultValue) {
            return this->preferences.getBool(key, defaultValue);
        }
        float getValue(const char* key, const float& defaultValue) {
            return this->preferences.getFloat(key, defaultValue);
        }
        double getValue(const char* key, const double& defaultValue) {
            return this->preferences.getDouble(key, defaultValue);
        }

        bool putValue(const char* key, const char* value) {
            return this->preferences.putString(key, value);
        }
        bool putValue(const char* key, int value) {
            return this->preferences.putInt(key, value);
        }
        bool putValue(const char* key, bool value) {
            return this->preferences.putBool(key, value);
        }
        bool putValue(const char* key, float value) {
            return this->preferences.putFloat(key, value);
        }
        bool putValue(const char* key, double value) {
            return this->preferences.putDouble(key, value);
        }

        /*String getDalDataString(const char* key, const String& defaultVal) override {
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
        }*/
    
    public:
        INsvDal(const char* ns) : prefNamespace(ns) {};
        virtual ~INsvDal() = default;

        template <typename T>
        T getDalData(const char* key, const T& defaultValue) {
            this->open();
            T data = this->getValue(key, defaultValue);
            this->close();
            return data;
        }

        template <typename T>
        bool storeDalData(const char* key, const T& value) {
            this->open();
            bool result = this->putValue(key, value);
            this->close();
            return result;
        }
    };
}
  
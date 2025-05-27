#pragma once

//#include <Arduino.h>

namespace TinyMVCino {
  class IDal {
    protected:
        virtual void open() = 0;
        virtual void close() = 0;

        /*
        virtual String getDalDataString(const char* key, const String& defaultVal) = 0;
        virtual int getDalDataInt(const char* key, int defaultVal) = 0;
        virtual float getDalDataFloat(const char* key, float defaultVal) = 0;
        virtual double getDalDataDouble(const char* key, double defaultVal) = 0;
        virtual bool getDalDataBool(const char* key, bool defaultVal) = 0;
        // TODO: add missing data type

        virtual bool storeDalDataString(const char* key, const char* const& value) = 0;
        virtual bool storeDalDataInt(const char* key, int value) = 0;
        virtual bool storeDalDataFloat(const char* key, float value) = 0;
        virtual bool storeDalDataDouble(const char* key, double value) = 0;
        virtual bool storeDalDataBool(const char* key, bool value) = 0;
        // TODO: add missing data type
        */
    
    public:
        IDal() {};
        virtual ~IDal() = default;

        /*template<typename T>
        T getDalData(const char* key, const T& defaultVal);

        template<typename T>
        bool storeDalData(const char* key, const T& value);*/
    };
}

// INCLUDE THE TPP FILE HERE
//#include "IDal.tpp"
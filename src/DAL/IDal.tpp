#include "IDal.hpp"

// GET
template<>
inline String TinyMVCino::IDal::getDalData<String>(const char* key, const String& defaultVal) {
  return this->getDalDataString(key, defaultVal);
}

template<>
inline int TinyMVCino::IDal::getDalData<int>(const char* key, const int& defaultVal) {
  return this->getDalDataInt(key, defaultVal);
}

template<>
inline float TinyMVCino::IDal::getDalData<float>(const char* key, const float& defaultVal) {
  return this->getDalDataFloat(key, defaultVal);
}

template<>
inline double TinyMVCino::IDal::getDalData<double>(const char* key, const double& defaultVal) {
  return this->getDalDataDouble(key, defaultVal);
}

template<>
inline bool TinyMVCino::IDal::getDalData<bool>(const char* key, const bool& defaultVal) {
  return this->getDalDataBool(key, defaultVal);
}

// SAVE
template<>
inline bool TinyMVCino::IDal::storeDalData<const char*>(const char* key, const char* const& value) {
  return this->storeDalDataString(key, value);
}

template<>
inline bool TinyMVCino::IDal::storeDalData<int>(const char* key, const int& value) {
  return this->storeDalDataInt(key, value);
}

template<>
inline bool TinyMVCino::IDal::storeDalData<float>(const char* key, const float& value) {
  return this->storeDalDataFloat(key, value);
}

template<>
inline bool TinyMVCino::IDal::storeDalData<double>(const char* key, const double& value) {
  return this->storeDalDataDouble(key, value);
}

template<>
inline bool TinyMVCino::IDal::storeDalData<bool>(const char* key, const bool& value) {
  return this->storeDalDataBool(key, value);
}
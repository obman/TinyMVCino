#include "LoginSecurityService.hpp"

namespace TinyMVCino {
  Preferences LoginSecurityService::storage;

  bool LoginSecurityService::isBlocked() {
    storage.begin(TINYMVCINO_SERVER_PREF_NAMESPACE, true);
    int attempts = storage.getInt(TINYMVCINO_SERVER_FAILED_LOGIN_NUM_PREF_KEY, 0);
    unsigned long last = storage.getULong(TINYMVCINO_SERVER_FAILED_LAST_LOGIN_TIME_PREF_KEY, 0);
    storage.end();
  
    if (attempts >= 5 && (millis() - last < TINYMVCINO_SERVER_LOGIN_BLOCK_TIME)) { // blocked for 180s 
      return true;
    }
    return false;
  }

  void LoginSecurityService::registerFailedAttempt() {
    storage.begin(TINYMVCINO_SERVER_PREF_NAMESPACE, false);
    int attempts = storage.getInt(TINYMVCINO_SERVER_FAILED_LOGIN_NUM_PREF_KEY, 0) + 1;
    storage.putInt(TINYMVCINO_SERVER_FAILED_LOGIN_NUM_PREF_KEY, attempts);
    storage.putULong(TINYMVCINO_SERVER_FAILED_LAST_LOGIN_TIME_PREF_KEY, millis());
    storage.end();
  }

  void LoginSecurityService::resetFailedAttempts() {
    storage.begin(TINYMVCINO_SERVER_PREF_NAMESPACE, false);
    storage.putInt(TINYMVCINO_SERVER_FAILED_LOGIN_NUM_PREF_KEY, 0);
    storage.putULong(TINYMVCINO_SERVER_FAILED_LAST_LOGIN_TIME_PREF_KEY, 0);
    storage.end();
  }
}
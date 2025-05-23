#pragma once

#include "Preferences.h"
#include "../../Config/ServerConfig.hpp"

namespace TinyMVCino {
  class LoginSecurityService {
    private:
      static Preferences storage;
  
    public:
      LoginSecurityService() = default;
      static bool isBlocked();
      static void registerFailedAttempt();
      static void resetFailedAttempts();
  };
}
#pragma once

#include "ESPAsyncWebServer.h"
#include "../IMiddleware.hpp"

namespace TinyMVCino {
  class ApiGuardMiddleware : public TinyMVCino::IMiddleware {
    public:
      ApiGuardMiddleware() = default;
      bool hasValidAccessToken(AsyncWebServerRequest *request, const char* accessToken);
      bool hasValidRefreshToken(AsyncWebServerRequest *request, const char* accessToken);
  };
}
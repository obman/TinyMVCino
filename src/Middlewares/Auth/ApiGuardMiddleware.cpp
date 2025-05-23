#include "ApiGuardMiddleware.hpp"

namespace TinyMVCino {
  bool ApiGuardMiddleware::hasValidAccessToken(AsyncWebServerRequest *request, const char* accessToken) {
    AsyncWebHeader* bearerToken = request->getHeader("Authorization");
    if (!bearerToken) {
      request->send(403, "application/json", "{\"error\":\"Unauthorized - Missing Authorization header\"}");
      return false;
    }
  
    String value = bearerToken->value();
    if (!value.startsWith("Bearer ")) {
      request->send(403, "application/json", "{\"error\":\"Unauthorized - Invalid token format\"}");
      return false;
    }
  
    String token = value.substring(7);
    if (accessToken == nullptr || strlen(accessToken) == 0) {
      request->send(403, "application/json", "{\"error\":\"Unauthorized - Empty access token\"}");
      return false;
    }
    
    if (token != accessToken) {
      request->send(403, "application/json", "{\"error\":\"Unauthorized - Token mismatch\"}");
      return false;
    }

    return true;
  };
  
  bool ApiGuardMiddleware::hasValidRefreshToken(AsyncWebServerRequest *request, const char* accessToken) {
    AsyncWebHeader* cookieHeader = request->getHeader("Cookie");  
    if (!cookieHeader) {
      request->send(403, "application/json", "{\"error\":\"Unauthorized - No cookies provided\"}");
      return false;
    }
  
    String cookies = cookieHeader->value();
    if (cookies.indexOf("refresh_token") == -1) {
      request->send(403, "application/json", "{\"error\":\"Unauthorized - Refresh token not found\"}");
      return false;
    }

    return true;
  };
}
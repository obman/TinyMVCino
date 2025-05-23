#pragma once

#include "mbedtls/md.h"
#include <string.h>
#include <cstdio>
#include "../Config/ChiperConfig.hpp"

namespace TinyMVCino {
  class Encrypter {
    public:
      Encrypter() = default;

      static void hash(char* value) {
        if (!value) {
            return;
        }
      
        char saltedInput[128];
        Serial.println("Salt: " + String(TINYMVCINO_CHIPER_SALT));
        snprintf(saltedInput, sizeof(saltedInput), "%s%s", value, TINYMVCINO_CHIPER_SALT);
      
        unsigned char hash[32]; // SHA-256 produces 32-byte hash
        mbedtls_md_context_t ctx;
        const size_t inputLen = strlen(value);
      
        // Initialize and compute hash
        mbedtls_md_init(&ctx);
        mbedtls_md_setup(&ctx, mbedtls_md_info_from_type(MBEDTLS_MD_SHA256), 0);
        mbedtls_md_starts(&ctx);
        mbedtls_md_update(&ctx, (const unsigned char*)saltedInput, strlen(saltedInput));
        mbedtls_md_finish(&ctx, hash);
        mbedtls_md_free(&ctx);
      
        // Convert binary hash to hex string
        char hexHash[65];
        uint8_t i = 0;
        for (; i < 32; i++) {
          snprintf(&hexHash[i * 2], 3, "%02x", hash[i]); // always write 2 chars + null
        }
        hexHash[64] = '\0';
        strncpy(value, hexHash, 65);
      };

      static bool verify(const char* plainText, const char* storedHash) {
        if (!plainText || !storedHash) return false;
      
        char hashBuffer[TINYMVCINO_HASH_LENGTH];
        strncpy(hashBuffer, plainText, sizeof(hashBuffer) - 1);
        hashBuffer[sizeof(hashBuffer) - 1] = '\0';
      
        TinyMVCino::Encrypter::hash(hashBuffer);
        return strcmp(hashBuffer, storedHash) == 0;
      };
  };
}
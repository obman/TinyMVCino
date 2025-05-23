#pragma once

#ifndef TINYMVCINO_CHIPER_SALT
  #define TINYMVCINO_CHIPER_SALT ""
#endif
#ifndef TINYMVCINO_HASH_LENGTH
  #define TINYMVCINO_HASH_LENGTH 65
#endif

#ifndef TINYMVCINO_AES_ENCRYPTION_BIT_KEY
  #define TINYMVCINO_AES_ENCRYPTION_BIT_KEY 128
#endif
#ifndef TINYMVCINO_AES_KEY
  #define TINYMVCINO_AES_KEY \
    { \
      0x00,0x01,0x02,0x03, \
      0x04,0x05,0x06,0x07, \
      0x08,0x09,0x0A,0x0B, \
      0x0C,0x0D,0x0E,0x0F  \
    }
#endif
static constexpr uint8_t AES_KEY[16] = TINYMVCINO_AES_KEY;

#ifndef TINYMVCINO_AES_IV
  #define TINYMVCINO_AES_IV \
    { \
      0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08, \
      0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00, \
    }
#endif
static constexpr uint8_t AES_IV[16] = TINYMVCINO_AES_IV;
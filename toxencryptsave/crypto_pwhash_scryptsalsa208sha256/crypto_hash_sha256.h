#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef  VANILLA_NACL /* toxcore only uses this when libsodium is unavailable */

#ifndef crypto_hash_sha256_H
#define crypto_hash_sha256_H

/*
 * WARNING: Unless you absolutely need to use SHA256 for interoperatibility,
 * purposes, you might want to consider crypto_generichash() instead.
 * Unlike SHA256, crypto_generichash() is not vulnerable to length
 * extension attacks.
 */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "export.h"

#ifdef __cplusplus
# if __GNUC__
#  pragma GCC diagnostic ignored "-Wlong-long"
# endif
extern "C" {
#endif

typedef struct crypto_hash_sha256_state {
    uint32_t      state[8];
    uint32_t      count[2];
    unsigned char buf[64];
} crypto_hash_sha256_state;

#define crypto_hash_sha256_BYTES 32U
SODIUM_EXPORT
size_t crypto_hash_sha256_bytes(void);

SODIUM_EXPORT
int crypto_hash_sha256(unsigned char *out, const unsigned char *in,
                       unsigned long long inlen);

SODIUM_EXPORT
int crypto_hash_sha256_init(crypto_hash_sha256_state *state);

SODIUM_EXPORT
int crypto_hash_sha256_update(crypto_hash_sha256_state *state,
                              const unsigned char *in,
                              unsigned long long inlen);

SODIUM_EXPORT
int crypto_hash_sha256_final(crypto_hash_sha256_state *state,
                             unsigned char *out);

#ifdef __cplusplus
}
#endif

#endif

#endif

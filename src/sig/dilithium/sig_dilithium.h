#ifndef __OQS_SIG_DILITHIUM_H
#define __OQS_SIG_DILITHIUM_H

#include <oqs/oqs.h>

#define SEEDBYTES 32U
#define CRHBYTES 48U
#define N 256U
#define Q 8380417U
#define QBITS 23U
#define ROOT_OF_UNITY 1753U
#define D 14U
#define GAMMA1 ((Q - 1U)/16U)
#define GAMMA2 (GAMMA1/2U)
#define ALPHA (2U*GAMMA2)


#ifdef OQS_ENABLE_SIG_dilithium_L3

#define K 5U
#define L 4U
#define ETA 5U
#define SETABITS 4U
#define BETA 275U
#define OMEGA 96U

OQS_SIG *OQS_SIG_dilithium_L3_new();

OQS_API OQS_STATUS OQS_SIG_dilithium_L3_keypair(uint8_t *public_key, uint8_t *secret_key);
OQS_API OQS_STATUS OQS_SIG_dilithium_L3_sign(uint8_t *signature, size_t *signature_len, const uint8_t *message, size_t message_len, const uint8_t *secret_key);
OQS_API OQS_STATUS OQS_SIG_dilithium_L3_verify(const uint8_t *message, size_t message_len, const uint8_t *signature, size_t signature_len, const uint8_t *public_key);

#endif // OQS_ENABLE_SIG_dilithium_L3


#define POL_SIZE_PACKED ((N*QBITS)/8)
#define POLT1_SIZE_PACKED ((N*(QBITS - D))/8)
#define POLT0_SIZE_PACKED ((N*D)/8)
#define POLETA_SIZE_PACKED ((N*SETABITS)/8)
#define POLZ_SIZE_PACKED ((N*(QBITS - 3))/8)
#define POLW1_SIZE_PACKED ((N*4)/8)
#define POLVECK_SIZE_PACKED (K*POL_SIZE_PACKED)
#define POLVECL_SIZE_PACKED (L*POL_SIZE_PACKED)

#define CRYPTO_PUBLICKEYBYTES (SEEDBYTES + K*POLT1_SIZE_PACKED)
#define CRYPTO_SECRETKEYBYTES (2*SEEDBYTES + (L + K)*POLETA_SIZE_PACKED + CRHBYTES + K*POLT0_SIZE_PACKED)
#define CRYPTO_BYTES (L*POLZ_SIZE_PACKED + (OMEGA + K) + (N/8 + 8))

#endif // __OQS_SIG_DILITHIUM_H

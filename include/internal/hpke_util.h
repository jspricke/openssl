/*
 * Copyright 2022 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

<<<<<<< HEAD
<<<<<<< HEAD
#ifndef OSSL_INTERNAL_HPKE_UTIL_H
# define OSSL_INTERNAL_HPKE_UTIL_H
=======
#ifndef OSSL_CRYPTO_HPKE_H
# define OSSL_CRYPTO_HPKE_H
>>>>>>> 788a6e16af (rebased and latest HPKE (still leaks, will fix in a bit))
=======
#ifndef OSSL_INTERNAL_HPKE_UTIL_H
# define OSSL_INTERNAL_HPKE_UTIL_H
>>>>>>> f94c4f04a1 (more PR comments)
# pragma once

/* Constants from RFC 9180 Section 7.1 and 7.3 */
# define OSSL_HPKE_MAX_SECRET 64
# define OSSL_HPKE_MAX_PUBLIC 133
# define OSSL_HPKE_MAX_PRIVATE 66
<<<<<<< HEAD
<<<<<<< HEAD
# define OSSL_HPKE_MAX_KDF_INPUTLEN 64

/*
 * max length of a base-nonce (the Nn field from OSSL_HPKE_AEAD_INFO), this
 * is used for a local stack array size
 */
# define OSSL_HPKE_MAX_NONCELEN 12

/*
 * @brief info about a KEM
 * Used to store constants from Section 7.1 "Table 2 KEM IDs"
 * and the bitmask for EC curves described in Section 7.1.3 DeriveKeyPair
 */
typedef struct {
    uint16_t      kem_id; /* code point for key encipherment method */
    const char    *keytype; /* string form of algtype "EC"/"X25519"/"X448" */
    const char    *groupname; /* string form of EC group for NIST curves  */
    const char    *mdname; /* hash alg name for the HKDF */
    size_t        Nsecret; /* size of secrets */
    size_t        Nenc; /* length of encapsulated key */
    size_t        Npk; /* length of public key */
    size_t        Nsk; /* length of raw private key */
    uint8_t       bitmask;
} OSSL_HPKE_KEM_INFO;

/*
 * @brief info about a KDF
 */
typedef struct {
    uint16_t       kdf_id; /* code point for KDF */
    const char     *mdname; /* hash alg name for the HKDF */
    size_t         Nh; /* length of hash/extract output */
} OSSL_HPKE_KDF_INFO;

/*
 * @brief info about an AEAD
 */
typedef struct {
    uint16_t       aead_id; /* code point for aead alg */
    const char     *name;   /* alg name */
    size_t         taglen; /* aead tag len */
    size_t         Nk; /* size of a key for this aead */
    size_t         Nn; /* length of a nonce for this aead */
} OSSL_HPKE_AEAD_INFO;

const OSSL_HPKE_KEM_INFO *ossl_HPKE_KEM_INFO_find_curve(const char *curve);
const OSSL_HPKE_KEM_INFO *ossl_HPKE_KEM_INFO_find_id(uint16_t kemid);
const OSSL_HPKE_KEM_INFO *ossl_HPKE_KEM_INFO_find_random(OSSL_LIB_CTX *ctx);
const OSSL_HPKE_KDF_INFO *ossl_HPKE_KDF_INFO_find_id(uint16_t kdfid);
const OSSL_HPKE_KDF_INFO *ossl_HPKE_KDF_INFO_find_random(OSSL_LIB_CTX *ctx);
const OSSL_HPKE_AEAD_INFO *ossl_HPKE_AEAD_INFO_find_id(uint16_t aeadid);
const OSSL_HPKE_AEAD_INFO *ossl_HPKE_AEAD_INFO_find_random(OSSL_LIB_CTX *ctx);

=======
# define OSSL_HPKE_MAX_NONCE 12
=======
>>>>>>> fabc0ea89d (more PR nits)
# define OSSL_HPKE_MAX_KDF_INPUTLEN 64

<<<<<<< HEAD
>>>>>>> 788a6e16af (rebased and latest HPKE (still leaks, will fix in a bit))
=======
/*
 * max length of a base-nonce (the Nn field from OSSL_HPKE_AEAD_INFO), this
 * is used for a local stack array size
 */
# define OSSL_HPKE_MAX_NONCELEN 12

/*
 * @brief info about a KEM
 * Used to store constants from Section 7.1 "Table 2 KEM IDs"
 * and the bitmask for EC curves described in Section 7.1.3 DeriveKeyPair
 */
typedef struct {
    uint16_t      kem_id; /* code point for key encipherment method */
    const char    *keytype; /* string form of algtype "EC"/"X25519"/"X448" */
    const char    *groupname; /* string form of EC group for NIST curves  */
    const char    *mdname; /* hash alg name for the HKDF */
    size_t        Nsecret; /* size of secrets */
    size_t        Nenc; /* length of encapsulated key */
    size_t        Npk; /* length of public key */
    size_t        Nsk; /* length of raw private key */
    uint8_t       bitmask;
} OSSL_HPKE_KEM_INFO;

/*
 * @brief info about a KDF
 */
typedef struct {
    uint16_t       kdf_id; /* code point for KDF */
    const char     *mdname; /* hash alg name for the HKDF */
    size_t         Nh; /* length of hash/extract output */
} OSSL_HPKE_KDF_INFO;

/*
 * @brief info about an AEAD
 */
typedef struct {
    uint16_t       aead_id; /* code point for aead alg */
    const char     *name;   /* alg name */
    size_t         taglen; /* aead tag len */
    size_t         Nk; /* size of a key for this aead */
    size_t         Nn; /* length of a nonce for this aead */
} OSSL_HPKE_AEAD_INFO;

/*
 * table with identifier and synonym strings
 * right now, there are 4 synonyms for each - a name, a hex string
 * a hex string with a leading zero and a decimal string - more
 * could be added but that seems like enough
 */
typedef struct OSSL_HPKE_synonymtab_str {
    uint16_t id;
    char *synonyms[4];
} synonymttab_t;

const OSSL_HPKE_KEM_INFO *ossl_HPKE_KEM_INFO_find_curve(const char *curve);
const OSSL_HPKE_KEM_INFO *ossl_HPKE_KEM_INFO_find_id(uint16_t kemid);
const OSSL_HPKE_KEM_INFO *ossl_HPKE_KEM_INFO_find_random(OSSL_LIB_CTX *ctx);
const OSSL_HPKE_KDF_INFO *ossl_HPKE_KDF_INFO_find_id(uint16_t kdfid);
const OSSL_HPKE_KDF_INFO *ossl_HPKE_KDF_INFO_find_random(OSSL_LIB_CTX *ctx);
const OSSL_HPKE_AEAD_INFO *ossl_HPKE_AEAD_INFO_find_id(uint16_t aeadid);
const OSSL_HPKE_AEAD_INFO *ossl_HPKE_AEAD_INFO_find_random(OSSL_LIB_CTX *ctx);

>>>>>>> ffba35cfa5 (latest HPKE and removed draft-10 code; has small leak on server exit)
int ossl_hpke_kdf_extract(EVP_KDF_CTX *kctx,
                          unsigned char *prk, size_t prklen,
                          const unsigned char *salt, size_t saltlen,
                          const unsigned char *ikm, size_t ikmlen);

int ossl_hpke_kdf_expand(EVP_KDF_CTX *kctx,
                         unsigned char *okm, size_t okmlen,
                         const unsigned char *prk, size_t prklen,
                         const unsigned char *info, size_t infolen);

int ossl_hpke_labeled_extract(EVP_KDF_CTX *kctx,
                              unsigned char *prk, size_t prklen,
                              const unsigned char *salt, size_t saltlen,
                              const char *protocol_label,
                              const unsigned char *suiteid, size_t suiteidlen,
                              const char *label,
                              const unsigned char *ikm, size_t ikmlen);
int ossl_hpke_labeled_expand(EVP_KDF_CTX *kctx,
                             unsigned char *okm, size_t okmlen,
                             const unsigned char *prk, size_t prklen,
                             const char *protocol_label,
                             const unsigned char *suiteid, size_t suiteidlen,
                             const char *label,
                             const unsigned char *info, size_t infolen);

EVP_KDF_CTX *ossl_kdf_ctx_create(const char *kdfname, const char *mdname,
                                 OSSL_LIB_CTX *libctx, const char *propq);

<<<<<<< HEAD
<<<<<<< HEAD
int ossl_hpke_str2suite(const char *suitestr, OSSL_HPKE_SUITE *suite);
=======
>>>>>>> 788a6e16af (rebased and latest HPKE (still leaks, will fix in a bit))
=======
int ossl_hpke_str2suite(const char *suitestr, OSSL_HPKE_SUITE *suite);
>>>>>>> ffba35cfa5 (latest HPKE and removed draft-10 code; has small leak on server exit)
#endif

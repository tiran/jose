/* vim: set tabstop=8 shiftwidth=4 softtabstop=4 expandtab smarttab colorcolumn=80: */
/*
 * Copyright 2016 Red Hat, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <jansson.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * Adds an additional signature to the JWS using the specified JWK.
 *
 * The jws parameter is modified to contain the new signature.
 *
 * The sig parameter optionally contains a template to use for the signature.
 */
bool
jose_jws_sign(json_t *jws, const json_t *jwk, const json_t *sig);

/**
 * Verififes a signature in a JWS using the specified JWK.
 *
 * If you would like to verify a particular signature object, you may specify
 * it in the sig parameter. Otherwise, simply pass NULL to find out if any
 * signature verifies.
 */
bool
jose_jws_verify(const json_t *jws, const json_t *jwk, const json_t *sig);

/**
 * Merges the protected and unprotected headers into the single JOSE header.
 *
 * WARNING: This function does not verify the protected header. You MUST call
 * jose_jws_verify() with the specific signature object containing the header
 * you want to merge to ensure that the protected header has not been modified.
 */
json_t *
jose_jws_merge_header(const json_t *sig);

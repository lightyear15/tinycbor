/****************************************************************************
**
** Copyright (C) 2015 Intel Corporation
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
** THE SOFTWARE.
**
****************************************************************************/

#ifndef CBORJSON_H
#define CBORJSON_H

#include "cbor.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Conversion to JSON */
enum CborToJsonFlags
{
    CborConvertAddMetadata = 1,
    CborConvertTagsToObjects = 2,
    CborConvertIgnoreTags = 0,

    CborConvertObeyByteStringTags = 0,
    CborConvertByteStringsToBase64Url = 4,

    CborConvertRequireMapStringKeys = 0,
    CborConvertStringifyMapKeys = 8,

    CborConvertDefaultFlags = 0
};

typedef struct {
    char *const buffer;
    const size_t buffer_len;
    size_t pos;
} MEMFILE;

#define MEMFILE_INIT(buf, buf_len) { .buffer = (buf), .buffer_len = (buf_len), .pos = 0 }

CBOR_API CborError cbor_value_to_json_advance(MEMFILE *out, CborValue *value, int flags);
CBOR_API CborError cbor_value_to_json(MEMFILE *out, const CborValue *value, int flags);

#ifdef __cplusplus
}
#endif

#endif /* CBORJSON_H */


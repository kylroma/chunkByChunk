#ifndef INFO_H
#define INFO_H
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace  std;

#define MAX_BUF 1024
#define MAX_CHUNK 512

typedef struct {
    uint8_t buf[MAX_CHUNK];
    uint32_t size;
    bool isEndFile;
} CHUNK;

typedef struct {
    uint16_t getMaxSize;
    uint32_t position;
} GET_CHUNK;

#endif // INFO_H

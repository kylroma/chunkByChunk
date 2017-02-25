#ifndef UM_H
#define UM_H

#include "info.h"


class UC;

class UM
{
public:
    UM();
    ~UM();
    bool readFile(const GET_CHUNK &getChunk);
    void init(UC *uc);
private:
    bool openFile(uint32_t position);//const GET_CHUNK &getChunk);
    uint8_t buf[MAX_BUF];
    UC *mUc;
FILE *fp;
    uint32_t positionBigChunk;
    uint32_t sizeBigChunk;
    bool isValidChunk;
};

#endif // UM_H

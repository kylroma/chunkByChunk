#ifndef UC_H
#define UC_H

#include "info.h"
#include "um.h"

class  UM;

class UC
{
public:
    UC();
    ~UC();
    void writeFile(const CHUNK & chunk);
    void run();
    void init();
private:
    saveFile();
    UM mUm;
    uint32_t position;
    GET_CHUNK getChunk;
    FILE *fp;
};

#endif // UC_H

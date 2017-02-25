#include "uc.h"

UC::UC() : position(0), mUm(), getChunk()
{
    fp = fopen("newTest.txt", "wb");
}

UC::~UC()
{
    fclose(fp);
}

void UC::init()
{
    mUm.init(this);
    getChunk.position = 0;
    getChunk.getMaxSize = MAX_CHUNK;
}

void UC::run()
{
    if (mUm.readFile(getChunk)) {
       run();
    }
}

void UC::writeFile(const CHUNK & chunk)
{
    //cout << getChunk.position << " ";

    fseek(fp, getChunk.position, SEEK_SET);
    //uint32_t i = 0;
    for(uint32_t i = 0; i<chunk.size; ++i)
    {
        //putc(chunk.buf[i], fp);
        fwrite(&chunk.buf[i], 1, 1, fp);
        //cout << chunk.buf[i];
    }
    getChunk.position += chunk.size;
}

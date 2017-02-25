#include "um.h"
#include "uc.h"

UM::UM() : mUc(nullptr)

  , buf()
  , positionBigChunk(0)
  , sizeBigChunk(MAX_BUF)
  , isValidChunk(false)
{
    fp = fopen("test", "rb");
    if(fp == NULL)
    {
        cout << "Don't open file\n";
    }
}

UM::~UM()
{
    fclose(fp);
}

bool UM::readFile(const GET_CHUNK &getChunk)
{
    bool result = true;
    if(isValidChunk == false)
    {
        result = openFile(getChunk.position);//getChunk);
        positionBigChunk = 0;
    }

    if(result == false)
    {
        return result;
    }

    if(mUc != nullptr)
    {
        CHUNK chank = {0};

        chank.size = getChunk.getMaxSize;
        if(chank.size > sizeBigChunk)
        {
            chank.size = sizeBigChunk;
        }
        memcpy(chank.buf, &buf[positionBigChunk], chank.size);
        positionBigChunk += chank.size;
        if(positionBigChunk >= sizeBigChunk)
        {
            isValidChunk = false;
        }
        mUc->writeFile(chank);
    }
    return result;
}

void UM::init(UC *uc)
{
    mUc = uc;
}

bool UM::openFile(uint32_t position)//const GET_CHUNK &getChunk)
{
    fp = fopen("test", "rb");
    if(fp == NULL)
    {
        cout << "Don't open file\n";
        return false;
    }

    uint8_t n = fseek(fp, position, SEEK_SET);
    if(n != 0)
    {
        return false;
    }
    uint32_t i = 0;
    for(; i<sizeBigChunk;)
    {
        if(fread(&buf[i], 1, 1, fp))
        {
            ++i;
        }
        else {
            break;
        }
    }
    bool result = true;
    sizeBigChunk = i;
    if(sizeBigChunk == 0)
    {
        return false;
    }
    isValidChunk = true;
    return result;
}

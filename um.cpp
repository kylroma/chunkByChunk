#include "um.h"
#include "uc.h"

UM::UM() : mUc(nullptr), mBuffer()


{
    fp = fopen("test", "rb");
    if(fp == NULL)
    {
        cout << "Don't open file\n";
    }
    mBuffer.position = 0;
    mBuffer.validBuf = false;
    mBuffer.size = MAX_BUF;
}

UM::~UM()
{
    fclose(fp);
}

bool UM::readFile(const GET_CHUNK &getChunk)
{
    bool result = true;
    if(mBuffer.validBuf == false)
    {
        result = openFile(getChunk.position);//getChunk);
        mBuffer.position = 0;
        cout << "A";
    }

    if(result == false)
    {
        return result;
    }

    if(mUc != nullptr)
    {
        CHUNK chank = {0};

        chank.size = getChunk.getMaxSize;
        if(chank.size > mBuffer.size)
        {
            chank.size = mBuffer.size;
        }
        memcpy(chank.buf, &mBuffer.buf[mBuffer.position], chank.size);
        mBuffer.position += chank.size;
        cout << mBuffer.position << " " << mBuffer.size << endl;
        if(mBuffer.position >= mBuffer.size)
        {
            mBuffer.validBuf = false;
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
    for(; i<mBuffer.size;)
    {
        if(fread(&mBuffer.buf[i], 1, 1, fp))
        {
            ++i;
        }
        else {
            break;
        }
    }
    bool result = true;
    mBuffer.size = i;
    if(mBuffer.size == 0)
    {
        return false;
    }
    mBuffer.validBuf = true;
    return result;
}

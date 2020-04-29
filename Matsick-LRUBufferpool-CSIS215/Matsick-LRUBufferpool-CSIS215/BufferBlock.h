#pragma once

// Include statemets
#include <iostream>
#include "BufferBlockADT.h"
#include "constants.h"

/*
  Class for a Blocks that are used in a LRU Buffer Pool
  Made using the inherited Buffer Block Abstract Data Type
*/
class BufferBlock : public BufferblockADT {
private:
    int blockID; // ID of the block
    char* block; // One block in the buffer pool
public:
    /*
      sz is the size of the character array data points to.
    */
	BufferBlock() {}
	BufferBlock(char* data, int sz = 4096) {

        // Creates a block with the proper size
        block = getCharArray(sz);					

        // Fills each block with data
        for (int i = 0; i < sz; i++) {
            block[i] = data[i];
        }
    }

    /*
      Destructer
    */
	~BufferBlock() {}

    /* 
      read the block from pos to pos + sz-1 (or to the end of the block)
    */
    void getData(int pos, int sz, char* data) {

        // Finds the position of the data in relation to the block
        pos = pos % BLOCKSIZE;

        // Creates new block with the data
        char* curBlock = getBlock();

        // Loops through to get sz characters from the block
        for (int i = 0; i < sz; i++) {
            data[i] = curBlock[pos + i];
        }
    }

    /*
      setID
    */
    void setID(int id) {
        blockID = id;
    }

    /*
      getID
    */
    int getID() const {
        return blockID;
    }

    /*
      getBlocksize
    */
    int getBlocksize() const {
        return BLOCKSIZE;
    }

    /*
      return the block
    */
    char* getBlock() const {
        return block;
    }
    
    /*
      set the block
    */
    void setBlock(char* blk) {
        block = blk;
    }
};
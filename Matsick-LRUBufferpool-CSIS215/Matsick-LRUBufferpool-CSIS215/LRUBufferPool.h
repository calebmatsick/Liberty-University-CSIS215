#pragma once

// Include statements
#include <fstream>
#include <iostream>
#include <array>
#include <string>
#include "BufferPoolADT.h"
#include "BufferBlock.h"

/*
  Class for a Least Recently Used Buffer Pool
  Made using the inherited Buffer Pool Abstract Data Type
*/
class LRUBufferPool : public BufferPoolADT {
private:
	std::array<BufferBlock*, 5> blockArray; // Array that holds each of the five blocks
	BufferBlock * block; // Block that goes into the buffer pool
	char* data = new char[4096]; // Char that holds data read from file
	fstream input; // Input file
	string inputFile; // Name of the file
public:
	/*
	  Constructor gets the filename of the file to be buffered,
	  opens the file, and instantiates poolSize buffer blocks by
	  reading the file and filling the blocks in order.  When the constructor
	  is done the buffer pool blocks should be full with the beginning
	  contents of the input file.
	*/
	LRUBufferPool() {}
	LRUBufferPool(string filename, int poolSize = 5, int blockSize = 4096) {

		// Opens the given binary file
		inputFile = filename;
		input.open(filename.c_str(), fstream::in | fstream::binary);

		// Loops through to add blocks to the pool according to the size of the pool
		for (int i = 0; i < poolSize; i++) {

			// Finds the data for the respective block and reads it
			int temp = i * 4096;
			input.seekg(temp);
			input.read(data, blockSize);

			// Creates new block and assigns an ID and data to it
			block = new BufferBlock(data, blockSize);
			blockArray[i] = block;
			block->setID(i);
		}

		// Close the file
		input.close();
	}

	/* 
	  Destructer
	*/
	~LRUBufferPool() {}

	/*
	  Copy "sz" bytes from position "pos" of the buffered storage to "space".
	*/ 
	void getBytes(char* space, int sz, int pos) {

		bool inPool = false; // True if block is already in the pool
		int ID = pos / BLOCKSIZE; // ID of the block

		// Checks to see if the block is already in the pool
		for (int i = 0; i < POOL_SIZE; i++) {
			if (blockArray[i]->getID() == ID) {
				inPool = true;
			}
		}

		// If-else for inPool blocks vs. new blocks being added to the pool
		if (inPool) {
			int i = 0; // Counter for while loop

			// Loops until i equals the block in the pool
			while (blockArray[i]->getID() != ID)
				i++;

			// Creates a temp block with the data that is in the block that is being accessed 
			BufferBlock* temp = blockArray[i];

			// Shifts all blocks down one spot
			while (i > 0) {
				blockArray[i] = blockArray[i - 1];
				i--;
			}

			// Sets the top block to temp
			blockArray[0] = temp;
		} 
		else {

			// Shifts all blocks down one
			int i = 4;
			while (i > 0) {
				blockArray[i] = blockArray[i - 1];
				i--;
			}
			
			// Reopens the file
			fstream input;
			input.open(inputFile.c_str(), fstream::in | fstream::binary);

			// Creates new block and adds it to the top of the pool
			int temp = ID * 4096;
			input.seekg(temp);
			input.read(data, 4096);
			block = new BufferBlock(data, 4096);
			blockArray[0] = block;
			block->setID(ID);
		}
		
		// Gets the data from the top block
		blockArray[0]->getData(pos, sz, space);
	}

	/* 
	  Print the order of the buffer blocks using the block id numbers.
	*/
	void printBufferBlockOrder() {

		// Header for the data
		std::cout << "The order of the buffer pool is:" << std::endl;

		// Loops through each ID for all the blocks in the pool
		for (int i = 0; i < 5; i++) {
			std::cout << blockArray[i]->getID() << endl;
		}
	}

	/* 
	  Get the block id number of the least recently used buffer block.
	*/
	int getLRUBlockID() {
		return blockArray[0]->getID();
	}
};
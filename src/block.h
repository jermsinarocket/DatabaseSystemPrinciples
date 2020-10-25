#ifndef BLOCK_H
#define BLOCK_H

#include "record.h"
using std::vector;

//Structure to store one block
struct Block
{
public:
	//Structure to store one block
	vector <Record> records;
	
	int getNumRecords() { 
    	return records.size();
	}
	
	void addRecord(Record r){
		records.push_back(r);
	}
	
	int getBlockSize(){
		int block_size = 0;
		for(int i = 0; i < records.size(); i++){ 
			block_size += records[i].getRecordSize();
		} 
		return block_size;
	}
	
};

 
#endif

#ifndef STORAGE_H
#define STORAGE_H
#include <iostream>
#include "block.h"
using namespace std;
using std::vector;

//Structure to store one block
struct Storage
{
public:
	//Structure to store one block
	vector <Block> blocks;
	
	//Add Block to Storage
	void addBlock(Block blk){
		blocks.push_back(blk);
	}
	
	// Total Storage Size
	long getStorageSize(){
		double storage_size = 0;
		for(int j = 0; j < blocks.size(); j++){ 
			//cout << "Block Number: " << j << ": "<<  blocks[j].getBlockSize() << endl;
			//cout << "Number Records: " << blocks[j].getNumRecords() << endl;
			//for(int i = 0; i < blocks[j].records.size(); i++){ 
			//  cout << "Record Size: " << blocks[j].records[i].getRecordSize() << endl;
			//}
			storage_size += blocks[j].getBlockSize();
			
		} 
		
		return storage_size;
		
	}
	
	//Get Total Number of Blocks
	int getNumBlocks(){
		return blocks.size();
	}
	
	//Get Total Number of Records
	int getNumRecords(){
		int num_records;
		
		for(int i = 0; i < blocks.size(); i++){ 
			num_records += blocks[i].getNumRecords();
			
		} 
		
		return num_records;
		
	}
	
};

 
#endif

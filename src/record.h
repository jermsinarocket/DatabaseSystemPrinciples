#ifndef RECORD_H
#define RECORD_H

//Structure to store one record

struct Record
{
public:
 	int tconst;
    double rating;
    int votes;
    
    //Calculating size of each record
    int getRecordSize() { 
    	return sizeof(tconst) + sizeof(rating) + sizeof(votes);
	}
};
 
#endif

#include "record.h"
 
// Record constructor
Record::Record(int tconst, double rating, int votes)
{
    createRecord(tconst, rating, votes);
}
 
 
void Record::createRecord(int tconst, double rating, int votes){
	
	tconst = tconst;
	rating = rating;
	votes = votes;
	
}

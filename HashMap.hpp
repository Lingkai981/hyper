#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_

#include <cstdint>
#include <cstddef>

const int HASH_SCALE = 2;
class HashMap {
private:
	unsigned int *head_;
	unsigned int *val_;
	unsigned int *mp_;
	unsigned int *next_;
	int cur_, capacity_, buckets_;

public:
	HashMap(int size) ;
	~HashMap() ;

	void insert(unsigned int v, unsigned int t) ;
	int find(unsigned int v) ;
};

#endif

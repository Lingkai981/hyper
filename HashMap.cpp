#include "HashMap.hpp"
#include <cstdint>


HashMap::HashMap(int size) {
	head_ = val_ = mp_ = next_ = NULL;
	buckets_ = size * HASH_SCALE;
	cur_ = 0;
	capacity_ = size;

	head_ = new unsigned int[buckets_];
	val_ = new unsigned int[size];
	next_ = new unsigned int[size];
	mp_ = new unsigned int[size];

	for(unsigned int i = 0;i < buckets_;i ++) head_[i] = -1;

}

HashMap::~HashMap() {
	if(head_ != NULL) delete[] head_;
	if(val_ != NULL) delete[] val_;
	if(next_ != NULL) delete[] next_;
	if(mp_ != NULL) delete[] mp_;
}

void HashMap::insert(unsigned int v, unsigned int t) {

	int target_bucket = v % buckets_;
	val_[cur_] = v;
	mp_[cur_] = t;
	next_[cur_] = head_[target_bucket];
	head_[target_bucket] = cur_ ++;
}

int HashMap::find(unsigned int v) {
	unsigned int target_bucket = v % buckets_;
	for(unsigned int i = head_[target_bucket]; i != -1; i = next_[i]) {
		if(val_[i] == v){
			return mp_[i];
		}
	}
	return -1;
}
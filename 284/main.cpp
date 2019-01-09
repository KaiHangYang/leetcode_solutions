#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        this->raw_ptr = shared_ptr<Iterator>(new Iterator(nums));
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        this->peek_ptr = shared_ptr<Iterator>(new Iterator(*this->raw_ptr.get()));
        return this->peek_ptr->next();
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return this->raw_ptr->next();
	}

	bool hasNext() const {
	    return this->raw_ptr->hasNext();
	}

    shared_ptr<Iterator> peek_ptr;
    shared_ptr<Iterator> raw_ptr;
};

class RandomAccessIterator {
	private:
		T* ptr;
	
	public:
		RandomAccessIterator();
		RandomAccessIterator(T*);
	
		RandomAccessIterator& operator=(const RandomAccessIterator&);
		RandomAccessIterator operator++();
		RandomAccessIterator operator++(int);
		RandomAccessIterator operator+(size_t);
		RandomAccessIterator operator+=(size_t);
		RandomAccessIterator operator-(size_t);
		RandomAccessIterator operator-=(size_t);
		RandomAccessIterator operator--();
		RandomAccessIterator operator--(int);
					
		T& operator*() const;
		T* operator->() const;
		bool operator==(const RandomAccessIterator&) const;
		bool operator!=(const RandomAccessIterator&) const;
};

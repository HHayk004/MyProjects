class BidirectionalIterator {
	private:
		T* ptr;

	public:
		BidirectionalIterator();
		BidirectionalIterator(T*);

		BidirectionalIterator& operator=(const BidirectionalIterator&);
		BidirectionalIterator operator++();
		BidirectionalIterator operator++(int);
		BidirectionalIterator operator--();
		BidirectionalIterator operator--(int);
					
		T& operator*() const;
		T* operator->() const;
		bool operator==(const BidirectionalIterator&) const;
		bool operator!=(const BidirectionalIterator&) const;
};

BidirectionalIterator begin() const;
BidirectionalIterator end() const;


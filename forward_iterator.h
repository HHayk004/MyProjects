class ForwardIterator {
	private:
		T* ptr;

	public:
		ForwardIterator();
		ForwardIterator(T*);

		ForwardIterator& operator=(const ForwardIterator&);
		ForwardIterator operator++();
		ForwardIterator operator++(int);
					
		T& operator*() const;
		T* operator->() const;
		bool operator==(const ForwardIterator&) const;
		bool operator!=(const ForwardIterator&) const;
};

ForwardIterator begin() const;
ForwardIterator end() const;

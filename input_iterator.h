class Iterator {
	private:
		T* ptr;

	public:
		explicit Iterator(T*);
					
		const Iterator& operator=(const Iterator&);
		Iterator operator++();
		Iterator operator++(int);
					
		const T& operator*() const;
		const T* operator->() const;
		bool operator==(const Iterator&) const;
		bool operator!=(const Iterator&) const;
};

Iterator begin() const;
Iterator end() const;

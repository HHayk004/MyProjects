template <typename T>
MyVector<T>::BidirectionalIterator::BidirectionalIterator() : ptr(nullptr){}

template <typename T>
MyVector<T>::BidirectionalIterator::BidirectionalIterator(T* ptr1) : ptr(ptr1){}

template <typename T>
typename MyVector<T>::BidirectionalIterator& MyVector<T>::BidirectionalIterator::operator=(const MyVector<T>::BidirectionalIterator& other)
{
	ptr = other.ptr;
	return *this;
}

template <typename T>
typename MyVector<T>::BidirectionalIterator MyVector<T>::BidirectionalIterator::operator++()
{
	++ptr;
	return *this;
}

template <typename T>
typename MyVector<T>::BidirectionalIterator MyVector<T>::BidirectionalIterator::operator++(int)
{
	BidirectionalIterator tmp = *this;
	++ptr;
	return tmp;
}

template <typename T>
typename MyVector<T>::BidirectionalIterator MyVector<T>::BidirectionalIterator::operator--()
{
	--ptr;
	return *this;
}

template <typename T>
typename MyVector<T>::BidirectionalIterator MyVector<T>::BidirectionalIterator::operator--(int)
{
	BidirectionalIterator tmp = *this;
	--ptr;
	return *this;
}

template <typename T>
bool MyVector<T>::BidirectionalIterator::operator==(const MyVector<T>::BidirectionalIterator& other) const
{
	return this->ptr == other.ptr;
}

template <typename T>
bool MyVector<T>::BidirectionalIterator::operator!=(const MyVector<T>::BidirectionalIterator& other) const
{
	return this->ptr != other.ptr;
}

template <typename T>
typename MyVector<T>::BidirectionalIterator MyVector<T>::begin() const
{
    BidirectionalIterator it(m_ptr);
    return it;
}

template <typename T>
typename MyVector<T>::BidirectionalIterator MyVector<T>::end() const
{
    BidirectionalIterator it(m_ptr + m_size);
    return it;
}

template <typename T>
T& MyVector<T>::BidirectionalIterator::operator*() const
{
	return *ptr;
}

template <typename T>
T* MyVector<T>::BidirectionalIterator::operator->() const
{
	return ptr;
}


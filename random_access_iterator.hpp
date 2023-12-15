template <typename T>
typename MyVector<T>::RandomAccessIterator& MyVector<T>::RandomAccessIterator::operator=(const MyVector<T>::RandomAccessIterator& other)
{
	ptr = other.ptr;
	return *this;
}

template <typename T>
typename MyVector<T>::RandomAccessIterator MyVector<T>::RandomAccessIterator::operator++()
{
	++ptr;
	return *this;
}

template <typename T>
typename MyVector<T>::RandomAccessIterator MyVector<T>::RandomAccessIterator::operator++(int)
{
	RandomAccessIterator tmp = *this;
	++ptr;
	return tmp;
}

template <typename T>
typename MyVector<T>::RandomAccessIterator MyVector<T>::RandomAccessIterator::operator+(size_t disp)
{
	RandomAccessIterator t = *this;
	for (size_t i = 0; i < disp; ++i)
	{
		++t;
	}

	return t;
}

template <typename T>
typename MyVector<T>::RandomAccessIterator MyVector<T>::RandomAccessIterator::operator+=(size_t disp)
{
	for (size_t i = 0; i < disp; ++i)
	{
		++(*this);
	}

	return *this;
}

template <typename T>
typename MyVector<T>::RandomAccessIterator MyVector<T>::RandomAccessIterator::operator--()
{
	--ptr;
	return *this;
}

template <typename T>
typename MyVector<T>::RandomAccessIterator MyVector<T>::RandomAccessIterator::operator--(int)
{
	RandomAccessIterator tmp = *this;
	--ptr;
	return *this;
}

template <typename T>
typename MyVector<T>::RandomAccessIterator MyVector<T>::RandomAccessIterator::operator-(size_t disp)
{
	RandomAccessIterator t = *this;
	for (size_t i = 0; i < disp; ++i)
	{
		--t;
	}

	return t;
}

template <typename T>
typename MyVector<T>::RandomAccessIterator MyVector<T>::RandomAccessIterator::operator-=(size_t disp)
{
	for (size_t i = 0; i < disp; ++i)
	{
		--(*this);
	}

	return *this;
}

template <typename T>
bool MyVector<T>::Iterator::operator<(const MyVector<T>::Iterator& other) const
{
	return ptr < other.ptr;
}

template <typename T>
bool MyVector<T>::Iterator::operator<=(const MyVector<T>::Iterator& other) const
{
	return ptr <= other.ptr;
}

template <typename T>
bool MyVector<T>::Iterator::operator>(const MyVector<T>::Iterator& other) const
{
	return ptr > other.ptr;
}

template <typename T>
bool MyVector<T>::Iterator::operator>=(const MyVector<T>::Iterator& other) const
{
	return ptr >= other.ptr;
}

template <typename T>
bool MyVector<T>::RandomAccessIterator::operator==(const MyVector<T>::RandomAccessIterator& other) const
{
	return this->ptr == other.ptr;
}

template <typename T>
bool MyVector<T>::RandomAccessIterator::operator!=(const MyVector<T>::RandomAccessIterator& other) const
{
	return this->ptr != other.ptr;
}

template <typename T>
typename MyVector<T>::RandomAccessIterator MyVector<T>::begin() const
{
    RandomAccessIterator it(m_ptr);
    return it;
}

template <typename T>
typename MyVector<T>::RandomAccessIterator MyVector<T>::end() const
{
    RandomAccessIterator it(m_ptr + m_size);
    return it;
}

template <typename T>
T& MyVector<T>::RandomAccessIterator::operator*() const
{
	return *ptr;
}

template <typename T>
T* MyVector<T>::RandomAccessIterator::operator->() const
{
	return ptr;
}

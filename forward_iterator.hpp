template <typename T>
MyVector<T>::ForwardIterator::ForwardIterator() : ptr(nullptr){}

template <typename T>
MyVector<T>::ForwardIterator::ForwardIterator(T* ptr1) : ptr(ptr1){}

template <typename T>
typename MyVector<T>::ForwardIterator& MyVector<T>::ForwardIterator::operator=(const MyVector<T>::ForwardIterator& other)
{
	ptr = other.ptr;
	return *this;
}

template <typename T>
typename MyVector<T>::ForwardIterator MyVector<T>::ForwardIterator::operator++()
{
	++ptr;
	return *this;
}

template <typename T>
typename MyVector<T>::ForwardIterator MyVector<T>::ForwardIterator::operator++(int)
{
	ForwardIterator tmp = *this;
	++ptr;
	return tmp;
}

template <typename T>
bool MyVector<T>::ForwardIterator::operator==(const MyVector<T>::ForwardIterator& other) const
{
	return this->ptr == other.ptr;
}

template <typename T>
bool MyVector<T>::ForwardIterator::operator!=(const MyVector<T>::ForwardIterator& other) const
{
	return this->ptr != other.ptr;
}

template <typename T>
typename MyVector<T>::ForwardIterator MyVector<T>::begin() const
{
    ForwardIterator it(m_ptr);
    return it;
}

template <typename T>
typename MyVector<T>::ForwardIterator MyVector<T>::end() const
{
    ForwardIterator it(m_ptr + m_size);
    return it;
}

template <typename T>
T& MyVector<T>::ForwardIterator::operator*() const
{
	return *ptr;
}

template <typename T>
T* MyVector<T>::ForwardIterator::operator->() const
{
	return ptr;
}

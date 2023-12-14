template <typename T>
MyVector<T>::Iterator::Iterator(T* ptr1) : ptr(ptr1){}

template <typename T>
typename MyVector<T>::Iterator& MyVector<T>::Iterator::operator=(const MyVector<T>::Iterator& other)
{
	ptr = other.ptr;
	return *this;
}

template <typename T>
typename const MyVector<T>::Iterator MyVector<T>::Iterator::operator++()
{
	++ptr;
	return *this;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::Iterator::operator++(int)
{
	Iterator tmp = *this;
	++ptr;
	return tmp;
}

template <typename T>
bool MyVector<T>::Iterator::operator==(const MyVector<T>::Iterator& other) const
{
	return this->ptr == other.ptr;
}

template <typename T>
bool MyVector<T>::Iterator::operator!=(const MyVector<T>::Iterator& other) const
{
	return this->ptr != other.ptr;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::begin() const
{
    Iterator it(m_ptr);
    return it;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::end() const
{
    Iterator it(m_ptr + m_size);
    return it;
}

template <typename T>
const T& MyVector<T>::Iterator::operator*() const
{
	return *ptr;
}

template <typename T>
const T* MyVector<T>::Iterator::operator->() const
{
	return ptr;
}

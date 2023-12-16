#define BYTE (sizeof(uint8_t) * 8)

template<typename T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& other)
{
    return other.operator<<(os);
}

template <typename T>
MyVector<T>::MyVector()
{
	m_ptr = nullptr;
	m_size = 0;
	m_capacity = 0;
}

template <typename T>
MyVector<T>::MyVector(T obj)
{
	m_capacity = 10;
	m_ptr = new T [m_capacity]{};

	m_ptr[0] = obj;
	m_size = 1;
}

template <typename T>
MyVector<T>::MyVector(std::initializer_list<T> list)
{
	m_size = list.size();
	m_capacity = m_size + 10;
	m_ptr = new T [m_capacity]{};

	int index = 0;
	for (const auto& elem : list)
	{
		m_ptr[index] = elem;
		++index;
	}
}

template <typename T>
MyVector<T>::MyVector(const MyVector& other) noexcept
{
	m_size = other.m_size;
	m_capacity = other.m_capacity;

	m_ptr = new T [m_size]{}; 
	for (int i = 0; i < m_size; ++i)
	{
		m_ptr[i] = other[i];
	}
}

template <typename T>
MyVector<T>::MyVector(MyVector&& other)
{
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_ptr = other.m_ptr;

	other.m_size = 0;
	other.m_capacity = 0;
	other.m_ptr = nullptr;
}

template <typename T>
MyVector<T>::~MyVector()
{
    delete[] m_ptr;
    m_ptr = nullptr;
}

template <typename T>
T* MyVector<T>::data() const
{
    return m_ptr;
}

template <typename T>
void MyVector<T>::push_back(T val)
{
    if (m_size > m_max_size - 10)
    {
        std::cerr << "m_size > m_max_size - 10 in push_back:\n";
        exit(-1);
    }

    if (m_size == m_capacity)
    {
        resize(m_capacity + 10);    
    }

    m_ptr[m_size++] = val;
}

template <typename T>
void MyVector<T>::pop_back()
{
    if (m_size == 0)
    {
        std::cerr << "Wrong index for pop:\n";
        exit(-1);
    }

    --m_size;
}

template <typename T>
void MyVector<T>::insert(size_t pos, T val)
{
    if (pos > m_size)
    {
        std::cerr << "Wrong index for index:\n";
        exit(-1);
    }

    if (m_size == m_capacity)
    {
        resize(m_capacity + 10);
    }

    for (int i = m_size; i > pos; --i)
    {
        m_ptr[i] = m_ptr[i - 1];
    }

    m_ptr[pos] = val;
    ++m_size;
}

template <typename T>
void MyVector<T>::erase(size_t pos)
{
    if (pos >= m_size)
    {
        std::cerr << "Wrong index for erase:\n";
        exit(-1);
    }

    for (int i = pos; i < m_size - 1; ++i)
    {
        m_ptr[i] = m_ptr[i + 1]; 
    }

    --m_size;
}

template <typename T>
void MyVector<T>::erase(size_t begin, size_t end)
{
    if (end < begin || end >= m_size)
    {
        std::cerr << "Wrong indexes for erase:\n";
        exit(-1);
    }
    
    size_t delta = end - begin;
    for (int i = begin; i < m_size - delta; ++i)
    {
        m_ptr[i] = m_ptr[i + delta];
    }

    m_size -= delta;
}

template <typename T>
bool MyVector<T>::empty() const
{
    return m_size == 0;
}

template <typename T>
void MyVector<T>::reserve(size_t new_capacity)
{
    if (new_capacity > m_max_size)
    {
        std::cerr << "Wrong size for reserve:\n";
        exit(-1);
    }

    if (new_capacity > m_capacity)
    {
        m_capacity = new_capacity;
        if (m_ptr == nullptr)
        {
            m_ptr = new T [m_capacity];
        }

        else
        {
            T* new_ptr = new T [m_capacity];
            for (int i = 0; i < m_size; ++i)
            {
                new_ptr[i] = m_ptr[i];
            }

            delete[] m_ptr;
            m_ptr = new_ptr;
            new_ptr = nullptr;      
        }
    }
}

template <typename T>
void MyVector<T>::resize(size_t new_size)
{
    if (new_size > m_max_size)
    {
        std::cerr << "new_size > m_max_size in resize:\n";
        exit(-1);
    }

    if (m_ptr == nullptr)
    {
        m_capacity = new_size;
        m_ptr = new T [m_capacity]{};
    }
    
    else if (new_size > m_capacity)
    {
        m_capacity = new_size;
        T* new_ptr = new T [m_capacity]{};
        for (int i = 0; i < m_size; ++i)
        {
            new_ptr[i] = m_ptr[i];
        }

        delete[] m_ptr;
        m_ptr = new_ptr;
        new_ptr = nullptr;
    }

    else
    {
        m_size = new_size; 
    }
}

template <typename T>
void MyVector<T>::shrink_to_fit()
{
    if (m_size < m_capacity)
    {
        m_capacity = m_size;
        T* new_ptr = new T [m_capacity];
        for (int i = 0; i < m_size; ++i)
        {
            new_ptr[i] = m_ptr[i];
        }

        delete[] m_ptr;
        m_ptr = new_ptr;
        new_ptr = nullptr;
    }
}

template <typename T>
T& MyVector<T>::operator[](const size_t index) const
{
    return m_ptr[index];
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(std::initializer_list<T> list)
{   
    m_size = list.size();
    
    if (m_size > m_capacity)
    {
        resize(m_size);
    }    

    int index = 0;
    for (const auto& elem: list)
    {
        m_ptr[index] = elem;
    }

    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other)
{
    if (this != &other)
    {
        m_size = other.m_size;
        m_capacity = other.m_capacity;

        delete[] m_ptr;
        m_ptr = new T [m_capacity];
    
        for (int i = 0; i < m_size; ++i)
        {
            m_ptr[i] = other[i];
        }
    }

    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other)
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;

    delete[] m_ptr;
    m_ptr = other.m_ptr;

    other.m_size = 0;
    other.m_capacity = 0;
    other.m_ptr = nullptr;

    return *this;
}

template <typename T>
std::ostream& MyVector<T>::operator<<(std::ostream& os) const
{
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_ptr[i] << ' ';
    }
    return os;
}

template <typename T>
T MyVector<T>::at(size_t index) const
{
    if (index >= m_size)
    {
        std::cerr << "Wrong index for at:\n";
        exit(-1);         
    }

    return m_ptr[index];
}

template <typename T>
size_t MyVector<T>::size() const
{
    return m_size;
}

template <typename T>
size_t MyVector<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
const size_t MyVector<T>::max_size() const
{
    return m_max_size;
}

template <typename T>
T& MyVector<T>::front() const
{
    return m_ptr[0];
}

template <typename T>
T& MyVector<T>::back() const
{    
    return m_ptr[m_size - 1];
}

template <typename T>
void MyVector<T>::swap(MyVector& vec)
{
    std::swap(m_ptr, vec.m_ptr);
    std::swap(m_size, vec.m_size);
    std::swap(m_capacity, vec.m_capacity);
}

template <typename T>
void MyVector<T>::clear()
{
    for (int i = 0; i < m_size; ++i)
    {
        m_ptr[i] = 0;
    }
    m_size = 0;
}

template <typename T>
MyVector<T>::Iterator::Iterator() : ptr(nullptr){}

template <typename T>
MyVector<T>::Iterator::Iterator(T* ptr1) : ptr(ptr1){}

template <typename T>
typename MyVector<T>::Iterator& MyVector<T>::Iterator::operator=(const MyVector<T>::Iterator& other)
{
	ptr = other.ptr;
	return *this;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::Iterator::operator++()
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
typename MyVector<T>::Iterator MyVector<T>::Iterator::operator+(size_t disp)
{
	Iterator t = *this;
	for (size_t i = 0; i < disp; ++i)
	{
		++t;
	}

	return t;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::Iterator::operator+=(size_t disp)
{
	for (size_t i = 0; i < disp; ++i)
	{
		++(*this);
	}

	return *this;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::Iterator::operator-(size_t disp)
{
	Iterator t = *this;
	for (size_t i = 0; i < disp; ++i)
	{
		--t;
	}

	return t;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::Iterator::operator-=(size_t disp)
{
	for (size_t i = 0; i < disp; ++i)
	{
		--(*this);
	}

	return *this;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::Iterator::operator--()
{
	--ptr;
	return *this;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::Iterator::operator--(int)
{
	Iterator tmp = *this;
	--ptr;
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
T& MyVector<T>::Iterator::operator[](int disp) const
{
	Iterator tmp = *this;
	tmp += disp;
	return *tmp;
}

template <typename T>
T& MyVector<T>::Iterator::operator*() const
{
	return *ptr;
}

template <typename T>
T* MyVector<T>::Iterator::operator->() const
{
	return ptr;
}

std::ostream& operator<<(std::ostream& os, const MyVector<bool>& other)
{
    return other.operator<<(os);
}

std::ostream& MyVector<bool>::operator<<(std::ostream& os) const
{
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << ((m_ptr[i / BYTE] >> (i % BYTE)) & 1) << ' ';
    }
    return os;
}

MyVector<bool>& MyVector<bool>::operator=(std::initializer_list<bool> list)
{
    m_size = list.size();
    
    if (m_size > m_capacity)
    {
        resize(m_size);
    }    

    int index = 0;
    for (const auto& elem: list)
    {
        m_ptr[index] = elem;
    }

    return *this;
}

MyVector<bool>& MyVector<bool>::operator=(const MyVector& other)
{
    if (this != &other)
    {
        m_size = other.m_size;
        m_capacity = other.m_capacity;

        delete[] m_ptr;
        m_ptr = new uint8_t [m_capacity];
    
        for (int i = 0; i < m_size; ++i)
        {
            m_ptr[i] = other.m_ptr[i];
        }
    }

    return *this;
}

MyVector<bool>& MyVector<bool>::operator=(MyVector&& other)
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;

    delete[] m_ptr;
    m_ptr = other.m_ptr;

    other.m_size = 0;
    other.m_capacity = 0;
    other.m_ptr = nullptr;

    return *this;
}


bool MyVector<bool>::at(size_t index) const
{
    if (index >= m_size)
    {
        std::cerr << "Index >= m_size for [] operator:\n";
        exit(-1);
    }

    return (m_ptr[index / BYTE] >> (index % BYTE)) & 1;
}

MyVector<bool>::MyVector()
{
	m_ptr = nullptr;
	m_size = 0;
	m_capacity = 0;
}

MyVector<bool>::MyVector(bool obj)
{
	m_capacity = 1;
	m_ptr = new uint8_t [m_capacity]{};

	m_ptr[0] = obj;
	m_size = 1;
}

MyVector<bool>::MyVector(std::initializer_list<bool> list)
{
	m_size = list.size();
	m_capacity = m_size / BYTE + 1;
	m_ptr = new uint8_t [m_capacity]{};

	int index = 0;
	for (const auto& elem : list)
	{
		m_ptr[index / BYTE] |= elem << (index % BYTE);
        ++index;
	}
}

MyVector<bool>::MyVector(const MyVector<bool>& other) noexcept
{
	m_size = other.m_size;
	m_capacity = other.m_capacity;

	m_ptr = new uint8_t [m_size]; 
	for (int i = 0; i < m_size; ++i)
	{
		m_ptr[i] = other.m_ptr[i];
	}
}

MyVector<bool>::MyVector(MyVector<bool>&& other)
{
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_ptr = other.m_ptr;

	other.m_size = 0;
	other.m_capacity = 0;
	other.m_ptr = nullptr;
}

MyVector<bool>::~MyVector()
{
    delete[] m_ptr;
    m_ptr = nullptr;
}

MyVector<bool>::Reference MyVector<bool>::operator[](size_t index)
{
    return MyVector::Reference(m_ptr, index);
}

MyVector<bool>::Reference::Reference(uint8_t* ptr1, size_t index1) : 
	ptr(ptr1), index(index1)
{
	flag = (ptr[index / BYTE] >> (index % BYTE)) & 1;
}

MyVector<bool>::Reference::Reference(const Reference& obj)
{
	index = obj.index;
	ptr = obj.ptr;
	flag = obj.flag;
}

MyVector<bool>::Reference::Reference(Reference&& obj)
{
	index = obj.index;
	ptr = obj.ptr;
	flag = obj.flag;
	obj.ptr = nullptr;
	obj.index = 0;
	obj.flag = 0;
}

MyVector<bool>::Reference& MyVector<bool>::Reference::operator=(const Reference& obj)
{
	if (flag != obj.flag)
	{
		ptr[index / BYTE] &= ~(1 << (index % BYTE));
		ptr[index / BYTE] |= (obj.flag << (index % BYTE));
	}
	return *this;
}

MyVector<bool>::Reference& MyVector<bool>::Reference::operator=(bool flag)
{
	if (this->flag != flag)
	{
		ptr[index / BYTE] &= ~(1 << (index % BYTE));
		ptr[index / BYTE] |= (flag << (index % BYTE));
	}
	return *this;
}

MyVector<bool>::Reference::operator bool() const
{
	return flag;
}

uint8_t* MyVector<bool>::data() const
{
    return m_ptr;
}

void MyVector<bool>::reserve(size_t new_capacity)
{
    if (new_capacity > m_max_size)
    {
        std::cerr << "Erong size for reserve:\n";
        exit(-1);
    }

    new_capacity = new_capacity / BYTE + static_cast<bool>(new_capacity % BYTE);
    if (new_capacity > m_capacity)
    {
        m_capacity = new_capacity;
        if (m_ptr == nullptr)
        {
            m_ptr = new uint8_t [m_capacity];
        }

        else
        {
            uint8_t* new_ptr = new uint8_t [m_capacity];
            for (int i = 0; i < m_size; ++i)
            {
                new_ptr[i] = m_ptr[i];
            }

            delete[] m_ptr;
            m_ptr = new_ptr;
            new_ptr = nullptr;      
        }
    }
}

void MyVector<bool>::resize(size_t new_size)
{
    if (new_size > m_max_size)
    {
        std::cerr << "new_size > m_max_size in resize:\n";
        exit(-1);
    }

    new_size = new_size / BYTE + static_cast<bool>(new_size % 8);
    if (m_ptr == nullptr)
    {
        m_capacity = new_size;
        m_ptr = new uint8_t [m_capacity]{};
    }
    
    else if (new_size > m_capacity)
    {
        m_capacity = new_size;
        uint8_t* new_ptr = new uint8_t [m_capacity]{};
        for (int i = 0; i < m_size; ++i)
        {
            new_ptr[i] = m_ptr[i];
        }

        delete[] m_ptr;
        m_ptr = new_ptr;
        new_ptr = nullptr;
    }

    else
    {
        m_size = new_size;
    }
}

void MyVector<bool>::shrink_to_fit()
{
    size_t wanted_size = m_size / BYTE + static_cast<bool>(m_size % BYTE); 
    if (wanted_size < m_capacity)
    {
        m_capacity = wanted_size;
        uint8_t* new_ptr = new uint8_t [m_capacity];
        for (int i = 0; i < wanted_size; ++i)
        {
            new_ptr[i] = m_ptr[i];
        }

        delete[] m_ptr;
        m_ptr = new_ptr;
        new_ptr = nullptr;
    }
}

void MyVector<bool>::push_back(bool val)
{
    if (m_size > m_max_size - 10)
    {
        std::cerr << "m_size > m_max_size - 10 in push_back:\n";
        exit(-1);
    }

    if (m_size / BYTE == m_capacity && m_size % BYTE == 0)
    {
        resize(m_capacity + 2);    
    }

    m_ptr[m_size / BYTE] &= ~(1 << (m_size % BYTE));
    m_ptr[m_size / BYTE] |= val << (m_size % BYTE);
    ++m_size;
}

void MyVector<bool>::pop_back()
{
    if (m_size == 0)
    {
        std::cerr << "Size is 0 for pop:\n";
        exit(-1);
    }

    --m_size;
}

void MyVector<bool>::swap(MyVector<bool>& other)
{
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
    std::swap(m_ptr, other.m_ptr);
}

size_t MyVector<bool>::size() const
{
    return m_size;
}

size_t MyVector<bool>::capacity() const
{
    return m_capacity;
}

const size_t MyVector<bool>::max_size() const
{
    return m_max_size;
}

void MyVector<bool>::clear()
{
	int size = m_size / BYTE + static_cast<bool>(m_size % BYTE);
	for (int i = 0; i < size; ++i)
	{
		m_ptr[i] = 0;
	}
    m_size = 0;
}

bool MyVector<bool>::empty() const
{
    return m_size == 0;
}

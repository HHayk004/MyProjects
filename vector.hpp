#define BYTE (sizeof(uint8_t) * 8) // macro for bool vector element size in bits

template <typename T>
Vector<T>::Vector() // standart default constructor
{
	m_ptr = nullptr;
	m_size = 0;
	m_capacity = 0;
}

template <typename T>
Vector<T>::Vector(size_t size, T value) // parametrakan constructor that allocates size count elements with value
{
    m_size = size;
	m_capacity = size + 10; // 10 is extra space
	m_ptr = new T [m_capacity]{}; // allocate the memory
    
    for (int i = 0; i < size; ++i)
    {
        m_ptr[i] = value; // defined each element with value
    }
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> list) // initializer list constructor
{
	m_size = list.size();
	m_capacity = m_size + 10; // 10 extra space
	m_ptr = new T [m_capacity]{}; // memory allocation

	int index = 0;
	for (const auto& elem : list) // defining each element with list element with range for
	{
		m_ptr[index] = elem;
		++index; // adding index for m_ptr
	}
}

template <typename T>
Vector<T>::Vector(const Vector& other) noexcept // copy constructor
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
Vector<T>::Vector(Vector&& other) noexcept
{
	m_size = std::move(other.m_size);
	m_capacity = std::move(other.m_capacity);
	m_ptr = std::move(other.m_ptr);

    // all data members making zero after moving
	other.m_size = 0;
	other.m_capacity = 0;
	other.m_ptr = nullptr;
}

template <typename T>
Vector<T>::~Vector() // standart destructor
{
    delete[] m_ptr;
    m_ptr = nullptr;
}

template <typename T>
T* Vector<T>::data() const // returning m_ptr
{
    return m_ptr;
}

template <typename T>
void Vector<T>::push_back(T val) // adding from back the value
{
    if (m_size > m_max_size - 10) // if vector's size is bigger than max_size, throw exception
    {
        std::cerr << "m_size > m_max_size - 10 in push_back:\n";
        exit(-1);
    }

    if (m_size == m_capacity) // if there aren't any space, resize the vector by 10
    {
        resize(m_capacity + 10);    
    }

    m_ptr[m_size++] = val; // adding the value and increment the size of vector
}

template <typename T>
void Vector<T>::push_front(T val) // adding from front the value
{
    if (m_size > m_max_size - 10) // if vector's size is bigger than max_size, throw exception
    {
        std::cerr << "m_size > m_max_size - 10 in push_back:\n";
        exit(-1);
    }

    if (m_size == m_capacity) // if there aren't any space, resize the vector by 10
    {
        resize(m_capacity + 10);    
    }
    
    for (int i = m_size; i > 0; --i) // push forward all elements by one
    {
        m_ptr[i] = m_ptr[i - 1];
    }

    m_ptr[0] = val; // define the first elemetn with value;
    ++m_size; // increment the size
}

template <typename T>
void Vector<T>::pop_back() // deleting element from back
{
    if (m_size == 0) // if there aren't any element, throw exception
    {
        std::cerr << "Wrong index for pop:\n";
        exit(-1);
    }

    --m_size; // otherwise decrement the size;
}

template <typename T>
void Vector<T>::pop_front() // deleting element from back 
{
    if (m_size == 0) // if there aren't any element, throw exception
    {
        std::cerr << "Wrong index for pop:\n";
        exit(-1);
    }

    for (int i = 1; i < m_size; ++i) // move forward element by one (from index 1);
    {
        m_ptr[i - 1] = m_ptr[i];
    }

    --m_size; // decrement the size;
}

template <typename T>
void Vector<T>::insert(Iterator it, T val) // element insert by interator
{
    if (it < begin() || it > end()) // if iterator is out of range. throw exception
    {
        std::cerr << "Wrong index for insert:\n";
        exit(-1);
    }

    if (m_size == m_capacity) // if there aren't any space, resize vector by 10
    {
        resize(m_capacity + 10);
    }

    for (Iterator tmp_it = end(); tmp_it > it; --tmp_it) // moving element back by one from it to end;
    {
        *tmp_it = *(tmp_it - 1);
    }

    *it = val; // insert the element
    ++m_size; // increment the size
}

template <typename T>
void Vector<T>::insert(Iterator it, std::initializer_list<T> list) // insert list by iterator
{
    if (it < begin() || it > end()) // if the it is out of range, throw exception
    {
        std::cerr << "Wrong index for insert:\n";
        exit(-1);
    }

    if (m_size + list.size() > m_capacity) // checking if total size is bigger than capacity, resize it
    {
        resize(m_capacity + list.size() + 10);
    }

    for (Iterator tmp_it = end() + list.size() - 1; tmp_it > it; --tmp_it) // moving elements back by list size from iterator;
    {
        tmp_it = tmp_it - list.size();
    }

    for (const auto& elem : list) // adding list element to vector (using it, because it isn't nessesary in my program)
    {
        *it = elem; // adding element
        ++it; // incrementing the iterator
    }

    m_size += list.size(); // adding the size by list.size
}

template <typename T>
void Vector<T>::erase(Iterator it) // deleting element with iterator
{
    if (it < begin() || it >= end()) // if iterator is out of range, throw exception
    {
        std::cerr << "Wrong index for erase:\n";
        exit(-1);
    }

    for (Iterator tmp_it = it; tmp_it < end() - 1; ++tmp_it) // moving forward elements from it
    {
        *tmp_it = *(tmp_it + 1); 
    }

    --m_size; // decrement the size
}

template <typename T>
void Vector<T>::erase(Iterator begin, Iterator end) // range erase with iterator
{
    if (begin < this->begin() || end < begin || end >= this->end()) // if iterators don't confirm with range, throw exception
    {
        std::cerr << "Wrong indexes for erase:\n";
        exit(-1);
    }
    
    size_t delta = end - begin; // element count that would be deleted
    for (Iterator it = begin; it < end; ++it) // moving forward elements from it by delta
    {
        *it = *(it + delta);
    }

    m_size -= delta; // decrease size by delta
}

template <typename T>
bool Vector<T>::empty() const // checking if vector is empty with size
{
    return m_size == 0;
}

template <typename T>
void Vector<T>::reserve(size_t new_capacity) // increasing the capacity
{
    if (new_capacity > m_max_size) // if new capacity is bigger than m_max_size, throw exception
    {
        std::cerr << "Wrong size for reserve:\n";
        exit(-1);
    }

    if (new_capacity > m_capacity) // increase the size if it's needed
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
void Vector<T>::resize(size_t new_size) // changing the capacity
{
    if (new_size > m_max_size) // throw exception if new_size is bigger than m_max_size
    {
        std::cerr << "new_size > m_max_size in resize:\n";
        exit(-1);
    }

    if (m_ptr == nullptr) // if the vector is empty, allocate m_size space
    {
        m_capacity = new_size;
        m_ptr = new T [m_capacity]{};
    }
    
    else if (new_size > m_capacity) // if new_size is bigger than capacity
    {
        m_capacity = new_size;
        T* new_ptr = new T [m_capacity]{}; // allocate new space with m_capacity size
        for (int i = 0; i < m_size; ++i) // copying the element to new space
        {
            new_ptr[i] = std::move(m_ptr[i]); // using std::move() for optimization
        }

        delete[] m_ptr; // deleting old space
        m_ptr = new_ptr; // giving new space to m_ptr
        new_ptr = nullptr; // defining nullptr the dangling pointer
    }

    else if (new_size < m_size) // if new_size < m_size, change the m_size
    {
        m_size = new_size; 
    }
}

template <typename T>
void Vector<T>::shrink_to_fit() // minimlize the m_capacity
{
    if (m_size < m_capacity) // checking if we can minimilize the m_capacity
    {
        m_capacity = m_size; 
        T* new_ptr = new T [m_capacity]; // allocating new space
        for (int i = 0; i < m_size; ++i) // copying the elements from old space to new space;
        {
            new_ptr[i] = std::move(m_ptr[i]); // using std::move() for optimization;
        }

        delete[] m_ptr; // deleting the old space
        m_ptr = new_ptr; // giving the permission to m_ptr
        new_ptr = nullptr; // defining nullptr the dangling pointer 
    }
}

template <typename T>
T& Vector<T>::operator[](const size_t index) const // subscipr operator for element access with index
{
    return m_ptr[index];
}

template <typename T>
Vector<T>& Vector<T>::operator=(std::initializer_list<T> list) // assignment operator for initializer list
{   
    m_size = list.size();
    
    if (m_size > m_capacity) // if it's neccesary, resize the vector
    {
        resize(m_size);
    }    

    int index = 0;
    for (const auto& elem: list) // copying the elements from list to our vector
    {
        m_ptr[index] = elem;
    }

    return *this; // returning our object
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) // assignment operator for copying
{
    if (this != &other) // checking fo self assignment
    {
        m_size = other.m_size; 
        m_capacity = other.m_capacity;

        delete[] m_ptr; // deleting old space
        m_ptr = new T [m_capacity]; // allocating new space
    
        for (int i = 0; i < m_size; ++i) // copying the element
        {
            m_ptr[i] = other[i];
        }
    }

    return *this; // return the object
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) // assigment operator for move
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;

    delete[] m_ptr; // deleting old memory
    m_ptr = other.m_ptr; // shallow copy

    other.m_size = 0; // removing the other object
    other.m_capacity = 0;
    other.m_ptr = nullptr;

    return *this; // return the object
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& other) // operator for printing whole vector
{
    return other.operator<<(os); // calling the operator that is defined in class
}

template <typename T>
std::ostream& Vector<T>::operator<<(std::ostream& os) const // cout << vec; 1 2 3 ...
{
    for (int i = 0; i < m_size; ++i) // printing our vector
    {
        std::cout << m_ptr[i] << ' ';
    }
    return os; // return the stream to global function
}

template <typename T>
T& Vector<T>::at(size_t index) const // accessing the elements from vector with index
{
    if (index < 0 || index >= m_size) // if index is out of range, throw exception
    {
        std::cerr << "Wrong index for at:\n";
        exit(-1);         
    }

    return m_ptr[index]; // return the 
}

template <typename T>
size_t Vector<T>::size() const // m_size getter
{
    return m_size;
}

template <typename T>
size_t Vector<T>::capacity() const // m_capacity getter
{
    return m_capacity;
}

template <typename T>
const size_t Vector<T>::max_size() const // max_size getter
{
    return m_max_size;
}

template <typename T>
T& Vector<T>::front() const // returning the reference to the first element of vector
{
    return m_ptr[0];
}

template <typename T>
T& Vector<T>::back() const  // returning the reference to the last element of vector
{    
    return m_ptr[m_size - 1];
}

template <typename T>
void Vector<T>::swap(Vector& vec) // swapping 2 vectors 
{
    std::swap(m_ptr, vec.m_ptr);
    std::swap(m_size, vec.m_size);
    std::swap(m_capacity, vec.m_capacity);
}

template <typename T>
void Vector<T>::clear() // clears all elements fo vector (doesn't delete the memory)
{
    for (int i = 0; i < m_size; ++i)
    {
        m_ptr[i] = 0;
    }
    m_size = 0;
}

template <typename T>
Vector<T>::Iterator::Iterator() : ptr(nullptr){} // iterator default constructor

template <typename T>
Vector<T>::Iterator::Iterator(T* ptr1) : ptr(ptr1){} // iterator parameter constructor

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator=(const Vector<T>::Iterator& other) // copy constructor
{
	ptr = other.ptr; // copying the iterator
	return *this; // return the iterator
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++() // ++ prefix operator for iterator
{
	++ptr; 
	return *this;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator++(int) // ++ postfix operator for iterator
{
	Iterator tmp = *this; // tmp for saving old value
	++ptr; // 
	return tmp;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator+(size_t disp) // + operator, which use as argument displacement (integer value)
{
	Iterator t = *this; // creating tmp iterator
	for (size_t i = 0; i < disp; ++i) // increment the value disp times
	{
		++t;
	}

	return t; // return tmp iterator
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator+=(size_t disp) // same as operator+, but without tmp iterator
{
	for (size_t i = 0; i < disp; ++i) // increment disp times our iterator
	{
		++(*this);
	}

	return *this; // return the object
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator-(size_t disp) // same as in operator+, but with -
{
	Iterator t = *this;
	for (size_t i = 0; i < disp; ++i)
	{
		--t;
	}

	return t;
}

template <typename T>
size_t Vector<T>::Iterator::operator-(Iterator it) // return the difference of iterators
{
    return ptr - it.ptr;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator-=(size_t disp) // same as operator+=, but with -
{
	for (size_t i = 0; i < disp; ++i)
	{
		--(*this);
	}

	return *this;
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator--() // same as operator--, but with -
{
	--ptr;
	return *this;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator--(int) // same as operator++(int), but with -
{
	Iterator tmp = *this;
	--ptr;
	return *this;
}

template <typename T>
bool Vector<T>::Iterator::operator<(const Vector<T>::Iterator& other) const // compare the iterators, returns apprpriate bool value
{
	return ptr < other.ptr;
}

template <typename T>
bool Vector<T>::Iterator::operator<=(const Vector<T>::Iterator& other) const // compare the iterators, returns apprpriate bool value
{
	return ptr <= other.ptr;
}

template <typename T>
bool Vector<T>::Iterator::operator>(const Vector<T>::Iterator& other) const // compare the iterators, returns apprpriate bool value
{
	return ptr > other.ptr;
}

template <typename T>
bool Vector<T>::Iterator::operator>=(const Vector<T>::Iterator& other) const // compare the iterators, returns apprpriate bool value
{
	return ptr >= other.ptr;
}

template <typename T>
bool Vector<T>::Iterator::operator==(const Vector<T>::Iterator& other) const // compare the iterators, returns apprpriate bool value
{
	return this->ptr == other.ptr;
}

template <typename T>
bool Vector<T>::Iterator::operator!=(const Vector<T>::Iterator& other) const // compare the iterators, returns apprpriate bool value
{
	return this->ptr != other.ptr;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::begin() const // return the iterator to the first element of vector
{
    Iterator it(m_ptr);
    return it;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end() const // return the iterator to the last element of vector
{
    Iterator it(m_ptr + m_size);
    return it;
}

template <typename T>
T& Vector<T>::Iterator::operator[](int disp) const // return *(this + disp)
{
	Iterator tmp = *this;
	tmp += disp;
	return *tmp;
}

template <typename T>
T& Vector<T>::Iterator::operator*() const // return the element reference that is pointed by iterator
{
	return *ptr;
}

template <typename T>
T* Vector<T>::Iterator::operator->() const // return the pointer that iterator is pointed
{
	return ptr;
}

// bool vector

std::ostream& operator<<(std::ostream& os, const Vector<bool>& other) // global operator for printing whole bool vector
{
    return other.operator<<(os);
}

std::ostream& Vector<bool>::operator<<(std::ostream& os) const // class method for printing whole bool vector
{
    for (int i = 0; i < m_size; ++i) // printing whole bool vector
    {
        std::cout << at(i) << ' ';
    }
    return os;
}

Vector<bool>& Vector<bool>::operator=(std::initializer_list<bool> list) // assignment operator with initializer list
{
    m_size = list.size(); // assign new size;
    
    if (m_size > m_capacity) // checking for resize
    {
        resize(m_size);
    }    

    int index = 0;
    for (const auto& elem: list) // copying the elements from list
    {
        m_ptr[index] = elem;
    }

    return *this; // returning the object
}

Vector<bool>& Vector<bool>::operator=(const Vector& other) noexcept // assignment operator with copy
{
    if (this != &other) // checking for self-assignment
    {
        m_size = other.m_size; // assign the fields
        m_capacity = other.m_capacity;

        delete[] m_ptr; // delete old space
        m_ptr = new uint8_t [m_capacity]; // allocating new space
    
        for (int i = 0; i < m_size; ++i) // copying the elements
        {
            m_ptr[i] = other.m_ptr[i];
        }
    }

    return *this;
}

// Move assignment operator for Vector<bool>
Vector<bool>& Vector<bool>::operator=(Vector&& other) noexcept
{
    // Move size and capacity from 'other'
    m_size = std::move(other.m_size);
    m_capacity = std::move(other.m_capacity);

    // Move pointer and invalidate 'other'
    delete[] m_ptr;
    m_ptr = std::move(other.m_ptr);

    // Reset 'other' to a valid state
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_ptr = nullptr;

    return *this;
}

// Access element at the given index, with bounds checking
bool Vector<bool>::at(size_t index) const
{
    // Check if the index is out of bounds
    if (index >= m_size)
    {
        std::cerr << "Index >= m_size for [] operator:\n";
        exit(-1);
    }

    // Create a Reference object for the specified index
    Reference ref(m_ptr, index);
    return ref;
}

// Default constructor
Vector<bool>::Vector()
{
    m_ptr = nullptr;
    m_size = 0;
    m_capacity = 0;
}

// Constructor with size and default value
Vector<bool>::Vector(size_t size, bool obj)
{
    // Set size and calculate capacity
    m_size = size;
    m_capacity = m_size / BYTE + 1;
    m_ptr = new uint8_t[m_capacity]{}; // Initialize with zero

    // Initialize elements with the specified value
    for (int i = 0; i < size; ++i)
    {
        (*this)[i] = obj;
    }
}

// Constructor with an initializer list
Vector<bool>::Vector(std::initializer_list<bool> list)
{
    // Set size and calculate capacity
    m_size = list.size();
    m_capacity = m_size / BYTE + 1;
    m_ptr = new uint8_t[m_capacity]{}; // Initialize with zero

    int index = 0;
    // Iterate through the initializer list and set bits accordingly
    for (const auto& elem : list)
    {
        m_ptr[index / BYTE] |= elem << (index % BYTE);
        ++index;
    }
}

// Copy constructor
Vector<bool>::Vector(const Vector<bool>& other) noexcept
{
    // Copy size and capacity
    m_size = other.m_size;
    m_capacity = other.m_capacity;

    // Allocate new memory and copy elements
    m_ptr = new uint8_t[m_size];
    for (int i = 0; i < m_size; ++i)
    {
        m_ptr[i] = other.m_ptr[i];
    }
}

// Move constructor
Vector<bool>::Vector(Vector<bool>&& other) noexcept
{
    // Move size, capacity, and pointer
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_ptr = other.m_ptr;

    // Reset 'other' to a valid state
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_ptr = nullptr;
}

// Destructor
Vector<bool>::~Vector()
{
    // Deallocate memory
    delete[] m_ptr;
    m_ptr = nullptr;
}

// Reference constructor with a pointer and index
Vector<bool>::Reference::Reference(uint8_t* ptr1, size_t index1) :
    ptr(ptr1), index(index1)
{
    // Initialize flag based on the bit at the specified index
    flag = (ptr[index / BYTE] >> (index % BYTE)) & 1;
}

// Copy constructor for Reference
Vector<bool>::Reference::Reference(const Reference& obj) noexcept
{
    // Copy index, pointer, and flag
    index = obj.index;
    ptr = obj.ptr;
    flag = obj.flag;
}

// Subscript operator for Vector<bool>
Vector<bool>::Reference Vector<bool>::operator[](size_t index)
{
    // Create and return a Reference object for the specified index
    return Vector::Reference(m_ptr, index);
}

// Move constructor for Reference
Vector<bool>::Reference::Reference(Reference&& obj) noexcept
{
    // Move index, pointer, and flag, and invalidate 'obj'
    index = obj.index;
    ptr = obj.ptr;
    flag = obj.flag;
    obj.ptr = nullptr;
    obj.index = 0;
    obj.flag = 0;
}

// Assignment operator for Reference
Vector<bool>::Reference& Vector<bool>::Reference::operator=(bool flag)
{
    // Set the bit at the specified index to the new flag value
    if (this->flag != flag)
    {
        ptr[index / BYTE] &= ~(1 << (index % BYTE));
        ptr[index / BYTE] |= (flag << (index % BYTE));
    }
    return *this;
}

// Assignment operator for Reference
Vector<bool>::Reference& Vector<bool>::Reference::operator=(const Reference& obj)
{
    // Assign the flag value from 'obj'
    if (flag != obj.flag)
    {
        (*this) = obj.flag;
    }
    return *this;
}

// Conversion operator to bool for Reference
Vector<bool>::Reference::operator bool() const
{
    return flag;
}

// Return a pointer to the underlying data
uint8_t* Vector<bool>::data() const
{
    return m_ptr;
}

// Reserve memory for a specified capacity
void Vector<bool>::reserve(size_t new_capacity)
{
    // Check if the new capacity is within bounds
    if (new_capacity > m_max_size)
    {
        std::cerr << "Erong size for reserve:\n"; // Typo: 'Er...'; should be 'Wrong size for reserve:'
        exit(-1);
    }

    // Calculate new capacity in bytes
    new_capacity = new_capacity / BYTE + static_cast<bool>(new_capacity % BYTE);

    // Check if reallocation is needed
    if (new_capacity > m_capacity)
    {
        m_capacity = new_capacity;

        // Allocate new memory and copy existing elements
        if (m_ptr == nullptr)
        {
            m_ptr = new uint8_t[m_capacity];
        }
        else
        {
            uint8_t* new_ptr = new uint8_t[m_capacity];
            for (int i = 0; i < m_size; ++i)
            {
                new_ptr[i] = m_ptr[i];
            }

            // Deallocate old memory and update the pointer
            delete[] m_ptr;
            m_ptr = new_ptr;
            new_ptr = nullptr;
        }
    }
}

// Resize the vector to a new size
void Vector<bool>::resize(size_t new_size)
{
    // Check if the new size is within bounds
    if (new_size > m_max_size)
    {
        std::cerr << "new_size > m_max_size in resize:\n";
        exit(-1);
    }

    // Calculate new size in bytes
    new_size = new_size / BYTE + static_cast<bool>(new_size % 8);

    // Check if reallocation is needed
    if (m_ptr == nullptr)
    {
        // Allocate new memory if the vector is empty
        m_capacity = new_size;
        m_ptr = new uint8_t[m_capacity]{};
    }
    else if (new_size > m_capacity)
    {
        // Allocate new memory and copy existing elements
        m_capacity = new_size;
        uint8_t* new_ptr = new uint8_t[m_capacity]{};
        for (int i = 0; i < m_size; ++i)
        {
            new_ptr[i] = m_ptr[i];
        }

        // Deallocate old memory and update the pointer
        delete[] m_ptr;
        m_ptr = new_ptr;
        new_ptr = nullptr;
    }
    else
    {
        // Update the size if no reallocation is needed
        m_size = new_size;
    }
}

// Reduce the capacity to fit the actual size
void Vector<bool>::shrink_to_fit()
{
    // Calculate the wanted size in bytes
    size_t wanted_size = m_size / BYTE + static_cast<bool>(m_size % BYTE);

    // Check if shrinking is necessary
    if (wanted_size < m_capacity)
    {
        m_capacity = wanted_size;

        // Allocate new memory and copy existing elements
        uint8_t* new_ptr = new uint8_t[m_capacity];
        for (int i = 0; i < wanted_size; ++i)
        {
            new_ptr[i] = m_ptr[i];
        }

        // Deallocate old memory and update the pointer
        delete[] m_ptr;
        m_ptr = new_ptr;
        new_ptr = nullptr;
    }
}

// Add an element to the end of the vector
void Vector<bool>::push_back(bool val)
{
    // Check if the vector is close to its maximum size
    if (m_size > m_max_size - 10)
    {
        std::cerr << "m_size > m_max_size - 10 in push_back:\n";
        exit(-1);
    }

    // Check if reallocation is needed
    if (m_size / BYTE == m_capacity && m_size % BYTE == 0)
    {
        resize(m_capacity + 2);
    }

    // Set the new element at the end of the vector
    (*this)[m_size] = val;
    ++m_size;
}

// Remove the last element from the vector
void Vector<bool>::pop_back()
{
    // Check if the vector is empty
    if (m_size == 0)
    {
        std::cerr << "Size is 0 for pop:\n";
        exit(-1);
    }

    // Decrease the size to remove the last element
    --m_size;
}

// Swap contents with another vector
void Vector<bool>::swap(Vector<bool>& other)
{
    // Swap size, capacity, and pointer
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
    std::swap(m_ptr, other.m_ptr);
}

// Return the current size of the vector
size_t Vector<bool>::size() const
{
    return m_size;
}

// Return the current capacity of the vector
size_t Vector<bool>::capacity() const
{
    return m_capacity;
}

// Return the maximum size the vector can reach
const size_t Vector<bool>::max_size() const
{
    return m_max_size;
}

// Clear all elements in the vector
void Vector<bool>::clear()
{
    // Set all bytes to zero and reset the size
    int size = m_size / BYTE + static_cast<bool>(m_size % BYTE);
    for (int i = 0; i < size; ++i)
    {
        m_ptr[i] = 0;
    }
    m_size = 0;
}

// Check if the vector is empty
bool Vector<bool>::empty() const
{
    return m_size == 0;
}


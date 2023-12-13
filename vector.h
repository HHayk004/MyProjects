#ifndef VECTOR_PROTO_H
    #define VECTOR_PROTO_H

    #ifndef IOSTREAM
        #define IOSTREAM
        #include <iostream>
    #endif

    #ifndef INITIALIZER_LIST
        #define INITIALIZER_LIST
        #include <initializer_list>
    #endif

    #ifndef LIMITS
        #define LIMITS
        #include <limits>
    #endif    

    template <typename T>
    class MyVector 
    {
        private:
            T* m_ptr;
            size_t m_size;
		    const size_t m_max_size = std::numeric_limits<size_t>::max() / sizeof(T);
            size_t m_capacity;
        
        public:
		    MyVector();
		    MyVector(T);
		    MyVector(std::initializer_list<T>);
		    MyVector(const MyVector&) noexcept;
            MyVector(MyVector&&);
		    ~MyVector();
 
			class Iterator{
				private:
					T* ptr;

				public:
					explicit Iterator(T*);
					
					Iterator& operator=(const Iterator&);
					Iterator operator++();
					Iterator operator++(int);
					
					T& operator*() const;
					T* operator->() const;
					bool operator==(const Iterator&) const;
					bool operator!=(const Iterator&) const;
			};

            T& operator[](const size_t) const;

            MyVector& operator=(std::initializer_list<T>);
            MyVector& operator=(const MyVector&);
            MyVector& operator=(MyVector&&);

            std::ostream& operator<<(std::ostream&) const;

            T* data() const;
            T at(size_t) const;
    
            T& back() const;
            T& front() const;

            void shrink_to_fit();
        
            void reserve(size_t);
            void resize(size_t);
            bool empty() const;        
        
            void push_back(T);
            void pop_back();
        
            void insert(size_t, T);
            void erase(size_t);
            void erase(size_t, size_t);

            void swap(MyVector&);

            size_t size() const;
            const size_t max_size() const;
            size_t capacity() const;

            void clear();
    };

    template <>
    class MyVector<bool>
    {
        private:
            size_t m_size;
            size_t m_capacity;
            const size_t m_max_size = std::numeric_limits<size_t>::max() / sizeof(bool);
            uint8_t* m_ptr;

        public:
            MyVector();
		    MyVector(bool);
		    MyVector(std::initializer_list<bool>);
		    MyVector(const MyVector<bool>&) noexcept;
            MyVector(MyVector<bool>&&);
		    ~MyVector();
            
            class Reference {
                private:
                    uint8_t* ptr;
                    size_t index;
                    bool flag;
                
                public:
                    Reference(uint8_t*, size_t);
					Reference(const Reference&);
					Reference(Reference&&);                   
					operator bool() const; 
                    Reference& operator=(const Reference& obj);
                    Reference& operator=(bool flag);
            };  
            
            Reference operator[](size_t index);
            std::ostream& operator<<(std::ostream&) const;

            MyVector& operator=(std::initializer_list<bool>);
            MyVector& operator=(const MyVector&);
            MyVector& operator=(MyVector&&); 

            uint8_t* data() const;
            bool at(size_t) const;

            void shrink_to_fit();

            void reserve(size_t); 
            void resize(size_t);
            bool empty() const; 
        
            void push_back(bool);
            void pop_back();
        
            void swap(MyVector<bool>&);

            size_t size() const;
            const size_t max_size() const;
            size_t capacity() const;

            void clear();
    };
#endif

#ifndef VECTOR_HPP
    #define VECTOR_HPP
    #include "vector.hpp"
#endif

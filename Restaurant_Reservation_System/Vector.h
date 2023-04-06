#ifndef VEC_ITERATOR_H
#define VEC_ITERATOR_H

// VecIterator class template definition
template< typename T >
class VecIterator
{
   template< typename T > friend class vector;
public:
   VecIterator( T *p = 0 ) // default constructor
      : ptr( p )
   {
   }

   VecIterator( const VecIterator &iteratorToCopy ) // copy constructor
      : ptr( iteratorToCopy.ptr )
   {
   }

   ~VecIterator() // destructor
   {
   }

   // const return avoids: ( a1 = a2 ) = a3
   const VecIterator &operator=( const VecIterator &right )
   {
      if( &right != this ) // avoid self-assignment
         ptr = right.ptr;
      return *this; // enables x = y = z, for example
   }

   T& operator*() const // dereferencing operator
   {
      return *ptr;
   }

   T* operator->() const // class member access operator
   {
      return ptr;
   }

   VecIterator& operator++() // prefix increment operator
   {
      ++ptr;
      return *this;
   }

   VecIterator& operator--() // predecrement an iterator
   {
      --ptr;
      return *this;
   }

   bool operator==( const VecIterator &right ) const // equal to
   {
      return ptr == right.ptr;
   }

   bool operator!=( const VecIterator &right ) const // not equal to
   {
      return ptr != right.ptr;
   }

private:
   T *ptr; // keep a pointer to vector
}; // end class template VecIterator

#endif


#ifndef VECTOR_H
#define VECTOR_H

// vector class template definition
template< typename T >
class vector
{
public:
   using iterator = VecIterator< T >;
//   typedef VecIterator< T > iterator;

   vector( unsigned int n = 0 ); // Constructor; Constructs a zero vector with size n

   // Copy constructor; Constructs a vector with a copy of each of the elements in vectorToCopy.
   vector( const vector &vectorToCopy );

   ~vector(); // Destroys the vector.

   // subscript operator for const objects returns rvalue
   T operator[]( unsigned int subscript ) const;

   iterator begin() const; // Returns a pointer pointing to the first element in the vector.
                           // If the vector is empty, the returned pointer shall not be dereferenced.

   // Returns an pointer pointing to the past-the-end element in the vector.
   // The past-the-end element is the theoretical element that would follow the last element in the vector.
   // It does not point to any element, and thus shall not be dereferenced.
   iterator end() const;

   // Returns the number of elements in the vector.
   // This is the number of actual objects held in the vector,
   // which is not necessarily equal to its storage capacity.
   unsigned int size() const;

   // Returns the size of the storage space currently allocated for the vector,
   // expressed in terms of elements.
   unsigned int capacity() const;
   
   // Adds a new element at the end of the vector, after its current last element.
   // The content of val is copied to the new element.
   // This effectively increases the vector size by one,
   // which causes an automatic reallocation of the allocated storage space
   // if and only if the new vector size surpasses the current vector capacity.
   void push_back( const T val );

   iterator erase( iterator position );
   // Removes from the Vector a single element.   
   // This effectively reduces the container size by one.   
   // Relocates all the elements after the element erased to their new positions.

private:
   T *myFirst = nullptr;
   T *myLast = nullptr;
   T *myEnd = nullptr;
}; // end class template vector

#endif


#ifndef VECTOR_CPP
#define VECTOR_CPP

// constructor; constructs a zero vector with size n
template< typename T >
vector< T >::vector( unsigned int n )
   : myFirst( n == 0 ? nullptr : new T[ n ]() ),
      myLast( n == 0 ? nullptr : myFirst + n ),
       myEnd( n == 0 ? nullptr : myLast )
{
} // end vector default constructor

// copy constructor; constructs a vector with a copy of each of the elements in vectorToCopy
template< typename T >
vector< T >::vector( const vector< T > &vectorToCopy )
   : myFirst( vectorToCopy.capacity() == 0 ? nullptr : new T[ vectorToCopy.capacity() ] ),
      myLast( vectorToCopy.capacity() == 0 ? nullptr : myFirst + vectorToCopy.size() ),
       myEnd( vectorToCopy.capacity() == 0 ? nullptr : myFirst + vectorToCopy.capacity() )
{
   for( unsigned int i = 0; i < size(); i++ )
      myFirst[ i ] = vectorToCopy.myFirst[ i ];
} // end vector copy constructor

// destructor; destroys the vector
template< typename T >
vector< T >::~vector()
{
   if( myFirst != nullptr )
      delete[] myFirst;
} // end destructor

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
template< typename T >
T vector< T >::operator[]( unsigned int subscript ) const
{
   // check for subscript out-of-range error
   if( subscript < 0 || subscript >= size() )
   {
      cerr << "\nError: Subscript " << subscript << " out of range\n";
      system( "pause" );
      exit( 1 ); // terminate program; subscript out of range
   } // end if

   return myFirst[ subscript ]; // returns copy of this element
} // end function operator[]

template< typename T >
VecIterator< T > vector< T >::begin() const
{
   return iterator( myFirst );
}

template< typename T >
VecIterator< T > vector< T >::end() const
{
   return iterator( myLast );
}

template< typename T >
unsigned int vector< T >::size() const
{
   return ( myLast - myFirst );
}

template< typename T >
unsigned int vector< T >::capacity() const
{
   return ( myEnd - myFirst );
}
// Adds a new element at the end of the vector, after its current last element.
// The content of val is copied to the new element.
// This effectively increases the vector size by one,
// which causes an automatic reallocation of the allocated storage space
// if and only if the new vector size surpasses the current vector capacity.
template<typename T>
void vector<T>::push_back(const T val)
{
	int tmpsize = size();
	int tmpcapacity = capacity();
	T *copy = new T[tmpsize + 1];
	for (int i = 0; i < size(); i++)
	{
		copy[i] = myFirst[i];
	}
	copy[size()] = val;
	delete[] myFirst;
	myFirst = copy;
	myLast = myFirst + (tmpsize + 1);
	myEnd = myFirst + (tmpcapacity + 1);
}
template<typename T>
VecIterator< T > vector<T>::erase(iterator position)
{
	if (myLast != myFirst)
	{
		*position = myFirst[size() - 1];
		myLast--;
		return iterator();
	}
}
// Removes from the Vector a single element.   
// This effectively reduces the container size by one.   
// Relocates all the elements after the element erased to their new positions.
#endif
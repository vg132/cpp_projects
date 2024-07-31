#ifndef __6BF5E12394D0A11D6CF0__VGPTR__HPP__
#define __6BF5E12394D0A11D6CF0__VGPTR__HPP__

#include <map>
#include <iostream>

namespace vwf
{
	template <class TYPE>
	class CVGPtr
	{
	private:
		TYPE *ptr;
		int *count;
		CVGPtr(TYPE *p, int *c);

		template <class U>
			friend class CVGPtr;

		template <class TO, class FROM> 
		friend CVGPtr<TO> dynamic_ptr_cast(const CVGPtr<FROM>& p);
	public:
		CVGPtr(TYPE *ptr=NULL) throw(std::bad_alloc);
		CVGPtr(const CVGPtr& other) throw();
		~CVGPtr();

		template <class OTHERTYPE>
			operator CVGPtr<OTHERTYPE>();
		TYPE& operator*(){return(*ptr);};
		TYPE* operator->(){return(ptr);};
		operator TYPE*() const throw(){return(ptr);};

		CVGPtr<TYPE>& operator=(const CVGPtr<TYPE>& other);
		bool operator==(const CVGPtr& other) const throw();
		bool operator!=(const CVGPtr& other) const throw();

		operator bool() const { return ptr != 0; }
	};

	template <class TYPE>
		CVGPtr<TYPE>::CVGPtr(TYPE *pek, int *c)
	: ptr(pek), count(c)
	{

	}

	template <class TYPE>
		CVGPtr<TYPE>::CVGPtr(TYPE *pek) throw(std::bad_alloc)
	: ptr(pek), count((pek)?new int(1):0)
	{
	}

	template <class TYPE>
		CVGPtr<TYPE>::CVGPtr(const CVGPtr& other) throw()
	: ptr(other.ptr),count(other.count)
	{
		if(ptr)
			(*count)++;
	}

	template <class TYPE>
	CVGPtr<TYPE>::~CVGPtr()
	{
		if((ptr)&&((--*count)==0))
		{
			delete count;
			delete ptr;
		}
	}

	template <class TYPE>
		template <class OTHERTYPE>
		CVGPtr<TYPE>::operator CVGPtr<OTHERTYPE>()
	{
		return(CVGPtr<OTHERTYPE>(ptr,count));
	}

	template <class TYPE>
	bool CVGPtr<TYPE>::operator==(const CVGPtr& other) const throw()
	{
		return(ptr==other.ptr);
	}

	template <class TYPE>
	bool CVGPtr<TYPE>::operator!=(const CVGPtr& other) const throw()
	{
		return(ptr!=other.ptr);
	}

	template <class TYPE>
	CVGPtr<TYPE>& CVGPtr<TYPE>::operator=(const CVGPtr<TYPE>& other)
	{
		if(ptr!=other.ptr)
		{
			if(ptr&&((--*count)==0))
			{
				delete count;
				delete ptr;
			}
			ptr=other.ptr;
			count=other.count;
			if(ptr)
				++*count;
		}
		return(*this);
	}

	template <class TO, class FROM>
	CVGPtr<TO> dynamic_ptr_cast(const CVGPtr<FROM>& p)
	{
		if (TO *tmp=dynamic_cast<TO *>(p.ptr))
			return CVGPtr<TO>(tmp, p.count);
		else
			return CVGPtr<TO>();
	}
}
#endif // __6BF5E12394D0A11D6CF0__VGPTR__HPP__

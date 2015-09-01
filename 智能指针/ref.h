
template<class T>
class ref_ptr
{
public:

	typedef T element_type;

	ref_ptr():_ptr(0){}

	ref_ptr(T* ptr) : _ptr(ptr) { if (_ptr) _ptr->ref(); }
	ref_ptr(const ref_ptr& rp) : _ptr(rp._ptr) { if (_ptr) _ptr->ref(); }
	template<class Other> ref_ptr(const ref_ptr<Other>& rp) : _ptr(rp._ptr) { if (_ptr) _ptr->ref(); }
	~ref_ptr() { if (_ptr) _ptr->unref();  _ptr = 0; }

	ref_ptr& operator = (const ref_ptr& rp)
	{
		assign(rp);
		return *this;
	}

	template<class Other> ref_ptr& operator = (const ref_ptr<Other>& rp)
	{
		assign(rp);
		return *this;
	}

	inline ref_ptr& operator = (T* ptr)
	{
		if (_ptr==ptr) return *this;
		T* tmp_ptr = _ptr;
		_ptr = ptr;
		if (_ptr) _ptr->ref();
		// unref second to prevent any deletion of any object which might
		// be referenced by the other object. i.e rp is child of the
		// original _ptr.
		if (tmp_ptr) tmp_ptr->unref();
		return *this;
	}
	bool operator == (const ref_ptr& rp) const { return (_ptr==rp._ptr); }
	bool operator == (const T* ptr) const { return (_ptr==ptr); }
	friend bool operator == (const T* ptr, const ref_ptr& rp) { return (ptr==rp._ptr); }

	bool operator != (const ref_ptr& rp) const { return (_ptr!=rp._ptr); }
	bool operator != (const T* ptr) const { return (_ptr!=ptr); }
	friend bool operator != (const T* ptr, const ref_ptr& rp) { return (ptr!=rp._ptr); }

	bool operator < (const ref_ptr& rp) const { return (_ptr<rp._ptr); }


private:
	template<class Other> void assign(const ref_ptr<Other>& rp)
	{
		if (_ptr==rp._ptr) return;
		T* tmp_ptr = _ptr;
		_ptr = rp._ptr;
		if (_ptr) _ptr->ref();
		// unref second to prevent any deletion of any object which might
		// be referenced by the other object. i.e rp is child of the
		// original _ptr.
		if (tmp_ptr) tmp_ptr->unref();
	}
	template<class Other> friend class ref_ptr;
	T* _ptr;
};
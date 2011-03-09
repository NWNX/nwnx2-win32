template <class T>
class CExoArrayList_2 {
public:
	T *data;
	int len;
	int alloc;

	CExoArrayList_2();
	~CExoArrayList_2();
	int Add(T val, int reserver=1);
	int Remove(T val);
	int IndexOf(T val);
};

template<class T>
CExoArrayList_2<T>::CExoArrayList_2() {
	len = 0;
	alloc = 16;
	data = new T[alloc];
}

template<class T>
CExoArrayList_2<T>::~CExoArrayList_2() {
	len = 0;
	alloc = 0;
	delete[] data;
}


template<class T>
int CExoArrayList_2<T>::Add(T val, int reserve = 1) {
	if (len == alloc) {
		T *re;
		if ((re = (T*)realloc(data, sizeof(T) * (alloc+reserve))) == NULL)
			return -1;
		data = re;
		alloc += reserve;
	}
	data[len++] = val;
	return len;
}

template<class T>
int CExoArrayList_2<T>::Remove(T val) {
	int i=0;
	while (i < len) {
		if (data[i] == val) break;
		++i;
	}
	if (i < len) {
		for (len; i<len; ++i)
			data[i] = data[i+1];
	}
	--len;
	return i;
}

template<class T>
int CExoArrayList_2<T>::IndexOf(T val) {
	if (len <=0) return -1;

	for (int i=0; i<len; ++i) {
		if (data[i] == val) return i;
	}

	return -1;
}

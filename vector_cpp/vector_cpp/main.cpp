#include<iostream>
#include<Windows.h>
#include"vld.h"
using namespace std;

namespace V {
	template<class T>
	class vector {
	public://----------------������--------------------------
		typedef vector<T> Self;
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin() const {
			return _start;
		}
		iterator end() const {
			return _finish;
		}

	public://-----------------init-------------------------------
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		vector(int n, const T& data)
			:_start(new T[n])
		{
			for (int i = 0;i < n;i++) {
				_start[i] = data;
			}
			_finish = _endofstorage = _start + n;
		}
		template<class Iterator>
		vector(Iterator frist, Iterator last) {
			size_t count = 0;
			auto it = frist;
			while (it != last) {
				it++;
				count++;
			}
			_start = new T[count];

			for (size_t i = 0;i < count;i++) {
				_start[i] = *frist++;
			}
			_finish = _endofstorage = _start + count;
		}
		vector(const Self& v) {
			_start = _finish = new T[v.size()];
			_endofstorage = _start + v.size();
			iterator it = v.begin();
			while (_finish != _endofstorage) {
				*_finish = *it;
				_finish++;
				it++;
			}
		}
		~vector() {
			clear();
		}
	public://----------------����-----------------------------
		T& operator[](int i) {
			return *(_finish + i);
		}
		//const T& operator[](int i) {
		//	return *(_finish + i);
		//}

	//public://----------------function-------------------------
		size_t size()const {
			return _finish - _start;
		}
		size_t capacity()const {
			return _endofstorage - _start;
		}
		bool empty() {
			return _start == _finish;
		}
		void reserve(size_t n) {
			size_t oldsize = size();
			if (n <= capacity()) {
				return;
			}
			T* p = new T[n];
			memcpy(p, _start, sizeof(T)*size());
			delete[] _start;
			_start = p;
			_finish = p + oldsize;
			_endofstorage = _start + n;
		}
		void resize(size_t newsize, const T& data) {
			reserve(newsize);
			auto it = newsize - size() + _finish;
			for (;_finish < it;_finish++) {
				*_finish = data;
			}
		}
		iterator insert(iterator pos, const T& data) {
			if (_finish == _endofstorage) {
				reserve(capacity() * 2);
			}
			auto it = _finish();
			while (it != pos) {
				*it = *(it - 1);
				it--;
			}
			*it = data;
			++_finish;
			return pos;
		}
		void push_back(const T& data) {
			if (_finish == _endofstorage) {
				reserve(size() * 2);
			}
			*_finish = data;
			_finish++;
		}
		void pop_back() {
			_finish--;
		}
		T front() {
			return *_start;
		}
		T back() {
			return *(_finish - 1);
		}
		void clear() {
			if (_start == nullptr) {
				return;
			}
			delete[] _start;
			_start = _endofstorage = _finish = nullptr;
		}
	
	public://--------------------------------------------------------------------------
	private:
		T* _start;
		T* _finish;
		T* _endofstorage;
	};
}

int main() {
	V::vector<int>v1;
	V::vector<int>v2(1, 10);
	V::vector<int>v3(v2.begin(), v2.end());
	v3.reserve(100);
	v3.resize(6, 99);

	v3.push_back(2);
	for (auto e : v3) {
		cout << e << " ";
	}
	cout << endl;
	v3.pop_back();
	cout << v3.back() << " " << v3.front();
	cout << endl << v3.size() << " " << v3.capacity();
	system("pause");
	return 0;
}
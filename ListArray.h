#include <ostream>
#include "List.h"
#include <iostream>

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;
	void resize (int new_size){}
    public:
        // miembros públicos, incluidos los heredados de List<T>
    	ListArray(T* arr, int max, int n){
		 arr(arr), max(max), n(n);
	}
	~ListArray() {}
	
	T operator[](int pos){
		if( pos > 0 || pos < n){

		return pos;
		
		}else{
		throw std::invalid_argument("Posicion fuera");
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
	out <<"[";
	for (int i = 0; i < list.size(); ++i) {
		out << list[i];
		if (i < list.size() - 1) {
			out << ", ";
		}
	}
	out << "]";
	return out;

	}

	void insert(int pos, T e) override {
		if (pos < 0 || pos > n){
		throw std::out_of_range("Posición inválida en insert()");
		}
		if (n == max){
		resize(max * 2);
		}
		for (int i = n; i > pos; i--){
		arr[i] = arr[i - 1];
		arr[pos] = e;
		n++;
		}
	}
	void append(T e) override {
		insert(n , e);
	}
	void prepend(T e) override {
		insert(0 , e);
	
	}
	T remove(int pos) override {
	if (pos < 0 || pos > n){
	throw std::out_of_range("Posición inválida");
	}
	T removed_element = arr[pos];
	
	for (int i = pos; i < n - 1; ++i){
		arr[i] = arr[i+1];
	}
	--n;
	if (n <= max / 4 && max > MINSIZE) {
        resize(max / 2);
    	}
	return removed_element;
	}

	T get (int pos) override {
	if (pos < 0 || pos > n){
	throw std::out_of_range("Posición inválida");
	}
	else{
	return arr[pos];
	}	
	}
	int search(T e) override {
	if (pos > 0 && pos < n){
		return e;
	}else{
		return -1;
	}	
	}
	bool empty() override {
	if (arr[pos] == 0){
		std::cout << ("Lista vacia")
	}
	}
	int size() override {
		return n;

	}
}; 

template<class TYPE >
void swap(TYPE &a, TYPE & b){
	TYPE tmp = a;
	a = b;
	b = tmp;
}
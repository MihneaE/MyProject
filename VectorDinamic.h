#ifndef VECTORDINAMIC_H_
#define VECTORDINAMIC_H_
#include <iostream>
using namespace std;

template <typename T>
class VectorDinamic {
private:
	T* vectorDinamic;
	int capacitate;
	int dimensiune;

public:
	VectorDinamic()
	{
		capacitate = 2;
		vectorDinamic = new T[capacitate];
		dimensiune = 0;
	}

	VectorDinamic(const VectorDinamic& v)
	{
		this->capacitate = v.capacitate;
		this->dimensiune = v.dimensiune;
		this->vectorDinamic = new T[capacitate];
		for (int i = 0; i < v.dimensiune; ++i)
			this->vectorDinamic[i] = v.vectorDinamic[i];
	}

	VectorDinamic& operator=(const VectorDinamic& v)
	{
		if (this == &v)
			return *this;
		delete[] this->vectorDinamic;
		this->vectorDinamic = new T[v.capacitate];
		for (int i = 0; i < v.dimensiune; ++i)
			this->vectorDinamic[i] = v.vectorDinamic[i];

		this->capacitate = v.capacitate;
		this->dimensiune = v.dimensiune;
		return *this;
	}

	~VectorDinamic()
	{
		delete[] vectorDinamic;
	}

	

	void push(const T& element);
	void pop(int index);
	T& getElement(int index);
	int size();
	int getCapacitate();
};

template <typename T>
void VectorDinamic<T>::push(const T& element)
{
	if (dimensiune == capacitate)
	{
		T* aux = new T[2 * capacitate];
		for (int i = 0; i < capacitate; ++i)
			aux[i] = vectorDinamic[i];

		delete[] vectorDinamic;
		capacitate *= 2;
		vectorDinamic = aux;
	}

	vectorDinamic[dimensiune] = element;
	dimensiune++;
}

template <typename T>
void VectorDinamic<T>::pop(int index)
{
	for (int i = index; i < dimensiune - 1; ++i)
		vectorDinamic[i] = vectorDinamic[i + 1];
	dimensiune--;
}

template <typename T>
T& VectorDinamic<T>::getElement(int index)
{
	if (index < capacitate)
		return vectorDinamic[index];
	return vectorDinamic[0];
}

template <typename T>
int VectorDinamic<T>::size()
{
	return dimensiune;
}

template <typename T>
int VectorDinamic<T>::getCapacitate()
{
	return capacitate;
}

#endif
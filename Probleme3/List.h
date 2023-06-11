#pragma once
#include "Node.h"


template<typename T>

struct List{

private:

	Node<T>* head = NULL;

public:

	Node<T>* getHead() {
		return head;
	}

	void afisare() {


		Node<int>* aux = head;

		while (aux != NULL)
		{

			cout << aux->getData() << " ";
			aux = aux->getNext();
		}

	}

	void addStart(T data) {

		if (head == NULL) {
			head = new Node<T>();

			head->setNext(NULL);
			head->setData(data);
		}
		else {

			Node<T>* nou = new Node<T>();

			nou->setNext(head);
			nou->setData(data);
			head = nou;

		}


	}

	void addEnd(T data) {

		if (head == NULL) {

			head = new Node<T>();

			head->setNext(NULL);
			head->setData(data);

		}
		else
		{

			Node<T>* aux = head;

			while (aux->getNext() != NULL)
			{
				aux = aux->getNext();
			}

			Node<T>* nou = new Node<T>();

			nou->setData(data);
			nou->setNext(NULL);
			aux->setNext(nou);
		}


	}

	void addPoz(T data, int poz) {

		if (head == NULL) {

			head = new Node<T>();

			head->setNext(NULL);
			head->setData(data);

		}
		else
		{
			Node<T>* aux = head;
			int ct = 0;
			while (ct < poz)
			{
				ct++;
				aux = aux->getNext();
			}

			Node<T>* nou = new Node<T>();

			nou->setData(data);
			nou->setNext(aux->getNext());
			aux->setNext(nou);



		}



	}

	void stergerePrimul() {
		head = head->getNext();
	}

	void stergereUltimul() {

		Node<T>* aux = head;

		while (aux->getNext()->getNext() != NULL)
		{
			aux = aux->getNext();
		}

		aux->setNext(NULL);

	}

	void stergerePoz(int poz) {

		int ct = 0;
		Node<T>* aux = head;

		if (poz == 0) {
			stergerePrimul();
		}

		while (ct < poz - 1)
		{
			ct++;
			aux = aux->getNext();
		}

		if (aux->getNext() == NULL) {
			stergereUltimul();
		}

		aux->setNext(aux->getNext()->getNext());

	}

	int size() {

		Node<T>* aux = head;
		int ct = 0;

		while (aux != NULL)
		{
			aux = aux->getNext();
			ct++;
		}


		return ct;
	}

	int mediaAritmetica(int dim) {

		Node<T>* aux = head;

		int s = 0;

		for (int i = 0; i < dim; i++) {
			s += aux->getData();
			aux = aux->getNext();
		}

		return s / dim;
	}

	int ctMaiMareMedia(int dim) {

		Node<T>* aux = head;

		int media = mediaAritmetica(dim);
		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() > media) ct++;
			aux = aux->getNext();
		}

		return ct;
	}

	int ctPerechiCifZeci(int dim) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			Node<T>* nou = head;
			int ct1 = 0;
			while (ct1 < i - 1)
			{
				ct1++;
				nou = nou->getNext();
			}

			for (int j = i; j < dim; j++) {
				if (aux->getData() / 10 % 10 == nou->getData() / 10 % 10)
					ct++;
				nou = nou->getNext();
			}
			aux = aux->getNext();
		}

		return ct / 2;
	}

	int sumaCif(int nr) {

		int s = 0;

		while (nr != 0)
		{
			int c = nr % 10;
			s += c;
			nr /= 10;
		}

		return s;
	}

	int ctPerechiSumEgal(int dim) {

		Node* aux = head;
		Node* nou = head;
		int ct = 0;

		for (int i = 0; i < dim; i++) {
			nou = head;
			nextI(i + 1, nou);

			for (int j = 0; j < dim; j++) {

				if ((nou->getData() != aux->getData()) && (sumaCif(nou->getData()) == sumaCif(aux->getData()))) {
					ct++;
				}

				if (nou->getNext() == NULL) {
					j = dim;
					break;
				}
				nou = nou->getNext();
			}

			aux = aux->getNext();
		}

		return ct / 2;


	}

	void addPrime(int dim, List list) {


		for (int i = 0; i < dim; i++) {

			if (prim(list.head->getData())) {
				addStart(list.head->getData());
			}

			list.head = list.head->getNext();
		}

	}

	void addRestulImp(int dim, List list) {

		for (int i = 0; i < dim; i++) {
			int nr = list.head->getData();
			int sumacif = sumaCif(list.head->getData());
			addEnd(nr % sumacif);

			list.head = list.head->getNext();
		}

	}

};
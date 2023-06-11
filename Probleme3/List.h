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

		Node<T>* aux = head;
		Node<T>* nou = head;
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

	bool prim(int nr) {

		if (nr == 0 || nr == 1)
			return false;

		for (int i = 2; i <= nr / 2; i++)
			if (nr % i == 0)
				return false;

		return true;
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

	int maxi(int dim) {
		Node<T>* aux = head;
		int maxi = -1;

		for (int i = 0; i < dim; i++) {

			if (aux->getData() > maxi)
				maxi = aux->getData();

			aux = aux->getNext();
		}

		return maxi;
	}

	int mini(int dim) {
		Node<T>* aux = head;
		int mini = 99999;

		for (int i = 0; i < dim; i++) {

			if (aux->getData() < mini)
				mini = aux->getData();

			aux = aux->getNext();
		}

		return mini;
	}

	int mediaAritNenule(int dim) {

		Node<T>* aux = head;

		int s = 0;
		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() != 0) {
				ct++;
				s += aux->getData();
			}

			aux = aux->getNext();
		}


		return s / ct;
	}

	int getUltimulNr(int dim) {

		Node<T>* aux = head;

		for (int i = 0; i < dim - 1; i++)
			aux = aux->getNext();

		return aux->getData();
	}

	int ctIntervalAfara(int dim) {

		Node<T>* aux = head;

		int ct = 0;
		int ultim = getUltimulNr(dim);
		int primul = aux->getData();
		for (int i = 0; i < dim; i++) {
			if (aux->getData() < primul && aux->getData() > ultim)
				ct++;

			aux = aux->getNext();
		}

		return ct;
	}

	void setPoz(int poz, int nr) {
		Node<T>* aux = head;
		int ct = 0;
		while (ct < poz)
		{
			aux = aux->getNext();
			ct++;
		}

		aux->setData(nr);


	}

	void InlocNule(int dim) {

		Node<T>* aux = head;

		for (int i = 0; i < dim; i++) {

			if (aux->getData() == 0) {
				setPoz(i, mediaAritNenule(dim));
			}

			aux = aux->getNext();
		}

	}

	int divizorComun(int n, int m) {

		while (m != 0)
		{
			int r = n % m;
			n = m;
			m = r;
		}

		return n;
	}

	int ctPerechiPrime(int dim) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			int n, m;
			n = aux->getData();
			Node<T>* nou = head;
			for (int j = 0; j < dim; j++) {
				m = nou->getData();
				if (divizorComun(n, m) == 1) ct++;
				nou = nou->getNext();
			}

			aux = aux->getNext();
		}

		return ct / 2;
	}

	int ctPerechiPrimeUltim(int dim) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			int n, m;
			n = aux->getData();
			m = getUltimulNr(dim);
			if (divizorComun(n, m) == 1) ct++;

			aux = aux->getNext();
		}

		return ct;

	}

	int ctCifra(int dim, int nr) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() == nr)
				ct++;

			aux = aux->getNext();
		}

		return ct;
	}

	int getPoz(int poz) {

		Node<T>* aux = head;

		int ct = 0;

		while (ct < poz)
		{
			aux = aux->getNext();
			ct++;
		}

		return aux->getData();
	}

	void crescator(int dim) {

		Node<T>* head1 = head;

		int semn = 1;

		do {
			semn = 1;
			head1 = head;
			for (int i = 0; i < dim - 1; i++) {

				if (head1->getData() > head1->getNext()->getData()) {

					int aux = getPoz(i);
					setPoz(i, getPoz(i + 1));
					setPoz(i + 1, aux);
					semn = 0;
				}

				head1 = head1->getNext();
			}

		} while (semn == 0);



	}

	int ctEgalUiltim(int dim) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() == getUltimulNr(dim))
				ct++;

			aux = aux->getNext();
		}

		return ct;

	}

	int ctNrPrime(int dim) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (prim(aux->getData()))
				ct++;

			aux = aux->getNext();
		}

		return ct;


	}

	int ctNr(int nr) {
		int ct = 0;
		while (nr != 0)
		{
			ct++;
			nr /= 10;
		}
		return ct;
	}

	bool verifPatratPerfect(int nr) {

		int ctnr = ctNr(nr);
		if (ctnr > 2) {
			nr = nr / pow(10, ctnr - 2);
		}

		if (sqrt(nr) == (int)sqrt(nr))
			return true;

		return false;
	}

	void afisarePatratPerf(int dim) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (verifPatratPerfect(aux->getData()))
				cout << aux->getData() << " ";


			aux = aux->getNext();
		}


	}

	void afisareSumele(int dim) {

		int ct = dim;
		while (ct >= 1)
		{

			Node<T>* aux = head;
			int s = 0;
			for (int i = 0; i < ct; i++) {

				s += aux->getData();
				aux = aux->getNext();
			}
			cout << s << endl;

			ct--;
		}




	}

	int primulNr() {

		return head->getData();
	}

	int pozPrimaCif(int dim, int nr) {

		Node<T>* aux = head;

		int poz = 0;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() == nr)
				poz = i + 1;



			aux = aux->getNext();
		}

		return poz;
	}


};
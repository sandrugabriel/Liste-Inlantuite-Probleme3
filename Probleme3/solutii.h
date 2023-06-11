#pragma once
#include "List.h"


List<int> list;

/*#487
Se dă un vector cu n numere naturale. Să se determine câte dintre elemente au valoarea strict mai mare decât
media aritmetică a elementelor vectorului.
Ex:
5
5 0 2 1 4 se afiseaza 2
*/
void solutia1() {

	int dim = 5, v[100] = { 5, 0, 2, 1, 4 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	cout << list.ctMaiMareMedia(dim);

}

/*#4380
Se dă un vector cu n numere naturale. Să se determine câte dintre perechile de elemente din vector au aceeași cifră zecilor.
Ex:
6
145 207 56 1248 1001 249 se afiseaza 4
*/
void solutia2() {

	int dim = 6, v[100] = { 145, 207, 56, 1248, 1001, 249 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	cout << list.ctPerechiCifZeci(dim);
}

/*#499
Se dă un vector cu n numere naturale. Să se determine câte dintre perechile de elemente din vector sunt
formate din valori cu aceeași sumă a cifrelor.
Ex:
6
51 842 15 28 77 132
se afiseaza 4
*/
void solutia3() {

	int dim = 6, v[100] = { 51, 842, 15, 28, 77, 132 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);


}

/*#493
Se dă un vector x cu n elemente, numere naturale. Să se construiască un alt vector, y, cu proprietatea că y[i] este egal
cu restul împărțirii lui x[i] la suma cifrelor lui x[i].
Ex:
6
50 1815 15 289 35 40
se afiseaza 0 0 3 4 3 0
*/
void solutia4() {

	int dim = 6;
	int v[100] = { 50, 1815, 15, 289 ,35, 40 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	List<int> y;

	y.addRestulImp(dim, list);
	y.afisare();

}

/*#495
Se dă un vector x cu n elemente, numere naturale. Să se construiască un alt vector, y, care să conțină elementele prime
din x, în ordine inversă.
Ex:
6
50 5 15 29 13 40
 se afiseaza 13 29 5
*/
void solutia5() {

	int dim = 6;
	int v[100] = { 50, 5, 15, 29 ,13, 40 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);
	List<int> y;

	y.addPrime(dim, list);
	y.afisare();
}







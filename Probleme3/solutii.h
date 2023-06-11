﻿#pragma once
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

/*#986
Se dă un șir cu n elemente, numere reale. Să se determine câte dintre elemente se află în afara intervalului închis
determinat de primul și ultimul element.
Ex:
6
2 0 4 -1 -8 -3 se afiseaza 2
*/
void solutia6() {

	int dim = 6;
	int v[100] = { 2, 0, 4, -1, -8, -3 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	cout << list.ctIntervalAfara(dim);
}

/*#498
Se dă un vector cu n numere naturale. Să se determine câte dintre perechile de elemente din vector sunt prime între ele.
Ex:
6
51 18 15 28 77 121 se afiseaza 9
*/
void solutia7() {

	int dim = 6;
	int v[100] = { 51, 18, 15, 28, 77, 121 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	cout << list.ctPerechiPrime(dim);

}

/*#496
Se dă un vector cu n numere naturale. Să se determine câte dintre elementele vectorului sunt prime cu ultimul element.
Ex:
6
50 64 15 28 35 75 se afiseaza 2
*/
void solutia8() {

	int dim = 6;
	int v[100] = { 50, 64, 15, 28, 35, 75 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	cout << list.ctPerechiPrimeUltim(dim);
}

/*#161
* Se dă un vector cu n elemente, numere naturale. Să se înlocuiască toate elementele nule din vector cu partea întreagă
a mediei aritmetice a elementelor nenule din vector.
Ex:
5
0 2 0 4 5
se afiseaza 3 2 3 4 5
*/
void solutia9() {

	int dim = 5;
	int v[100] = { 0, 2, 0 ,4 ,5 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	list.InlocNule(dim);
	list.afisare();
}

/*#98
Se dă un șir cu n elemente numere naturale. Să se determine valoarea maximă din șir și de câte ori apare.
Ex:
5
5 3 2 4 5 se afiseaza 5 2
*/
void solutia10() {

	int dim = 5;
	int v[100] = { 5, 3 ,2, 4 ,5 };
	for (int i = 0; i < dim; i++)
		list.addEnd(v[i]);

	cout << list.maxi(dim) << " " << list.ctCifra(dim, list.maxi(dim));
}






/*3. Given two arrays: А[n] and B[m]. We need to create a
third array that should contain:
■■ Elements of both arrays;
■■ Elements common for two arrays;
■■ Elements of array A that are not included within B;
■■ Elements of array B that are not included within A;
■■ Elements of arrays A and B that are not common for
them (in other words an aggregation of the results of previous
varians).*/



#include <iostream>
#include <time.h>
using namespace std;
void initA(int *p, int Size);
void initB(int *p, int Size);
void initThird(int *p, int *q, int *f, int Size, int Sizec);
void print(int *p, int Size);
void elementsInBoth(int *p, int *q, int *third, int Size, int secondSize, int thirdSize);
void elementsInA(int *f, int *p, int thirdSize, int Size);
void elementsInB(int *f, int *q, int thirdSize, int secondSize);
void elementsOutsideAandB(int *f, int *p, int *q,int thirdSize, int secondSize, int firstSize);
void main() {
	//Step1: Add three sizes for the three arrays
	const int sizeOne = 3;
	const int secondSize = 5;
	const int thirdSize = 8;
	//Step2: Declare three arrays
	int a[sizeOne];
	int b[secondSize];
	int c[thirdSize];
	//Step 3: init and print (test) all arrays:
	int *p, *q, *f;
	p = &a[0];
	cout << " First array: " << endl;
	initA(p,sizeOne);
	print(p, sizeOne);
	q = &b[0];
	cout << endl << " Second array: " << endl;
	initB(q, secondSize);
	print(q, secondSize);
	p = &a[0];
	q = &b[0];
	f = &c[0];
	int matches[thirdSize];
	int *e;
	e = &matches[0];
	cout <<endl<< " Both arrays: " << endl;
	initThird(p,q,f,sizeOne,secondSize);
        print(f, thirdSize);
        //4.Execute the conditions:
	elementsInBoth(p,q,e,sizeOne,secondSize,thirdSize);
	elementsInA(f, p, thirdSize, sizeOne);
	elementsInB(f,q,thirdSize,secondSize);
	elementsOutsideAandB(f,p,q,thirdSize,secondSize,sizeOne);
	system("pause>nul");
}
/*5.Condition: Elements of arrays A and B that are not common for
them (in other words an aggregation of the results of previous
varians).*/
 void elementsOutsideAandB(int *f, int *p, int *q, int thirdSize, int secondSize, int firstSize) {
	 cout <<endl<< " Elements outside from A and B: " << endl;
	 for (int i = 0; i < thirdSize; i++) {
		 bool matchA = false;
		 bool matchB = false;
		 for (int j = 0; j < secondSize; j++) {
			 if (*(f+i)==*(q+j)) {
				 matchA = true;
			 }
		 }
		 for (int k = 0; k < firstSize; k++) {
			 if (*(f+i)==*(p+k)) {
				 matchB = true;
			 }
		 }
		 if (!matchA || !matchB) {
			 cout << *(f + i)<<" ";
		 }
	 }
}
void initA(int *p, int Size) {
	srand(time(NULL));
	int f = 0;
	for (int i = 0; i < Size; i++,p++) {
		cin >> f;
		*p = f;

	}
}
void initB(int *p, int Size) {
	srand(time(NULL));
	int y = 0;
	cout << endl;
	for (int i = 0; i < Size; i++, p++) {
		cin >> y;
		*p = y;
	}
}
//1.Condition: Elements of both arrays;
void initThird(int *p, int *q, int *f, int Size, int Sizec) {
	for (int i = 0; i < Size; i++,f++,p++) {
		*f = *p;
	}
	for (int i = Size; i < Size+Sizec; i++,f++,q++) {
		*f = *q;
	}
}
void print(int *p, int Size) {
	cout << endl;
	for (int i = 0; i < Size; i++, p++) {
		cout << *p<<" ";
	}
}
//2.Condition: Elements that contains in both arrays:
void elementsInBoth(int *p, int *q, int *third, int Size, int secondSize, int thirdSize) {
	int k = 0;
	cout << endl;
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < secondSize; j++) {
			if (*(p+i)==*(q+j)) {
				*(third + k) = *(p + i);
				k++;
			}
		}
	}
	cout << " Elements that exist in both arrays: " << endl;
	for (int i = 0; i < thirdSize; i++) {
		if (*(third+i)>=0) {
			cout << *(third + i);
		}
	}
}
//3.Condition: Elements of array B that are not included within A;
void elementsInB(int *f, int *p, int thirdSize, int Size) {
	cout<<endl<< " Elements that are included only in B and not in A: " << endl;
	for (int i = 0; i < thirdSize; i++) {
		bool match = false;
		for (int j = 0; j < Size; j++) {
			if (*(f+i)==*(p+j)) {
				match = true;
			}
		}
		if (!match) {
			cout << *(f + i)<<"  ";
		}
	}
}
//4.Condition: Elements of array A that are not included within B;
void elementsInA(int *f, int *q, int thirdSize, int secondSize) {
	cout<<endl<< " Elements that are included only in A and not in B: " << endl;
	for (int i = 0; i < thirdSize; i++) {
		bool match = false;
		for (int j = 0; j < secondSize; j++) {
			if (*(f + i) == *(q + j)) {
				match = true;
			}
		}
		if (!match) {
			cout << *(f + i)<<"    ";
		}
	}
}


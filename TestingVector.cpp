
#include "headers.h"
#include "Vector.h"

using namespace std;

void pushBack_Standartinis() {
	Vector<int> v;
	int dydis = 10000;
	int kiekis = 0;
	auto laikas = hrClock::now(); // nuimamas laikas

	for (int i = 0; i < dydis; i++) {
		v.push_back(i);
		if (v.size() == v.capacity()) {
			kiekis++;
		}
	}
	
	cout << " std::Vector efektyvumas uztruko: " << durationDouble(hrClock::now() - laikas).count() << " s." << endl; // baigiamas matuoti laikas
}

void test_standartinis() {
	Vector<int> v;
	cout << "std::Vector testo rezultatai" << endl;

	// asign
	v.assign(5, 10);
	cout << "assign() funkcija: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	// pop_back
	v.pop_back();
	cout << "pop_back funkcija: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	// push_back
	v.push_back(5);
	cout << "push_back funkcija: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	// reserve
	cout << "Vektoriaus dydis pries reserve: " << v.capacity() << endl;
	v.reserve(25);
	cout << "Vektoriaus dydis po reserve: " << v.capacity() << endl;

	// erase
	cout << "Vektoriaus dydis pries erase: " << v.size() << endl;
	v.erase(v.begin(), v.end());
	cout << "Vektoriaus dydis po erase: " << v.size() << endl;


}

void test_sukurtas() {
	Vector<int> v;
	cout << "std::Vector testo rezultatai" << endl;

	// asign
	v.assign(5, 10);
	cout << "assign() funkcija: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;


	// pop_back
	v.pop_back();
	cout << "pop_back funkcija: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;


	// push_back
	v.push_back(5);
	cout << "push_back funkcija: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	// reserve
	cout << "Vektoriaus dydis pries reserve: " << v.capacity() << endl;
	v.reserve(25);
	cout << "Vektoriaus dydis po reserve: " << v.capacity() << endl;

	// erase
	cout << "Vektoriaus dydis pries erase: " << v.size() << endl;
	v.erase(v.begin(), v.end());
	cout << "Vektoriaus dydis po erase: " << v.size() << endl;


}

void pushBack_Sukurtas() {
	Vector<int> v;
	int dydis = 10000;
	int kiekis = 0;
	auto laikas = hrClock::now(); // nuimamas laikas

	for (int i = 0; i < dydis; i++) {
		v.push_back(i);
		if (v.size() == v.capacity()) {
			kiekis++;
		}
	}

	cout << " sukurto Vector efektyvumas uztruko: " << durationDouble(hrClock::now() - laikas).count() << " s." << endl; // baigiamas matuoti laikas

}

int main() {

	test_standartinis();
	test_sukurtas();

	pushBack_Standartinis();
	pushBack_Sukurtas();



	return 0;
}


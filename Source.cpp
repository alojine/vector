#include "headers.h"
#include "Studentas.h"
#include "functions.h"

int main()
{
	cout << "Ar norite skityti duomenis is failo? (y/n) ";
	char howInput = charApsauga(howInput);

	if (howInput == 'n') Ranka();
	else {
		cout << "Ar norite ivesti faila? (y/n) ";
		char gen = charApsauga(gen);

		if (gen == 'y') automatinisGen();
		else automatinisBeGen();
	}


	system("pause");
}

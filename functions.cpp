#include "headers.h"
#include "Studentas.h"
#include "functions.h"

// Skaiciavimai
double vidurkis(Vector<int> p, int egz)
{	
	
	double v = 0;
	for (auto& el : p)
	{
		v += el;
	}

	if (p.size() != 0)
		v = v / (p.size() * 1.0) * 0.4 + egz * 0.6;
	else
		v = egz * 0.6;

	return v;
	
};

double mediana(Vector<int> p, int egz)
{

	double m, s;
	std::sort(p.begin(), p.end());
	if (p.size() % 2 == 0 && p.size() != 0)
	{
		m = (double)((p[p.size() / 2] + p[p.size() / 2 - 1]) / 2);
		s = (m * 4 / 10) + (egz * 0.6);
	}
	else if (p.size() % 2 != 0 && p.size() != 0)
	{
		s = p[p.size() / 2] * 0.4 + egz * 0.6;
	}
	else
		s = egz * 0.6;

	return s;
};

/*
void skaiciavimai(Vector<data>& st, char vm)
{
	for (auto& el : st)
	{
		if (vm == 'y')
			el.v = vidurkis(el.p, el.egz);
		else if (vm == 'n')
			el.m = mediana(el.p, el.egz);
		else if (vm == 'a')
		{
			el.m = mediana(el.p, el.egz);
			el.v = vidurkis(el.p, el.egz);
		}
	}
};
*/

// Apsaugos
int sveikojoApsauga(int& a)
{
	cin >> a;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cin >> a;
	}
	return a;
};

char charApsauga(char& a)
{
	do
	{
		cin >> a;
	} while (a != 'y' && a != 'n');
	return a;
};

char konteinerioApsauga(char& a)
{
	do
	{
		cin >> a;

	} while (a != 'v' && a != 'd' && a != 'l');
	return a;
}

int genrand()
{

	unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed1);
	std::uniform_int_distribution<int> dist(1, 10);
	int sk = dist(generator);

	return sk;
}

// Funkcijos Terminalui
void Ranka() {
	/*
	vector<data> st;
	cout << "Jei norite kad programa isvestu vidurki iveskite 'y', jeigu mediana, iveskite 'n': ";
	char vm = charApsauga(vm);

	cout << "Iveskite studentu skaiciu: ";
	int studentai = sveikojoApsauga(studentai);
	st.reserve(studentai);

	for (int i = 0; i < studentai; i++)
	{
		data temp;
		skaitymasRanka(temp);
		st.push_back(temp);
	}
	skaiciavimai(st, vm);
	antraste(vm);
	for (int i = 0; i < st.size(); i++)
	{
		rasymasRanka(st.at(i), vm);
	}

	st.clear();
	*/
}

void skaitymasRanka(data& st) {
	cout << "Iveskite studento varda: "; cin >> st.vardas;
	cout << "Iveskite studento pavarde: "; cin >> st.pavarde;
	cout << "Iveskite pazymiu kieki: ";
	int pazimys;
	int kiek = sveikojoApsauga(kiek);
	for (int i = 0; i < kiek; i++) {
		pazimys = genrand();
		st.p.push_back(pazimys);
		cout << "Ivestas " << i + 1 << "-asis pazimys: " << pazimys << endl;
	}
	st.p.shrink_to_fit();

	int it;
	char check;
	do {
		it = kiek;
		cout << "Jei noretumete ivesti dar pazymiu iveskite 'y', jei ne 'n': ";
		check = charApsauga(check);

		if (check == 'y') {
			pridetiRanka(st, it, kiek);
			for (int i = it; i < kiek; i++) {
				cout << "Ivestas " << i + 1 << "-asis pazimys: " << st.p[i] << endl;
			}
		}
	} while (check != 'n');

	st.egz = genrand();
	cout << "Egzamino vertinimas: " << st.egz << endl;

};

void pridetiRanka(data& st, int& it, int& kiek)
{
	kiek += 1;
	int pazimys;
	st.p.reserve(kiek);

	for (int i = it; i < kiek; i++)
	{
		pazimys = genrand();
		st.p.push_back(pazimys);
	}
	st.p.shrink_to_fit();
};

void rasymasRanka(data& st, char vm)
{
	cout << string(60, '-') << std::endl;
	cout << std::left << std::setw(20) << st.vardas << std::left << std::setw(20) << st.pavarde;
	if (vm == 'y') cout << std::left << std::setw(23) << std::setprecision(2) << st.v << endl;
	else if (vm == 'n') cout << std::left << std::setw(20) << std::setprecision(2) << st.m << endl;
};

void antraste(char vm)
{
	if (vm == 'n')
		cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Med.)" << endl;
	else if (vm == 'y')
		cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Vid.)" << endl;
};

//------------------------------

void automatinisGen()
{
	char gen = 'y';
	cout << "(Vidurkis/Mediana) - (y/n) ";
	char vm = charApsauga(vm);
	cout << "Kokia skirstymo strategija norite naudoti? 1 - 'y', 2 - 'n': ";
	char st = charApsauga(st);
	cout << endl;
	do
	{
		try
		{
			Vector<Studentas> s;
			Vector<Studentas> Kieti;
			Vector<Studentas> Vargsai;												   // Klases
			string fname = "studentai", n = "nuskriaustukai.txt", k = "kietiakai.txt"; // Failai
			cout << "Iveskite studentu kieki: ";
			int skiekis = sveikojoApsauga(skiekis);
			fname += std::to_string(skiekis) + ".txt";
			auto laikasVisa = hrClock::now(); // Laikas

			if (!(egzistuojaFailas(fname)))
				generuotifailus(fname, skiekis, 5);
			skaitymas(s, fname);
			std::sort(s.begin(), s.end(), rikiuotiPazymi);
			paskirstymas(s, Kieti, Vargsai, vm, st);
			std::sort(Kieti.begin(), Kieti.end(), rikiuotiVarda);
			std::sort(Vargsai.begin(), Vargsai.end(), rikiuotiVarda);

			rasymas(Kieti, k, vm);
			rasymas(Vargsai, n, vm);

			s.clear();
			Kieti.clear();
			Vargsai.clear();

			cout << "Visa programa uztruko " << durationDouble(hrClock::now() - laikasVisa).count() << " s" << endl;
			cout << endl;

			cout << "Ar norite ivesti dar viena faila? (y/n) ";
			char oneMore = charApsauga(oneMore);
			gen = oneMore;
			cout << endl;
		}
		catch (std::exception& e)
		{
			cout << "Nera tokio failo" << endl;
		}
	} while (gen == 'y');
}

void automatinisBeGen()
{
	Vector<Studentas> s;
	try
	{
		cout << "(Vidurkis/Mediana) - (y/n) ";
		char vm = charApsauga(vm);
		string kursiokai = "kursiokai.txt";
		skaitymas(s, "studentai.txt");
		std::sort(s.begin(), s.end(), rikiuotiPazymi);
		rasymas(s, kursiokai, vm);
	}
	catch (std::exception& e)
	{
		cout << "Neteisingas failo pavadinimas" << endl;
	}
}

inline bool egzistuojaFailas(string& fname)
{
	ifstream f(fname.c_str());
	return f.good();
}

void generuotifailus(string& failopavadinimas, int kiek, int nd)
{

	ofstream rf(failopavadinimas);

	string ndskaicius = "ND";
	string vardas = "Vardas";
	string pavarde = "Pavarde";

	auto start = hrClock::now(); // pradedamas skaiciavimas

	rf << std::left << std::setw(15) << "Vardas" << std::right << std::setw(15) << "Pavarde";
	for (int i = 0; i < nd; i++)
	{
		rf << std::right << std::setw(15) << ndskaicius + std::to_string(i + 1);
	}
	rf << std::right << std::setw(15) << "Egz." << endl;

	for (int i = 0; i < kiek; i++)
	{
		rf << std::left << std::setw(15) << vardas + std::to_string(i + 1) << std::right << std::setw(15) << pavarde + std::to_string(i + 1);
		for (int j = 0; j < nd; j++)
		{
			rf << std::right << std::setw(15) << genrand();
		}
		rf << std::right << std::setw(15) << genrand();
		if (i + 1 != kiek)
			rf << endl; // if sakinys, kad isvengti papildomo nuskaitymo kai pabaigoje failo endline ideda
	}

	cout << "Failo sudarymas uztruko: " << durationDouble(hrClock::now() - start).count() << endl;

	rf.close();
}

void skaitymas(Vector<Studentas>& s, string fname)
{
	auto laikasSkaitymas = hrClock::now();
	ifstream fd(fname);
	if (fd.is_open())
	{
		string vardas, pavarde;
		int egz, nd;
		int st = 0, mk = 0;
		string line;
		std::stringstream buffer;
		std::getline(fd, line);

		buffer << line;
		string reiksme;
		while (buffer >> reiksme)
			st++;
		for (int l = 0; std::getline(fd, line); l++)
			mk++;
		fd.clear();
		fd.seekg(0);
		std::getline(fd, line);

		data temp;
		for (int i = 0; i < mk; i++)
		{
			fd >> vardas >> pavarde;
			Studentas studentas(vardas, pavarde);

			for (int j = 0; j < st - 3; j++)
			{
				fd >> nd;
				studentas.setPazymi(nd);
			}
			fd >> egz;
			studentas.setEgzaminas(egz);
			studentas.setVidurki();
			studentas.setMediana();
			s.push_back(studentas);
		}
	}
	fd.close();
	cout << "Failo nuskaitymas uztruko: " << durationDouble(hrClock::now() - laikasSkaitymas).count() << " s" << endl;
}

void paskirstymas(Vector<Studentas>& s, Vector<Studentas>& Kieti, Vector<Studentas>& Vargsai, char vm, char stratType)
{

	auto laikasSkirstymas = hrClock::now();

	if (stratType == 'n')
	{
		Vector<Studentas>::iterator it = s.end();
		it--;

		if (vm == 'y')
		{
			for (auto i = s.size() - 1; i > 0; i--)
			{
				if (it->getVidurkis() < 5)
				{
					Vargsai.push_back(*it);
					s.resize(s.size() - 1);
				}
				it--;
			}
		}

		if (vm == 'n')
		{
			for (auto i = s.size() - 1; i > 0; i--)
			{
				if (it->getMediana() < 5)
				{
					Vargsai.push_back(*it);
					s.resize(s.size() - 1);
				}
				it--;
			}
		}
		Kieti = s;
		s.clear();
	}

	else if (stratType == 'y')
	{
		if (vm == 'y')
		{
			for (auto& el : s)
			{
				if (el.getVidurkis() >= 5)
					Kieti.push_back(el);
				else
					Vargsai.push_back(el);
			}
		}

		else if (vm == 'n')
		{
			for (auto& el : s)
			{
				if (el.getMediana() >= 5)
					Kieti.push_back(el);
				else
					Vargsai.push_back(el);
			}
		}
	}
	cout << "Failo skirstymas i grupes uztruko: " << durationDouble(hrClock::now() - laikasSkirstymas).count() << " s" << endl;
}

void rasymas(Vector<Studentas>& s, string fname, char vm)
{
	auto laikasNuskriaustukai = hrClock::now();
	Vector<Studentas>::iterator it;

	std::stringstream buffer;
	buffer << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde";
	if (vm == 'y')
		buffer << std::left << std::setw(20) << "Galutinis(Vid.)";
	else if (vm == 'n')
		buffer << std::left << std::setw(20) << "Galutinis(Med.)";
	buffer << endl;

	for (auto& el : s)
	{
		buffer << el;
	}
	buffer.clear();

	buffFaila(fname, buffer);
	cout << fname << " surasymas uztruko: " << durationDouble(hrClock::now() - laikasNuskriaustukai).count() << " s" << endl;
};

void buffFaila(string fname, std::stringstream& buffer)
{
	ofstream fp(fname);
	fp << buffer.rdbuf();
	fp.close();
};

bool rikiuotiVarda(Studentas& a, Studentas& b)
{
	return a.getVardas() < b.getVardas();
}

bool rikiuotiPazymi(Studentas& a, Studentas& b)
{
	return a.getEgzaminas() < b.getEgzaminas();
}
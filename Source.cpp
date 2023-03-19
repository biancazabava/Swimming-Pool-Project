#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;
//Am ales tema Bazin de inot

//metode virtuale
class Persoana{
public:
	virtual void afiseazaNume() = 0;
	virtual void raport() = 0;
};
class Bazin
{
	char* denumire;
	int capacitate = 0;
	float lungime=0;
public:
	char* getDenumire()
	{
		return this->denumire;
	}
	void setDenumire(const char* denumire)
	{
		if (denumire != NULL)
		{
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else
			cout << "\nNume invalid\n";
	}
	int getCapacitate()
	{
		return this->capacitate;
	}
	void setCapacitate(int capacitate)
	{
		if (capacitate > 0)
			this->capacitate = capacitate;
	}
	float getLungime()
	{
		return this->lungime;
	}
	void setLungime()
	{
		if (lungime >= 15)
			this->lungime = lungime;
	}
	Bazin()
	{
		this->denumire = new char[strlen("Bazin neinaugurat") + 1];
		strcpy(this->denumire, "Bazin neinaugurat");
	}
	Bazin(const char* denumire,float lungime)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->lungime = lungime;
	}
	Bazin(const char* denumire, int capacitate, float lungime)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->capacitate = capacitate;
		this->lungime = lungime;
	}
	Bazin(const Bazin& b)
	{
		this->denumire = new char[strlen(b.denumire)+1];
		strcpy(this->denumire, b.denumire);
		this->capacitate = b.capacitate;
		this->lungime = b.lungime;
	}
	~Bazin()
	{
		if(denumire!=nullptr)
		delete[] this->denumire;
	}
	Bazin& operator=(const Bazin& b)
	{
		delete[] this->denumire;
		this->denumire = nullptr;
		this->denumire = new char[strlen(b.denumire)+1];
		strcpy(this->denumire, b.denumire);
		this->capacitate = b.capacitate;
		this->lungime = b.lungime;
		cout << "\nApel operator = \n";
		return *this;
	}
	friend ostream& operator<<(ostream& out, Bazin b)
	{
		cout << "Denumire: ";
		out << b.denumire;
		cout << "; Capacitate: ";
		out << b.capacitate;
		cout << "; Lungime bazin: ";
		out<< b.lungime;
		cout << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Bazin& b)
	{
		cout << "\nIntroduceti numele bazinului de inot: ";
		char buffer[200];
		in.getline(buffer, 199);
		delete[] b.denumire;
		b.denumire = new char[strlen(buffer) + 1];
		strcpy(b.denumire, buffer);
		cout << "Introduceti capacitatea bazinului: ";
		in >> b.capacitate;
		cout << "Introduceti lungimea bazinului: ";
		in >> b.lungime;

		return in;

	}
	void tipBazin()
	{
		if (lungime >= 15 && lungime < 25)
			cout<< "Bazinul este destinat incepatorilor";
		if (lungime >= 25 && lungime < 50)
			cout<< "Bazinul este de tip semiolimpic.";
		if (lungime >= 50)
			cout<< "Bazinul este de tip olimpic.";
		
	}
	void tipActivitate()
	{
		if (capacitate < 50)
			cout<< "\nBazinul este destinat exclusiv cluburilor sportive.";
		if (capacitate >= 50 && capacitate < 150)
			cout<< "\nBazinul este destinat incepatorilor si avansatilor.";
		if (capacitate >= 150)
			cout<< "\nBazinul este destinat tuturor persoanelor, indiferent de nivelul de pregatire.";
	}
	bool operator==(Bazin b)
	{
		if (this->capacitate = b.capacitate && this->lungime == b.lungime)
			return true;
		else
			return false;
	}
	Bazin operator-(int x)
	{
		Bazin copie = *this;
		copie.capacitate = copie.capacitate - 20;
		return copie;
	}
	//salvarea in fisier binar
	void salveaza_in_fisier(ofstream& out)
	{
		out.write((char*)&denumire, sizeof(denumire)+1);
		out.write((char*)&capacitate,sizeof(int));
		out.write((char*)&lungime, sizeof(float));
	}

};

class Sala
{
	static int etaje;
	string denumire;
	int nrVestiare;//numarul de camere ce contin vestiare
	int* vestiare;
public:
	static int getEtaj()
	{
		return Sala::etaje;
	}
	string getDenumire()
	{
		return this->denumire;
	}
	void setDenumire(string denumire)
	{
		if (denumire != "")
			this->denumire = denumire;
	}
	int getNrVestiare()
	{
		return this->nrVestiare;
	}
	int* getVestiare()
	{
		return this->vestiare;
	}
	void setVestiare(int nrVestiare, int* vestiare)
	{
		delete[] this->vestiare;
		if(nrVestiare>0)
		this->nrVestiare = nrVestiare;
		this->vestiare = new int[nrVestiare];
		for (int i = 0; i < nrVestiare; i++)
			this->vestiare[i] = vestiare[i];
	}
	Sala()
	{
		this->denumire = "";
		this->nrVestiare = 0;
		this->vestiare = nullptr;
	}
	Sala(string denumire)
	{
		this->denumire = denumire;
	}
	Sala(string denumire, int nrVestiare, int* vestiare)
	{
		this->denumire = denumire;
		if (nrVestiare > 0)
			this->nrVestiare = nrVestiare;
		this->vestiare = new int[nrVestiare];
		for (int i = 0; i < nrVestiare; i++)
			this->vestiare[i] = vestiare[i];
	}
	Sala(const Sala& s)
	{
		this->denumire = s.denumire;
		if (s.nrVestiare > 0)
			this->nrVestiare = s.nrVestiare;
		this->vestiare = new int[s.nrVestiare];
		for (int i = 0; i < s.nrVestiare; i++)
			this->vestiare[i] = s.vestiare[i];
	}
	~Sala()
	{
		delete[] this->vestiare;
	}
	Sala& operator=(const Sala& s)
	{
		delete[] this->vestiare;
		this->denumire = s.denumire;
		if (s.nrVestiare > 0)
			this->nrVestiare = s.nrVestiare;
		this->vestiare = new int[s.nrVestiare];
		for (int i = 0; i < s.nrVestiare; i++)
			this->vestiare[i] = s.vestiare[i];
		return *this;
	}
	friend ostream& operator<<(ostream& out, Sala s)
	{
		out << s.denumire << ", " << s.etaje << ", " << s.nrVestiare<<", ";
		for (int i = 0; i < s.nrVestiare; i++)
			out << s.vestiare[i]<<", ";
		return out;
	}
	friend istream& operator>>(istream& in, Sala& s)
	{
		cout << "\nIntroduceti numele salii de sport: ";
		in >> s.denumire;
		cout << "\nIntroduceti numarul de camere cu vestiare:";
		in >> s.nrVestiare;
		delete[] s.vestiare;
		s.vestiare = new int[s.nrVestiare];
		for (int i = 0; i < s.nrVestiare; i++)
		{
			cout << "Introduceti numarul de vestiare pentru camera " << i+1 << ": ";
			in >> s.vestiare[i];
		}
		return in;
	}

	void calculCapacitate()
	{
		int capacitate = 0;
		for (int i = 0; i < nrVestiare; i++)
			capacitate += vestiare[i];
		cout << "\nCapacitatea salii este de " << capacitate << " persoane.";
	}
	void facilitati()
	{
		if (nrVestiare >= 5)
			cout << "\nSala dispune de o camera pentru masaj";
		if (nrVestiare > 3&&nrVestiare< 5)
			cout << "\nSala dispune de o incapere dotata cu sauna";
		if(nrVestiare<=3)
				cout << "\nSala este in curs de expansiune";
	}
	Sala operator+(int x)//adauga o camera cu vestiare
	{
		Sala copie = *this;
		copie.nrVestiare = copie.nrVestiare + 1;
		delete[] copie.vestiare;
		copie.vestiare = new int[copie.nrVestiare];
		for (int i = 0; i < this->nrVestiare; i++)
			copie.vestiare[i] = this->vestiare[i];
		for (int i = this->nrVestiare; i < copie.nrVestiare; i++)
			copie.vestiare[i] = x;
		
		return copie;
	}
	bool operator==(Sala s)
	{
		int sumaVestiare1 = 0;
		int sumaVestiare2 = 0;
		for (int i = 0; i < this->nrVestiare; i++)
			sumaVestiare1 += this->vestiare[i];
		for (int i = 0; i < s.nrVestiare; i++)
			sumaVestiare2 += s.vestiare[i];
		if (this->etaje == s.etaje && sumaVestiare1 == sumaVestiare2)
			return true;
		else
			return false;
	}
	//salvarea in fisier binar
	void salveaza_in_fisier(ofstream& out)
	{
		out.write((char*)&denumire, sizeof(string));
		out.write((char*)&nrVestiare, sizeof(int));
		for (int i = 0; i < this->nrVestiare; i++)
			out.write((char*)&vestiare[i], sizeof(float));
	}
};
int Sala::etaje = 3;

class Instructor: public Persoana
{
	const int id;
	int aniExperienta;
	string nume;
	int nrPersoane;//numarul de persoane pe care le pregateste instructorul
	int* persoane;
public:
	int getId()
	{
		return this->id;
	}
	int getExperienta()
	{
		return this->aniExperienta;
	}
	void setExperienta(int experienta)
	{
		if(experienta>0)
		this->aniExperienta = experienta;
	}
	string getNume()
	{
		return this->nume;
	}
	void setGrad(string nume)
	{
		if (nume!="")
			this->nume = nume;
	}
	int* getPersoane()
	{
		return this->persoane;
	}
	void setPersoane(int nrPersoane, int* persoane)
	{
		if (nrPersoane > 0)
			this->nrPersoane = nrPersoane;
		delete[] this->persoane;
		this->persoane = new int[nrPersoane];
		for (int i = 0; i < nrPersoane; i++)
			this->persoane[i] = persoane[i];

	}
	Instructor():id(0)
	{
		this->aniExperienta = 0;
		this->nume = "";
		this->nrPersoane = 0;
		this->persoane = 0;
	}
	Instructor(int id, int aniExperienta, string nume):id(id)
	{
		this->aniExperienta = aniExperienta;
		this->nume = nume;
	}
	Instructor(int id, int aniExperienta, string nume, int nrPersoane, int* persoane):id(id)
	{
		this->aniExperienta = aniExperienta;
		this->nume = nume;
		this->nrPersoane = nrPersoane;
		this->persoane = new int[nrPersoane];
		for (int i = 0; i < nrPersoane; i++)
			this->persoane[i] = persoane[i];
	}
	Instructor(const Instructor& in):id(in.id)
	{
		this->aniExperienta = in.aniExperienta;
		this->nume = in.nume;
		this->nrPersoane = in.nrPersoane;
		this->persoane = new int[in.nrPersoane];
		for (int i = 0; i < in.nrPersoane; i++)
			this->persoane[i] = in.persoane[i];
	}
	~Instructor()
	{
		delete[] this->persoane;
	}
	Instructor& operator=(const Instructor& in)
	{
		delete[] this->persoane;
		this->aniExperienta = in.aniExperienta;
		this->nume = in.nume;
		this->nrPersoane = in.nrPersoane;
		this->persoane = new int[in.nrPersoane];
		for (int i = 0; i < in.nrPersoane; i++)
			this->persoane[i] = in.persoane[i];
		return *this;
	}
	friend ostream& operator<<(ostream& out, Instructor in)
	{
		out << in.id << ", " << in.aniExperienta << ", " << in.nume << ", " << in.nrPersoane<<", ";
		for (int i = 0; i < in.nrPersoane; i++)
			out << in.persoane[i] << ", ";
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Instructor& ins)
	{
		cout << "\nIntroduceti anii de activitate ai instructorului: ";
		in >> ins.aniExperienta;
		cout << "\nIntroduceti numele instructorului: ";
		in >> ins.nume;
		cout << "\nIntroduceti numarul de persoane pregatite de instructor: ";
		in >> ins.nrPersoane;
		for (int i = 0; i < ins.nrPersoane; i++)
		{
			cout << "Introduceti varsta persoanei " << i + 1<<": ";
			in >> ins.persoane[i];
		}
		return in;
	}

	string calculGrad()
	{
		if (nrPersoane > 0 && nrPersoane < 5)
			return "\nInstructorul are o grupa de incepatori";
		if (nrPersoane >= 5 && nrPersoane < 10)
			return "\nInstructorul are o grupa de intermediari";
		if (nrPersoane >= 10)
			return "\nInstructorul are o grupa de avansati";
	}
	void medieGrupa()
	{
		float medie = 0;
		for (int i = 0; i < nrPersoane; i++)
			medie += persoane[i];
		cout << "\nMedia grupei atribuite instructorului " << nume << " este de " << medie / nrPersoane << " ani.";
	}
	bool operator==(Instructor in)
	{
		if (in.aniExperienta == this->aniExperienta)
			return true;
		else
			return false;
	}
	int operator[](int index) {
		if (index >= 0 && index < this->nrPersoane) {
			return persoane[index];
		}
		else {
			return -1;
		}
	}
	explicit operator int()
	{
		return aniExperienta;
	}
	//salvarea in fisier binar
	void salveaza_in_fisier(ofstream& out)
	{
		out.write((char*)&aniExperienta, sizeof(int));
		out.write((char*)&nume, sizeof(string));
		out.write((char*)&nrPersoane, sizeof(int));
		for (int i = 0; i < this->nrPersoane; i++)
			out.write((char*)&persoane[i], sizeof(int));
	}

    void afiseazaNume()
	{ 
		cout << this->nume;
	}
	void raport()
	{
		cout << endl << "Instructorul " << this->nume << " are " << this->aniExperienta << " ani de experienta si antreneaza " << this->nrPersoane << " persoane ce au urmatoarele varste: ";
		for (int i = 0; i < this->nrPersoane; i++)
			cout << persoane[i] << " ";
	}
};

class Client
{
	char* nume=nullptr;
	int varsta;
	int inaltime;
public:
	const char* getNume()
	{
		return this->nume;
	}
	void setNume(const char* nume)
	{
		if (nume != nullptr)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
	}
	int getVarsta()
	{
		return this->varsta;
	}
	void setVarsta(int varsta)
	{
		if (varsta > 6)
			this->varsta = varsta;
		else
			cout << "Persoana este prea tanara pentru a participa la cursuri de inot.";
	}
	int getInaltime()
	{
		return this->inaltime;
	}
	void setInaltime()
	{
		if (inaltime > 100)
			this->inaltime = inaltime;
		else
			cout << "Persoana este prea scunda pentru a participa la cursuri de inot.";
	}
	Client()
	{
		this->varsta = 0;
		this->inaltime = inaltime;
	}
	Client(int varsta, int inaltime)
	{
		this->nume = new char[strlen("Nume Prenume") + 1];
		strcpy(this->nume, "Nume Prenume");
		this->varsta = varsta;
		this->inaltime = inaltime;
	}
	Client(const char* nume, int varsta, int inaltime)
	{
		if (nume != nullptr)
		{
			this->nume = new char[strlen(nume)+1];
			strcpy(this->nume, nume);
		}
		this->varsta = varsta;
		this->inaltime = inaltime;
	}
	Client(const Client& c)
	{
		this->nume = new char[strlen(c.nume) + 1];
		strcpy(this->nume, c.nume);
		this->varsta = c.varsta;
		this->inaltime = c.inaltime;
	}
	~Client()
	{
		delete[] this->nume;
	}
	Client& operator=(const Client& c)
	{
		delete[] this->nume;
		this->nume = new char[strlen(c.nume) + 1];
		strcpy(this->nume, c.nume);
		this->varsta = c.varsta;
		this->inaltime = c.inaltime;
		return *this;
	}
	friend ostream& operator<<(ostream& out, Client c)
	{
		out << c.nume << ", " << c.varsta << ", " << c.inaltime << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Client& c)
	{
		cout << "\nIntrodcueti numele clientului: ";
		char buffer[200];
		in.getline(buffer, 199);
		delete[] c.nume;
		c.nume = new char[strlen(buffer) + 1];
		strcpy(c.nume, buffer);
		cout << "\nIntroduceti varsta clientului: ";
		in >> c.varsta;
		cout << "Introduceti inaltimea clientului: ";
		in >> c.inaltime;
		cout << endl;
		return in;
	}
	void competitie()
	{
		if (varsta > 10)
			cout << "\nClientul se poate inscrie la competitii de inot.";
		if (varsta > 6 && varsta <= 10)
			cout << "\nClientul se poate inscrie doar la competitii pe echipe.";
	}

	void incadrare(string nivelPregatire)
	{
		if (nivelPregatire == "incepator")
			cout << "\nClientul are prioritate in folosirea echipamentului ajutator.";
		else
			if (nivelPregatire == "intermediar")
				cout << "\nClientul are prioritate la culoarele interioare.";
			else
				if (nivelPregatire == "avansat")
					cout << "\nClientul are prioritate la culoarele exterioare.";
	}

	bool operator==(Client c)
	{
		if (this->varsta == c.varsta && this->inaltime == c.inaltime)
			return true;
		else
			return false;
	}
	//pre-incrementare
	Client operator++()
	{
		this->varsta++;
		return *this;
	}
	//post-incrementare
	Client operator++(int x)
	{
		Client copie = *this;
		this->varsta++;
		return copie;
	}
	//salvarea in fisier binar
	void salveaza_in_fisier(ofstream& out)
	{
		out.write((char*)&nume, sizeof(nume)+1);
		out.write((char*)&varsta, sizeof(int));
		out.write((char*)&inaltime, sizeof(int));
	}
	void raport()
	{
		cout << endl << "Cientul " << this->nume << " are " << this->varsta << " ani si inaltimea de " << this->inaltime << " cm." << endl;
	}
	void afiseazaNume()
	{
		cout << this->nume;
	}

};

class Sedinta
{
	const float pret;
	int durata;
	int persoaneSedinta;
	float nrAbonati=0;//cati clienti care participa la sedinta au abonament
	float* abonati=nullptr;
public:
	float getPret()
	{
		return this->pret;
	}
	int getDurata()
	{
		return this->durata;
	}
	void setDurata()
	{
		if (durata > 30)
			this->durata = durata;
	}
	int getPersoaneSedinta()
	{
		return this->persoaneSedinta;
	}
	void setPersoane(int persoane)
	{
		if (persoane > 5)
			this->persoaneSedinta = persoane;
	}
	float* getAbonati()
	{
		return this->abonati;
	}
	void setAbonati(float nrAbonati, float* abonati)
	{
		if (nrAbonati > 0)
			this->nrAbonati = nrAbonati;
		this->abonati = new float[nrAbonati];
		for (int i = 0; i < nrAbonati; i++)
			this->abonati[i] = abonati[i];
	}
	Sedinta():pret(0)
	{
		this->persoaneSedinta = 0;
		this->durata = 0;
	}
	Sedinta(float pret, int durata, int nrPersoane):pret(pret)
	{
		this->durata = durata;
		this->persoaneSedinta = nrPersoane;
	}
	Sedinta(float pret, int durata, int nrPersoane, float nrAbonati, float* abonati) :pret(pret)
	{
		this->durata = durata;
		this->persoaneSedinta = nrPersoane;
		if (nrAbonati > 0)
			this->nrAbonati = nrAbonati;
		this->abonati = new float[nrAbonati];
		for (int i = 0; i < nrAbonati; i++)
			this->abonati[i] = abonati[i];
	}
	Sedinta(const Sedinta& s):pret(s.pret)
	{
		this->durata = s.durata;
		this->persoaneSedinta = s.persoaneSedinta;
		if (s.nrAbonati > 0)
			this->nrAbonati = s.nrAbonati;
		this->abonati = new float[s.nrAbonati];
		for (int i = 0; i < s.nrAbonati; i++)
			this->abonati[i] = s.abonati[i];
	}
	~Sedinta()
	{
		delete[] this->abonati;
	}
	Sedinta& operator=(const Sedinta& s)
	{
		this->durata = s.durata;
		this->persoaneSedinta = s.persoaneSedinta;
		if (s.nrAbonati > 0)
			this->nrAbonati = s.nrAbonati;
		delete[] this->abonati;
		this->abonati = new float[s.nrAbonati];
		for (int i = 0; i < s.nrAbonati; i++)
			this->abonati[i] = s.abonati[i];
	}
	friend ostream& operator<<(ostream& out, Sedinta s)
	{
		out << s.pret << ", " << s.durata << ", " << s.persoaneSedinta << ", " << s.nrAbonati << ", ";
		for (int i = 0; i < s.nrAbonati; i++)
		{
			out << s.abonati[i] << ", ";
		}
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Sedinta& s)
	{
		cout << "\nIntroduceti durata sedintei: ";
		in >> s.durata;
		cout << "\nIntroduceti numarul de persoane care participa la sedinta: ";
		in >> s.persoaneSedinta;
		cout << "\nIntroduceti numarul de abonati care participa la sedinta: ";
		in >> s.nrAbonati;
		cout << "\nIntroduceti valoarea abonamentului pentru fiecare abonat: ";
		for (int i = 0; i < s.nrAbonati; i++)
		{
			cout << "Abonamentul "<<i+1<<": ";
			in >> s.abonati[i];
		}
		cout << endl;
		return in;
	}
	int calculNeabonati()
	{
		return persoaneSedinta - nrAbonati;
	}
	void calculCastigSedinta()
	{
		cout << "\nIncasarile realizate sunt in valoare de " << (persoaneSedinta - nrAbonati) * pret << " de lei.";
	}
	bool operator==(Sedinta s)
	{
		int sumaAbonati1 = 0;
		int sumaAbonati2 = 0;
		for (int i = 0; i < this->nrAbonati; i++)
			sumaAbonati1 += this->abonati[i];
		for (int i = 0; i < s.nrAbonati; i++)
			sumaAbonati1 += s.abonati[i];
		if (this->durata == s.durata && this->pret == s.pret && this->persoaneSedinta == s.persoaneSedinta
			&& this->nrAbonati == nrAbonati && sumaAbonati1 == sumaAbonati2)
			return true;
		else
			return false;
	}
	bool operator>(Sedinta s)
	{
		if (this->durata > s.durata)
			return true;
		else
			return false;
	}
	bool operator!()
	{
		bool ok;
		if (this->durata > 60)
			ok = false;
		else
			ok = true;
		return ok;
	}
	//salvarea in fisier binar
	void salveaza_in_fisier(ofstream& out)
	{
		out.write((char*)&durata, sizeof(int));
		out.write((char*)&persoaneSedinta, sizeof(int));
		out.write((char*)&nrAbonati, sizeof(float));
		for (int i = 0; i < this->nrAbonati; i++)
			out.write((char*)&abonati[i], sizeof(float));
	}

	void raport()
	{
		cout << endl << "Sedinta selectata are o durata de " << this->durata << " de minute, un numar de " << this->persoaneSedinta << " de participanti, dintre care "
			<< this->nrAbonati << " au abonamente. Valoarea abonamentelor este: ";
		for (int i = 0; i < this->nrAbonati; i++)
			cout << abonati[i] << " ";
		cout << endl;
	}
};

class Meniu
{
public:
	static void afisareMeniuPrincipal() {
		cout << endl;
		cout << "1)Afiseaza ultimul bazin inregistrat" << endl;
		cout << "2)Calculeaza capacitatea vestiarului" << endl;
		cout << "3)Verifica la ce competitii poate concura clientul." << endl;
		cout << "0)Iesire" << endl;
		cout << "Alege optiunea:";
	}

};

//Faza 3
class ClubSportiv: public Sala {
private:
	string nume;
	Instructor instructor;
	Client client;
	Bazin** vectorBazine=nullptr;
	int nrBazine=0;
public:
	string getNume()
	{
		return this->nume;
	}
	void setNume(string nume)
	{
		this->nume = nume;
	}
	Bazin** getvectorBazine()
	{
		return this->vectorBazine;
	}
	ClubSportiv()
	{
		this->nume = "";
	}
	ClubSportiv(string nume, Instructor i, Client c, int nrBazine, Bazin** vectorBazine)
	{
		this->nume = nume;
		this->instructor = i;
		this->client = c;
		this->nrBazine = nrBazine;
		this->vectorBazine = new Bazin * [this->nrBazine];
		for (int i = 0; i < this->nrBazine; i++)
		{
			this->vectorBazine[i] = vectorBazine[i];
		}
	}
	ClubSportiv(const ClubSportiv& c)
	{
		this->nume = c.nume;
		this->instructor = c.instructor;
		this->client = c.client;
		this->nrBazine = c.nrBazine;
		this->vectorBazine = new Bazin * [this->nrBazine];
		for (int i = 0; i < this->nrBazine; i++)
		{
			this->vectorBazine[i] = c.vectorBazine[i];
		}
	}
	~ClubSportiv()
	{
		if (this->vectorBazine)
			delete[] this->vectorBazine;
	}
	ClubSportiv& operator=(const ClubSportiv& c)
	{
		if (this->vectorBazine)
			delete[] this->vectorBazine;
		this->nume = c.nume;
		this->instructor = c.instructor;
		this->client = c.client;
		this->nrBazine = c.nrBazine;
		this->vectorBazine = new Bazin * [this->nrBazine];
		for (int i = 0; i < this->nrBazine; i++)
		{
			this->vectorBazine[i] = c.vectorBazine[i];
		}
		return *this;
	}
	
	friend ostream& operator<<(ostream& out, ClubSportiv& c)
	{
		out << endl;
		out << c.nume << endl;
		out << c.instructor<<endl;
		out << c.client<<endl;
		out << c.nrBazine<<endl;
		for (int i = 0; i < c.nrBazine; i++)
		{
			out << *c.vectorBazine[i] << endl;
		}
		return out;
	}
	void raport()
	{
		cout << endl << "Clubul sportiv " << this->nume << " are instructorul: " <<endl<< this->instructor << " si clientul: "<<this->client
			<< " si un numar de " << this->nrBazine<< " bazine disponibile. Lista acestora este: "<<endl;
		for (int i = 0; i < this->nrBazine; i++)
			cout << *this->vectorBazine[i] << endl;
		cout << endl;
	}
};

int main()
{
	Bazin b1;
	cout << b1.getDenumire() << endl;
	b1.setCapacitate(400);
	cout << b1.getCapacitate() << endl;
	Bazin b2("StayFit Pool", 25);
	cout << b2.getLungime() << endl;
	Bazin b3("InterGroup Bazin", 40, 50);
	cout << b3.getDenumire() << endl;
	b3.setDenumire("Bazin Olimpic Centru");
	cout << b3.getDenumire() << endl;
	b1 = b3;
	//cin >> b2;
	cout << b2;
	Bazin b4 = b3;
	b2.tipBazin();
	b1.tipActivitate();
	if (b2 == b4)
		cout << "\nBazinele au aceleasi dimensiuni.";
	else
		cout << "\nBazinele nu au aceleasi dimensiuni";
	cout << endl<< b4;
	cout << endl<< b4 - 10;

	ifstream bazine("bazine.txt");
	char buffer[2000];
	if (bazine.is_open()) {
		string linieFisier;
		while (!bazine.eof()) {
			bazine >> linieFisier;
			cout << linieFisier<<" ";
			if (linieFisier == "-----------------------------")
				cout << endl;
		}
		bazine.close();
		cout << endl;
	}

	ofstream bazinebin("bazine.bin", ios::binary);
	if (bazinebin.is_open()) {
		b1.salveaza_in_fisier(bazinebin);
		b2.salveaza_in_fisier(bazinebin);
		b3.salveaza_in_fisier(bazinebin);
		b4.salveaza_in_fisier(bazinebin);
		bazinebin.close();
	}

	cout << "\n" << "\n";

	Sala s1("CityLink");
	int vestiare[3] = { 20,20,60 };
	Sala s2("StayFit Gym", 3, vestiare);
	for (int i = 0; i < s2.getNrVestiare(); i++)
		cout << s2.getVestiare()[i] << ", ";
	int vestiare2[5] = { 15,20,15,40,50 };
	s1.setVestiare(5, vestiare2);
	cout << "\n" << "\n";
	cout << s1;
	Sala s3 = s1;
	//cin >> s3;
	//cout << s3;
	s3.calculCapacitate();
	s2.facilitati();
	s3.facilitati();
	cout <<endl<< s1+20;
	if (s1 == s2)
		cout << "\nSalile au aceeasi capacitate.";
	else
		cout << "\nSalile nu au aceeasi capacitate.";

	cout << endl;
	ifstream sali("sali.txt");
	if (sali.is_open()) {
		string linieFisier;
		while (!sali.eof()) {
			sali >> linieFisier;
			cout << linieFisier << " ";
			if (linieFisier == "-----------------------------")
				cout << endl;
		}
		sali.close();
		cout << endl;
	}

	ofstream salibin("sali.bin", ios::binary);
	if (salibin.is_open()) {
		s1.salveaza_in_fisier(salibin);
		s2.salveaza_in_fisier(salibin);
		s3.salveaza_in_fisier(salibin);
		salibin.close();
	}

	cout << "\n" << "\n";

	Instructor in1(1, 3, "Marcel");
	int persoane[4] = { 15,10,8,12 };
	Instructor in2(2, 5, "Popescu", 4, persoane);
	int persoane2[7] = { 20,23,18,16,17,21,19 };
	in1.setPersoane(7, persoane2);
	cout << in1;
	cout << in2.calculGrad();
	in1.medieGrupa();
	Instructor in3 = in2;
	//cin >> in3;
	//cout << in3;
	if (in2 == in3)
		cout << "\nInstructorii sunt la fel de pregatiti";
	else
		cout << "\nInstructorii au un nivel diferit de pregatire";
	cout << endl << "\nVerificare operator[]: " <<in1[4];
	int x = (int)in3;
	cout << endl << x;

	cout << endl;
	ifstream instructori("instructori.txt");
	if (instructori.is_open()) {
		string linieFisier;
		while (!instructori.eof()) {
			instructori >> linieFisier;
			cout << linieFisier << " ";
			if (linieFisier == "-----------------------------")
				cout << endl;
		}
		instructori.close();
		cout << endl;
	}
	ofstream instructoribin("instructori.bin", ios::binary);
	if (instructoribin.is_open()) {
		in1.salveaza_in_fisier(instructoribin);
		in2.salveaza_in_fisier(instructoribin);
		in3.salveaza_in_fisier(instructoribin);
		instructoribin.close();
	}

	in3.raport();

	cout << "\n" << "\n";

	Client c1(13, 150);
	cout << c1;
	Client c2("Ionut Stanescu", 15, 140);
	cout << c2;
	Client c3 = c2;
	//cin >> c3;
	//cout << c3;
	c1.competitie();
	c2.incadrare("intermediar");
	if (c2 == c3)
		cout << "\nClientii au aceeasi varsta si aceeasi inaltime.";
	else
		cout << "\nClientii nu au aceeasi varsta si nici aceeasi inaltime.";
	cout <<endl<< ++c2;
	cout <<endl<< c2++;

	cout << endl;
	ifstream clienti("clienti.txt");
	if (clienti.is_open()) {
		string linieFisier;
		while (!clienti.eof()) {
			clienti >> linieFisier;
			cout << linieFisier << " ";
			if (linieFisier == "-----------------------------")
				cout << endl;
		}
		clienti.close();
		cout << endl;
	}
	ofstream clientibin("clienti.bin", ios::binary);
	if (clientibin.is_open()) {
		c1.salveaza_in_fisier(clientibin);
		c2.salveaza_in_fisier(clientibin);
		c3.salveaza_in_fisier(clientibin);
		clientibin.close();
	}

	c2.raport();

	cout << "\n" << "\n";

	Sedinta sd1(10, 60, 25);
	float abonati[4] = { 30,60,100,360 };
	Sedinta sd2(15, 120, 10, 4, abonati);
	cout << sd2;
	float abonati2[6] = { 30, 30, 30, 100, 100, 60 };
	sd1.setAbonati(6, abonati2);
	Sedinta sd3 = sd1;
	cout << sd3;
	sd3.calculCastigSedinta();
	cout<<"\nLa sedinta participa "<< sd2.calculNeabonati()<<" persoane neabonate.";
	Sedinta sd4(20, 30, 5);
	if (!sd4)
		cout << "\nSedinta are o durata prea mica.";
	else
		cout << "\nSedinta se poate desfasura.";

	cout << endl;
	ifstream sedinte("sedinte.txt");
	if (sedinte.is_open()) {
		string linieFisier;
		while (!sedinte.eof()) {
			sedinte >> linieFisier;
			cout << linieFisier << " ";
			if (linieFisier == "-----------------------------")
				cout << endl;
		}
		sedinte.close();
		cout << endl;
	}
	ofstream sedintebin("sedinte.bin", ios::binary);
	if (sedintebin.is_open()) {
		sd1.salveaza_in_fisier(sedintebin);
		sd2.salveaza_in_fisier(sedintebin);
		sd3.salveaza_in_fisier(sedintebin);
		sd4.salveaza_in_fisier(sedintebin);
		sedintebin.close();
	}

	sd2.raport();

	ClubSportiv cs1;
	cs1.setNume("CSM Unirea");
	cout << endl << cs1.getNume();
	Bazin** vb = new Bazin * [3];
	vb[0] = &b1;
	vb[1] = &b2;
	vb[2] = &b3;
	ClubSportiv cs2("SwimBud", in2, c3, 3, vb);
	cout << endl << cs2;
	cs2.raport();

	cout <<endl << "STL - Vector"<<endl;
	vector<Client*> vectorClienti;
	vectorClienti.push_back(&c2);
	vectorClienti.push_back(&c3);

	vector<Client*>::iterator it;
	for (it = vectorClienti.begin(); it != vectorClienti.end(); it++)
	{
		cout << **it << endl;
	}

	cout << endl << "STL - Lista" << endl;
	list<float> lista;
	lista.push_back(70.44);
	lista.push_front(25.21);
	lista.push_back(11.78);
	lista.push_front(30.33);

	cout << "\nAfisare lista: \n";
	list<float>::iterator it2;
	for (it2 = lista.begin(); it2 != lista.end(); it2++)
	{
		cout << *it2 << " ";
	}

	cout << "\nAfisare lista sortata: \n";
	lista.sort();
	for (it2 = lista.begin(); it2 != lista.end(); it2++) {
		cout << *it2 << "\t";
	}

	cout << endl << "STL - Set" << endl;
	set<string> setNume;
	setNume.insert("Ana");
	setNume.insert("Maria");
	setNume.insert("Dragos");
	setNume.insert("Vlad");
	cout << "\nAfisare persoane din set: \n";
	set<string>::iterator it3;
	for (it3 = setNume.begin(); it3 != setNume.end(); it3++) {
		cout << *it3 << " ";
	}
	cout << endl;
	it3 = setNume.find("Dragos");
	if (it3 != setNume.end()) {
		cout << "S-a gasit persoana.\n";
	}
	else {
		cout << "Nu s-a gasit persoana.\n";
	}

	cout << endl << "STL - Map" << endl;
	map<int, Bazin> constructie;
	constructie.insert(make_pair(2020, b1));
	constructie.insert(make_pair(2021, b2));
	constructie.insert(make_pair(2019, b4));

	map<int, Bazin>::iterator itMap;
	for (itMap = constructie.begin(); itMap != constructie.end(); itMap++) {
		cout << "In anul " << itMap->first << " a fost construit " << itMap->second.getDenumire() << endl;
	}


	bool startMeniuActivat = true;
	while (startMeniuActivat) {
		int optiune;
		Meniu::afisareMeniuPrincipal();
		cin >> optiune;
		switch (optiune) {
		case 0: {
			startMeniuActivat = false;
			system("cls");
			cout << "Meniul a fost inchis." << endl;
			break;
		}
		case 1: {
			system("cls");
			cout << b4;

			break;
		}
		case 2: {
			system("cls");

			s1.calculCapacitate();

			break;
		}
		case 3: {
			c2.competitie();
			break;
		}

		default: {
			system("cls");
			cout << "Optiune invalida" << endl << endl;
			break;
		}
		}
	}


	return 0;
}
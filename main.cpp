#include <iostream>
#include <fstream>
#include <vector>
#include <list>

typedef std::pair<int, int> pereche;
typedef std::vector<std::list<pereche>> ht;

class HashTable
{
private:
	ht table;
public:

	HashTable(int n)
	{
		table.resize(n);
	}

	int hashFunction(int key, int n)
	{
		return key % n;
	}

	void insertInTable(int key, int value, int n)
	{
		int index = hashFunction(key, n);
		pereche p = std::make_pair(key, value);
		table[index].push_back(p);
	}

	void cautareInTable(int key, int n)
	{
		int index = hashFunction(key, n);
		for (pereche p : table[index])
		{
			if (p.first == key)
				std::cout << "Elementul cu cheia " << key << " este " << p.second << "\n";
		}
	}

	void afisTable()
	{
		std::cout << "Hash Table:\n";
		for (int i = 0; i < table.size(); i++)
		{
			std::cout << "T[" << i << "] : ";

			for (pereche p : table[i])
				std::cout << " ( " << p.first << ", " << p.second << " ) ; ";

			std::cout << std::endl;
		}
	}

};

int main()
{
	std::ifstream fis("date.in");
	if (!fis)
	{
		std::cerr << "Eroare la deschiderea fisierului";
		return -1;
	}

	int n, key, value;
	fis >> n;

	HashTable T(n);

	for (int i = 0; i < n; i++)
	{
		fis >> key >> value;
		T.insertInTable(key, value, n);
	}

	std::cout << "  MENIU \n";
	std::cout << "0. EXIT\n";
	std::cout << "1. Cautare element.\n";
	std::cout << "2. Adaugare element.\n";
	std::cout << "3. Afisare tabel.\n";
	std::cout << "4. Afisare meniu.\n";
	std::cout << "Optiunea dumneavoastra este: ";


	int choice;

	std::cin >> choice;

	while (choice)
	{
		switch (choice)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			std::cout << "\nIntrodu cheia elementului pe care doresti sa il cauti: ";
			int cheie;
			std::cin >> cheie;
			T.cautareInTable(cheie, n);
			std::cout << "\nOptiunea dumneavoastra este: ";
			std::cin >> choice;
			break;
		}
		case 2:
		{
			std::cout << "\nIntrodu cheia, respectiv valoarea noului element pe care doresti sa il adaugi: ";
			int cheie, valoare;
			std::cin >> cheie >> valoare;
			T.insertInTable(cheie, valoare, n);
			std::cout << "\nElementul a fost adaugat cu succes!";
			std::cout << "\nOptiunea dumneavoastra este: ";
			std::cin >> choice;
			break;
		}
		case 3:
		{
			T.afisTable();
			std::cout << "\nOptiunea dumneavoastra este: ";
			std::cin >> choice;
			break;
		}
		case 4:
		{
			std::cout << "  MENIU \n";
			std::cout << "0. EXIT\n";
			std::cout << "1. Cautare element.\n";
			std::cout << "2. Adaugare element.\n";
			std::cout << "3. Afisare tabel.\n";
			std::cout << "4. Afisare meniu.\n";
			std::cout << "Optiunea dumneavoastra este: ";
			std::cin >> choice;
			break;
		}
		default:
		{
			std::cout << "\nOptiunea aleasa nu este valabila. Incercati din nou.";
			std::cout << "\nOptiunea dumneavoastra este: ";
			std::cin >> choice;
			break;
		}
		}
	}

	return 0;
}
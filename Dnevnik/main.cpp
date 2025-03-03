#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void unos_ucenika(){
	system("CLS");
	
	ofstream podaci;
	podaci.open("PODACI.txt");	
	
	int broj_ucenika;
	string redni_broj_ucenika;
	string ime;
	string prezime;
	
	cout << "Koliko zelite ucenika da uneste u eDenvnik?"<< endl;
	cin >> broj_ucenika;
	
	system("CLS");
	
	for(int i = 0; i < broj_ucenika; i++){	
		cout << "Unesite redni broj ucenika/ce: ";
	    cin >> redni_broj_ucenika;

		cout <<"Unesite ime ucenika/ce: ";
		cin >> ime;		
		if(tolower(ime[0])){
			ime[0] = toupper(ime[0]);
		}else{
			ime;
		}
		cout <<"Unesite prezime ucenika/ce: ";
		cin >> prezime;
		if(tolower(prezime[0])){
			prezime[0] = toupper(prezime[0]);
		}else{
			prezime;
		}
		system("CLS");
		
		podaci <<" "<<redni_broj_ucenika <<" "<< ime << " " << prezime << endl; 	
		
		ofstream konj;
		string fajl = redni_broj_ucenika + " " + ime + " " + prezime + ".txt";
		konj.open(fajl.c_str());
		konj.close();
	}		
	podaci.close();	
}
void unos_ocjene(){
	system("CLS");
	
	int broj_predmeta;
	float zbir = 0.0;
	float prosjecna_ocjena;
	string ocjena;
	string ime;
	string prezime;
	string citanje;
	string podaci;
	string naziv_predmeta;
	string redni_broj_ucenika;
	
	cout << "Redni broj ucenika/ce kome upisujete ocejne: ";
	cin >> redni_broj_ucenika;
	
	cout << "Ime ucenika/ce kojoj upisujete ocjene: " ;
	cin >> ime;
	if(tolower(ime[0])){
			ime[0] = toupper(ime[0]);
		}else{
			ime;
		}	
	cout << "Prezime ucenika/ce kojoj upisuete ocjene: ";
	cin >> prezime;
		if(tolower(prezime[0])){
			prezime[0] = toupper(prezime[0]);
		}else{
			prezime;
		}
	cout << "Koliko zelite predmeta da unesete: ";
	cin >> broj_predmeta;
	
	ofstream file;
	citanje = redni_broj_ucenika+ " " + ime + " " + prezime + ".txt";
	file.open(citanje.c_str());
	string ocjene;
	system("CLS");
	
	if (file.is_open()){
	 for(int i = 0; i < broj_predmeta; i++){
	 	
	 	cout << "Predmet: ";
		cin >> naziv_predmeta;
		if(tolower(naziv_predmeta[0])){
			naziv_predmeta[0] = toupper(naziv_predmeta[0]);
		}else{
			naziv_predmeta;
	 }
	 
		cout << "Ocjena: " ;
		cin >> ocjena;
		system("CLS");		
		
	    ocjene = naziv_predmeta + ": " + ocjena;
		file << ocjene << endl;   
			
	 }
	 bool pronadjena_ocjena = false;
	 for(int j = 0; j < ocjene.length(); ++j){
			if(isdigit(ocjene[j])){
				cin.ignore();
				file << ocjene[j] << endl;
				pronadjena_ocjena = true;
			}
		}		
	 file.close(); 
	}else{
		cout << "Nismo pronasli ucenika";
	}
}
void pronalazak(){
	system("CLS");
	float zbir = 0.0;
	float prosjecna_ocjena;
	string podaci;
	string ime;
    string prezime;
	string file;
	string predmet;
	string redni_broj_ucenika;
	
	cout << "Ucenici dostupni: " <<endl;
	
	ifstream fajl;
	fajl.open("PODACI.txt");
	if(fajl.is_open()){
		while(getline(fajl, podaci)){
			cout << podaci << endl;
		}
		fajl.close();
	}else{
		cout << "Nemozemo pronaci ucenika.";
	}
	cout << "Unesite redni broj ucenika/ce koje trazite: ";
	cin >> redni_broj_ucenika;
	
	cout << "Unesite ime ucenika/ce koje trazite: " ;
	cin >> ime;		
	if(tolower(ime[0])){	
		ime[0] = toupper(ime[0]);
		}else {
			ime;
		}
	cout <<"Unesite prezime ucenika/ce: ";
	cin >> prezime;
	if(tolower(prezime[0])){
			prezime[0] = toupper(prezime[0]);
		}else{
			prezime;
		}
	system("CLS");
	
	ifstream citatelj;
	file = redni_broj_ucenika + " " + ime + " " + prezime + ".txt";
	citatelj.open(file.c_str());
	
	if(citatelj.is_open()){
		cout << "Ocjene ucenika pod rednim brojem " << redni_broj_ucenika << " su: " << endl;
			while(getline(citatelj, predmet)){
				cout << predmet << endl;
		   }
		   
		citatelj.close();
	}else{
		cout << "Nemozemo pronaci ucenika.";
	}
}
void ispisivanje_ucenika(){
}
int main() {
	int a;
	
	cout << "---------------------eDnevnik---------------------" << endl;
	cout << "__________________________________________________" << endl;
	cout << "| 1.UNESITE UCENIKA.............................. |" << endl;
	cout << "| 2.UNESITE OCJENE............................... |" << endl;
	cout << "| 3.PRONADJI ODREDJENOG UCENIKA I NJEGOVE OCJENE  |" << endl;
	cout << "| 4.ISPI�I ODREDJENOG UCENIKA                     |" <<endl;
	cout << "|_________________________________________________|" << endl;
	
	cin >> a;
	if (a > 3 || a < 1){
		cout << "Nepostoje takve opcije." << endl;
	}else{
		switch(a){
		case 1:
			unos_ucenika();
			main();
			break;
		case 2:
			unos_ocjene();
			main();
			break;
		case 3:
			pronalazak();
			main;
			break;
		case 4:
			ispisivanje_ucenika();
			main();
			break;
	}
	}
	return 0;
}

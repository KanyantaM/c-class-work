#include <iostream>
#include <fstream>

using namespace std;

//Setting the constants that will be able to stire the strings as well as other long daat types
const int words = 100, id = 51;
string bloodbank[] = {"A+ ", "A- ", "B+ ", "B- ", "AB+", "AB-"}; // WHY

struct BloodDonor { // LIKE IN CLASSES KAH
	char fname[words];// WHY
	char gender;
	char datebirth[words];
	int bloodType;
	long long int phoneNumber;
	char email[words];
	char homeAddress[words];
};

void donorRegistration() {
	char again;
	ofstream donorList;
	donorList.open("donor.dat", ios::binary  | ios::app  );// WHY
	do {
		BloodDonor person;
		cout << "Enter donor full name\n";
		cin >> person.fname;

		cout << "Enter gender (m/f)\n";
		cin >> person.gender;

		cout << "Enter date of birth in the following format dd/mm/yyyy\n";
		cin >> person.datebirth;

		cout << "Enter blood type\n[1]A+\n[2]A-\n[3]B+\n[4]B-\n[5]AB+\n[6]AB-";
		int select;
		cin >> select;
		person.bloodType  = select -1;

		cout << "Enter phonenumber\n";
		cin >> person.phoneNumber;

		cout << "Enter email\n";
		cin >> person.email;

		cout << "Enter home adsress\n";
		cin >> person.homeAddress;

		donorList.write(reinterpret_cast<char*>(&person), sizeof(person)); // WHY
		cout << "contacts succesfully added\nDo you want to enter more data? (y/n)\n"; // HEH ?
		cin >> again;
	} while (again == 'y' || again == 'Y');
	donorList.close();
}

void searchDonor() {
	BloodDonor person;
	ifstream file3;
	int selection1, selection2;

	cout << "Search by\n[1] Blood Type\n[2] Address\n";
	cin >> selection1;
	switch (selection1){
	case 1:
		cout << "Enter blood type\n[1]A+\n[2]A-\n[3]B+\n[4]B-\n[5]AB+\n[6]AB-" << endl;
		cin >> selection2;
		file3.open("donor.dat", ios::binary);
		while (!file3.eof()) {
			if (file3.read(reinterpret_cast<char*>(&person), sizeof(person))) {
				if (selection2 == person.bloodType + 1) {
					cout << "Name:          " << person.fname <<endl;
					cout << "Gender:        " << person.gender << endl;
					cout << "Date of Birth: " << person.datebirth << endl;
					cout << "Blood type:    " << bloodbank[person.bloodType] << endl;
					cout << "Phone Number:  " << person.phoneNumber << endl;
					cout << "Address:       " << person.homeAddress << endl;
					cout << "email:         " << person.email << endl;
				}
			}
		}
		file3.close();
		break;
	case 2:
		string address1;
		cout << "Enter your adress\n" << endl;
		cin >> address1;
		file3.open("donor.dat", ios::binary);
		while (!file3.eof()) {
			if (file3.read(reinterpret_cast<char*>(&person), sizeof(person))) {
				if (address1 == person.homeAddress) {
					cout << "Name: " << person.fname << endl;
					cout << "Gender: " << person.gender << endl;
					cout << "Date of Birth: " << person.datebirth << endl;
					cout << "Blood type: " << bloodbank[person.bloodType] << endl;
					cout << "Phone Number: " << person.phoneNumber << endl;
					cout << "Address" << person.homeAddress << endl;
					cout << "email: " << person.email << endl;
				}
			}
		}
		file3.close();
		break;
	}
	}

void aboutUs() {
	cout << "Blood Bank Management System has functionalities of enlisting blood givers and through which individuals requiring blood can look and contact them after donors are registered.The blood request and recipient blood need to be approved or rejected by the system.The blood stock and blood donations are not limited to the users\n";
}

void contactUs() {
	BloodDonor person;
	cout << "Contact the managment on +260 76 195 1500\n";
	cout << "=============================\n\t\t\t\t\t\t\tBlood donor conatacts\n=============================\n";
	ifstream donors4;
	donors4.open("donor.dat", ios::binary);
	while(!donors4.eof()){
		donors4.read(reinterpret_cast<char*>(&person), sizeof(person));
		cout << "Name: " << person.fname << endl;
		cout << "Phone Number: " << person.phoneNumber << endl;
		cout << "Address: " << person.homeAddress << endl;
		cout << "email: " << person.email << endl;
	}
}

void homepage() {
	while (1) {
		int choice;
		system("cls");
		system("color 13");
		cout << "\nCONTACT MANAGEMENT SYSTEM\n";
		cout << "Main menu";
		cout << "\n=============================\n";
		cout << "[1] Donor registration\n";
		cout << "[2] List all Contacts\n";
		cout << "[3] Search for Donor(s)\n";
		cout << "[4] About us\n";
		cout << "[0] exit\n";
		cout << "\n=============================\n";
		cout << "Enter your choice\n";
		cin >> choice;

		switch (choice) {
		case 1:
			system("cls");
			donorRegistration();
			break;

		case 2:
			system("cls");
			contactUs();
			break;
		case 3:
			system("cls");
			searchDonor();
			break;

		case 4:
			system("cls");
			aboutUs();
			break;

		case 0:
			system("cls");
			cout << "\n\n\n\t\t\tThank you yor using BBMS(Blood Bank Management System).\n";
			exit(0);
			break;

		default:
			continue;
		}

		int opt;
		cout << "\n\n...::Enter the Choice\n [1] Main Menu \t\t[0]exit\n";
		cin >> opt;

		switch (opt) {
		case 0:
			system("cls");
			cout << "\n\n\n\t\t\tThank you yor using BBMS(Blood Bank Management System).\n";
			exit(0);
			break;
		default:
			continue;
		}
	}
}

void login() {
	system("cls"); //clears screen
	system("color 1D"); //changing colour # light blue background with white font
	int count;
	string userID, password, id, pass;
	cout << "Please enter your user name and password\n";
	cout << "Enyter your username: ";
	cin >> userID;
	cout << endl;
	cout << "Enter password: ";
	cin >> password;

	ifstream admin;
	admin.open("admin.txt");
	while (admin >> id) {
		if (userID == id) {
			admin >> id;
			if (password == id) {
				admin.close();
				homepage();
			}
			else {
				cout << "Incoreect login details\n";
				break;
			}
		}
	}
}

void registration() {
	system("cls"); //clears screen
	system("color 1D"); //changing colour # light blue background with white font

	ofstream admin;
	string user, password;
	admin.open("admin.txt", ios::app);
	cout << "Enter Name of new admin: ";
	cin >> user;
	admin << user << endl;

	cout << "\nEnter password for new admin: ";
	cin >> password;
	admin << password << endl;

	admin.close();
	cout << "Registration successful\n";
}

void forgotPassword(){
	system("cls"); //clears screen
	system("color 3D"); //changing colour # light blue background with white 

	int count;
	string userID, password, id;
	cout << "Please enter your user name and password\n";
	cout << "Enyter your username: ";
	cin >> userID;
	cout << endl;

	fstream admin;
	admin.open("admin.txt", ios::in | ios::out);
	while (admin >> id) {
		if (userID == id) {
			cout << "Enter new password: ";
			cin >> password;
			admin >> password;
			admin.close();
			break;
		}
	}
}

int main() {
	system("cls"); //clears screen
	system("color 3F"); //changing colour # light blue background with white font

	cout << "\n\n\n\n\n\n\t WELCOME TO THE BLOOD BANK MANAGMENT SYSTEM\n";
	int c;

	do {
		cout << "_____________________________________________________________________________________________\n";
		cout << "                                Welcome to the blood bank management system.\n";
		cout << "_____________________________________________________________________________________________\n\n\n";
		cout << "Press\n[1] to log in\n[2]Register\n[3]Forgot Password\n";
		cin >> c;

		switch (c) {
		case 1:
			login();
			break;
		case 2:
			registration();
			break;
		case 3:
			forgotPassword();
			break;
		}
	} while (c != 0);

	return 0;
}
# include <cctype>
# include <cmath>
# include <fstream>
# include <iostream>
# include <iomanip>
# include <string>
# include <windows.h>

using namespace std;

//Siang Ruo Ying (Patron Module, Lbr Module, borrowbook Module)
void mainLogo();
void patronLogo();
void lbrLogo();
void patronREG();
void patronLogin();
void patronPage();
void lbrLogin();
void lbrPage();
bool testID(string);
bool testPW(string);
struct bookList;
void borrowbook();

//Tan Pei Shi (appendBook Module, deleteBook Module, showBorrow Module)
void maintenance();
void appendBook();
void deleteBook();
void readtoArray(string bookList1[50][8], int&);
struct bookArray;
bool validTitle(string);
bool validAuthor(string);
bool validRating(double);
bool validBookno(int);
bool validPrice(double);
bool validBookid(int);
int intValid(string, string);
double douValid(string, string);
double stringTodou(string);
int stringToint(string);
string intTostring(int);
string douTostring(double);
void showBorrow();

//Teh Yu Qian (sorting Module, displayBook Module, returnbook Module)
void inventory();
void sorting(int);
void displayBook();
void returnbook();
HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);

int main() {

	system("cls");
	mainLogo();
	cout << "		  'Nothing is pleasanter than exploring a "
		<< "library!' " << endl << endl;
	string who;
	cout << "------------------------------------------" << endl;
	cout << "||\t1. Patron\t\t\t||" << endl;
	cout << "||\t2. Librarian\t\t\t||" << endl;
	cout << "||\tQ. leave the paradise :(\t||" << endl;
	cout << "------------------------------------------" << endl
		<< endl;
	cout << "Welcome to ESL Library! :)" << endl;
	cout << "Who are you ? >> ";

	SetConsoleTextAttribute(col, 7);
	getline(cin, who);

	while (who != "1" && who != "2" && toupper(who[0]) != 'Q' ||
		who.length() != 1) {
		SetConsoleTextAttribute(col, 4);
		cout << "Ooooppsss, invalid input :(\nPlease key in a "
			<< "valid input." << endl << endl;
		SetConsoleTextAttribute(col, 7);
		cout << "What do you want to do? >> ";
		getline(cin, who);
	}

	if (who == "1") {
		system("cls");
		patronLogo();
		cout << "--------------------------------------------------"
			<< endl;
		cout << "||\t1. Login (I am existing patron!)\t||" << endl;
		cout << "||\t2. Register (I am a new patron!)\t||" << endl;
		cout << "||\tQ. Back to previous\t\t\t||" << endl;
		cout << "--------------------------------------------------"
			<< endl << endl;

		string patron_choice;
		cout << "Hello, dear patron!" << endl;
		cout << "What do you want to do? >> ";
		getline(cin, patron_choice);

		while (patron_choice != "1" && patron_choice != "2" &&
			toupper(patron_choice[0]) != 'Q' ||
			patron_choice.length() != 1) {
			SetConsoleTextAttribute(col, 4);
			cout << "Invalid input! Please key in a valid input."
				<< endl << endl;

			SetConsoleTextAttribute(col, 7);
			cout << "What do you want to do? >> ";
			getline(cin, patron_choice);
		}

		if (patron_choice == "1") {
			patronLogin();
			main();
		}
		else if (patron_choice == "2") {
			patronREG();
			patronPage();
			main();
		}
		else if (toupper(patron_choice[0]) == 'Q') {
			main();
		}

	}

	else if (who == "2") {
		system("cls");
		lbrLogo();
		cout << "--------------------------------------------------"
			<< "------------------------" << endl;
		cout << "||\t1. Login (I am existing librarian!)\t\t\t\t||"
			<< endl;
		cout << "||\tQ. Back to main page\t\t\t\t\t\t||" << endl;
		cout << "-----------------------------------------------"
			<< "-------------------------- - " << endl << endl;

		string lbr_choice;
		cout << "Hello, dear librarian!" << endl;
		cout << "What do you want to do? >> ";
		getline(cin, lbr_choice);

		while (lbr_choice[0] != '1' && toupper(lbr_choice[0]) != 'Q'
			|| lbr_choice.length() != 1) {
			SetConsoleTextAttribute(col, 4);
			cout << "Invalid input! Please key in a valid input."
				<< endl << endl;
			SetConsoleTextAttribute(col, 7);
			cout << "What do you want to do? >> ";
			getline(cin, lbr_choice);
		}

		if (lbr_choice == "1") {
			lbrLogin();
			main();
		}

		else
			main();
	}

	else if (toupper(who[0]) == 'Q') {
		cout << endl << "Sad to know that you want to quit :("
			<< endl;
		cout << "Hope to see you next time!" << endl;
		system("Pause");
		return 0;
	}
}


//Patron Registration and Login, Librarian Login
void mainLogo() {
	SetConsoleTextAttribute(col, 14);
	cout << " /@@@@@@@  /@@@@@@@  /@@@         /@@@      /@@@@@@@  /@@@@@@@   /@@@@@@@      /@@@@     /@@@@@@@  /@@    /@@" << endl;
	cout << "| @@@___/ | @@@___/ | @@@        | @@@     |/__@@@_/ | @@@__/@@ | @@@__/@@    /@@  @@   | @@@__/@@ \\ @@ / @@" << endl;
	cout << "| @@@     | @@@     | @@@        | @@@       | @@@   | @@@   @@ | @@@   @@   | @@  @@   | @@@   @@  \\ @@|@@" << endl;
	cout << "| @@@@@@@ | @@@@@@@ | @@@        | @@@       | @@@   | @@@@@@@  | @@@@@@@   | @@@@@@@@  | @@@@@@@    \\ @@@" << endl;
	cout << "| @@@___/ |/____@@@ | @@@        | @@@       | @@@   | @@@__/@@ | @@@@@_/   | @@@_/@@@  | @@@@@_/    | @@@" << endl;
	cout << "| @@@           @@@ | @@@        | @@@       | @@@   | @@@   @@ | @@@ @@@  / @@@   /@@@ | @@@ @@@    | @@@" << endl;
	cout << "| @@@@@@@  /@@@@@@@ | @@@@@@@@   | @@@@@@@@ /@@@@@@@ | @@@@@@@  | @@@ |@@@ | @@@  | @@@ | @@@ |@@@   | @@@" << endl;
	cout << "|/______/ |/______/ |/_______/   |/_______/ |/_____/ |/______/  |/_/  |/_/ |/__/  |/__/ |/_/  |/_/   |/__/" << endl;
	cout << endl;
	SetConsoleTextAttribute(col, 7);
}

void patronLogo() {
	SetConsoleTextAttribute(col, 14);
	cout << "@@@@@@@@    @@@@   @@@@@@@@@@@ @@@@@@@@  @@@@@@@  @@@@@  @@   @@  @@@@@@@" << endl;
	cout << "@@    @@   @@  @@      @@      @@    @@  @@   @@  @@@@@  @@   @@  @@" << endl;
	cout << "@@    @@   @@  @@      @@      @@    @@  @@   @@  @@ @@  @@  @@   @@" << endl;
	cout << "@@@@@@@@  @@@@@@@@     @@      @@@@@@@@  @@   @@  @@  @@ @@       @@@@@@@" << endl;
	cout << "@@       @@      @@    @@      @@  @@    @@   @@  @@  @@ @@            @@" << endl;
	cout << "@@       @@      @@    @@      @@   @@   @@   @@  @@   @@@@            @@" << endl;
	cout << "@@      @@        @@   @@      @@    @@  @@@@@@@  @@   @@@@       @@@@@@@" << endl;
	cout << endl;
	SetConsoleTextAttribute(col, 7);
}

void lbrLogo() {
	SetConsoleTextAttribute(col, 14);
	cout << "@@        @@@@@@  @@@@@@@@  @@@@@@@       @@@@      @@@@@@@   @@@@@@      @@@@     @@@@@  @@   @@  @@@@@@@" << endl;
	cout << "@@          @@    @@    @@  @@    @@     @@  @@     @@    @@    @@       @@  @@    @@@@@  @@   @@  @@" << endl;
	cout << "@@          @@    @@    @@  @@    @@     @@  @@     @@    @@    @@       @@  @@    @@ @@  @@  @@   @@" << endl;
	cout << "@@          @@    @@@@@@    @@@@@@@@    @@@@@@@@    @@@@@@@@    @@      @@@@@@@@   @@  @@ @@       @@@@@@@" << endl;
	cout << "@@          @@    @@    @@  @@  @@     @@      @@   @@  @@      @@     @@      @@  @@  @@ @@            @@" << endl;
	cout << "@@          @@    @@    @@  @@   @@    @@      @@   @@   @@     @@     @@      @@  @@   @@@@            @@" << endl;
	cout << "@@@@@@@@  @@@@@@  @@@@@@@@  @@    @@  @@        @@  @@    @@  @@@@@@  @@        @@ @@   @@@@       @@@@@@@" << endl;
	cout << endl;
	SetConsoleTextAttribute(col, 7);
}

void patronREG() {
	system("cls");
	patronLogo();

	string patronName, ID, PW, patronGender, choice, patronage, line;
	int patronAge;
	bool testID(string ID);
	bool testPW(string PW);
	bool IDvalid = false, searchID = true;

	ofstream patronFile;
	patronFile.open("patronList.txt", ios::app);

	cout << "Hello, new patron!\nWelcome to ESL LIbrary! :)" << endl;
	cout << "Before you become a part of us, we need to gather some "
		<< "information from you." << endl << endl;
	cout << "======================================================="
		<< "==================== = " << endl << endl;

	do {
		cout << "Please key in your name >> ";
		getline(cin, patronName);

		if (patronName.length() == 0) {
			SetConsoleTextAttribute(col, 4);
			cout << "Opps...Invalid input. Please enter a valid "
				<< "name." << endl << endl;
			SetConsoleTextAttribute(col, 7);
		}
	} while (patronName.length() == 0);

	cout << endl;
	patronFile << "\n" << patronName << "\n";

	cout << endl;
	cout << "--------------------------------------------------------"
		<< "--" << endl;
	cout << "||\t\tRULES of ID\t\t\t\t||" << endl;
	cout << "|| 1. It must contain 9 characters.\t\t\t||" << endl;
	cout << "|| 2. The first 3 characters must be alphabets.\t\t||"
		<< endl;
	cout << "|| 3. The remaining 6 characters must be digits.\t||"
		<< endl;
	cout << "--------------------------------------------------------"
		<< "--" << endl;

	while (IDvalid == false || searchID == true) {
		cout << "Please key in your ID (eg: abc123456) >> ";
		getline(cin, ID);

		IDvalid = testID(ID); //Check the validation of ID

		if (!IDvalid) {
			SetConsoleTextAttribute(col, 4);
			cout << "Ooooppsss, invalid ID :(" << endl;
			cout << "Please follow the 'RULES of ID' as shown as "
				<< "above.";
			SetConsoleTextAttribute(col, 7);
			cout << endl << endl;
		}

		else {
			ifstream patronFile;
			patronFile.open("patronList.txt", ios::in);

			while (!patronFile.eof()) {
				//To determine either the patron ID already
				// exist in the system or not
				getline(patronFile, line);

				if (line == ID) {
					searchID = true;
					break;
				}

				else
					searchID = false;
			}

			if (searchID) {
				SetConsoleTextAttribute(col, 4);
				cout << "Ooooops, the patron ID entered already"
					<< " present in our system :(" << endl;
				cout << "Please enter another patron ID again."
					<< endl << endl;
				SetConsoleTextAttribute(col, 7);
				patronFile.close();
			}
		}
	}
	patronFile << ID << "\n";
	cout << "Your ID is as important as your life, don't forget it!"
		<< endl << endl;

	do {
		cout << "Please key in your password "
			<< "(minimum 6 characters) >> ";
		getline(cin, PW);

		if (!testPW(PW)) { //Check the validation of password (PW)
			SetConsoleTextAttribute(col, 4);
			cout << "Ooooppss, invalid password :(\nPlease key"
				<< " in a password with minimum 6 "
				<< "characters." << endl << endl;
			SetConsoleTextAttribute(col, 7);
		}
	} while (!testPW(PW)); //while the input PW is not validate

	patronFile << PW << "\n";
	cout << "Your password is as important as your life, don't forget"
		<< " it!" << endl << endl;

	do {
		cout << "Please key in your gender (M/F) >> ";
		getline(cin, patronGender);

		if (patronGender.length() != 1) {
			SetConsoleTextAttribute(col, 4);
			cout << "Oooppsss, invalid input :(\nPlease key in"
				<< " according to the format." << endl << endl;
			SetConsoleTextAttribute(col, 7);
		}
		else if (toupper(patronGender[0]) != 'M' &&
			toupper(patronGender[0]) != 'F') {
			SetConsoleTextAttribute(col, 4);
			cout << "Oooppsss, invalid input:(\nPlease key in "
				<< "according to the format." << endl << endl;
			SetConsoleTextAttribute(col, 7);
		}
	} while (patronGender.length() != 1 ||
		toupper(patronGender[0]) != 'M' &&
		toupper(patronGender[0]) != 'F');

	patronFile << (char)toupper(patronGender[0]) << "\n";

	do {
		cout << endl;
		string quest = "Please key in your age >> ";
		SetConsoleTextAttribute(col, 7);
		cout << quest;
		getline(cin, patronage);
		patronAge = intValid(patronage, quest);
		//Check if it is an integer and return integer value

		if (patronAge < 0) {
			SetConsoleTextAttribute(col, 4);
			cout << "Huhhh?? You haven't born yet!\nPlease key "
				<< "in a valid age." << endl;
			SetConsoleTextAttribute(col, 7);
		}

		else if (patronAge <= 3) {
			SetConsoleTextAttribute(col, 4);
			cout << "Huhhh?? You still a baby? "
				<< "Impossible!!\nPlease key in a valid age."
				<< endl;
			SetConsoleTextAttribute(col, 7);
		}

		else if (patronAge > 122) {
			SetConsoleTextAttribute(col, 4);
			cout << "Huhhh?? You are older than documented 122"
				<< " year old?? Impossible!!\nPlease key in "
				<< "correct a valid age." << endl;
			SetConsoleTextAttribute(col, 7);
		}
	} while (patronAge <= 3 || patronAge > 122);

	patronFile << patronAge;
	patronFile.close();

	ofstream outFile;
	outFile.open("LoginId.txt"); //Save the patron ID into file
	outFile << ID;               //for future use
	outFile.close();
}

void patronLogin() {
	system("cls");
	patronLogo();

	string patronID, patronPW, line;
	bool searchID = false, searchPW = false;

	do {
		ifstream patronFile;
		patronFile.open("patronList.txt", ios::in);

		cout << "Please key in your patron ID (eg: abc123456) >> ";
		getline(cin, patronID);

		while (!patronFile.eof()) {
			//To ignore the line without patron ID
			getline(patronFile, line);
			//To get the line with patron ID
			getline(patronFile, line);

			if (line == patronID) {
				searchID = true;
				break;
			}
			else
				searchID = false;

			//To ignore the line without patron ID
			getline(patronFile, line);
			getline(patronFile, line);
			getline(patronFile, line);
		}

		if (!searchID) {
			SetConsoleTextAttribute(col, 4);
			cout << "Ooooppsss, the patron ID entered is not "
				<< "found in our system : ("
				<< endl << "Please enter "
				<< "a correct patron ID." << endl << endl;
			SetConsoleTextAttribute(col, 7);
			patronFile.close();
		}
	} while (!searchID);

	string patronList[20][3];

	if (searchID) {
		do {
			ifstream patronFile;
			patronFile.open("patronList.txt", ios::in);

			cout << "Please key in your password >> ";
			getline(cin, patronPW);

			for (int i = 0; !patronFile.eof(); i++) {
			//To determine either the patronPW is correct 
			//or not

				getline(patronFile, line);
				getline(patronFile, patronList[i][0]);
				getline(patronFile, patronList[i][1]);

				if (patronList[i][0] == patronID) {
					if (patronList[i][1] == patronPW) {
						searchPW = true;
						break;
					}
					else
						searchPW = false;
				}

				//Does not contain patron PW, thus ignore
				getline(patronFile, line);
				getline(patronFile, line);
			}

			if (searchPW) {
				//Save the patron ID into file for future use
				ofstream outFile;
				outFile.open("LoginId.txt");
				outFile << patronID;
				outFile.close();

				patronPage(); //Move to patronPage
			}

			else {
				SetConsoleTextAttribute(col, 4);
				cout << "Oooppsss, the password is "
					<< "incorrect!\nPlease key in a correct"
					<< " password." << endl << endl;
				SetConsoleTextAttribute(col, 7);
			}
			patronFile.close();
		} while (!searchPW);
	}
}

void patronPage() {
	system("cls");
	patronLogo();
	cout << "\t\t'Welcome to The World of Patron!'\n\n";
	string choice;

	cout << "------------------------------------------------------"
		<< "---" << endl;
	cout << setw(50) << left << "||\t1. Check out books" << "|| "
		<< endl;
	cout << setw(50) << left << "||\t2. Return book" << "||" << endl;
	cout << setw(50) << left << "||\t3. Borrow book" << "|| " << endl;
	cout << "||\t4. Check the list of books "
		<< setw(20) << left
		<< "being borrowed" << "|| " << endl;
	cout << setw(50) << left << "||\tQ. Back to main page" << "||"
		<< endl;
	cout << "-----------------------------------------------------"
		<< "----" << endl;

	do {
		cout << "What do you want to do? >> ";
		getline(cin, choice);

		if (choice.length() != 1 || choice != "1" && choice != "2"
			&& choice != "3" && choice != "4"
			&& toupper(choice[0]) != 'Q') {
			SetConsoleTextAttribute(col, 4);
			cout << "Oooppsss, invalid input :(\nPlease key in "
				<< "a valid input!\n\n";
			SetConsoleTextAttribute(col, 7);
		}
	} while (choice.length() != 1 || choice != "1" && choice != "2"
		&& choice != "3" && choice != "4"
		&& toupper(choice[0]) != 'Q');

	if (choice == "1") {
		inventory();
		system("Pause");
		patronPage();
	}

	else if (choice == "2") {
		returnbook();
		system("Pause");
		patronPage();
	}

	else if (choice == "3") {
		borrowbook();
		system("Pause");
		patronPage();
	}

	else if (choice == "4") {
		showBorrow();
		system("Pause");
		patronPage();
	}
}

void lbrLogin() {
	system("cls");
	lbrLogo();

	string lbrID, lbrPW, line;
	bool searchID = false, searchPW = false;

	do {
		ifstream lbrFile;
		lbrFile.open("lbrList.txt", ios::in);

		cout << "Please key in your librarian ID (eg: abc123456)"
			<< " >> ";
		getline(cin, lbrID);

		while (!lbrFile.eof()) { //To check the validation of lbrID

			//To ignore the line without lbr ID
			getline(lbrFile, line);
			//To get the line with lbr ID
			getline(lbrFile, line);

			if (line == lbrID) {
				searchID = true;
				break;
			}
			else
				searchID = false;

			getline(lbrFile, line);
			getline(lbrFile, line);
			getline(lbrFile, line);
		}

		if (!searchID) {
			SetConsoleTextAttribute(col, 4);
			cout << "Ooooops, the librarian ID entered is not"
				<< " found in our system :(\nPlease key in "
				<< "a correct ID." << endl << endl;
			SetConsoleTextAttribute(col, 7);
			lbrFile.close();
		}
	} while (!searchID);

	string lbrList[20][3];

	if (searchID) {
		do {
			ifstream lbrFile;
			lbrFile.open("lbrList.txt", ios::in);

			cout << "Please key in your password >> ";
			getline(cin, lbrPW);

			for (int i = 0; !lbrFile.eof(); i++) {
				//To determine either the lbrPW is 
				//correct or not

				getline(lbrFile, line);
				getline(lbrFile, lbrList[i][0]);
				//Store into lbrList as it contain lbrID
				getline(lbrFile, lbrList[i][1]);
				//Store into lbrList as it contain lbrPW

				if (lbrList[i][0] == lbrID) {
					if (lbrList[i][1] == lbrPW) {
						searchPW = true;
						break;
					}
					else
						searchPW = false;
				}

				getline(lbrFile, line);
				getline(lbrFile, line);
			}

			if (searchPW)
				lbrPage();

			else {
				SetConsoleTextAttribute(col, 4);
				cout << "Ooooops, the password is"
					<< " incorrect!\nPlease key in a correct"
					<< " password." << endl << endl;
				SetConsoleTextAttribute(col, 7);
			}
			lbrFile.close();
		} while (!searchPW);
	}
}

void lbrPage() {
	system("cls");
	lbrLogo();
	cout << "\t\t\t'Welcome to The Secret Base of Librarian!'"
		<< endl << endl;
	string choice;

	cout << "--------------------------------------------------"
		<< endl;
	cout << setw(43) << left << "||\t1. Maintenace" << "||" << endl;
	cout << setw(43) << left << "||\t2. Inventory Review" << "|| "
		<< endl;
	cout << setw(43) << left << "||\tQ. Quit" << "|| " << endl;
	cout << "-------------------------------------------------"
		<< endl;

	do {
		cout << "What do you want to do? >> ";
		getline(cin, choice);

		if (choice != "1" && choice != "2" &&
			toupper(choice[0]) != 'Q' ||
			choice.length() != 1) {
			SetConsoleTextAttribute(col, 4);
			cout << "Oooppsss, invalid input :(\nPlease key in "
				<< "a valid input!" << endl << endl;
			SetConsoleTextAttribute(col, 7);
		}
	} while (choice != "1" && choice != "2" &&
		toupper(choice[0]) != 'Q' ||
		choice.length() != 1);

	if (choice == "1") {
		maintenance();
		lbrPage();
	}

	else if (choice == "2") {
		inventory();
		lbrPage();
	}
}

bool testID(string ID) {
	int count;
	bool IDvalid;

	if (ID.length() != 9)
		IDvalid = false;
	else
		IDvalid = true;

	if (IDvalid == true) {

		//Determine if the first three is alphabet
		for (count = 0; count < 3; count++) {
			if (!isalpha(ID[count])) {
				IDvalid = false;
				break;
			}
			else
				IDvalid = true;
		}

		if (IDvalid == true) {

			//Determine if the last six is digit
			for (count = 3; count < 9; count++) {
				if (!isdigit(ID[count])) {
					IDvalid = false;
					break;
				}
				else
					IDvalid = true;
			}
		}
	}

	if (IDvalid == false)
		return false;
	else
		return true;
}

bool testPW(string PW) {
	if (PW.length() < 5)
		return false;
	else
		return true;
}

struct BookList {
	string title;
	string author;
	string genre;
	double rating;
	char avl;
	int totalavl;
	double price;
	string ID;
};

//Maintenance (1. appendBook	2. deleteBook)
void maintenance() {
	string option;
	system("cls");
	lbrLogo();
	cout << "\t\t\t'Welcome to The Secret Base of Librarian!'" << endl
		<< endl;
	cout << "------------------------------------------------------"
		<< "------------" << endl;
	cout << "||\t1. Add new book(s) into "
		<< setw(33) << left << "ESL Library database  " << "||" 
		<< endl;
	cout << "||\t2. Delete book(s) from the "
		<< setw(30) << left << "ESl Library database" << "||" 
		<< endl;
	cout << setw(60) << left << "||\tQ. Quit" << "||" << endl;
	cout << "----------------------------------------------------"
		<< "---------------" << endl;
	cout << "What do you want to do? >> ";

	do {
		cout << "\nOption: ";
		getline(cin, option);

		if (option.length() != 1 || option != "1" && option != "2"
			&& toupper(option[0]) != 'Q') {
			SetConsoleTextAttribute(col, 4);
			cout << "Oooppss, invalid input :(\nPlease key in"
				<< " a valid input.\n\n";
			SetConsoleTextAttribute(col, 7);
		}
	} while (option.length() != 1 || option != "1" && option != "2"
		&& toupper(option[0]) != 'Q');

	switch (option[0]) {
	case '1':
		appendBook();
		cout << endl;
		system("Pause");
		break;

	case '2':
		deleteBook();
		cout << endl;
		system("Pause");
		break;
	}
}

void appendBook() {
	bool invalid;
	int num, count = 0, Bookno = 1, Bookid = 100000;
	double Rating = 3.5, Price = 3.5;
	char avail = 'Y';
	string ans, title, author, genre, rating, price, bookNo, bookId;
	string bookList1[50][8];
	string quest = "How many book do you want to append? : ";

	system("cls");
	lbrLogo();
	cout << "\t\t\t'Welcome to The Secret Base of Librarian!'"
		<< endl << endl;
	cout << endl << quest; //Display question
	getline(cin, ans);

	//Determine the input validation and return integer value
	num = intValid(ans, quest);

	if (num == 0) { //if num is equal to 0
		SetConsoleTextAttribute(col, 4);
		cout << "Dingdong! No book is added." << endl;
		SetConsoleTextAttribute(col, 7);
	}

	else if (num < 0) {
		SetConsoleTextAttribute(col, 4);
		cout << "Oooppss, invalid input :(\nPlease key in a "
			<< "valid input (a positive value)." << endl
			<< endl;
		SetConsoleTextAttribute(col, 7);
	}

	else if (num > 0) {
		cout << "------------------------------------------"
			<< endl;
		cout << "\nPlease key in the details of book.\n" << endl;

		for (int i = 0; i < num; i++) {
			cout << "----------------------------------" << endl;
			cout << "|\tBook " << i + 1 << "\t\t\t||" << endl;
			cout << "----------------------------------" << endl;

			do {
				cout << "Title >> ";
				getline(cin, title);
				invalid = validTitle(title);
				//Check the validation of title

			} while (invalid == true);

			do {
				cout << "\nAuthor >> ";
				getline(cin, author);
				invalid = validAuthor(author);
				//Check the validation of author

				if (invalid == true) {
					SetConsoleTextAttribute(col, 4);
					cout << "Oooppss, invalid input :(\n"
						<< "Please key in a valid "
						<<"input (only"
						<< " alphabets are allowed)."
						<< endl << endl;
					SetConsoleTextAttribute(col, 7);
				}
			} while (invalid == true);

			do {
				string opt;
				cout << "\Genre (select "
					<< "one)" << endl;
				cout << setw(18) << left << "< 1 > Horror"
					<< setw(18) << left << "< 2 > Treatise"
					<< setw(18) << left << "< 3 > Comics"
					<< endl << setw(18) << left
					<< "< 4 > Adventure"
					<< setw(18) << left << "< 5 > Fiction"
					<< setw(18) << left << "< 6 > Biography"
					<< endl << setw(18) << left
					<< "< 7 > Crime";
				cout << "\nGenre >> ";
				getline(cin, opt);

				if (opt.length() != 1 || opt[0] != '1' &&
					opt[0] != '2' && opt[0] != '3' &&
					opt[0] != '4' && opt[0] != '5' &&
					opt[0] != '6' && opt[0] != '7') {

					invalid = true;
					SetConsoleTextAttribute(col, 4);
					cout << "Oooppss, invalid input :(\n"
						<< "Please key in a valid input."
						<< endl << endl;
					SetConsoleTextAttribute(col, 7);
				}
				else {
					invalid = false;

					switch (opt[0]) {
					case '1':
						genre = "Horror";
						break;
					case '2':
						genre = "Treatise";
						break;
					case '3':
						genre = "Comics";
						break;
					case '4':
						genre = "Adventure";
						break;
					case '5':
						genre = "Fiction";
						break;
					case '6':
						genre = "Biography";
						break;
					case '7':
						genre = "Crime";
						break;
					}
				}
			} while (invalid == true);

			do {
				string quest3 = "\nRating (0 - 5) >> ";
				cout << quest3;
				getline(cin, rating);

				//Check if rating is consists of digit
				// and return double value
				Rating = douValid(rating, quest3);
				invalid = validRating(Rating);
				//Check the validation of rating

				if (invalid == true) {
					SetConsoleTextAttribute(col, 4);
					cout << "Oooppss, invalid input :(\n"
						<< "Please key in a valid input."
						<< endl << endl;
					SetConsoleTextAttribute(col, 7);
				}
			} while (invalid == true);

			//Book's availability by default is Yes (Y)
			cout << "\nAvailability (Y/N) >> Y" << endl;

			do {
				string quest5 = "Number of book available >> ";
				cout << quest5;
				getline(cin, bookNo);

				//Check if bookNo is consists of digit only 
				//and return int value
				Bookno = intValid(bookNo, quest5);
				invalid = validBookno(Bookno);
				//Check the validation of Bookno

				if (invalid == true) {
					SetConsoleTextAttribute(col, 4);
					cout << "Oooppss, invalid input.\n"
						<< "Please key in a valid"
						<< " input.\n\n";
					SetConsoleTextAttribute(col, 7);
				}

			} while (invalid == true);

			do {
				string quest6 = "\nPrice of book >> RM";
				cout << quest6;
				getline(cin, price);

				//Check if price is a valid double value
				// and return double value
				Price = douValid(price, quest6);
				invalid = validPrice(Price);
				//Check the validation of Price

				if (invalid == true) {
					SetConsoleTextAttribute(col, 4);
					cout << "Oooppss, invalid input.\n"
						<< "Please key in a valid"
						<<" input.\n\n";
					SetConsoleTextAttribute(col, 7);
				}
			} while (invalid == true);

			do {
				readtoArray(bookList1, count);
				string quest7 = "\nBook ID (eg: 123456) >> ";
				cout << quest7;
				getline(cin, bookId);

				//Check if bookId is consists of digit only and
				// return int value
				Bookid = intValid(bookId, quest7);
				invalid = validBookid(Bookid);
				//Check the validation of Bookid

				if (invalid == true) {
					SetConsoleTextAttribute(col, 4);
					cout << "Oooppss, invalid input :(\n"
						<< "Please key in a valid"
						<< " input." << endl << endl;
					SetConsoleTextAttribute(col, 7);
				}

				else if (invalid == false) {
					bookId = intTostring(Bookid);
					//Convert Bookid from integer to 
					//string type

					for (int k = 0; k <= count; k++) {
						//Determine if book ID already exists
						// in the system

						if (bookId == bookList1[k][7]) {
							SetConsoleTextAttribute(col,
								4);
							cout << "Oooppss, the book "
								<< "ID already exist in"
								<< " ESL database"
								<< " :(\nPlease key in"
								<< " another unique"
								<< " book ID." << endl
								<< endl;
							SetConsoleTextAttribute(col,
								7);
							invalid = true;
							break;
						}
						else {
							invalid = false;
						}
					}
				}
			} while (invalid == true);

			cout << endl;
			ofstream outFile; //Update bookList file
			outFile.open("bookList.txt", ios::app);
			outFile << endl << title << endl << author << endl
				<< genre << endl;
			outFile << Rating << " " << avail << " " << Bookno
				<< " " << Price << " " << Bookid;
			outFile.close();
		}
	}
}

void deleteBook() {
	system("cls");
	lbrLogo();
	cout << "\t\t\t'Welcome to The Secret Base of Librarian!'" << endl
		<< endl;

	int bookId = 100010, count = 0;
	bool invalid, valid = true;
	int Num, Key, index;
	string num, key, line1, line2;
	string one = "How many book do you want to delete ";
	string two = "from the library database? : ";
	string quest = one + two;
	cout << quest;
	getline(cin, num);
	Num = intValid(num, quest);
	//Determine the validation of int and return integer value

	if (Num == 0) {
		SetConsoleTextAttribute(col, 4);
		cout << "Dingdong! No book is deleted.";
		SetConsoleTextAttribute(col, 7);
	}

	else if (Num < 0) {
		SetConsoleTextAttribute(col, 4);
		cout << "Oooppss, invalid input :(\nPlease key in a "
			<< "valid input (a positive value)." << endl
			<< endl;
		SetConsoleTextAttribute(col, 7);
	}

	else if (Num > 0) {
		cout << endl;
		string one = "Please enter ID of the book that you";
		string two = " want to delete (eg: 123456): ";
		string quest2 = one + two;

		for (int i = 0; i < Num; i++)
		{
			// 0: Title  1: Author  2: Genre  3: Rating
			// 4: Availability (Y/N)
			// 5: Number of stock  6: Price  7: Book ID
			string bookList1[50][8];
			string bookList2[50][8];
			readtoArray(bookList1, count);

			cout << "Book " << i + 1 << ":" << endl;

			do {
				cout << quest2;
				getline(cin, key); //Key is book ID

				Key = intValid(key, quest2);
				invalid = validBookid(Key);
				//Check the validation of key
				key = intTostring(Key);

				if (invalid == true) {
					SetConsoleTextAttribute(col, 4);
					cout << "Oooppss, invalid input :(\n"
						<< "Please key in a valid input."
						<< endl << endl;
					SetConsoleTextAttribute(col, 7);
				}
			} while (invalid == true);

			cout << endl;

			//Determine if the input book ID exists in the
			//system or not
			for (int k = 0; k <= count; k++) {
				if (bookList1[k][7] == key) {
					valid = true;
					index = k;
					break;
				}
				else
					valid = false;
			}

			if (valid == false) {
				SetConsoleTextAttribute(col, 4);
				cout << "Oooppss, the book ID is not found"
					<< " in ESL database.\nNo book is "
					<< "deleted." << endl << endl;
				SetConsoleTextAttribute(col, 7);
			}

			else {
				//Display the corresponding details of book
				// ID (input)

				cout << setw(30) << left << "|| Title" << ":"
					<< bookList1[index][0] << endl;
				cout << setw(30) << left << "|| Author" << ":"
					<< bookList1[index][1] << endl;
				cout << setw(30) << left << "|| Genre" << ":"
					<< bookList1[index][2] << endl;
				cout << setw(30) << left << "|| Rating" << ":"
					<< fixed << setprecision(2)
					<< stringTodou(bookList1[index][3])
					<< endl;
				cout << "|| " << setw(27) << left
					<< "Book's Availability (Y/N)" << ":"
					<< bookList1[index][4] << endl;
				cout << setw(30) << left << "|| Stock of book"
					<< ":" << bookList1[index][5] << endl;
				cout << setw(30) << left << "|| Price" << ":RM"
					<< fixed << setprecision(2)
					<< stringTodou(bookList1[index][6])
					<< endl;
				cout << setw(30) << left << "|| Book ID" << ":"
					<< bookList1[index][7] << endl;

				string confirm;
				bool invalid = false;

				do {
					cout << "\nAre you confirm to delete "
						<< "the book from the ESL "
						<< "database? (Y/N) >> ";
					getline(cin, confirm);

					if (confirm.length() == 1) {
						if (toupper(confirm[0]) != 'Y'
							&& toupper(confirm[0]) != 'N')
							invalid = true;
						else
							invalid = false;
					}
					else
						invalid = true;

					if (invalid == true) {
						SetConsoleTextAttribute(col, 4);
						cout << "Oooppss, invalid input"
							<< " :(\nPlease key in a valid"
							<< " input." << endl << endl;
						SetConsoleTextAttribute(col, 7);
					}
				} while (invalid == true);

				if (toupper(confirm[0]) == 'Y') {
					for (int m = 0; m <= count; m++) {
						//Store data without the book being
						//deleted into bookList2
						if (m < index) {
							for (int z = 0; z <= 7; z++) {
								bookList2[m][z]
									= bookList1[m][z];
							}
						}
						else if (m > index) {
							for (int z = 0; z <= 7; z++) {
								bookList2[m - 1][z]
									= bookList1[m][z];
							}
						}
					}

					ofstream outFile; //Update bookList file
					outFile.open("bookList.txt");

					for (int n = 0; n < count; n++) {
						outFile << bookList2[n][0] << endl
							<< bookList2[n][1] << endl
							<< bookList2[n][2] << endl
							<< bookList2[n][3] << " "
							<< bookList2[n][4] << " "
							<< bookList2[n][5] << " "
							<< bookList2[n][6] << " "
							<< bookList2[n][7];
						if (n != count - 1)
							outFile << endl;
					}
					outFile.close();
				}

				//Clear the data store in both bookList1 and
				// //bookList2
				//a is row and b is column
				for (int a = 0; a <= count; a++) {
					for (int b = 0; b < 8; b++)
						bookList1[a][b].clear();
				}

				for (int a = 0; a < count; a++) {
					for (int b = 0; b < 8; b++)
						bookList2[a][b].clear();
				}

				if (toupper(confirm[0]) == 'Y') {
					SetConsoleTextAttribute(col, 11);
					cout << "\nBOOK DELETE SUCCESSFULLY!\n"
						<< "We kick one book out from "
						<< "ESL database." << endl;
					SetConsoleTextAttribute(col, 7);
				}
				if (i != Num - 1)
					cout << endl;
			}
		}
	}
}

void readtoArray(string bookList1[50][8], int& count) {

	ifstream inFile;
	inFile.open("bookList.txt");

	if (inFile.fail()) {
		SetConsoleTextAttribute(col, 4);
		cout << "Error! Error! Unable to open the file.\n"
			<< "Please have a check." << endl;
		SetConsoleTextAttribute(col, 7);
	}

	else {

		for (int i = 0; !inFile.eof(); i++) {

			getline(inFile, bookList1[i][0]); // To get title
			getline(inFile, bookList1[i][1]); // To get author
			getline(inFile, bookList1[i][2]); // To get genre
			inFile >> bookList1[i][3] //To get rating
				>> bookList1[i][4] //To get book'availability
				>> bookList1[i][5] //To get number of stock
				>> bookList1[i][6] //To get book's price
				>> bookList1[i][7]; //To get book ID
			inFile.ignore();

			count = i; //To count the number of books
		}
	}
	inFile.close();
}

struct bookArray
{
	string title;
	string author;
	string genre;
	double rating;
	char avail;
	int bookNo;
	double price;
	int bookId;
} book[50];

bool validTitle(string title) {
	bool invalid;
	string Title, ignore;

	ifstream inFile;
	inFile.open("bookList.txt");

	if (title.length() != 0) {
		if (inFile.fail()) {
			SetConsoleTextAttribute(col, 4);
			cout << "Error! Error! Unable to open the"
				<< " file.\nPlease have a check.\n";
			SetConsoleTextAttribute(col, 7);
		}
		else {
			while (!inFile.eof()) {
				getline(inFile, Title);
				if (title == Title) {
					invalid = true;
					SetConsoleTextAttribute(col, 4);
					cout << "Oooppss, invalid input :(\n"
						<< "Please key in a valid input."
						<< endl << endl;
					SetConsoleTextAttribute(col, 7);
					break;
				}
				else
					invalid = false;
				//To ignore the line without title
				getline(inFile, ignore);
				getline(inFile, ignore);
				getline(inFile, ignore);
			}
		}
	}
	else {
		invalid = true;
		SetConsoleTextAttribute(col, 4);
		cout << "Oooppss, invalid input :(\nPlease key in a "
			<< "valid input." << endl << endl;
		SetConsoleTextAttribute(col, 7);
	}

	inFile.close();

	return invalid;
}

bool validAuthor(string author) {
	bool invalid;

	if (author.length() != 0) {
		for (int i = 0; i < author.length(); i++) {
			if (isdigit(author[i])) {
				invalid = true;
				break;
			}
			else
				invalid = false;
		}
	}
	else
		invalid = true;

	return invalid;
}

bool validRating(double Rating) {
	bool invalid;

	if (Rating < 0 || Rating >5)
		invalid = true;
	else
		invalid = false;

	return invalid;
}

bool validBookno(int Bookno) {
	bool invalid;

	if (Bookno <= 0)
		invalid = true;
	else
		invalid = false;

	return invalid;
}

bool validPrice(double Price) {
	bool invalid;

	if (Price <= 0)
		invalid = true;
	else
		invalid = false;

	return invalid;

}

bool validBookid(int Bookid) {
	bool invalid;

	if (Bookid < 100000 || Bookid > 999999)
		invalid = true;
	else
		invalid = false;

	return invalid;
}

int intValid(string input, string quest) {

	string num;
	int numValue = 0, no = 0;
	bool invalid = true;

	ifstream inFile;
	ofstream outFile;
	outFile.open("Input.txt");
	outFile << input;
	outFile.close();

	while (invalid == true) {

		inFile.open("Input.txt");

		if (inFile.fail()) {
			SetConsoleTextAttribute(col, 4);
			cout << "Error! Error! Unable to open the"
				<< " file.\nPlease have a check."
				<< endl;
			SetConsoleTextAttribute(col, 7);
		}
		else {
			while (!inFile.eof()) {
				getline(inFile, num);

				for (int i = 0; i < num.length(); i++) {
					if (num[0] == '-')
						invalid = false;

					else if (!isdigit(num[i])) {
						invalid = true;
						break;
					}
					else {
						invalid = false;
					}
				}
			}
		}
		inFile.close();

		if (invalid) {
			outFile.open("Input.txt");
			SetConsoleTextAttribute(col, 4);
			cout << "Ooooppsss, invalid input :(\nPlease key in"
				<< " a valid input (only integer is allowed)."
				<< endl << endl;
			SetConsoleTextAttribute(col, 7);
			cout << quest;
			getline(cin, num);
			outFile << num;
			outFile.close();
		}
	}

	inFile.open("Input.txt");
	while (!inFile.eof()) {
		inFile >> numValue;
	}
	inFile.close();

	return numValue;
}

double douValid(string input, string quest) {

	string num;
	double numValue = 0;
	bool invalid = true;

	ifstream inFile;
	ofstream outFile;
	outFile.open("Input.txt");
	outFile << input;
	outFile.close();

	while (invalid == true) {
		inFile.open("Input.txt");

		if (inFile.fail()) {
			SetConsoleTextAttribute(col, 4);
			cout << "Error! Error! Unable to open the"
				<< " file.\nPlease have a check."
				<< endl;
			SetConsoleTextAttribute(col, 7);
		}
		else {
			while (!inFile.eof()) {
				getline(inFile, num);

				int digitNum = 0, dotNum = 0, alphaNum = 0;

				for (int i = 0; i < num.length(); i++) {

					if (num[i] == '.') {
						dotNum++;
						invalid = false;
					}
					else if (isdigit(num[i])) {
						digitNum++;
						invalid = false;
					}
					else if (num[0] == '-') {
						invalid = false;
					}
					else if (isalpha(num[i])) {
						alphaNum++;
						invalid = false;
					}
					else {
						//To determine whether the character
						//is other than ".", digit and 
						//alphabet or not
						invalid = true;
						break;
					}
				}

				if (invalid != true) {
					//num[num.length()-1) is used to determine
					//if the last digit is '.' or not
					if (num[0] != '.' &&
						num[num.length() - 1] != '.'
						&& digitNum > 0 && (dotNum == 0
							|| dotNum == 1)
						&& alphaNum == 0)
						invalid = false;
					else
						invalid = true;
				}
			}
		}
		inFile.close();

		if (invalid) {
			outFile.open("Input.txt");
			SetConsoleTextAttribute(col, 4);
			cout << "Ooooppsss, invalid input :(\nPlease key in"
				<< " a valid input (only one value is "
				<< "allowed)." << endl << endl;
			SetConsoleTextAttribute(col, 7);
			cout << quest;
			getline(cin, num);
			outFile << num;
			outFile.close();
		}
	}

	inFile.open("Input.txt");
	while (!inFile.eof()) {
		inFile >> numValue;
	}
	inFile.close();

	return numValue;
}

double stringTodou(string num) {

	double Num;

	ofstream outFile;
	outFile.open("Input.txt");
	outFile << num;
	outFile.close();

	ifstream inFile;
	inFile.open("Input.txt");
	inFile >> Num;
	inFile.close();

	return Num;
}

int stringToint(string num) {

	int Num;

	ofstream outFile;
	outFile.open("Input.txt");
	outFile << num;
	outFile.close();

	ifstream inFile;
	inFile.open("Input.txt");
	inFile >> Num;
	inFile.close();

	return Num;
}

string intTostring(int num) {

	string Num;

	ofstream outFile;
	outFile.open("Input.txt");
	outFile << num;
	outFile.close();

	ifstream inFile;
	inFile.open("Input.txt");
	inFile >> Num;
	inFile.close();

	return Num;
}

string douTostring(double num) {

	string Num;

	ofstream outFile;
	outFile.open("Input.txt");
	outFile << num;
	outFile.close();

	ifstream inFile;
	inFile.open("Input.txt");
	inFile >> Num;
	inFile.close();

	return Num;
}

//Inventory (1. showBorrow	2.sorting	3. displayBook)
void inventory() {

	string Option;
	int num;

	system("cls");
	mainLogo();
	cout << "\t\t\t'Welcome to ESL Book Shelf'" << endl << endl;
	cout << "--------------------------------------------------------"
		<< endl;
	cout << setw(49) << left << "||\t1. Alphabet of book's title"
		<< "||" << endl;
	cout << setw(49) << left << "||\t2. Author" << "||" << endl;
	cout << setw(49) << left << "||\t3. Book ID" << "||" << endl;
	cout << setw(49) << left << "||\tQ. Quit" << "||" << endl;
	cout << "--------------------------------------------------------"
		<< endl << endl;
	cout << "Which category do you want to have a look? >> ";

	getline(cin, Option);
	while (Option.length() != 1 || Option[0] != '1' &&
		Option[0] != '2' && Option[0] != '3'
		&& toupper(Option[0]) != 'Q') {
		SetConsoleTextAttribute(col, 4);
		cout << "Oooppsss, invalid input :(\nPlease key in a "
			<< "valid input." << endl;
		SetConsoleTextAttribute(col, 7);
		cout << "\nWhich category do you want to have a look? >> ";
		getline(cin, Option);
	}
	cout << endl;

	system("cls");
	mainLogo();
	cout << "\t\t\t'Welcome to ESL Book Shefl'" << endl << endl;

	switch ((char)toupper(Option[0])) {

	case '1':
		num = 0;
		sorting(num);
		break;

	case '2':
		num = 1;
		sorting(num);
		break;

	case '3':
		num = 7;
		sorting(num);
		break;

	default:
		break;
	}
}

void showBorrow() {
	system("cls");
	patronLogo();
	cout << "\t\t\t'Treasures Return Centre'\n\n";

	int index = 0, count = 0;
	string patronID, line;
	string patronBor[50];
	string bookList1[50][8];
	readtoArray(bookList1, count);

	ifstream loginFile; //To get the patron ID
	loginFile.open("LoginID.txt");

	if (loginFile.fail()) {
		SetConsoleTextAttribute(col, 4);
		cout << "Error! Error! Unable to open the file.\nPlease"
			<< " have a check." << endl;
		SetConsoleTextAttribute(col, 7);
	}
	else
		getline(loginFile, patronID);

	loginFile.close();

	// To get the list of book borrowed(not yet
	// return) by patron
	ifstream borrowFile;
	borrowFile.open("borrowList.txt");

	if (borrowFile.fail()) {
		SetConsoleTextAttribute(col, 4);
		cout << "Error! Error! Unable to open the file.\nPlease"
			<< " have a check." << endl;
		SetConsoleTextAttribute(col, 7);
	}
	else {
		while (!borrowFile.eof()) {
			//To get the list of book borrowed (not yet return) 
			//by current patron

			borrowFile >> line;
			if (line == patronID) {
				borrowFile >> line; //To obatin the book ID
				patronBor[index] = line;
				index++;
			}
			else
				borrowFile >> line;
			//To ignore the book ID which is
			//not related to current patron
		}
	}
	borrowFile.close();

	for (int k = 0; k < index; k++) {
		//Display the details of book borrowed (not 
		//yet return) by patron
		for (int m = 0; m <= count; m++) {
			if (bookList1[m][7] == patronBor[k]) {
				cout << setw(30) << left << "|| Title" << ": "
					<< bookList1[m][0] << endl;
				cout << setw(30) << left << "|| Author" << ": "
					<< bookList1[m][1] << endl;
				cout << setw(30) << left << "|| Rating" << ": "
					<< fixed << setprecision(2)
					<< stringTodou(bookList1[m][3])
					<< endl;
				cout << setw(30) << left
					<< "|| Availability (Y/N)" << ": "
					<< bookList1[m][4] << endl;
				cout << setw(30) << left << "|| Price of book"
					<< ": RM" << fixed << setprecision(2)
					<< stringTodou(bookList1[m][6])
					<< endl;
				cout << setw(30) << left << "|| Book ID" << ": "
					<< bookList1[m][7] << endl 
					<< endl << endl;
			}
		}
	}
}

void sorting(int num) {

	int count = 0, sum = 0, value, Booknum, index;
	string opt = "Y", rep = "Y", bookNum;

	// 0: Title  1: Author  2: Genre  3: Rating  4: Availability (Y/N) 
	// 5: Number of stock  6: Price  7: Book ID
	string bookList1[50][8];
	string idList[50];
	readtoArray(bookList1, count);

	//num represents either title, author or bookid
	//Store the data of num into idList
	for (int i = 0; i <= count; i++) {
		idList[i] = bookList1[i][num];
	}

	//Sort the data in ascending order
	for (int j = count; j > 0; j--) {
		for (int n = 0; n <= j; n++) {
			if (idList[j] <= idList[j - n])
				idList[j].swap(idList[j - n]);
		}
	}

	//Display sorted data
	for (int k = 0; k <= count; k++) {
		cout << k + 1 << ". " << idList[k] << endl;
	}

	// Calculate the total number of book available
	for (int y = 0; y <= count; y++) {
		value = stringToint(bookList1[y][5]);
		sum += value;
	}

	cout << endl << endl;
	cout << setw(40) << left << "Total books (with different book ID)"
		<< ": " << count + 1 << endl;
	cout << setw(40) << left << "Total stock (book)" << ": " << sum
		<< endl << endl;

	do {
		cout << "Do you want to display the details of "
			<< "book? (Y/N) >> ";
		getline(cin, opt);

		if (opt.length() != 1 || toupper(opt[0]) != 'Y'
			&& toupper(opt[0]) != 'N') {
			SetConsoleTextAttribute(col, 4);
			cout << "Oooppss, invalid input:(\nPlease key "
				<< "in a valid input." << endl << endl;
			SetConsoleTextAttribute(col, 7);
		}

	} while (opt.length() != 1 || toupper(opt[0]) != 'Y' &&
		toupper(opt[0]) != 'N');

	cout << endl;
	if (toupper(opt[0]) == 'N')
		rep = "N";

	while (toupper(rep[0]) == 'Y') {

		if (toupper(opt[0]) == 'Y') {
			do {
				string one = "Which book you want to display? ";
				string two = "(eg: 1, 2, 3, ...) >> ";
				string ques1 = one + two;
				cout << ques1;
				getline(cin, bookNum);
				Booknum = intValid(bookNum, ques1);

				if (Booknum < 1 || Booknum > count + 1) {
					SetConsoleTextAttribute(col, 4);
					cout << "Oooppss, invalid input :(\n"
						<< "Please key in a valid input"
						<< " (between 1 to "
						<< count + 1 << ")."
						<< endl << endl;
					SetConsoleTextAttribute(col, 7);
				}
			} while (Booknum < 1 || Booknum > count + 1);

			//To determine the index number of corresponding book
			// in bookList1
			for (int a = 0; a <= count; a++) {
				if (bookList1[a][num] == idList[Booknum - 1]) {
					index = a;
					break;
				}
			}

			cout << endl;

			//Display the details of book
			if (num == 0) {
				cout << setw(30) << left << "|| Title" << ": "
					<< idList[Booknum - 1] << endl << endl;
				cout << setw(30) << left << "|| Author" << ": "
					<< bookList1[index][1] << endl;
			}

			else if (num == 1) {
				cout << setw(30) << left << "|| Author" << ": "
					<< idList[Booknum - 1] << endl << endl;
				cout << setw(30) << left << "|| Title" << ": "
					<< bookList1[index][0] << endl;
			}
			else if (num == 7) {
				cout << setw(30) << left << "|| Book ID" << ": "
					<< idList[Booknum - 1] << endl << endl;
				cout << setw(30) << left << "|| Title" << ": "
					<< bookList1[index][0] << endl;
				cout << setw(30) << left << "|| Author" << ": "
					<< bookList1[index][1] << endl;
			}

			cout << setw(30) << left << "|| Genre" << ": "
				<< bookList1[index][2] << endl;
			cout << setw(30) << left << "|| Rating" << ": "
				<< fixed << setprecision(2)
				<< stringTodou(bookList1[index][3])
				<< endl;
			cout << setw(30) << left << "|| Availability (Y/N)"
				<< ": " << bookList1[index][4] << endl;
			cout << setw(30) << left
				<< "|| Number of stock (book)" << ": "
				<< bookList1[index][5] << endl;
			cout << setw(30) << left << "|| Price of book"
				<< ": RM" << fixed << setprecision(2)
				<< stringTodou(bookList1[index][6])
				<< endl;

			if (num == 0 || num == 1)
				cout << setw(30) << left << "|| Book ID" << ": "
				<< bookList1[index][7] << endl;

			cout << endl;
		}

		do {
			cout << "Do you want to display the details of "
				<< "another book? (Y/N) >> ";
			getline(cin, rep);

			if (rep.length() != 1 || toupper(rep[0]) != 'Y' &&
				toupper(rep[0]) != 'N') {
				SetConsoleTextAttribute(col, 4);
				cout << "Oooppss, invalid input :(\nPlease "
					<< "key in a valid input." << endl
					<< endl;
				SetConsoleTextAttribute(col, 7);
			}
		} while (rep.length() != 1 || toupper(rep[0]) != 'Y' &&
			toupper(rep[0]) != 'N');

		cout << endl;
	}
}

void displayBook() {

	string line;
	int lineNo = 0, total = 0;
	bookArray book[50];

	ifstream bookFile;
	bookFile.open("bookList.txt");

	if (bookFile.fail()) {
		SetConsoleTextAttribute(col, 4);
		cout << "Error! Error! Unable to open the file.\n"
			<< "Please have a check.";
		SetConsoleTextAttribute(col, 7);
	}
	else {
		while (!bookFile.eof()) {
			getline(bookFile, line);
			lineNo++;
		}
		bookFile.close();

		bookFile.open("bookList.txt");
		for (int i = 0; i < lineNo / 4; i++) {
			getline(bookFile, book[i].title);
			getline(bookFile, book[i].author);
			getline(bookFile, book[i].genre);
			bookFile >> book[i].rating
				>> book[i].avail
				>> book[i].bookNo
				>> book[i].price
				>> book[i].bookId;
			bookFile.ignore();

			total += book[i].bookNo;

			cout << setw(30) << left << "|| Title" << ": "
				<< book[i].title << endl;
			cout << setw(30) << left << "|| Author" << ": "
				<< book[i].author << endl;
			cout << setw(30) << left << "|| Genre" << ": "
				<< book[i].genre << endl;
			cout << setw(30) << left << fixed << setprecision(2)
				<< "|| Rating" << ": " << book[i].rating
				<< endl;
			cout << setw(30) << left << "|| Availability (Y/N)"
				<< ": " << book[i].avail << endl;
			cout << "|| Number of stock"
				<< setw(12) << left << " (book)"
				<< ": " << book[i].bookNo << endl;
			cout << setw(30) << left << fixed << setprecision(2)
				<< "|| Price of book" << ": RM"
				<< book[i].price << endl;
			cout << setw(30) << left << "|| Book ID" << ": "
				<< book[i].bookId << endl
				<< endl << endl;
		}
		cout << "Total books (with different book ID): "
			<< lineNo / 4 << endl;
		cout << "Total stock of books: " << total << endl << endl;
		bookFile.close();
	}
}

//Return_Borrow
void returnbook() {
	system("cls");
	patronLogo();
	cout << "\t\t\t'Treasures Return Centre'\n\n";

	string direct, id, patronID, confess, line;
	int ID, index, num = 0, lineNo = 0, count, lineNum = 1;
	bool invalid, valid = false;
	string borrowList[50][2];
	string bookList1[50][8];
	readtoArray(bookList1, count);

	cout << "\n----------------------------------" << endl;
	cout << "|| 1. Return book \t\t||" << endl;
	cout << "|| Q. Back to previous \t\t||" << endl;
	cout << "----------------------------------" << endl;

	do {
		cout << "\nWhat do you want to do? >> ";
		getline(cin, confess);

		if (confess.length() != 1 || confess != "1" &&
			toupper(confess[0]) != 'Q') {
			SetConsoleTextAttribute(col, 4);
			cout << "Oooppss, invalid input :(\nPlease key in"
				<< " a valid input.\n\n";
			SetConsoleTextAttribute(col, 7);
		}
	} while (confess.length() != 1 || confess != "1" &&
		toupper(confess[0]) != 'Q');

	if (confess == "1") {
		patronLogo();
		cout << "\t\t\t'Treasures Return Centre'\n\n";
		showBorrow();

		do {
			string one = "Which book do you want to return?";
			string two = "(Please key in the book ID) >> ";
			string ques1 = one + two;
			cout << ques1;
			getline(cin, id);

			ID = intValid(id, ques1);
			//Determine if it is an integer
			invalid = validBookid(ID);
			//Determine if it is a valid book ID 
			//and return boolean

			if (invalid == true) {
				SetConsoleTextAttribute(col, 4);
				cout << "Oooppss, invalid input :(\nPlease "
					<< "key in a valid input.\n\n";
				SetConsoleTextAttribute(col, 7);
			}
		} while (invalid == true);

		ifstream borrowFile;
		borrowFile.open("borrowList.txt");

		if (borrowFile.fail()) {
			SetConsoleTextAttribute(col, 4);
			cout << "Error! Error! Unable to open "
				<< "the file.\nPlease have a"
				<< " check.\n";
			SetConsoleTextAttribute(col, 7);
		}

		else {
			while (!borrowFile.eof()) {
				getline(borrowFile, line);
				lineNo++;
			}
		}
		borrowFile.close();

		borrowFile.open("borrowList.txt");

		if (borrowFile.fail()) {
			SetConsoleTextAttribute(col, 4);
			cout << "Error! Error! Unable to open the"
				<< " file.\nPlease have a check."
				<< endl;
			SetConsoleTextAttribute(col, 7);
		}

		else {
			for (int p = 0; p <= lineNo; p++) {
				borrowFile >> borrowList[p][0]
					//To store patron ID
					>> borrowList[p][1];
				//To store book ID
			}
		}
		borrowFile.close();

		ifstream loginFile;
		loginFile.open("LoginId.txt");

		if (loginFile.fail()) {
			SetConsoleTextAttribute(col, 4);
			cout << "Error! Error! Unable to open the"
				<< " file.\nPlease have a check."
				<< endl;
			SetConsoleTextAttribute(col, 7);
		}
		else
			getline(loginFile, patronID);
		//To get the ID of current user

		loginFile.close();

		for (int k = 0; k <= lineNo; k++) {
			if (borrowList[k][0] == patronID) {
				//borrowList[k][0] is patron ID
				if (borrowList[k][1] == id) {
					//borrowList[k][1] is book ID
					valid = true;
					index = k;
					break;
				}
				else
					valid = false;
			}
			else if (borrowList[k][0] != patronID)
				valid = false;
		}

		if (valid == false) {
			SetConsoleTextAttribute(col, 4);
			cout << "Huhhh? Your memory is too bad.\nYou"
				<< " didn't borrow such book before."
				<< "\n\n";
			SetConsoleTextAttribute(col, 7);
		}

		else {
			cout << endl << endl;
			SetConsoleTextAttribute(col, 11);
			cout << "BOOK RETURN SUCCESSFULLY!\n";
			cout << "Hope you retain something from "
				<< "the reading :)\n\n";
			SetConsoleTextAttribute(col, 7);

			for (int i = 0; i <= count; i++) {
				if (bookList1[i][7] == id) {
					//As the book is returned to library, 
					//thus, the stock of book +1
					bookList1[i][5]
						= intTostring(
							stringToint(
								bookList1[i][5])
							+ 1);

					if (stringToint(bookList1[i][5]) > 0)
						bookList1[i][4] = "Y";
					break;
				}
			}

			string borrowList2[50][2];

			//Update data without book being returned 
			//into borrowList2
			//Index is the position of book being returned 
			//in borrowList
			for (int k = 0; k < lineNo; k++) {
				if (k < index) {
					borrowList2[k][0] = borrowList[k][0];
					borrowList2[k][1] = borrowList[k][1];
				}
				else if (k > index) {
					borrowList2[k - 1][0] = borrowList[k][0];
					borrowList2[k - 1][1] = borrowList[k][1];
				}
			}

			ofstream Borrowfile;
			Borrowfile.open("borrowList.txt");

			for (int k = 0; k < lineNo - 1; k++) {
				if (k != 0)
					Borrowfile << endl;
				Borrowfile << borrowList2[k][0] << " "
					<< borrowList2[k][1];
			}
			Borrowfile.close();

			ofstream bookFile; //Update bookList file
			bookFile.open("bookList.txt");

			for (int k = 0; k <= count; k++) {
				if (k != 0)
					bookFile << endl;
				bookFile << bookList1[k][0] << endl
					<< bookList1[k][1] << endl
					<< bookList1[k][2] << endl;
				bookFile << bookList1[k][3] << " "
					<< bookList1[k][4] << " "
					<< bookList1[k][5] << " "
					<< bookList1[k][6] << " "
					<< bookList1[k][7];
			}
			bookFile.close();
		}
	}
	else
		patronPage();
}

void borrowbook() {
	system("cls");
	patronLogo();
	cout << "\t\t'Treasures Borrow Centre'" << endl << endl;

	string bookList1[50][8];
	string bookList2[50][8];
	int count;
	readtoArray(bookList1, count);
	displayBook();
	string BorrowId, patronID;
	int borrowId, lineNo = 1;
	bool invalid;
	char noBook;

	cout << "\n------------------------------------------------"
		<< "-------------------------" << endl;
	cout << "Here are the treasures in ESL Library!" << endl << endl;
	do {
		string one = "Which treasure do you want to borrow?";
		string two = " (Please key in book ID) >> ";
		string quest = one + two;
		cout << quest;
		getline(cin, BorrowId);

		borrowId = intValid(BorrowId, quest);
		invalid = validBookid(borrowId);
		BorrowId = intTostring(borrowId);

		if (invalid == false) {
			for (int i = 0; i <= count; i++) {
				if (BorrowId == bookList1[i][7]) {

					if (stringToint(bookList1[i][5]) == 0) {
						SetConsoleTextAttribute(col, 4);
						cout << "Oooppss, the book is"
							<< " currently unavailable :("
							<< endl << endl;
						SetConsoleTextAttribute(col, 7);
						invalid = false;
						noBook = 'T';
					}
					else if (stringToint(bookList1[i][5]) >
						0) {

						noBook = 'N';
						bookList1[i][5] =
							intTostring(
								stringToint(
									bookList1[i][5]) -
								1);

						if (stringToint(bookList1[i][5])
							== 0) {
							bookList1[i][4] = "N";
						}
						invalid = false;
					}
					break;
				}
				else
					invalid = true;
			}
			if (invalid == true) {
				SetConsoleTextAttribute(col, 4);
				cout << "Oooppss, invalid input :(\nPlease "
					<< "key in a valid input."
					<< endl << endl;
				SetConsoleTextAttribute(col, 7);
			}
		}
		else if (invalid == true) {
			SetConsoleTextAttribute(col, 4);
			cout << "Oooppss, invalid input :(\nPlease key"
				<< " in a valid input." << endl
				<< endl;
			SetConsoleTextAttribute(col, 7);
		}
	} while (invalid == true);

	if (noBook != 'T') {
		cout << endl << endl;
		SetConsoleTextAttribute(col, 11);
		cout << "BORROW SUCCESSFULLY!" << endl;
		cout << "Please remember to return the book in"
			<< " 7 days.\nPlease take good"
			<< " care of the book."
			<< endl << endl;
		SetConsoleTextAttribute(col, 7);

		ifstream inFile;
		inFile.open("LoginId.txt");
		if (inFile.fail()) {
			SetConsoleTextAttribute(col, 4);
			cout << "Error! Error! Unable to open the"
				<< " file.\nPlease have a check."
				<< endl;
			SetConsoleTextAttribute(col, 7);
		}
		else
			inFile >> patronID;
		inFile.close();

		inFile.open("borrowList.txt");
		if (inFile.fail()) {
			lineNo = 0;
		}
		inFile.close();

		ofstream outFile;
		outFile.open("borrowList.txt", ios::app);
		if (lineNo != 0)
			outFile << endl;
		outFile << patronID << " " << BorrowId;
		outFile.close();

		ofstream bookFile;
		bookFile.open("bookList.txt");
		for (int j = 0; j <= count; j++) {
			if (j != 0)
				bookFile << endl;
			bookFile << bookList1[j][0]
				<< endl << bookList1[j][1]
				<< endl << bookList1[j][2];
			bookFile << endl << bookList1[j][3] << " "
				<< bookList1[j][4] << " "
				<< bookList1[j][5] << " "
				<< bookList1[j][6] << " "
				<< bookList1[j][7];
		}
		bookFile.close();
	}
}

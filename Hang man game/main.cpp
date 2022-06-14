#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int random ();
string word (int);
void print_letters (string);
void print_result (string , string);
void print_man (int);
void check_letter (string &word, string);
bool check_lives (string, string);
int win (string , string);

int main(int argc, char** argv) {
	
	bool answer = true;
	
	while (answer)
	{
		int num = random() , blood = 7 , ans;
		string gues , parola = word (num), le;
		system ("CLS");
		while (blood >= 0)
		{
			if (blood == 0)
			{
				print_man (blood);
				cout << "\n\n";
				cout << "the word is : " << parola;
				cout << "\n\nEnterd letters : ";
				print_letters (gues);
				break;
			}
			print_man (blood);
			cout << "\n\n";
			cout << "Guess the word : ";
			print_result (gues , parola);
			cout << "\n\nEnterd letters : ";
			print_letters (gues);
			cout << "\n\nEnter a letter : ";
			cin >> le;
			check_letter (gues , le);
			int numero = win (parola, gues);
			if (numero == parola.length()){
				system ("CLS");
				print_man (blood);
				cout << "\n\n";
				cout << "The word is : ";
				print_result (gues , parola);
				cout << "\n\nEnterd letters : ";
				print_letters (gues);
				break;
			}
			bool lett = check_lives (parola, le);
			if (!lett)
			blood --;
			system ("CLS");
		}
	
		cout << "\n\n";
		if (blood > 0){
			cout << "YOU WON ! Wanna try agaim ? Tap \"1\" to continue or any other key to exit ";
			cin >> ans;
		}
		else {
			cout << "YOU LOST ! Wanna try agaim ? Tap \"1\" to continue or any other key to exit ";
			cin >> ans;
		}
		if (ans == 1)
		answer = true;
		else
		answer = false;
	}
	
	return 0;
}

int random () {
	srand (time(NULL));
	return rand () % 994;
}

string word (int random_number) {
	ifstream file ("words.txt");
	int index = 0;
	string temp;
	
	file >> temp;
	while (index != random_number)
	{
		file >> temp;
		index ++;
	}
	return temp;
}

void print_letters (string guess) {
	for (int x = 0; x < guess.length() ; x ++)
	{
		cout << guess [x] << " ";
	}
}

void print_result (string guess, string word) {
	
	for (int x = 0 ; x < word.size() ; x ++)
	{
		bool con = false;
		for (int y = 0 ; y < guess.size() ; y ++)
		{
			if (word [x] == guess [y])
			con = true;
		}
		if (con)
		cout << word [x] << " ";
		else
		cout << "_ ";
	}
}

bool check_lives (string word, string letter) {
	
	bool right = false;
	
	for (int x = 0 ; x < word.length(); x ++)
	{
		if (letter [0] == word [x])
		right = true;
	}
	
	return right;
} 

void check_letter (string &word, string letter) {
	
	bool ex = false; // ex stabds for exist
	
	for (int x = 0; x < word.length() ; x ++)
	{
		if (letter [0] == word [x])
		ex = true;
	}
	if (!ex)
	word += letter[0];
}

int win (string word, string guess) {
	
	int count = 0;
	
	for (int x = 0; x < word.length(); x ++)
	{
		for (int y = 0; y < guess.length(); y ++)
		{
			if (word [x] == guess[y])
			count ++;
		}
	}
	
	return count;
}

void print_man (int x) {
	switch (x) {
			case 7 :
				cout << "\t____________\n";
				cout << "\t|          |\n";
				cout << "\t|\n";
				cout << "\t|\n";
				cout << "\t|\n";
				cout << "\t|\n";
				cout << "\t|\n";
				break;
			case 6 :
				cout << "\t____________\n";
				cout << "\t|          |\n";
				cout << "\t|          O\n";
				cout << "\t|\n";
				cout << "\t|\n";
				cout << "\t|\n";
				cout << "\t|\n";
				break;
			case 5 :
				cout << "\t____________\n";
				cout << "\t|          |\n";
				cout << "\t|          O\n";
				cout << "\t|          |\n";
				cout << "\t|\n";
				cout << "\t|\n";
				cout << "\t|\n";
				break;
			case 4 :
				cout << "\t____________\n";
				cout << "\t|          |\n";
				cout << "\t|          O\n";
				cout << "\t|          |\n";
				cout << "\t|          |\n";
				cout << "\t|\n";
				cout << "\t|\n";
				break;
			case 3 :
				cout << "\t____________\n";
				cout << "\t|          |\n";
				cout << "\t|          O\n";
				cout << "\t|          |\n";
				cout << "\t|         /|\n";
				cout << "\t|\n";
				cout << "\t|\n";
				break;
			case 2 :
				cout << "\t____________\n";
				cout << "\t|          |\n";
				cout << "\t|          O\n";
				cout << "\t|          |\n";
				cout << "\t|         /|\\\n";
				cout << "\t|\n";
				cout << "\t|\n";
				break;
			case 1 :
				cout << "\t____________\n";
				cout << "\t|          |\n";
				cout << "\t|          O\n";
				cout << "\t|          |\n";
				cout << "\t|         /|\\\n";
				cout << "\t|         /\n";
				cout << "\t|\n";
				break;
			case 0 :
				cout << "\t____________\n";
				cout << "\t|          |\n";
				cout << "\t|          O\n";
				cout << "\t|          |\n";
				cout << "\t|         /|\\\n";
				cout << "\t|         / \\\n";
				cout << "\t|\n";
				break;
	}
}

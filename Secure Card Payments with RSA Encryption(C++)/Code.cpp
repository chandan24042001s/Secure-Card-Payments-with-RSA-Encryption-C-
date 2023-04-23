#include <iostream>
#include <string.h>

#include <stdio.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

using namespace std;

struct user
{
	string user_id;
	string user_name;

	int user_ccn;
	string user_address;
	int user_balance;
	string user_password;
	struct user *next;
} *first = NULL;

void enqueue();
void updation();
void display();
void user_account();

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int check_banker_id(string id)
{
	string check_id;
	int count = 0;
	cin.ignore();
	cout << "ENTER BANKER ID: ";
	getline(cin, check_id);
	if (id.length() == check_id.length())
	{
		for (int i = 0; i < id.length(); i++)
		{
			if (id[i] == check_id[i])
				count++;
			else
				break;
		}

		if (count == id.length())
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

int check_banker_password(string password)
{
	string check_password;
	cout << "Enter 10 digit password: ";
	char a;
	for (int i = 0; i < 10; i++)
	{
		a = getch();
		check_password = check_password + a;
		cout << "*";
	}
	int count = 0;
	if (password.length() == check_password.length())
	{
		for (int i = 0; i < check_password.length(); i++)
		{
			if (password[i] == check_password[i])
				count++;
			else
				break;
		}
		if (count == check_password.length())
			return 1;

		else
			return 0;
	}
	else
		return 0;
}
int main()
{

	string banker_id = "2345";
	char password[11] = "incredible";
	char a;
	string check_password;
	int check; // if k==1 then true else false
	int select;
	while (1)
	{
		cout << "\nselect 1 for banker , 2 for user, 3 for exit: ";
		cin >> select;
		if (select == 1)
		{
			check = check_banker_id(banker_id);
			if (check == 1)
			{
				check = check_banker_password(password);
				if (check == 1)
				{
					system("cls");
					cout << "\t\t\t.	ADMINISTRATOR PAGE	";
					cout << "\n\n";
					while (1)
					{

						cout << "\nChoose from the following option:\n1. add user\n2. update user\n3.view user details\n4. Main Page\n\nENTER THE OPTION: ";
						cin >> select;
						switch (select)
						{
						case 1:
						{  string id, name;
							cout << "	ADD USERS	" << endl;
							cout << "Enter the following details";
							cout << "\nUser Name: ";
							cin.ignore();
							getline(cin, name);
						}
						case 2:
						{
						}
						case 3:
						{
						}
						case 4:
						{
						}
						default:
						{

							cout << "INPUT !!!!!!\nTRY AGAIN";
						}
						}
					}
				}
				else
				{

					enqueue();
					break;

					updation();
					break;

					display();
					break;

					main();

					cout << "\nINVALID";

					cout << "\nWronng Password	\n";
				}
			}
			else
			{
				cout << "\nWrong Banker id	\n";
			}
		}
		else if (select == 2)
		{
			user_account();
		}
		else
			exit(0);
	}
	return 0;
}

void enqueue()
{
	int p, q, n, toitent, c, msg, e, z, k, i, d;
	cout << "enter two large prime numbers(p and q): ";
	cin >> p >> q;
	n = p * q;
	toitent = (p - 1) * (q - 1);
	cout << "select the value of e: ";
	for (i = 1; i < toitent; i++)
	{
		z = gcd(i + 1, toitent);
		if (z == 1)
			cout << i + 1 << " ";
	}

	cout << " ";
	cin >> e;
	string id, name;
	string address, password;
	int ccn, balance = 0;
	system("cls");
	cout << "	ADD USERS	" << endl;
	cout << "Enter the following details";
	cout << "\nUser Name: ";
	cin.ignore();
	getline(cin, name);
	cout << "User id: ";
	// cin.ignore();
	getline(cin, id);
	cout << "Enter ccn: ";
	cin >> ccn;
	cout << "Enter Address: ";
	// cin.ignore();
	getline(cin, address);
	cout << "Create new password(5): ";
	// cin.ignore();
	getline(cin, password);
	cin >> password;
	cout << "enter the initial balance: ";
	cin >> balance;
	struct user *temp;
	temp = (struct user *)malloc(sizeof(struct user));
	// int msg;
	msg = ccn;
	for (int i = 0; i < e; i++)
	{
		k = k * msg;

		k = k % n;
	}
	cout << "\nencrypted ccn: " << ccn;
	cout << "\nencrypted ccn is : " << k << endl;

	temp = new (struct user);
	temp->user_id = id;
	temp->user_name = name;
	temp->user_address = address;
	temp->user_ccn = ccn;
	temp->user_balance = balance;
	temp->user_password = password;
	temp->next = NULL;
	if (first == NULL)
		first = temp;
	else
	{
		struct user *s;
		s=(struct user*)malloc(sizeof(struct user));
		s = new (struct user);
		s = first;
		while (s->next != NULL)
			s = s->next;
		s->next = temp;
	}
}

void display()
{
	struct user *temp;
	temp = (struct user *)malloc(sizeof(struct user));
	if (first == NULL)
		cout << "\nNo records available\n";

	else
	{

		int num;
		cout << "press 1 to see all the records, 2 for specific record: ";
		cin >> num;
		if (num == 1)
		{

			temp = first;
			while (temp != NULL)
			{

				cout << "\nuser id: " << temp->user_id;
				cout << "\nuser_name: " << temp->user_name;
				cout << "\nccn: " << temp->user_ccn;
				cout << "\naddress: " << temp->user_address;
				cout << "\nBalance: " << temp->user_balance;
				cout << "\nPassword: " << temp->user_password;
				cout << "\n\n\n";
				temp = temp->next;
			}
		}

		else if (num == 2)
		{

			int flag = 0;
			string want_id;
			cout << "\nEnter the id: ";
			cin.ignore();
			getline(cin, want_id);
			temp = first;
			while (temp != NULL)
			{

				if (temp->user_id == want_id)
				{
					cout << "\nRECORD FOUND!!!";

					cout << "\nuser id: " << temp->user_id;
					cout << "\nuser_name: " << temp->user_name;
					cout << "\nccn: " << temp->user_ccn;
					cout << "\naddress: " << temp->user_address;
					cout << "\nBalance: " << temp->user_balance;
					cout << "\nPassword: " << temp->user_password;
					cout << endl;
					flag = 1;
					break;
				}
				temp = temp->next;
			}

			if (flag == 0)
				cout << "\nRECORD NOT FOUND\n";
		}
		else
		{

			cout << "Wrong Input, TRY AGAIN!!!";
			display();
		}
	}
}

int check_user_id()
{

	string id;
	struct user *temp;
	temp = new (struct user);
	cout << "Enter the user id : ";
	cin.ignore();
	getline(cin, id);

	int flag = 0;
	return 1;
}

void user_account()
{

	if (first == NULL)
		cout << "\nNo user record!!!" << endl;
	else
	{

		int flag = 0;
		string id;
		struct user *temp;
		temp = new (struct user);
		cout << "\nEnter the user id : ";
		cin.ignore();
		getline(cin, id);
		cin >> id;
		temp = first;
		while (temp != NULL)
		{
			if (temp->user_id == id)
			{

				flag = 1;
				break;
			}

			else
				temp = temp->next;
		}

		if (flag == 0)
			cout << "\nUser id NOT FOUND\n";
		else
		{

			flag = 0;
			string password;
			cout << "\nenter the 5 digit password: ";
			cin.ignore();
			char a;
			for (int i = 0; i < 5; i++)
			{

				a = getch();
				password = password + a;
				cout << "*";
			}
			cin >> password;
			while (temp != NULL)
			{

				if (temp->user_password == password)
				{

					flag = 1;
					break;
				}

				temp = temp->next;
			}
			if (flag == 0)
				cout << "\nInvalid password ";
			else
			{

				cout << "user found";
				cout << "\nuser id : " << temp->user_id;
				cout << "\nuser name: " << temp->user_name;
				cout << "\nuser ccn: " << temp->user_ccn;
				cout << "\nuser address: " << temp->user_address;
				int num;
				cout << "\npress 1 for payment process, 2 for main menu, any number for exit ";
				cin >> num;

				if (num == 1)
				{

					string id;
					cout << "\nenter the crredit card number";
					cin >> id;
					getline(cin, id);
					struct user *target;
					target = new (struct user);
					target = first;
					flag = 0;
					while (target != NULL)
					{
						if (target->user_id == id)
						{

							flag = 1;
							break;
						}

						target = target->next;
					}

					if (flag == 0)
					{

						cout << "\nINVALID credit card NUMBER.";
					}

					else
					{
						int amount;

						cout << "Enter the amount want to pay: ";
						cin >> amount;
						if (amount > temp->user_balance)
							cout << "\nInsufficient balance";
						else
						{

							temp->user_balance -= amount;
							target->user_balance += amount;
						}
					}
				}
			}
		}
	}
}

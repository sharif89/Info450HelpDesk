// helpdeskticket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "string"
#include <ctype.h>
#include <iomanip>
using namespace std;

class Ticket
{
	static int TicketIDGen;
	string issueStatus;
	string statusAnswer;
	int ID;
	char issueType;
	string issuePriority;
	string callerName;
	string description;
	int numUsersImpacted;

public:
	Ticket();
	int getID();
	void CaptureTicket();
	void ShowTicket();
	void CloseTicket();

};

int Ticket::TicketIDGen = 1;

Ticket::Ticket()
{
	issueStatus = "open";
	ID = TicketIDGen;
	TicketIDGen++;
}

int Ticket::getID()
{
	return ID;
}

	void Ticket::CaptureTicket()
	{
		cin.ignore();
		cout << "Enter Caller Name:" << endl;
		getline(cin, callerName);
		cout << "Issue Type? S=Server, A=Application, C=aCcess" << endl;
		cin >> issueType;
		switch (toupper(issueType))
		{
		
		case 'S':
			statusAnswer = "Server";
			break;
		
		case 'A':
			statusAnswer = "Application";
			break;
		
		case 'C':
			statusAnswer = "Access";
			break;

		default:
			cout << "Not valid entry, try again.";
		}
		cin.clear();
		cin.ignore();
		cout << "Description of Issue:" << endl;
		getline(cin, description);
		cout << "Number of users impacted:" << endl;
		cin >> numUsersImpacted;
		
		cin.clear();
		cin.ignore();

		
		
		
		if (numUsersImpacted < 10)
		{
			issuePriority = "low";
		}
		if (numUsersImpacted >= 10 && numUsersImpacted < 50)
		{
			issuePriority = "medium";
		}
		else if (numUsersImpacted >= 50)
		{
			issuePriority = "high";
		}

		cout << "TicketID:" << ID << endl;
	};


	void Ticket::ShowTicket()
	{
		cout << "\n-------------------------\n";
		std::cout << "List of Tickets:\n";
		std::cout << "TicketID:" << setw(2) << ID << endl;
		std::cout << "Type:" << setw(20) << statusAnswer << endl;
		std::cout << "Status:" << setw(16) << issueStatus << endl;
		std::cout << "User's Name:" << setw(15) << callerName << endl;
		std::cout << "Users Impacted:" << setw(6) << numUsersImpacted << endl;
		std::cout << "Priority:" << setw(18) << issuePriority << endl;
		std::cout << "\n-------------------------\n";
	};

	void Ticket::CloseTicket()
	{
		issueStatus = "closed";
		cout << "TicketID: " << ID << " is now "<< issueStatus << endl;
	};









int main()
{
	int newTicket = 0;
	char answer;
	Ticket TicketArray[100];

	cout << "Open Ticket? Y/N" << endl;
	cin >> answer;

	while (answer == 'Y' || answer == 'y')
	{
		TicketArray[newTicket].CaptureTicket();
		newTicket++;
		cout << "Open Ticket? Y/N" << endl;
		cin >> answer;
	}

	for (int i = 0; i < newTicket; i++)
	{
		TicketArray[i].ShowTicket();
	}



	TicketArray[0].CloseTicket();
	cin >> answer;

	return 0;
}


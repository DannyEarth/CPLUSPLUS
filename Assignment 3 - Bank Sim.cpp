bank﻿// BankPrint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;
using namespace std;

#define MAXLINE = 5;

struct node
{
	char person;
	int enterTime = 0;
	int serviceTime = 0;
	int departureTime = 0;
	int event;
	node* next;
};
class Queue
{
	//1st in 1st out
	//Inqueue/Dequeue
private:
	node *head = new node;
	node *tail = new node;
	node *headPtr = head;
public:
	Queue()
	{
		head = NULL;
		tail = NULL;
	}
	void enqueue(char person)
	{
		node *tmp = new node;
		tmp->person = person;
		tmp->next = NULL;
		node *tmp2 = head;
		node *tmp3 = new node;

		if (tmp2 == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			while (tmp2 != NULL)
			{
				tmp3 = tmp2;
				tmp2 = tmp2->next;
			}
			tmp3->next = tmp;
			tail = tmp;
		}
	}
	void enqueue(node* person)
	{
		node *tmp = new node;
		tmp->person = person->person;
		tmp->enterTime = person->enterTime;
		tmp->serviceTime = person->serviceTime;
		tmp->departureTime = person->departureTime;
		tmp->next = NULL;
		node *tmp2 = head;
		node *tmp3 = new node;

		if (tmp2 == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			while (tmp2 != NULL)
			{
				tmp3 = tmp2;
				tmp2 = tmp2->next;
			}
			tmp3->next = tmp;
			tail = tmp;
		}
	}
	int qLength()
	{
		int count = 0;
		node *tmp = new node;
		tmp = head;
		while (tmp != NULL)
		{
			tmp = tmp->next;
			count++;
		}
		return count;
	}
	char operator[] (int i)
	{
		if (qLength() - 1 >= i)
		{
			node* tmp = new node;
			tmp = head;
			for (int j = 0; j < i; j++)
			{
				tmp = tmp->next;
			}
			return tmp->person;
		}
		else
		{
			cout << "Index specified does not exist" << endl;
			return 0;
		}
	}
	void deleteNode(int i)
	{
		node *tmp = new node;
		tmp = head;
		node *tmp2 = new node;
		tmp2 = head->next;
		if (i == 0)//replace head
		{
			head = tmp2;//May cause return issues..
			return;
		}
		for (int j = 0; j < i; j++)//Go to correct Node specified by parameter i
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp2->next = tmp->next;
		if (i == qLength())
		{
			tail = tmp;
		}
	}
	node* dequeue()
	{
		node *tmp = new node;
		if (head == NULL)
		{
			cout << "Queue is empty!" << endl;
			return tmp;
		}
		else
		{
			tmp->person = head->person;
			tmp->enterTime = head->enterTime;
			tmp->serviceTime = head->serviceTime;
			tmp->departureTime = head->departureTime;
			head = head->next;
			if (head == NULL)
			{
				tail = NULL;
			}
			return tmp;
		}
	}
	void printQueue()
	{
		node *tmp = new node;
		tmp = head;
		if (tmp == NULL)
		{
			cout << "Queue is empty!" << endl;
			return;
		}
		while (tmp != NULL)
		{
			cout << tmp->person << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	void printQueueTimes()
	{
		node *tmp = new node;
		tmp = head;
		if (tmp == NULL)
		{
			cout << "Queue is empty!" << endl;
			return;
		}
		while (tmp != NULL)
		{
			cout << tmp->enterTime << " \n";
			cout << tmp->departureTime << " \n";

			tmp = tmp->next;
		}
		cout << endl;
	}
	void printTail()
	{
		if (tail == NULL)
		{
			cout << "Queue is empty!" << endl;
			return;
		}
		cout << tail->person << endl;
	}
	node* getTail()
	{
		return tail;
	}
	node* getFront()
	{
		return head;
	}
	void printHead()
	{
		if (head == NULL)
		{
			cout << "Queue is empty!" << endl;
			return;
		}
		cout << head->person << endl;
	}
};
class Bank
{
private:
	Queue line1;
	Queue line2;
	Queue line3;
	Queue line4;
	Queue events;
	Queue bank;
	int currentTime = 0;
	int deleteEvent = 0;
public:
	void printBank(int version)
	{
		switch (version)
		{
		case 0:
		{
			printf("\n");
			printf("\n");
			printf("\n");
			printf("         _._._                       _._._\n");
			printf("        _|   |_                     _|   |_\n");
			printf("        | ... |_._._._._._._._._._._| ... |\n");
			printf("        | ||| |  o CS311    BANK o  | ||| |\n");
			printf("        | *** |  ***    ***    ***  | *** |\n");
			printf("   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())\n");
			printf("  (())) |     |---------------------|     | (()))\n");
			printf(" (())())| ''' | '''     '''    '''  | ''' | (())())\n");
			printf(" (()))()| ::: |  :::    :::    :::  |[-|-]| (()))()\n");
			printf(" ()))(()||~|~|| |~|~|  |~|~|  |~|~| |     |()))(()\n");
			printf("    ||  ||_|_||_|_|_|__|_|_|__|_|_|_|_____|  ||\n");
		}
		break;
		case 1:
		{
			printf("\n");
			printf("\n");
			printf("\n");
			printf("         _._._                       _._._\n");
			printf("        _|   |_                     _|   |_\n");
			printf("        | ... |_._._._._._._._._._._| ... |\n");
			printf("        | ||| |  o CS311    BANK o  | ||| |\n");
			printf("        | *** |  ***    ***    ***  | *** |\n");
			printf("   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())\n");
			printf("  (())) |     |---------------------|     | (()))\n");
			printf(" (())())| ''' | '''     '''    '''  | ''' | (())())\n");
			printf(" (()))()| ::: |  :::    :::    :::  |[-|-]| (()))()\n");
			printf(" ()))(()||   || |~|~|  |~|~|  |~|~| |     |()))(()\n");
			printf("    ||  ||   ||_|_|_|__|_|_|__|_|_|_|_____|  ||\n");
		}
		break;
		case 2:
		{
			printf("\n");
			printf("\n");
			printf("\n");
			printf("         _._._                       _._._\n");
			printf("        _|   |_                     _|   |_\n");
			printf("        | ... |_._._._._._._._._._._| ... |\n");
			printf("        | ||| |  o CS311    BANK o  | ||| |\n");
			printf("        | *** |  ***    ***    ***  | *** |\n");
			printf("   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())\n");
			printf("  (())) |     |---------------------|     | (()))\n");
			printf(" (())())| ''' | '''     '''    '''  | ''' | (())())\n");
			printf(" (()))()| ::: |  :::    :::    :::  |[-|-]| (()))()\n");
			printf(" ()))(()||~|~|| |   |  |~|~|  |~|~| |     |()))(()\n");
			printf("    ||  ||_|_||_|   |__|_|_|__|_|_|_|_____|  ||\n");
		}
		break;
		case 3:
		{
			printf("\n");
			printf("\n");
			printf("\n");
			printf("         _._._                       _._._\n");
			printf("        _|   |_                     _|   |_\n");
			printf("        | ... |_._._._._._._._._._._| ... |\n");
			printf("        | ||| |  o CS311    BANK o  | ||| |\n");
			printf("        | *** |  ***    ***    ***  | *** |\n");
			printf("   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())\n");
			printf("  (())) |     |---------------------|     | (()))\n");
			printf(" (())())| ''' | '''     '''    '''  | ''' | (())())\n");
			printf(" (()))()| ::: |  :::    :::    :::  |[-|-]| (()))()\n");
			printf(" ()))(()||~|~|| |~|~|  |   |  |~|~| |     |()))(()\n");
			printf("    ||  ||_|_||_|_|_|__|   |__|_|_|_|_____|  ||\n");
		}
		break;
		case 4:
		{
			printf("\n");
			printf("\n");
			printf("\n");
			printf("         _._._                       _._._\n");
			printf("        _|   |_                     _|   |_\n");
			printf("        | ... |_._._._._._._._._._._| ... |\n");
			printf("        | ||| |  o CS311    BANK o  | ||| |\n");
			printf("        | *** |  ***    ***    ***  | *** |\n");
			printf("   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())\n");
			printf("  (())) |     |---------------------|     | (()))\n");
			printf(" (())())| ''' | '''     '''    '''  | ''' | (())())\n");
			printf(" (()))()| ::: |  :::    :::    :::  |[-|-]| (()))()\n");
			printf(" ()))(()||~|~|| |~|~|  |~|~|  |   | |     |()))(()\n");
			printf("    ||  ||_|_||_|_|_|__|_|_|__|   |_|_____|  ||\n");
		}
		break;
		default:
			break;
		}
	}
	void printBankQueue(int version)
	{
		int i = 0;
		int line1Size = line1.qLength();
		int line2Size = line2.qLength();
		int line3Size = line3.qLength();
		int line4Size = line4.qLength();
		printBank(version);
		for (; i < 5; i++)
		{

			if (line1Size > i)
			{
				printf("         | %c |", line1[i]);
			}
			else
			{
				printf("         |   |");
			}
			if (line2Size > i)
			{
				printf("  | %c |", line2[i]);
			}
			else
			{
				printf("  |   |");
			}
			if (line3Size > i)
			{
				printf("  | %c |", line3[i]);
			}
			else
			{
				printf("  |   |");
			}
			if (line4Size > i)
			{
				printf("  | %c |\n", line4[i]);
			}
			else
			{
				printf("  |   |\n");
			}
		}
	}
	node* removePersonLine1()
	{
		return(line1.dequeue());
	}
	node* removePersonLine2()
	{
		return (line2.dequeue());
	}
	node* removePersonLine3()
	{
		return (line3.dequeue());
	}
	node* removePersonLine4()
	{
		return (line4.dequeue());
	}
	node* removePersonBank()
	{
		return (bank.dequeue());
	}
	void addPeopleLine1(char peeps)
	{
		line1.enqueue(peeps);
	}
	void addPeopleLine3(char peeps)
	{
		line3.enqueue(peeps);
	}
	void addPeopleLine4(char peeps)
	{
		line4.enqueue(peeps);
	}
	void addPeopleLine2(char peeps)
	{
		line2.enqueue(peeps);
	}
	void simulateEnter1()
	{
		int line1Size = line1.qLength();
		int line2Size = line2.qLength();
		int line3Size = line3.qLength();
		int line4Size = line4.qLength();

		int num = 0;
		for (; num < (5 - line1Size); num++)
		{
			printBank(0);
			switch (num)
			{
			case 0://1st person is entering the line
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				printf("         | x |"); if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }
				if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }

			}
			break;
			case 1://1 Person is in the list and one is entering - currently shown is a 5 people line.
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				printf("         | x |"); if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }
				if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				if (line1Size > 4) { printf("         |  %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			break;
			case 2:
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				printf("         | x |"); if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }
				if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				if (line1Size > 4) { printf("         | %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			break;
			case 3:
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				printf("         | x |"); if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }
				if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				if (line1Size > 4) { printf("         | %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			break;
			case 4:
			{
				printf("         | x |"); if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }
				if (line4Size > 0) { printf("  | %c |\n", line4[0]); }
				else { printf("  |   |\n"); }

				printf("         |   |"); if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }
				if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				printf("         |   |"); if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }
				if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				printf("         |   |"); if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }
				if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				printf("         |   |"); if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }
				if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			}
			sleep_for(.05s);
			system("CLS");
		}
		addPeopleLine1('x');
		//New
		line1.getTail()->enterTime = currentTime;//This may not be accurate
		//events.dequeue();//Remove the event
		events.deleteNode(deleteEvent);
		//Add Details of Current Person's Service
		line1.getTail()->serviceTime = generateService();
		//line1.getTail()->departureTime = (line1.getTail()->serviceTime + currentTime);
		line1.getTail()->departureTime = calculateDepartureLine1() + line1.getTail()->enterTime;
		//Add the current person's departure event
		events.enqueue('L1');
		events.getTail()->event = 1;
		events.getTail()->enterTime = line1.getTail()->departureTime;
		//Add next persons arrival event
		events.enqueue('A');
		events.getTail()->event = 0;
		events.getTail()->enterTime = (currentTime + generateNextArrival());
		//End New
		printBankQueue(0);
		system("CLS");
		//One solution may be to traverse event queue for next event based on time. Then delete from queue...
	}
	void simulateEnter2()
	{
		int line1Size = line1.qLength();
		int line2Size = line2.qLength();
		int line3Size = line3.qLength();
		int line4Size = line4.qLength();
		int num = 0;
		for (; num < (5 - line2Size); num++)
		{
			printBank(0);
			switch (num)
			{
			case 0://1st person is entering the line
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				if (line1Size > 4) { printf("         | %c |", line1[4]); }
				else { printf("         |   |"); } printf("  | x |");
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }
				if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }

			}
			break;
			case 1://1 Person is in the list and one is entering - currently shown is a 5 people line.
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); } printf("  | x |");
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }
				if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				if (line1Size > 4) { printf("         |  %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			break;
			case 2:
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); } printf("  | x |");
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }
				if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				if (line1Size > 4) { printf("         | %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			break;
			case 3:
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); } printf("  | x |");
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }
				if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				if (line1Size > 4) { printf("         | %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			break;
			case 4:
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); } printf("  | x |");
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }
				if (line4Size > 0) { printf("  | %c |\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }
				if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }


				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }
				if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }


				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }
				if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }


				if (line1Size > 4) { printf("         | %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }
				if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			}
			sleep_for(.05s);
			system("CLS");
		}
		addPeopleLine2('x');
		//New
		line2.getTail()->enterTime = events.getFront()->enterTime;
		//events.dequeue();//Remove the event
		events.deleteNode(deleteEvent);
						 //Add Details of Current Person's Service
		line2.getTail()->serviceTime = generateService();
		//line2.getTail()->departureTime = (line2.getTail()->serviceTime + currentTime);
		line2.getTail()->departureTime = calculateDepartureLine2() + line2.getTail()->enterTime;
		//Add the current person's departure event
		events.enqueue('L2');
		events.getTail()->event = 1;
		events.getTail()->enterTime = line2.getTail()->departureTime;
		//Add next persons arrival event
		events.enqueue('A');
		events.getTail()->event = 0;
		events.getTail()->enterTime = (currentTime + generateNextArrival());
		//End New
		printBankQueue(0);
		system("CLS");
	}
	void simulateEnter3()
	{
		int line1Size = line1.qLength();
		int line2Size = line2.qLength();
		int line3Size = line3.qLength();
		int line4Size = line4.qLength();
		int num = 0;
		for (; num < (5 - line3Size); num++)
		{
			printBank(0);
			switch (num)
			{
			case 0://1st person is entering the line
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				if (line1Size > 4) { printf("         | %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				printf("  | x |");
				if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }

			}
			break;
			case 1://1 Person is in the list and one is entering - currently shown is a 5 people line.
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				printf("  | x |");
				if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				if (line1Size > 4) { printf("         |  %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			break;
			case 2:
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				printf("  | x |");
				if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				if (line1Size > 4) { printf("         | %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			break;
			case 3:
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				printf("  | x |");
				if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				if (line1Size > 4) { printf("         | %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			break;
			case 4:
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				printf("  | x |");
				if (line4Size > 0) { printf("  | %c |\n", line4[0]); }
				else { printf("  |   |\n"); }

				printf("         |   |"); if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }
				if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				printf("         |   |"); if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }
				if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				printf("         |   |"); if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }
				if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				printf("         |   |"); if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }
				if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			}
			sleep_for(.05s);
			system("CLS");
		}
		addPeopleLine3('x');
		//New
		line3.getTail()->enterTime = events.getFront()->enterTime;
		events.deleteNode(deleteEvent);//Remove the event
						 //Add Details of Current Person's Service
		line3.getTail()->serviceTime = generateService();
		//line3.getTail()->departureTime = (line3.getTail()->serviceTime + currentTime);
		line3.getTail()->departureTime = calculateDepartureLine3() + line3.getTail()->enterTime;
		//Add the current person's departure event
		events.enqueue('L3');
		events.getTail()->event = 1;
		events.getTail()->enterTime = line3.getTail()->departureTime;
		//Add next persons arrival event
		events.enqueue('A');
		events.getTail()->event = 0;
		events.getTail()->enterTime = (currentTime + generateNextArrival());
		//End New
		printBankQueue(0);
		system("CLS");
	}
	void simulateEnter4()
	{
		int line1Size = line1.qLength();
		int line2Size = line2.qLength();
		int line3Size = line3.qLength();
		int line4Size = line4.qLength();
		int num = 0;
		for (; num < (5 - line4Size); num++)
		{
			printBank(0);
			switch (num)
			{
			case 0://1st person is entering the line
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				if (line1Size > 4) { printf("         | %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }
				printf("  | x |\n");

			}
			break;
			case 1://1 Person is in the list and one is entering - currently shown is a 5 people line.
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }
				printf("  | x |\n");

				if (line1Size > 4) { printf("         |  %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			break;
			case 2:
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }
				printf("  | x |\n");

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				if (line1Size > 4) { printf("         | %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			break;
			case 3:
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }if (line4Size > 0) { printf("  | %c ||\n", line4[0]); }
				else { printf("  |   |\n"); }

				if (line1Size > 1) { printf("         | %c |", line1[1]); }
				else { printf("         |   |"); }if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }
				printf("  | x |\n");

				if (line1Size > 2) { printf("         | %c |", line1[2]); }
				else { printf("         |   |"); }if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				if (line1Size > 3) { printf("         | %c |", line1[3]); }
				else { printf("         |   |"); }if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				if (line1Size > 4) { printf("         | %c |", line1[4]); }
				else { printf("         |   |"); }if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			break;
			case 4:
			{
				if (line1Size > 0) { printf("         | %c |", line1[0]); }
				else { printf("         |   |"); }if (line2Size > 0) { printf("  | %c |", line2[0]); }
				else { printf("  |   |"); }
				if (line3Size > 0) { printf("  | %c |", line3[0]); }
				else { printf("  |   |"); }
				printf("  | x |\n");

				printf("         |   |"); if (line2Size > 1) { printf("  | %c |", line2[1]); }
				else { printf("  |   |"); }
				if (line3Size > 1) { printf("  | %c |", line3[1]); }
				else { printf("  |   |"); }
				if (line4Size > 1) { printf("  | %c |\n", line4[1]); }
				else { printf("  |   |\n"); }

				printf("         |   |"); if (line2Size > 2) { printf("  | %c |", line2[2]); }
				else { printf("  |   |"); }
				if (line3Size > 2) { printf("  | %c |", line3[2]); }
				else { printf("  |   |"); }
				if (line4Size > 2) { printf("  | %c |\n", line4[2]); }
				else { printf("  |   |\n"); }

				printf("         |   |"); if (line2Size > 3) { printf("  | %c |", line2[3]); }
				else { printf("  |   |"); }
				if (line3Size > 3) { printf("  | %c |", line3[3]); }
				else { printf("  |   |"); }
				if (line4Size > 3) { printf("  | %c |\n", line4[3]); }
				else { printf("  |   |\n"); }

				printf("         |   |"); if (line2Size > 4) { printf("  | %c |", line2[4]); }
				else { printf("  |   |"); }
				if (line3Size > 4) { printf("  | %c |", line3[4]); }
				else { printf("  |   |"); }
				if (line4Size > 4) { printf("  | %c |\n", line4[4]); }
				else { printf("  |   |\n"); }
			}
			}
			sleep_for(.05s);
			system("CLS");
		}
		addPeopleLine4('x');
		//New
		line4.getTail()->enterTime = events.getFront()->enterTime;
		events.deleteNode(deleteEvent);//Remove the event ****Need to delete the current event, might not be the front node...
						 //Add Details of Current Person's Service
		line4.getTail()->serviceTime = generateService();
		//line4.getTail()->departureTime = (line4.getTail()->serviceTime + currentTime);
		line4.getTail()->departureTime = calculateDepartureLine4() + line4.getTail()->enterTime;
		//Add the current person's departure event
		events.enqueue('L4');
		events.getTail()->event = 1;
		events.getTail()->enterTime = line4.getTail()->departureTime;
		//Add next persons arrival event
		events.enqueue('A');
		events.getTail()->event = 0;
		events.getTail()->enterTime = (currentTime + generateNextArrival());
		//End New
		printBankQueue(0);
		system("CLS");
	}
	void enterBankFromLine1()//Dequeus incorrectly sometimes
	{
		printBankQueue(1);
		sleep_for(.05s);
		system("CLS");
		bank.enqueue(removePersonLine1());
		printBankQueue(0);
		sleep_for(.05s);
		system("CLS");
	}
	void enterBankFromLine2()
	{
		printBankQueue(2);
		sleep_for(.05s);
		system("CLS");
		bank.enqueue(removePersonLine2());
		printBankQueue(0);
		sleep_for(.05s);
		system("CLS");
	}
	void enterBankFromLine3()
	{
		printBankQueue(3);
		sleep_for(.05s);
		system("CLS");
		bank.enqueue(removePersonLine3());
		printBankQueue(0);
		sleep_for(.05s);
		system("CLS");
	}
	void enterBankFromLine4()
	{
		printBankQueue(4);
		sleep_for(.05s);
		system("CLS");
		bank.enqueue(removePersonLine4());
		printBankQueue(0);
		sleep_for(.05s);
		system("CLS");
	}
	void simulateExit()
	{
		for (int i = 0; i < 5; i++)
		{
			printf("\n");
			switch (i)
			{
			case 0:
			{
				printf("                       |   |\n");
				printf("                       |   |\n");
				printf("         _._._         |   |         _._._\n");
				printf("        _|   |_        |   |        _|   |_\n");
				printf("        | ... |_._._._.| x |._._._._| ... |\n");
				printf("        | ||| |  o CS311    BANK o  | ||| |\n");
				printf("        | *** |  ***    ***    ***  | *** |\n");
				printf("   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())\n");
				printf("  (())) |     |---------------------|     | (()))\n");
				printf(" (())())| ''' | '''     '''    '''  | ''' | (())())\n");
				printf(" (()))()| ::: |  :::    :::    :::  |[-|-]| (()))()\n");
				printf(" ()))(()||~|~|| |~|~|  |~|~|  |~|~| |     |()))(()\n");
				printf("    ||  ||_|_||_|_|_|__|_|_|__|_|_|_|_____|  ||\n");
			}
			break;
			case 1:
			{
				printf("                       |   |\n");
				printf("                       |   |\n");
				printf("         _._._         |   |         _._._\n");
				printf("        _|   |_        | x |        _|   |_\n");
				printf("        | ... |_._._._.|._.|._._._._| ... |\n");
				printf("        | ||| |  o CS311    BANK o  | ||| |\n");
				printf("        | *** |  ***    ***    ***  | *** |\n");
				printf("   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())\n");
				printf("  (())) |     |---------------------|     | (()))\n");
				printf(" (())())| ''' | '''     '''    '''  | ''' | (())())\n");
				printf(" (()))()| ::: |  :::    :::    :::  |[-|-]| (()))()\n");
				printf(" ()))(()||~|~|| |~|~|  |~|~|  |~|~| |     |()))(()\n");
				printf("    ||  ||_|_||_|_|_|__|_|_|__|_|_|_|_____|  ||\n");
			}
			break;
			case 2:
			{
				printf("                       |   |\n");
				printf("                       |   |\n");
				printf("         _._._         | x |         _._._\n");
				printf("        _|   |_        |   |        _|   |_\n");
				printf("        | ... |_._._._.|._.|._._._._| ... |\n");
				printf("        | ||| |  o CS311    BANK o  | ||| |\n");
				printf("        | *** |  ***    ***    ***  | *** |\n");
				printf("   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())\n");
				printf("  (())) |     |---------------------|     | (()))\n");
				printf(" (())())| ''' | '''     '''    '''  | ''' | (())())\n");
				printf(" (()))()| ::: |  :::    :::    :::  |[-|-]| (()))()\n");
				printf(" ()))(()||~|~|| |~|~|  |~|~|  |~|~| |     |()))(()\n");
				printf("    ||  ||_|_||_|_|_|__|_|_|__|_|_|_|_____|  ||\n");
			}
			break;
			case 3:
			{
				printf("                       |   |\n");
				printf("                       | x |\n");
				printf("         _._._         |   |         _._._\n");
				printf("        _|   |_        |   |        _|   |_\n");
				printf("        | ... |_._._._.|._.|._._._._| ... |\n");
				printf("        | ||| |  o CS311    BANK o  | ||| |\n");
				printf("        | *** |  ***    ***    ***  | *** |\n");
				printf("   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())\n");
				printf("  (())) |     |---------------------|     | (()))\n");
				printf(" (())())| ''' | '''     '''    '''  | ''' | (())())\n");
				printf(" (()))()| ::: |  :::    :::    :::  |[-|-]| (()))()\n");
				printf(" ()))(()||~|~|| |~|~|  |~|~|  |~|~| |     |()))(()\n");
				printf("    ||  ||_|_||_|_|_|__|_|_|__|_|_|_|_____|  ||\n");
			}
			break;
			case 4:
			{
				printf("                       | x |\n");
				printf("                       |   |\n");
				printf("         _._._         |   |         _._._\n");
				printf("        _|   |_        |   |        _|   |_\n");
				printf("        | ... |_._._._.|._.|._._._._| ... |\n");
				printf("        | ||| |  o CS311    BANK o  | ||| |\n");
				printf("        | *** |  ***    ***    ***  | *** |\n");
				printf("   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())\n");
				printf("  (())) |     |---------------------|     | (()))\n");
				printf(" (())())| ''' | '''     '''    '''  | ''' | (())())\n");
				printf(" (()))()| ::: |  :::    :::    :::  |[-|-]| (()))()\n");
				printf(" ()))(()||~|~|| |~|~|  |~|~|  |~|~| |     |()))(()\n");
				printf("    ||  ||_|_||_|_|_|__|_|_|__|_|_|_|_____|  ||\n");
			}
			break;
			case 6:
			{
				printf("                       |   |\n");
				printf("                       |   |\n");
				printf("         _._._         |   |         _._._\n");
				printf("        _|   |_        |   |        _|   |_\n");
				printf("        | ... |_._._._.|._.|._._._._| ... |\n");
				printf("        | ||| |  o CS311    BANK o  | ||| |\n");
				printf("        | *** |  ***    ***    ***  | *** |\n");
				printf("   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())\n");
				printf("  (())) |     |---------------------|     | (()))\n");
				printf(" (())())| ''' | '''     '''    '''  | ''' | (())())\n");
				printf(" (()))()| ::: |  :::    :::    :::  |[-|-]| (()))()\n");
				printf(" ()))(()||~|~|| |~|~|  |~|~|  |~|~| |     |()))(()\n");
				printf("    ||  ||_|_||_|_|_|__|_|_|__|_|_|_|_____|  ||\n");
			}
			break;
			}
			printBankQueue(5);
			sleep_for(.05s);
			system("CLS");
		}
		system("CLS");
	}
	int generateService()
	{
		int generateService = rand() % 30 + 1;
		return generateService;
	}
	int generateNextArrival()
	{
		int nextArrival = rand() % 5 + 1;
		return nextArrival;
	}
	int nextEvent()
	{
		int nextEvent = 0;
		int index = 0;
		int firstEvent = 0;
		node* tmp = new node;
		tmp = events.getFront();
		firstEvent = tmp->enterTime;
		//Find the event that is supposed to happen next
		while (tmp != NULL)
		{
			if (tmp->enterTime < firstEvent)//head event
			{
				nextEvent = index;
				firstEvent = tmp->enterTime;//wrong
			}
			tmp = tmp->next;
			index++;
		}
		//next event should return 0 - 4;
		tmp = events.getFront();
		deleteEvent = nextEvent;
		for (int i = 0; i < nextEvent; i++)
		{
			tmp = tmp->next;
		}
		char logic = tmp->person;
		switch (logic)
		{
		case 'A':
		{
			nextEvent = 0;
		}
		break;
		case '1':
		{
			nextEvent = 1;
		}
		break;
		case '2':
		{
			nextEvent = 2;
		}
		break;
		case '3':
		{
			nextEvent = 3;
		}
		break;
		case '4':
		{
			nextEvent = 4;
		}
		break;
		}
		return nextEvent;
	}
	int smallestLine()
	{
		int l1 = line1.qLength();
		int l2 = line2.qLength();
		int l3 = line3.qLength();
		int l4 = line4.qLength();

		if (l1 <= l2)
		{
			if (l1 <= l3)
			{
				if (l1 <= l4)
				{
					return 1;
				}
			}
		}
		if (l2 <= l1)
		{
			if (l2 <= l3)
			{
				if (l2 <= l4)
				{
					return 2;
				}
			}
		}
		if (l3 <= l1)
		{
			if (l3 <= l2)
			{
				if (l3 <= l4)
				{
					return 3;
				}
			}
		}
		if (l4 <= l1)
		{
			if (l4 <= l3)
			{
				if (l4 <= l2)
				{
					return 4;
				}
			}
		}
		return 0;
	}
	void serviceRemaining()
	{
		while (events.qLength() != 0)
		{
			char currentEvent = events.getFront()->person;
			switch (currentEvent)
			{
			case '1':
			{
				enterBankFromLine1();
				simulateExit();
			}
			break;
			case '2':
			{
				enterBankFromLine2();
				simulateExit();
			}
			break;
			case '3':
			{
				enterBankFromLine3();
				simulateExit();
			}
			break;
			case '4':
			{
				enterBankFromLine4();
				simulateExit();
			}
			break;
			}
			events.deleteNode(0);
		}
	}
	void runOnEvents()
	{
		int currentEvent = nextEvent();
		currentTime = events.getTail()->enterTime;
		switch (currentEvent)//Execute based on event Type
		{
		case 0://Arrival
		{
			switch (smallestLine())//Checks which line to arrive in (shortest)
			{
			case 1:
			{
				simulateEnter1();
			}
			break;
			case 2:
			{
				simulateEnter2();
			}
			break;
			case 3:
			{
				simulateEnter3();
			}
			break;
			case 4:
			{
				simulateEnter4();
			}
			}
		}
		break;
		case 1:
		{
			events.deleteNode(deleteEvent);
			enterBankFromLine1();
			simulateExit();
		}
		break;
		case 2:
		{
			events.deleteNode(deleteEvent);
			enterBankFromLine2();
			simulateExit();
		}
		break;
		case 3:
		{
			events.deleteNode(deleteEvent);
			enterBankFromLine3();
			simulateExit();
		}
		break;
		case 4:
		{
			events.deleteNode(deleteEvent);
			enterBankFromLine4();
			simulateExit();
		}
		break;
		}
	}
	int calculateAverage()
	{
		int averageTime = 0;
		int numPeople = 0;
		node* tmp = new node;
		tmp = bank.getFront();
		while (tmp != NULL)
		{
			averageTime += (tmp->departureTime - tmp->enterTime);
			numPeople++;
			tmp = tmp->next;
		}
		averageTime = averageTime / numPeople;
		cout << "Number of people Serviced: " << numPeople << endl;
		cout << "For an average wait time of:  " << averageTime  << " Minutes" << endl;
		return averageTime;
	}
	int calculateDepartureLine1()
	{
		int serviceTimes = 0;
		node* tmp = new node;
		tmp = line1.getFront();
		while (tmp != NULL)
		{
			serviceTimes += tmp->serviceTime;
			tmp = tmp->next;
		}
		return serviceTimes;
	}
	int calculateDepartureLine2()
	{
		int serviceTimes = 0;
		node* tmp = new node;
		tmp = line2.getFront();
		tmp = tmp->next;
		while (tmp != NULL)
		{
			serviceTimes += tmp->serviceTime;
			tmp = tmp->next;
		}
		return serviceTimes;
	}
	int calculateDepartureLine3()
	{
		int serviceTimes = 0;
		node* tmp = new node;
		tmp = line3.getFront();
		while (tmp != NULL)
		{
			serviceTimes += tmp->serviceTime;
			tmp = tmp->next;
		}
		return serviceTimes;
	}
	int calculateDepartureLine4()
	{
		int serviceTimes = 0;
		node* tmp = new node;
		tmp = line4.getFront();
		while (tmp != NULL)
		{
			serviceTimes += tmp->serviceTime;
			tmp = tmp->next;
		}
		return serviceTimes;
	}
	void runBank(int runTime)
	{
		int totalRunTime = runTime;
		events.enqueue('A');
		events.getFront()->enterTime = 0;
		events.getFront()->event = 0;
		while (currentTime < totalRunTime)
		{
			runOnEvents();
		}
		events.deleteNode(events.qLength()-1);//Removes last arrival event (did not make it before bank closed)
		serviceRemaining();
		calculateAverage();
	}
};

int main()
{
	srand(time(NULL));
	Bank cs331;
	cs331.runBank(480);
	return 0;
}
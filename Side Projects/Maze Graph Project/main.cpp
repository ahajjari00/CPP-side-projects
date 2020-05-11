#include "Graph.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	using namespace AMIR_GRAPH;

	Graph* start = new Graph('A');
	Graph* two = new Graph('B');
	Graph* three = new Graph('C');
	Graph* four = new Graph('D');
	Graph* five = new Graph('E');
	Graph* six = new Graph('F');
	Graph* seven = new Graph('G');
	Graph* eight = new Graph('H');
	Graph* nine = new Graph('I');
	Graph* ten = new Graph('J');
	Graph* eleven = new Graph('K');
	Graph* twelve = new Graph('L');
	Graph* thirteen = new Graph('M');
	Graph* fourteen = new Graph('N');

	start->link_direction(two, 's');

	two->link_direction(three, 'e');

	three->link_direction(four, 'n');

	four->link_direction(five, 'e');

	five->link_direction(twelve, 'e');
	five->link_direction(six, 's');

	six->link_direction(seven, 's');
	six->link_direction(thirteen, 'e');

	seven->link_direction(eight, 'w');
	seven->link_direction(eleven, 's');
	seven->link_direction(six, 'n');

	eight->link_direction(nine, 'w');

	nine->link_direction(ten, 's');

	ten->link_direction(eleven, 'e');

	eleven->link_direction(seven, 'n');

	twelve->link_direction(thirteen, 's');
	twelve->link_direction(five, 'w');

	thirteen->link_direction(fourteen, 's');

	Graph* traverseNode = start;
	char next;
	do
	{
		traverseNode->output_poss_directions();
		cin >> next; // problem at first was that when i was using, cin.get(next), I was not accounting for the '\n'
		/*
		cin.get(next);
		cin.get(next2);
		This would work, cin is much simpler
		*/
		Graph* traverseNode2 = traverseNode->get_node(next);

		if (traverseNode2 == nullptr)
			cout << "Error!\n";

		else
			traverseNode = traverseNode2;

	} while (traverseNode != fourteen);

	cout << "You win!\n";
}
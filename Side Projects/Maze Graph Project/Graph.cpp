#include "Graph.h"
#include <iostream>
#include <string>
using namespace std;

namespace AMIR_GRAPH
{
	Graph::Graph() : letter(' '), north(nullptr), south(nullptr), east(nullptr), west(nullptr)
	{
		// empty
	}

	Graph::Graph(char label) : letter(label), north(nullptr), south(nullptr), east(nullptr), west(nullptr)
	{
		// empty
	}

	void Graph::output_poss_directions()
	{
		string output = "";

		if (north != nullptr)
			output = "North (N), ";
		
		if (south != nullptr)
			output += "South (S), ";

		if (east != nullptr)
			output += "East (E), ";

		if (west != nullptr)
			output += "West (W) ";

		if (output == "")
		{
			cout << letter << " has no possible directions!\n";
			return;
		}

		cout << output << "are your possible directions for the letter " << letter << "\n";
	}

	void Graph::link_direction(Graph* direction, char input_label)
	{
		input_label = toupper(input_label);

		if (input_label == 'N')
			north = direction;

		else if (input_label == 'S')
			south = direction;

		else if (input_label == 'E')
			east = direction;

		else if (input_label == 'W')
			west = direction;

	}

	void Graph::set_letter(char input_letter)
	{
		letter = input_letter;
	}

	
	Graph* Graph::get_node(char input_label)
	{
		input_label = toupper(input_label);

		if (input_label == 'N')
			return north;

		else if (input_label == 'S')
			return south;

		else if (input_label == 'E')
			return east;

		else if (input_label == 'W')
			return west;

		else
			return nullptr;

	} 

	Graph::~Graph()
	{
		delete north;
		delete south;
		delete west;
		delete east;
	}
	
}
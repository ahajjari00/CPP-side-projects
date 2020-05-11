#ifndef GRAPH_H
#define GRAPH_H


namespace AMIR_GRAPH
{
	class Graph
	{
	private:
		Graph* north, * south, * east, * west;
		char letter;

	public:

		// sets letter to space character
		// all graph pointer set to nullptr
		Graph();

		// sets letter to input
		// all graph pointer set to nullptr
		Graph(char label);

		// outputs the possible directions to go from the 
			// Graph pointer passed as argument
		void output_poss_directions();

		// links letter to the specified direction
		void link_direction(Graph* direction, char input_label);

		// sets letter (member variable) with "input_letter"
		void set_letter(char input_letter);

		// sees if next node is a link
		Graph* get_node(char input_label);

		// destructor
		~Graph();


	};
}

#endif
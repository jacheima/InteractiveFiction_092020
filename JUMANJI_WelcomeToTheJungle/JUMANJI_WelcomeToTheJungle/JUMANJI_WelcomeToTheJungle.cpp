/*
Jacquelynne Heiman
09/14/2020
This program is an interactive fiction that allows the users to input values
to customize their experience
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//declare local variable for the number of players
	int numberOfPlayers = 0;

	//declare local variable for the number of players who will be killed
	int killed = 0;

	//variable that holds the calculated number of survivors (numberOfPlayers - killed) after the player sets the preceeding variables
	int survivors = 0;

	//Get input from the player
	cout << "Please enter the following for your personalized adventure\n";

	cout << "Enter a number: ";
	cin >> numberOfPlayers;

	cout << "Enter a number, smaller than the first: ";
	cin >> killed;

	//if the player inputs a number less than 0 or greater than the number 
	//of players it will loop and ask them to try again
	while (killed < 0 || killed > numberOfPlayers)
	{
		cout << "\nInvalid input. Please try again." << endl;

		cout << "Please enter a number that is greater than 0 and smaller than " << numberOfPlayers << "." << endl;
		cin >> killed;
	}

	//calculate the number of survivors by subtracting the number killed from the total number of players
	survivors = numberOfPlayers - killed;

	string playerName;

	cout << "Enter your name: ";
	cin >> playerName;


	//tell the story
	cout << "\nA group of " << numberOfPlayers << " students have been sent to detention. While in detention, they discover a retro video game console.";
	cout << "In the console is a game cartridge called JUMANJI. The " << numberOfPlayers << " turn on the game and are immeadeately sucked into the fantasy world.";

	cout << "\n\nThe group was led by " << playerName << ", a nervous kid who would have to learn to face their fears. The group is met by Nigel, who briefs them on their quest";
	cout << " to save JUMANJI by finding the crystal skull and returning it to its rightful place.";

	cout << "\n\nThe group discovers a kid who had been trapped in the game for 15 years. They adopt him into their group and resolve to beat the game and escape JUMANJI.";
	cout << "The child warns the group that they will face many danagers they may be insurmountable for many of them.";

	cout << "\n\nThe group faces many challenges along the way and " << killed << " adventure(s) are killed on the many trials and tribulations that the adventurers faced. ";
	cout << "Though the adventurers have lost some of their band, their resolve to escape streghtens and they manage to find the skull and escape JUMANJI." << endl;


}





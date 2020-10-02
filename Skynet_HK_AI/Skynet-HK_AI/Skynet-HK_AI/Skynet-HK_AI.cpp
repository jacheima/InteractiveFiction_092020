/*
    Jacquelynne Heiman
    09/26/2020
    Skynet-HK Aeral 2.0 - To show the performance value of using binary 
    search over other search algroiths
*/

#include <iostream>
#include<vector>
#include<random>
#include<iomanip>

//defining so that I can easily access the length of the search grid from 
//anywhere in the file
#define ArrayLength(x) (sizeof(x)/sizeof((x)[0]))

using std::cout;
using std::vector;
using std::cin;
using std::setw;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

//declaration of the BinarySearch function
int BinarySearch(int grid[], int target);

//declaration of the LinearSearch function
int LinearSearch(int grid[], int target);

//declaration of the RandomSearch function
int RandomSearch(int grid[], int target);

int HumanSearch(int grid[], int target);

//the random generator to initiate the random enginge (See note at end)
random_device randomDevice;

//common random engine (see note at end)
mt19937 randomEngine(randomDevice());

//for randomly distibuted ints between two boundries (see note at end)
uniform_int_distribution<int> distribution(1, 64);

char playAgain = 'y';

const short ROWS = 8;
const short COLS = 8;

int main()
{
    //declaring an array to hold the grid
    int searchGrid[64] = {};

    //using a for loop to populate the array with grid locations 1 - 64
    for (int index = 0; index < ArrayLength(searchGrid); index++)
    {
        //in the index locaiton add the index number + 1
        searchGrid[index] = index + 1;
    }

    do
    {
        //the random location of the enemy
        int target = distribution(randomEngine);

        cout << "Welcome to Skynet HK-Aerial\n\n";

        cout << "Generating random enemy location on 8x8 grid....\n";
        cout << "Kynet HK-Aerial Initializing software....\n";


        cout << "\n\n------------------HUMAN SEARCH --------------------------\n\n";
        //The number of guess used by the human search
        int humanFound = HumanSearch(searchGrid, target);

        cout << "\n\n";

        cout << "\n\n-------------------BINARY SEARCH---------------------------\n\n";
        //The number of guess used by the Binary search
        int binaryFound = BinarySearch(searchGrid, target);

        cout << "\n\n";

        cout << "\n\n------------------LINEAR SEARCH-------------------------------\n\n";
        //The number of guess used by the Linear search
        int linearFound = LinearSearch(searchGrid, target);

        cout << "\n\n";

        cout << "\n\n------------------RANDOM SEARCH----------------------------------\n\n";

        //The number of guess used by the random search
        int randomFound = RandomSearch(searchGrid, target);

        cout << "\n\n-----------------------------RESULTS--------------------------------\n\n";

        cout << "All drones have found the enemy.\n";
        cout << "The enemy was hiding at grid loaction " << target << "\n";

        cout << "\n";

        cout << "\nThe Human Player using Human Search took " << humanFound;
        cout << " to find the enemy location at " << target;

        cout << "\n\nThe AI Player using Linear Search took " << linearFound;
        cout << " to find the enemy location at " << target;

        cout << "\n\nThe AI player using Random Search took " << randomFound;
        cout << " to find the enemy locaiton at " << target;

        cout << "\n\nThe AI player using Binary Search took " << binaryFound;
        cout << " to find the enemy location at " << target;

        cout << "\n\n----------------------------------------------------------------------\n\n";

        cout << "\n\nWould you like to play again? (y/n) ";

        cin >> playAgain;

    } while (playAgain != 'n');

    return 0;

}

//This function handles the binary search
int BinarySearch(int grid[], int target)
{

    //the minimum guess
    int min = 0;

    //the maximum guess
    int max = 64;

    int pings = 0;

    //while the min is less than the max
    while (min < max)
    {
        pings++;

        cout << "-------------------------------------------------------\n";
        cout << "Skynet HK -Aerial Radar sending out ping #" << pings << "\n";

        //calculate the guess by finding the middle
        int guess = (int)(min + max) / 2;

        //if the number at the guess index is less than the target
        if (guess < target)
        {
            //set the min to be guess + 1
            min = guess + 1;

            cout << "The target location prediction of " << guess;
            cout << " was lower than the actual enemy location of ";
            cout << target << ".\n";

            cout << "The new minimum is " << min << "\n";
        }

        //if the nuber at the guess indes is greater than the target
        if (guess > target)
        {
            //set the max to be guess - 1
            max = guess - 1;

            cout << "The target location prediction of " << guess;
            cout << " was higer than the actual enemy location of ";
            cout << target << ".\n";

            cout << "The new maximum is " << max << "\n";
        }

        //if the nuber at the guess index is equal to the target
        if (guess == target)
        {
            //we found the target!
            cout << "Enemy was hiding at location #" << guess << "\n";

            cout << "Skynet HK-Aerial Software took " << pings;
            cout << " pings to find the enemy location of a grid size of ";
            cout << "64 locations on an 8 x 8 grid.\n";

            return pings;
;

        }
    }
}

//The function that handles the linear search
int LinearSearch(int grid[], int target)
{
    //initializing the number of guess we've used to 0
    int guess = 0;

    //for loop declaration
    for (; guess < (ROWS * COLS); guess++)
    {
        cout << "---------------------------------------------------\n";
        cout << "Linear search turn #" << guess + 1 << "\n";

        //if our index + 1 is less than the target
        if (guess + 1 < target)
        {
            //The guess was lower than the actual location of the target
            cout << "The target location prediction of " << guess + 1;
            cout << " was lower than the actual enemy location of ";
            cout << target << ".\n";
        }
        //otherwise, if the guess + 1 is greater than the target
        else if (guess + 1 > target)
        {
            //The guess was higher than the actual location of the target
            cout << "The target location prediction of " << guess + 1;
            cout << " was higer than the actual enemy location of ";
            cout << target << ".\n";
        }
        //otherwise, if the guess is equal to the target
        else if (guess + 1 == target)
        {
            //We found the target
            cout << "Enemy was hiding at location #" << guess + 1 << "\n";

            cout << "Linear search took " << guess + 1;
            cout << " pings to find the enemy location of a grid size of ";
            cout << "64 locations on an 8 x 8 grid.\n";

            //retrun the number of guess it took to find the enemy
            return guess + 1;
        }
    }

    
}

//The function that handles the random search
int RandomSearch(int grid[], int target)
{
    //int to hold the random guess
    int guess = 0;

    //int to hold the number of guess the search took
    int pings = 0;

    //while the guess is not the target
    while (guess != target)
    {
        //choose a random number
        guess = distribution(randomEngine);

        //show the use which quess we are on
        cout << "Random Search turn #" << pings + 1 << "\n";

        //increase the number of pings
        pings++;

    }

    //if the guess equals the target
    if (guess == target)
    {
        cout << "Enemy was hiding at location #" << guess << "\n";

        cout << "Linear search took " << pings;
        cout << " pings to find the enemy location of a grid size of ";
        cout << "64 locations on an 8 x 8 grid.\n";
    }

    //return the final guess
    return pings;
}

//The function that handles the human search
int HumanSearch(int grid[], int target)
{
    //int to hold the guess of the human
    int guess = 0;

    //int to hold the number guess we are on
    int pings = 0;

   
    //while the player did not guess the target
    while (guess != target)
    {
        //increase the number of guess we've used
        pings++;
        
        cout << "---------------------------------------------------\n";
        cout << "Human locator turn #" << pings << "\n";
        cout << "Please enter your guess (1-64): ";

        //take the guess from the player and save it in guess
        cin >> guess;

        //if the guess was less than the actual location
        if (guess < target)
        {
            cout << "The target location predicion of " << guess;
            cout << " was lower than the actual location\n";
        }
        
        //if the guess was greater than the actual location
        if (guess > target)
        {
            cout << "The target location predicion of " << guess;
            cout << " was higher than the actual location\n";
        }
    }


    //if the player guessed the location of the target
    if (guess == target)
    {
        //we found the target!
        cout << "Enemy was hiding at location #" << guess << "\n";

        cout << "Human locator took " << pings;
        cout << " pings to find the enemy location of a grid size of ";
        cout << "64 locations on an 8 x 8 grid.\n";
    }

    //return how many guesses the human used
    return pings;
}

/*
    NOTE: I chose to use Mersenne Twister generator combined with random
    device and uniform int distribution to achieve a random number bwtween
    1 and 64.

    random_device: used to ignite the random engine so to speak, it gets the first random
    number in the sequence

    mt19937: this is the engine that runs the formula to create the random number
    sequence

    uniform_int_ditrubution: this allows us to randomly distribute the integers bewtween
    two boundries, or in our case between 1 and 64.
*/
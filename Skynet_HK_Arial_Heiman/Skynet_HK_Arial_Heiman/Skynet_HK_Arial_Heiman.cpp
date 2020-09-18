/*
    Jacquelynne Heiman
    09/18/2020
    Skynet_HK Arial - implement a binary search pattern
*/
#include <iostream>
#include <random>

//defining so that I can easily access the length of the search grid from 
//anywhere in the file
#define ArrayLength(x) (sizeof(x)/sizeof((x)[0]))

using namespace std;

//declaration of the BinarySearch function
int BinarySearch(int grid[], int target);

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

    //the random generator to initiate the random enginge (See note at end)
    random_device randomDevice;

    //common random engine (see note at end)
    mt19937 randomEngine(randomDevice());    

    //for randomly distibuted ints between two boundries (see note at end)
    uniform_int_distribution<int> distribution(1, 64);      

    //the random location of the enemy
    int target = distribution(randomEngine);

    cout << "Welcome to Skynet HK-Aerial" << endl << endl;

    cout << "Generating random enemy location on 8x8 grid...." << endl;
    cout << "The enemy is located at #" << target << " on 8x8 grid with 1-64 sectors." << endl;
    cout << "Kynet HK-Aerial Initializing software...." << endl;

    int found = BinarySearch(searchGrid, target);

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

        cout << "-------------------------------------------------------" << endl;
        cout << "Skynet HK -Aerial Radar sending out ping #" << pings << endl;

        //calculate the guess by finding the middle
        int guess = (int)(min + max) / 2;

        //if the number at the guess index is less than the target
        if (guess < target)
        {
            //set the min to be guess + 1
            min = guess + 1;

            cout << "The target location prediction of " << guess;
            cout << " was lower than the actual enemy location of ";
            cout << target << "." << endl;

            cout << "The new minimum is " << min << endl;
        }

        //if the nuber at the guess indes is greater than the target
        if (guess > target)
        {
            //set the max to be guess - 1
            max = guess - 1;

            cout << "The target location prediction of " << guess;
            cout << " was higer than the actual enemy location of ";
            cout << target << "." << endl;

            cout << "The new maximum is " << max << endl;
        }
        
        //if the nuber at the guess index is equal to the target
        if(guess == target)
        {
            //we found the target!
            cout << "Enemy was hiding at location #" << guess << endl;

            cout << "Skynet HK-Aerial Software took " << pings;
            cout << " pings to find the enemy location of a grid size of ";
            cout << "64 locations on an 8 x 8 grid." << endl;

            return guess;
        }
    }
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
/*
* Name: Mandar Tamhane
* Matriculation Number: 170021792
*/

#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include "HashTable.h"


/* Implement mc_dlog in this file */

ulint random(int min, int max) // random number generator
{
   srand((ulint)time(0)); // seeding the RNG
   return (rand()*rand()) % (min+max-1); // returning the random number within the range
}

ulint orderOfG(ulint g, ulint n) // function to calculate the Order of g
{
    ulint sqrtn = sqrt(n);
    HashTable Ord;

    for(ulint i = sqrtn ; i>=1; i--)
        {
            ulint r = random(0, n-1);
            ulint y = pow(g, r);
            y = y % n;

            if (Ord.getValue(y))
            {
                if(r-Ord.getValue(y) > 0)
                    return r-Ord.getValue(y);

                if(Ord.getValue(y)-r > 0)
                    return Ord.getValue(y)-r;
            }
           
            else Ord.insert(y,r);
        }

    return n-1;
}

ulint mc_dlog(ulint g, ulint a, ulint n) // finding the discrete algorithm
{
    HashTable A, B;

    ulint sqrtn = sqrt(n);

    for(ulint i = sqrtn ; i>=1; i--)
        {
            ulint r = random(0, n-1);
            ulint y = (ulint) (a * pow(g, r));
            y = y % n;

            if(B.getValue(y))
            {
                return B.getValue(y)-r;
            }
            else A.insert(y,r);

            r = random (0, n-1);
            y = (ulint)pow(g,r);
            y = y % n;

            if(A.getValue(y))
            {
                return r-A.getValue(y);
            }
            else B.insert(y,r);
        }

    return 0;
}

int main (int argc, char *argv[]) // main function with command line arguments
{
    if (argc != 4) // checking for the right number of command line arguments
        {
            cout<<"Invalid number of arguments provided"<<endl;
            return 1;
        }

    ulint g = atoi(argv[1]); // converting command line characters to integers
    ulint a = atoi(argv[2]);
    ulint n = atoi(argv[3]);

    if ( g > 2147483647 || a > 2147483647 || n > 2147483647) // checking whether command line arguments are negative
    {
        cout<<"You entered a negative Parameter"<<endl;
        return 1;
    }

    ulint order = orderOfG(g, n);
    ulint temp = mc_dlog(g, a, n);

    ulint x = order % temp; // calculating the solution 'x'

    if (x<0)
        x = order + x; // changing x if negative

    cout<<x<<endl; // printing the solution

    return 0;
}

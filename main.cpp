/*-------------------------------------Info------------------------------------
 *	Name:				Date:			Current Version:
 *	Martin Barcelon		11-15-2017		1.0
 *
 *	Email:
 *	martin.barcelon@stonybrook.edu
 *
 *	Student ID:
 *	110250249
 *
 */
/*-------------------------------Short Description-----------------------------
 *  This program takes the file "power1.dat" which contains a power plant's
 * output power in magawatts for each day in the week for 10 weeks. In other
 * words, the data file contains 7 columns of data (for each day) for 10 rows
 * (10 weeks of data). Each data point if a floating type. The program outputs
 * the day of the week and the power output on which the minimum power output
 * occurred.
 * ----------------------------------------------------------------------------
 */
#include <iostream> //Required for cout.
#include <fstream> //Required for ifstream and file functions.
#include <stdlib.h> //Required for exit().

using namespace std;

//Declare global values
const int NROWS = 10;
const int NCOLS = 7;
const float MAX_POW = 9999.9999;

int main()
{
    //Initialize variables and vector "powerGrid".
    float MIN_POW = MAX_POW;
    float powerGrid[NROWS][NCOLS];

    ifstream power;

    //Open "power1.dat" data file
    power.open("power1.dat");

    //
    if (power.fail()){ //If open failed alert user.
        cerr << "ERROR! : File 'power1.dat' failed to open.";
        exit(1); //End execution of the program.
    }

    //Load all the data float values into the vector "powerGrid".
    for(int i=0;i < NROWS;i++) {
        for (int j=0;j < NCOLS;j++){
            power>>powerGrid[i][j]; //Load value.
            if (powerGrid[i][j] <= MIN_POW) {
                MIN_POW = powerGrid[i][j]; //Find the minimum power.
            }
        }
    }

    //Output the minimum power.
    cout <<"The minimum power output was: " << MIN_POW <<" Megawatts"<<endl;
    cout<<"Which occurred during:\n";
    for(int i=0;i < NROWS;i++) {
        for (int j=0;j < NCOLS;j++){
            if (powerGrid[i][j] == MIN_POW) {
                //Output week and day min occurred
                cout<<"\tWeek "<<i+1<<", day "<<j+1<<endl;
            }
        }
    }

    //Close the file.
    power.close();

    //Prevents shutdown of cmd after program is run.
    cin.get();
    cin.get();

    return 0;
}

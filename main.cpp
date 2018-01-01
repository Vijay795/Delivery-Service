//Name: Vijayagopal Krishnan
//NetID: vxk131830
//Date: 10/06/2015
//Program: Project 2 (Delivery Service)

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <stdio.h>


using namespace std;
//Prototype functions
double getTotalCost(double,double);
double getTotalTimePerShipment(double, int);
bool validateFloat(char []);

// total size for the array
const int SIZE = 40;

int main()
{
 // variables for cost per pound, speed, distances of planets from the sun, delivery planet's gravity factor
 // service code, shipping planet code, delivery planet code, weight of the ship and the array of the number
 double costPerPound;
 int shippingSpeed;
 int shippingDistanceFromSun;
 int deliveryDistanceFromSun;
 double deliveryPlanetGravity;
 char serviceCode;
 char shippingPlanetCode;
 char deliveryPlanetCode;
 double shippingWeight;
 char number [SIZE];

// variables to keep track of total cost of shipping for each planet
 double mercuryCost = 0;
 double venusCost = 0;
 double earthCost = 0;
 double marsCost = 0;
 double jupiterCost = 0;
 double saturnCost = 0;
 double uranusCost = 0;
 double neptuneCost = 0;

 // variables to keep to keep track of total time per shipment
 double mercuryTime = 0;
 double venusTime = 0;
 double earthTime = 0;
 double marsTime = 0;
 double jupiterTime = 0;
 double saturnTime = 0;
 double uranusTime = 0;
 double neptuneTime = 0;

 ifstream file ("shipments.txt");
 if (file.fail()) // checks if shipments.txt exists or not
 cout << "The file you're trying to open/connect does not exist." << endl;
 else
  {
    while(!file.eof())
          {
           file.get(serviceCode);
           switch(serviceCode)
             {
               case 'F':
                costPerPound = 0.25;
                shippingSpeed = 45000;
               break;
               case 'P':
                costPerPound = 0.75;
                shippingSpeed = 95000;
               break;
               case 'E':
                costPerPound = 1.50;
                shippingSpeed = 175000;
                break;
               }
            file.ignore();
            file.get(shippingPlanetCode);
            switch (shippingPlanetCode)
              {
               case 'Y': case 'y':
                shippingDistanceFromSun = 36;
               break;
               case 'V': case 'v':
                shippingDistanceFromSun = 67;
               break;
               case 'E': case 'e':
                shippingDistanceFromSun = 93;
               break;
               case 'M': case 'm':
                shippingDistanceFromSun = 141;
               break;
               case 'J': case 'j':
                shippingDistanceFromSun = 483;
               break;
               case 'S': case 's':
                shippingDistanceFromSun = 886;
               break;
               case 'U': case 'u':
                shippingDistanceFromSun = 1782;
               break;
               case 'N': case 'n':
                shippingDistanceFromSun = 2793;
               break;
              }
            file.ignore();
            file.get(deliveryPlanetCode);
            switch (deliveryPlanetCode)
              {
                case 'Y': case 'y':
                 deliveryDistanceFromSun = 36;
                 deliveryPlanetGravity = 0.27;
                break;
                case 'V': case 'v':
                 deliveryDistanceFromSun = 67;
                 deliveryPlanetGravity = 0.86;
                break;
                case 'E': case 'e':
                 deliveryDistanceFromSun = 93;
                 deliveryPlanetGravity = 1.0;
                break;
                case 'M': case 'm':
                 deliveryDistanceFromSun = 141;
                 deliveryPlanetGravity = 0.37;
                break;
                case 'J': case 'j':
                 deliveryDistanceFromSun = 483;
                 deliveryPlanetGravity = 2.64;
                break;
                case 'S': case 's':
                 deliveryDistanceFromSun = 886;
                 deliveryPlanetGravity = 1.17;
                break;
                case 'U': case 'u':
                 deliveryDistanceFromSun = 1782;
                 deliveryPlanetGravity = 0.92;
                break;
                case 'N': case 'n':
                 deliveryDistanceFromSun = 2793;
                 deliveryPlanetGravity = 1.44;
                break;
               }
            file.ignore();
            file.getline(number,SIZE);
            // validates whether the number is a valid float or not
            if(validateFloat(number))
              {
                shippingWeight = atof(number);
                shippingWeight*= deliveryPlanetGravity;
                int distance = abs(deliveryDistanceFromSun - shippingDistanceFromSun);
                switch (shippingPlanetCode) // checks which shipping planet it is and then calculates the total cost
                                            // and total time per shipment accumulatively
                 {
                  case 'Y': case 'y':
                   mercuryCost+= getTotalCost(costPerPound,shippingWeight);
                   mercuryTime+= getTotalTimePerShipment(distance,shippingSpeed);
                  break;
                  case 'V': case 'v':
                   venusCost+= getTotalCost(costPerPound,shippingWeight);
                   venusTime+= getTotalTimePerShipment(distance,shippingSpeed);
                  break;
                  case 'E': case 'e':
                   earthCost+= getTotalCost(costPerPound,shippingWeight);
                   earthTime+= getTotalTimePerShipment(distance,shippingSpeed);
                  break;
                  case 'M': case 'm':
                   marsCost+= getTotalCost(costPerPound,shippingWeight);
                   marsTime+= getTotalTimePerShipment(distance,shippingSpeed);
                  break;
                  case 'J': case 'j':
                   jupiterCost+= getTotalCost(costPerPound,shippingWeight);
                   jupiterTime+= getTotalTimePerShipment(distance,shippingSpeed);
                  break;
                  case 'S': case 's':
                   saturnCost+= getTotalCost(costPerPound,shippingWeight);
                   saturnTime+= getTotalTimePerShipment(distance,shippingSpeed);
                  break;
                  case 'U': case 'u':
                   uranusCost+= getTotalCost(costPerPound,shippingWeight);
                   uranusTime+= getTotalTimePerShipment(distance,shippingSpeed);
                  break;
                  case 'N': case 'n':
                   neptuneCost+= getTotalCost(costPerPound,shippingWeight);
                   neptuneTime+= getTotalTimePerShipment(distance,shippingSpeed);
                  break;
                }
               }
             else
              file.ignore();
           }
    //Prints out the summary of the shipping planet delivery in a row column format
    cout << "Planet Name  Total Shipping Cost from Planet\tTotal Time for Deliveries \n";
    cout << "Mercury\t\t" << mercuryCost << "\t\t\t\t   " << mercuryTime << endl;
    cout << "Venus\t\t" << venusCost << "\t\t\t\t   " << venusTime << endl;
    cout << "Earth\t\t" << earthCost << "\t\t\t\t   " << earthTime << endl;
    cout << "Mars\t\t" << marsCost << "\t\t\t\t   " << marsTime << endl;
    cout << "Jupiter\t\t" << jupiterCost << "\t\t\t\t   " << jupiterTime << endl;
    cout << "Saturn\t\t" << saturnCost << "\t\t\t\t   " << saturnTime << endl;
    cout << "Uranus\t\t" << uranusCost << "\t\t\t\t   " << uranusTime << endl;
    cout << "Neptune\t\t" << neptuneCost << "\t\t\t\t   " << neptuneTime << endl;
   }
 return 0;
}
// Function calculates the total cost of the product and returns the value
double getTotalCost(double costPerPound, double productWeight)
{
  double totalShippingCost;
  totalShippingCost = costPerPound * productWeight;
  return totalShippingCost;
}

// Function calculates and returns the time per shipment
double getTotalTimePerShipment(double planetDistance, int shippingSpeed)
{
 double totalTimeShipping;
 totalTimeShipping = planetDistance/shippingSpeed;
 return totalTimeShipping;
}
// function takes an array containing a floating point number and checks if it's valid or not
bool validateFloat(char num [])
{
 int count = 1;
 if (!(isdigit(num[0])))
    return false;
 while (num[count] != '\0')
   {
     if(!(isdigit(num[count])))
       {
        if(ispunct(num[count]) && count > 1)
         {
          if(ispunct(num[count-1]))
             return false;
          }
        }
      count++;
    }
 return true;
}

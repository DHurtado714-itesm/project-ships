#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "port.h"
#include "ship.h"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream inputFile;
    ofstream outputFile;

    inputFile.open(argv[1]); // Opern input file
    outputFile.open(argv[2]); // Open Output file

    int case_type; // Read first line of the input file
    
    int container_number_C, ships_number_S, port_number_P, number_events_N; // Line 1 variables
    
    int case_id_port, case_weight; 
    char case_type_container; // Case 1 variables

    int case_total_weight, case_maxNumberOfAllContainers, case_maxNumberOfHeavyContainers, 
    case_maxNumberOfRefrigeratedContainers, case_maxNumberOfLiquidContainers;
    double case_fuelConsumptionPerKM; // Case 2 variables
        
    double case_x, case_y; // Case 3 variables
    
    int case_id_ship, case_id_container; // Case 4 variables

    double case_amount_fuel; // Case 7 variables
    
    inputFile >> container_number_C >> ships_number_S >> port_number_P >> number_events_N; // Read first line, var for vectors

    vector<Container*> Container_0(container_number_C);
    vector<Ship*> Ship_0(ships_number_S);
    vector<Port*> Port_0(port_number_P);

    // Iterators
    int countPort = 0, countContainer = 0, countShip = 0;

    for(int i = 0; i < number_events_N; i++){
        inputFile >> case_type;
        switch (case_type){
        
            case 1: inputFile >> case_id_port >> case_weight >> case_type_container;
                if(case_type_container == 'R'){
                    Container_0[countContainer] = new RefrigeratedContainer(countContainer, case_weight); // Add container to vector
                    Port_0[case_id_port] -> add(Container_0[countContainer]);

                } else if(case_type_container == 'L'){
                    Container_0[countContainer] = new LiquidContainer(countContainer, case_weight); // Add container to vector
                    Port_0[case_id_port] -> add(Container_0[countContainer]);

                } else{
                    if(case_weight <= 3000){
                        Container_0[countContainer] = new LightContainer(countContainer, case_weight); // Add container to vector
                        Port_0[case_id_port] -> add(Container_0[countContainer]);

                    }else{
                        Container_0[countContainer] = new HeavyContainer(countContainer, case_weight); // Add container to vector
                        Port_0[case_id_port] -> add(Container_0[countContainer]);

                    }
                }
                countContainer++;
            break;
            

            case 2: inputFile >> case_id_port >> case_total_weight >> case_maxNumberOfAllContainers >> case_maxNumberOfHeavyContainers >> case_maxNumberOfRefrigeratedContainers >> case_maxNumberOfLiquidContainers >> case_fuelConsumptionPerKM;
                Ship_0[countShip] = new Ship(countShip, Port_0[case_id_port], case_total_weight, case_maxNumberOfAllContainers, case_maxNumberOfHeavyContainers, case_maxNumberOfRefrigeratedContainers, case_maxNumberOfLiquidContainers, case_fuelConsumptionPerKM);
                countShip++;
            break;

            case 3: inputFile >> case_x >> case_y;
                Port_0[countPort] = new Port(countPort, case_x, case_y);
                countPort++;
            break;

            case 4: inputFile >> case_id_ship >> case_id_container;
                Ship_0[case_id_ship] ->load(Container_0[case_id_container]);
            break;

            case 5: inputFile >> case_id_ship >> case_id_container;
                Ship_0[case_id_ship] ->unLoad(Container_0[case_id_container]);
            break;

            case 6: inputFile >> case_id_ship >> case_id_port;
                Ship_0[case_id_ship] -> sailTo(Port_0[case_id_port]);
            break;

            case 7: inputFile >> case_id_ship >> case_amount_fuel;
                Ship_0[case_id_ship] -> reFuel(case_amount_fuel);
            break;
        };
    };
    
    for(Port* case_port:Port_0){
        outputFile << case_port->toString();
    };

    inputFile.close();
    outputFile.close();
    
    return 0;
}
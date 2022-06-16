#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "port.h"
#include "ship.h"
#include "container.h"
#include "simpleship.h"


using namespace std;


int main(int argc, char* argv[]) {
    ifstream inputFile;
    ofstream outputFile;

    if (argc != 3) {
        cout << "usage: " << argv[0] << " input_file output_file\n";
        return -1;
    }

    inputFile.open(argv[1]);
    if (!inputFile.is_open()) {
        cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
        return -1;
    }

    outputFile.open(argv[2]);

    // Read first line of the input file
    string line = "", case_type = "";

    // Line 1 variables
    string number_container = "", number_ships = "", number_ports = "", number_events = "";
    // inputFile >> number_container >> number_ships >> number_ports >> number_events;

    // Case 1 variables
    string case_id_port = "", case_weight = "", case_type_container = "";

    // Case 2 variables
    string case_total_weight = "", case_maxNumberOfAllContainers = "", case_maxNumberOfHeavyContainers = "", 
    case_maxNumberOfRefrigeratedContainers = "", case_maxNumberOfLiquidContainers = "", case_fuelConsumptionPerKM = "";
    
    // Case 3 variables
    string case_x = "", case_y = "";

    // Case 4 variables
    string case_id_ship = "", case_id_container = "";

    // Case 7 variables
    string case_amount_fuel  = "";
    
    getline(inputFile, line);
    cout << "Priemra linea " << line <<"\n";
    while (getline(inputFile, line)) {
        
        cout << line << "\n";
        stringstream readLine(line); // definir variables, es necesario que este vacio?
        readLine >> case_type;

        if(case_type == "1")
        {
            readLine >> case_id_port >> case_weight >> case_type_container;
            outputFile << "1 " << case_id_port << " " << case_weight << " " << case_type_container << "\n";

            // Los tipos válidos son B, R y L. R indica que es un contenedor refrigerado, 
            // mientras que L indica que es un contenedor líquido. Caso espacial es B, el tipo 
            // de contenedor que se creará dependerá del peso del contenedor. Si es peso es
            // menor o igual a 3000, se crea un contenedor ligero; si es mayo, se crea un contenedor pesado. 
            // Toma en cuenta que el identificador del contenedor será el orden de creación. 
            // Por ejemplo, el primer contenedor creado debe tener Id 0 y debe colocarse en la posición 0 del vector.

        } else if (case_type == "2")
        {
            readLine >> case_id_port >> case_total_weight >> case_maxNumberOfAllContainers >> case_maxNumberOfHeavyContainers >> 
            case_maxNumberOfRefrigeratedContainers >> case_maxNumberOfLiquidContainers >> case_fuelConsumptionPerKM;

            outputFile << "2 " << case_id_port << " " << case_total_weight << " " << case_maxNumberOfAllContainers << " " << case_maxNumberOfHeavyContainers << " " 
            << case_maxNumberOfRefrigeratedContainers << " " << case_maxNumberOfLiquidContainers << " " << case_fuelConsumptionPerKM << "\n";

            
        }else if (case_type == "3")
        {
            readLine >> case_x >> case_y;
            outputFile << "3 " << case_x << " " << case_y << "\n";

        }else if (case_type == "4")
        {
            readLine >> case_id_ship >> case_id_container;
            outputFile << "4 " << case_id_ship << " " << case_id_container << "\n";

        }else if (case_type == "5")
        {
            readLine >> case_id_ship >> case_id_container;
            outputFile << "5 " << case_id_ship << " " << case_id_container << "\n";

        }else if (case_type == "6")
        {
            readLine >> case_id_ship >> case_id_port;
            outputFile << "6 " << case_id_ship << " " << case_id_port << "\n";

        }else if (case_type == "7")
        {
            readLine >> case_id_ship >> case_amount_fuel;
            outputFile << "7 " << case_id_ship << " " << case_amount_fuel << "\n";

        } else {
            return 0;
        }
    } return 0;
    




    

    // for(int i = 1; i < number_events; i++){
    //     inputFile >> type_event;

    //     switch (type_event)
    //     {
    //     case 1:

    //     case 2:

    //     case 3:

    //         break;
    //     case 4:

    //         break;
    //     case 5:

    //         break;
    //     case 6:

    //         break;
    //     case 7:

    //         break;
    // }     
    // }

    outputFile << number_events;
    
    inputFile.close();
    outputFile.close();

    
    return 0;
}
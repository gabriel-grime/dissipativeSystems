// Parâmetros definidos no main e passados como argumento para as funções

#include <iostream>
#include <fstream>
#include <math.h>
#include "functions.hpp"

int main()
{
    // ------------------------------------------------------------------------


    // Number of iteractions
    int numberIterations = 1e2;

    double a = 4.;
    double initCondidion = 0.2;

    //mapSolution(numberIterations, initCondidion, a);

    // Diagram parameters of the map
    double ai =  3.829;
    double af =  3.844;

    double param[2] = { ai, af };
    int numParams = 1e4;
    
    //lyapunovDiagram(numberIterations,initCondidion,param,numParams);

    bifurcationDiagram(numberIterations, initCondidion, param, numParams); 
    
    return 0;
}

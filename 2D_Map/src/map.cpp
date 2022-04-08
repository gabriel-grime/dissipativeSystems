// Parâmetros definidos no main e passados como argumento para as funções

#include <iostream>
#include <fstream>
#include <math.h>
#include "functions.hpp"

int main()
{
    // ------------------------------------------------------------------------
    // Parameters of the map
    double ai =  1.0;
    double bi =  0.40;
    // For the bifurcation Diagram
    double af =  4.0;
    double bf =  0.40;



    // Initial conditions of Map
    double x0i = 0.3;
    double y0i =  0.0;
    // For de Grid
    double x0f =  1.5;
    double y0f =  1.5;

    // Parameters of the map plot
    int numberIterations = 1e6;


    double beginInitialConditions[2] = { x0i , y0i };
    double finalInitialConditions[2] = { x0f , y0f };


    double parameters[4] = { ai, bi , af, bf};



    double a = 4.0;
    double x0 = 0.1;
    double y0 = 0.1;
    double initCondidion[2] = {x0, y0};

    mapSolution(numberIterations, initCondidion, parameters);

    //bifurcationDiagram(numberIterations, beginInitialConditions, finalInitialConditions, parameters);
    
    //std::cout << lyapunov(numberIterations, ai, x0i) << '\n';

    lyapunovDiagram(numberIterations,x0i,ai,af,2000);
    
    return 0;
}

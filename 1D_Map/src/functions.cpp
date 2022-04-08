#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "functions.hpp"


// Calcula derivada da função do mapa
double derivMap (double a, double x)
{
    return a*(1. - 2.*x);
}


// Calcula função do mapa
double map (double a, double x)
{
    return a*x*(1. - x);
}


// Calcula expoente de Lyapunov
long double lyapunov (int iterations, double a, double initCondition)
{
    double exponent = 1.0;
    double point = initCondition;

    for (int i = 1; i <= iterations; i++ )
    {
        //std::cout << exponent << '\n';
        exponent = exponent + log(fabs(derivMap(a,point)));
        point = map(a, point);
    }

    exponent = exponent/iterations;
    
    return exponent;
}



void lyapunovDiagram(int iterations, double initCondition, double param[2], int numParam)
{  
    double ai = param[0];
    double af = param[1];
    double a;
    
    std::ofstream myfile ("../data/lyapunov/lyapunov2.dat");

    myfile << std::fixed;
    myfile.precision(10);

    for (int i = 0; i <=numParam; i++)
    {
        a = ai + i*(af - ai)/numParam;
        std::cout << a;
        myfile << std::setw(15) << a << std::setw(30) << lyapunov(iterations,a,initCondition) << '\n';
    }
}




// Iterates the map one time
void mapIteration(double pointBefore, double &pointAfter, double parameter)
{
    double a = parameter;
    pointAfter = map(parameter, pointBefore);
}

void mapSolution(int iterations, double initial, double parameter)
{
    double pointBefore = initial;
    double pointAfter;

    std::ofstream myfile ("../data/cobweb.dat");

    myfile << std::fixed;
    myfile.precision(10);

    myfile << std::setw(15) << pointBefore << '\t' << 0.0 << std::endl;

    for (int i = 1; i <= iterations; i++)
    {
        mapIteration(pointBefore, pointAfter, parameter);

        myfile << std::setw(15) << pointBefore << '\t' << std::setw(15) << pointAfter << std::endl;
        pointBefore = pointAfter;
        myfile << std::setw(15) << pointBefore << '\t' << std::setw(15) << pointBefore << std::endl;
    }
}


void bifurcationDiagram(int iterations, double initial, double parameters[2], int numParams)
{
    double pointBefore = initial;
    double pointAfter;
    
    double ai = parameters[0];
    double af = parameters[1];
    
    double a;

    std::ofstream myfile ("../data/bifurcation/bif1.dat");

    myfile << std::fixed;
    myfile.precision(10);

    for (int j = 0; j <= numParams; j++)
    {
        for (int i = 1; i <= iterations; i++)
        {
            a = ai + j*(af - ai)/numParams;
            mapIteration(pointBefore, pointAfter, a);
            if (i > 50) myfile << std::setw(15) << a << std::setw(15) << pointAfter << std::endl;
            pointBefore = pointAfter;
        }        
        //parameters[0] = a;
    }
    
    myfile.close();    
}









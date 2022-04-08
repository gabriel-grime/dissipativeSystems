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

void lyapunovDiagram(int iterations, double initCondition, double ai, double af, int numParam)
{  
    double a;
    std::ofstream myfile ("../data/lyapunov.dat");

    myfile << std::fixed;
    myfile.precision(10);

    for (int i = 0; i <=numParam; i++)
    {
        a = ai + i*(af - ai)/numParam;
        myfile << std::setw(15) << a << std::setw(30) << lyapunov(iterations,a,initCondition) << '\n';
    }
}


// Iterates the map one time
void mapIteration(double (&pointBefore)[2], double (&pointAfter)[2], double parameters[4])
{
    double a = parameters[0];
    double b  = parameters[1];
    pointAfter[0] = a - pointBefore[0]*pointBefore[0] + b*pointBefore[1];
	pointAfter[1] = pointBefore[0];
}

void mapSolution(int iterations, double (&initial)[2], double parameters[4])
{
    double pointBefore[2] = { initial[0] , initial[1]};
    double pointAfter[2];

    std::ofstream myfile ("../data/map.dat");

    myfile << std::fixed;
    myfile.precision(10);

    myfile << std::setw(15) << pointBefore[0] << "\t" <<  std::setw(15) << pointBefore[1] << std::endl;

    for (int i = 1; i <= iterations; i++)
    {
        mapIteration(pointBefore, pointAfter, parameters);

        myfile << std::setw(15) << pointAfter[0] << "\t" << std::setw(15) << pointAfter[1] << std::endl;

        pointBefore[0] = pointAfter[0];
        pointBefore[1] = pointAfter[1];
    }
}



// Reduce the angle to the first turn in trigonometric circle
double reduceAngle(double (&pointAfter)[2])
{
    double angle;

    angle = pointAfter[0] - floor(pointAfter[0]/1.0);
	if (angle <= 1.0 && angle >= 0.0)
        angle = angle;
	else
	    angle = angle - 1.0;
    return angle;
}

void bifurcationDiagram(int iterations, double (&initial)[2], double (&final)[2], double parameters[4])
{
    double pointBefore[2] = {initial[0],initial[1]};
    double pointAfter[2];
    
    double ai = parameters[0];
    double bi = parameters[1];
    double af = parameters[2];
    double bf = parameters[3];

    double a = ai;

    std::ofstream myfile ("../data/bif.dat");

    myfile << std::fixed;
    myfile.precision(10);

    while (a <= af)
    {
        for (int i = 1; i <= iterations; i++)
        {
            mapIteration(pointBefore, pointAfter, parameters);
            if (i > 500) myfile << std::setw(15) << a << std::setw(15) << pointAfter[0] << std::endl;
            pointBefore[0] = pointAfter[0];
            pointBefore[1] = pointAfter[1];
        }        
        a = a + 0.0001;
        parameters[0] = a;
    }
    
    myfile.close();    
}









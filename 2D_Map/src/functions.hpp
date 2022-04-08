#pragma once

double map(double a, double x);

double derivMap(double a, double x);

long double lyapunov(int iterations, double a, double initCondition);

void lyapunovDiagram(int iterations, double initCondition, double ai, double af, int numParam);

void mapIteration(double (&pointBefore)[2], double (&pointAfter)[2], double parameters[4]);

void mapSolution(int iterations, double (&initial)[2], double parameters[4]);

void bifurcationDiagram(int iterations, double (&initial)[2], double (&final)[2], double parameters[4]);

double reduceAngle(double (&pointAfter)[2]);

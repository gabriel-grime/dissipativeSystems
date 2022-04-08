#pragma once

double map(double a, double x);

double derivMap(double a, double x);

long double lyapunov(int iterations, double a, double initCondition);

void lyapunovDiagram(int iterations, double initCondition, double param[2], int numParam);

void mapIteration(double pointBefore, double &pointAfter, double parameters);

void mapSolution(int iterations, double initial, double parameter);

void bifurcationDiagram(int iterations, double initial, double parameters[2], int numParams);

double reduceAngle(double (&pointAfter)[2]);

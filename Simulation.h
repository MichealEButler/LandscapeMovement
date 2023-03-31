#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <vector>
#include <string>
#include "World.h"
#include "Display.h"
#include "Output.h"
#include "Chunk.h"
#include "Environment.h"

using namespace std;

class Simulation
{
public:
  Simulation();
  ~Simulation();
  void initSimulation();
  void updateSimulation();
  void renderSimulation();
  void cleanSimulation();

private:
  Display * display;
  World * world;
  Environment * environment;
  Chunk ** chunks;

};

#endif

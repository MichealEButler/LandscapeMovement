#include "Simulation.h"
#include <string>

Simulation::Simulation()
{

  cout << endl << "Simulation class agents created " << endl;

}

Simulation::~Simulation()
{
  cout << endl << "Simulation class destroyed! " << endl << endl;
}

void Simulation::initSimulation()
{
  world = new World();
  world->loadWorld("Input/nz7204_DTM_1M.txt");

  environment = new Environment();
  chunks = new Chunk*[100];
  // create the array of chunks and ask each chunk to reference which trees are in their space
  for(int i = 0; i < 100; i++)
  {
    chunks[i] = new Chunk(i+1);
    chunks[i]->storeNeighbours();
  }

  display = new Display();

  display->initDisplay("Test Display",500,0,1000,1000,true);

  cout << endl << "Simulation class agents created " << endl;

  environment->loadDEGD("Input/DEGD.txt");
  //create world
}

void Simulation::updateSimulation()
{
  //run tree commands
}

void Simulation::renderSimulation()
{

  while (display->running())
  {
    display->clearRenderer();
    display->renderDisplay();


    display->updateDisplay();
    display->renderPresent();

    cout << "<---------------------------------------->" << endl << endl;

    display->handleEvents();
  }
}

void Simulation::cleanSimulation()
{
  display->cleanDisplay();

  for(int i = 0; i < 100; i++)
  {
    delete chunks[i];
  }

  delete display;
  delete world;
}

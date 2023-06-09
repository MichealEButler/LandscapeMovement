#ifndef CHUNKS_H
#define CHUNKS_H

#include <string>
#include <fstream>
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "World.h"
#include "Output.h"

using namespace std;

class Chunk
{
public:
  Chunk();
  Chunk(int id);
  ~Chunk();

  void setX1(int x1);
  void setX2(int x2);
  void setY1(int y1);
  void setY2(int y2);

  int getID();
  int getX1();
  int getX2();
  int getY1();
  int getY2();

  void loadChunk(int x1, int x2, int y1, int y2, SDL_Renderer* renderer);
  void renderChunk();
  void storeNeighbours();
  void outNeighbours();

private:
  int _id;
  int _x1;
  int _x2;
  int _y1;
  int _y2;

  Output * output;
  int nChunks[8]; // array holding ID's of neighbouring chunks

};

#endif

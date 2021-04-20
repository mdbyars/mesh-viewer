
#include "mesh.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>;


using namespace std;
using namespace glm;
using namespace agl;
int minx = LONG_MIN;
int miny = LONG_MIN;
int minz = LONG_MIN;
int maxx = LONG_MAX;
int maxy = LONG_MAX;
int maxz = LONG_MAX;
int vertexn = 0;
int polygonn = 0;
vec3 vertices[] = { {}, {}, {} };
vec3 polygons[] = { {}, {}, {} };

Mesh::Mesh() 
{
    int vertexn = 0;
    int polygonn = 0;
    vec3 vertices[] = { {}, {}, {} };
    vec3 polygons[] = { {}, {}, {} };
    int minx = LONG_MIN;
    int miny = LONG_MIN;
    int minz = LONG_MIN;
    int maxx = LONG_MAX;
    int maxy = LONG_MAX;
    int maxz = LONG_MAX;
}

Mesh::~Mesh()
{
  
}

bool Mesh::loadPLY(const std::string& filename)
{
    string line;
    int i = 0;
    int vertexn = 0;
    int polygonn = 0;
    vec3 vertices[] = { {}, {}, {} };
    vec3 polygons[] = { {}, {}, {} };
    int minx = LONG_MIN;
    int miny = LONG_MIN;
    int minz = LONG_MIN;
    int maxx = LONG_MAX;
    int maxy = LONG_MAX;
    int maxz = LONG_MAX;

    ifstream myfile("filename");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (i == 0) {
                if (line != "Ply") {
                    cout << "First line not Ply";
                    myfile.close();
                    return false;
                }
                i++;
            }
            if (i == 1) {
                1 + 1;
            }
            if (i == 2) {
                vertexn = stoi(line.substr(14, line.size() - 1));
                i = i + 3;
            }
            if (i == 3 || i == 4 || i == 5) {
                1 + 1;

            }
            if (i == 6) {
                int polygonn = stoi(line.substr(12, line.size() - 1));
                i = i + 2;
            }
            if (i == 7) {
                if (vertexn == 0) {
                    cout << "vertices not found failure";
                    myfile.close();
                    return false;
                }
                int m = vertexn;
                //HELP HERE ??? hard coded size not working for variable 
                //vec3 vertices = new vec3[vertexn];
                //dynamically create vertices member variable in mesh class pointer 
                //vec3 vertices[myVertices];
                myVertices = new float[vertexn*3];
                vertices[0] = vec3(stoi(line.substr(0, 2)), stoi(line.substr(2, 5)), stoi(line.substr(5, 8)));
                //sscanf(line, "reg ex"); %f 
                //sstream 
                //print to check load cube.ply
                maxx = std::max(maxx, stoi(line.substr(0, 2)));
                maxy = std::max(maxx, stoi(line.substr(2, 5)));
                maxz = std::max(maxx, stoi(line.substr(5, 8)));
                minx = std::min(maxx, stoi(line.substr(0, 2)));
                miny = std::min(maxx, stoi(line.substr(2, 5)));
                minz = std::min(maxx, stoi(line.substr(5, 8)));


            }
            if (i > 7 & i < (7 + vertexn)) {
                vertices[i - 7] = vec3(stoi(line.substr(0, 2)), stoi(line.substr(2, 5)), stoi(line.substr(5, 8)));
                maxx = std::max(maxx, stoi(line.substr(0, 2)));
                maxy = std::max(maxx, stoi(line.substr(2, 5)));
                maxz = std::max(maxx, stoi(line.substr(5, 8)));
                minx = std::min(maxx, stoi(line.substr(0, 2)));
                miny = std::min(maxx, stoi(line.substr(2, 5)));
                minz = std::min(maxx, stoi(line.substr(5, 8)));

            }
            if (i >= vertexn + 7) {

                if (polygonn == 0) {
                    cout << "polygons not found failure";
                    myfile.close();
                    return false;
                }
                int m = polygonn;
                //HELP HERE ???
                vec3 polygons[1000];
                vertices[0] = vec3(stoi(line.substr(2)), stoi(line.substr(4)), stoi(line.substr(6)));
            }
            if (i > 7 & i < (7 + vertexn)) {
                vertices[i - (7 + vertexn)] = vec3(stoi(line.substr(2)), stoi(line.substr(4)), stoi(line.substr(6)));
            }
            i++;
        }
         
    
        myfile.close();
        return true;
    }
    else cout << "Unable to open file";
    return false;

}

glm::vec3 Mesh::getMinBounds() const
{
  return vec3(minx, miny, minz);
}

glm::vec3 Mesh::getMaxBounds() const
{
    //help here ??? had to put it as global 
  return vec3(maxx, maxy, maxz);
}

int Mesh::numVertices() const
{
   return vertexn;
}

int Mesh::numTriangles() const
{
   return polygonn;
}

float* Mesh::positions() const
{
    //help here ??
   return NULL;
}

float* Mesh::normals() const
{
   return NULL;
}

unsigned int* Mesh::indices() const
{
   return NULL;
}


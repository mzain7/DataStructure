#pragma once

#include <queue>
#include <string>
#include <iostream>

class Graph
{
    private:
        class Vertex
        {
            public:
                std::string name;
                Vertex() {}
                Vertex(std::string name): name(name) {}
        };

        Vertex* vertices;
        int** matrix;
        int size;

    public:
        Graph()
        {
            vertices = new Vertex[5];
            matrix = new int*[5];
            for (int i = 0; i < 5; i++)
            {
                matrix[i] = new int[5];
                for (int j = 0; j < 5; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        ~Graph()
        {
            delete[] vertices;
            for (int i = 0; i < 5; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        void addVertex(std::string name)
        {
            vertices[size++].name = name;
        }

        int searchVertex(Vertex *v)
        {
            for (int i = 0; i < size; i++)
            {
                if (vertices[i].name == v->name)
                    return i;
            }
            return -1;
        }

        void insertEdge(Vertex* v1, Vertex* v2, int weight)
        {
            int i = searchVertex(v1);
            int j = searchVertex(v2);
            if (i != -1 && j != -1)
            {
                matrix[i][j] = weight;
                matrix[j][i] = weight;
            }
        }

        Vertex* getAdjacents(Vertex* v)
        {
            int i = searchVertex(v);
            if (i != -1)
            {
                Vertex* adjacents = new Vertex[size];
                int count = 0;
                for (int j = 0; j < size; j++)
                {
                    if (matrix[i][j] != 0)
                        adjacents[count++] = vertices[j];
                }
                return adjacents;
            }
            return nullptr;
        }

        void bfs()
        {
            std::queue<Vertex*> q;
            int* colors = new int[size];
            for (int i = 0; i < size; i++)
            {
                colors[i] = 0;
            }
        }


};
/*
 * Edge.h
 *
 *  Created on: Mar 7, 2022
 *      Author: mao
 */

#ifndef GRAPHS_EDGE_H_
#define GRAPHS_EDGE_H_

//class Edge
//{
//public:
//  int u;
//  int v;
//
//  Edge(int u, int v)
//  {
//    this->u = u;
//    this->v = v;
//  }
//};

class Edge
{
public:
  int u;
  int v;
  int w;

  Edge(int u, int v)
  {
    this->u = u;
    this->v = v;
    this->w = 0;
  }

  Edge(int u, int v, int w)
  {
    this->u = u;
    this->v = v;
    this->w = w;
  }
};


#endif /* GRAPHS_EDGE_H_ */

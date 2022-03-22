/*
 * Tree.h
 *
 *  Created on: Mar 7, 2022
 *      Author: mao
 */

#ifndef GRAPHS_TREE_H_
#define GRAPHS_TREE_H_

#include <vector>
using namespace std;

class Tree
{
public:
	// Construct an empty tree
	Tree()
	{
		root = 0;
	}

	// Construct a tree with root, parent, and searchOrder
	Tree(int root, const vector<int>& parent, const vector<int>& searchOrders)
	{
		this->root = root;
		this->parent = parent;
		this->searchOrders = searchOrders;
	}

	// Return the root of the tree
	int getRoot() const
	{
		return root;
	}

	// Return the parent of vertex v
	int getParent(int v) const
	{
		return parent[v];
	}

	// Return search order
	vector<int> getSearchOrders() const
	{
		return searchOrders;
	}

	// Return number of vertices found
	int getNumberOfVerticesFound() const
	{
		return searchOrders.size();
	}

	// Return the path of vertices from v to the root in a vector
	vector<int> getPath(int v) const
	{
		vector<int> path;

		do
		{
			path.push_back(v);
			v = parent[v];
		}
		while (v != -1);

		return path;
	}

	// Print the whole tree
	void printTree() const
	{
		cout << "Root is: " << root << endl;
		cout << "Edges: ";
		for (unsigned i = 0; i < searchOrders.size(); i++)
		{
			if (parent[searchOrders[i]] != -1)
			{
				// Display an edge
				cout << "(" << parent[searchOrders[i]] << ", " <<
						searchOrders[i] << ") ";
			}
		}
		cout << endl;
	}

private:
	int root; // The root of the tree
	vector<int> parent; // Store the parent of each vertex
	vector<int> searchOrders; // Store the search order
};

#endif /* GRAPHS_TREE_H_ */

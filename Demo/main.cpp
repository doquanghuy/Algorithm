//
//  main.cpp
//  Demo
//
//  Created by Quang Huy on 11/20/18.
//  Copyright © 2018 Techmaster. All rights reserved.
//

#include <iostream>
#include <string>
#include "FileManager.hpp"
#include "Array.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "EvaluateExpression.hpp"
#include "Link.hpp"
#include "DoubleLink.hpp"
#include "Stack+LinkedList.hpp"
#include "Queue+LinkedList.hpp"
#include "Bag+LinkedList.hpp"
#include "UnionFind.hpp"
#include "QuickUnion.hpp"
#include "WeightedUnion.hpp"
#include "SelectionSort.hpp"
#include "InsertionSort.hpp"
#include "MergeSortTopDown.hpp"
#include "MergeSortBottomUp.hpp"
#include "QuickSort.hpp"
#include "QuickSortThreeWays.hpp"
#include "HeapSort.hpp"
#include "MaxPriorityQueue.hpp"
#include "MinPriorityQueue.hpp"
#include "MaxIndexPriorityQueue.hpp"
#include "MinIndexPriorityQueue.hpp"
#include "SequentialSearchST.hpp"
#include "BinarySearchST.hpp"
#include "BinarySearchTree.hpp"
#include "RedBlackTree.hpp"
#include "SeparateChainingHashST.hpp"
#include "LinearProbingHashST.hpp"
#include "Graph.hpp"
#include "DFS.hpp"
#include "BFS.hpp"
#include "UFS.hpp"
#include "DFP.hpp"
#include "BFP.hpp"
#include "DFSConnected.hpp"
#include "UFConnected.hpp"
#include "Cycle.hpp"
#include "TwoColors.hpp"
#include "SymbolGraph.hpp"
#include "DegreesOfSeparation.hpp"
#include "Digraph.hpp"
#include "DirectedDFS.hpp"
#include "DFDirectedPath.hpp"
#include "BFDirectedPath.hpp"
#include "DirectedCycle.hpp"
#include "DFOrder.hpp"
#include "Topological.hpp"
#include "KosarajuSCC.hpp"
#include "TransitiveClosure.hpp"
#include "Edge.hpp"
#include "EdgeWeightedGraph.hpp"
#include "LazyPrimMST.hpp"
#include "EagerPrimMST.hpp"
#include "KruskalPrimMST.hpp"
using namespace std;
int main() {
    string fileName = "/Users/huy/Desktop/Demo/Demo/test.txt";
    StdIn in(fileName);
    EdgeWeightedGraph  edg(in);
    EagerPrimMST lp(edg);
    Iterator<Edge>* iterator = lp.edges() -> iterator();
    while (iterator -> hasNext()) {
        Edge edge = iterator -> next();
        cout << edge.toString() << endl;
    }
    cout << lp.weight() <<endl;
}

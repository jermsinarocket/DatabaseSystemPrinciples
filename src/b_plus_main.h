#ifndef MAIN_H
#define MAIN_H


// uncomment for debug mode
//#define DEBUG 


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

#include "storage.h"
#include "block.h"
#define ERROR -1
#define NUM_ARGS 2
#define MIN_ORDER 3
#define OUTPUT_FILE "output_file.txt"


using namespace std;


// generic node
class Node
{
	protected:
		bool isLeaf;
		vector<float> keys;

	public:
		bool Get_IsLeaf();
		vector<float> Get_Keys();
		virtual void Insert(float key, int value){}
		virtual void Insert(float key, Node* rightChild){}
		virtual void Insert(float key, Node* leftChild, Node* rightChild){}
		virtual void Search(float key){}
		virtual void Search(float key1, float key2){}
		virtual Node* Split(float* keyToParent){}
		virtual vector<Node*> Get_Children(){}
		virtual vector< vector <int> > Get_Values(){}
		virtual Node* Get_Next(){}
};


// internal node
class InternalNode : public Node
{
	private:
		vector<Node*> children;

	public:
		InternalNode();
		void Insert(float key, Node* rightChild);
		void Insert(float key, Node* leftChild, Node* rightChild);
		Node* Split(float* keyToParent);
		vector<Node*> Get_Children();
};


// leaf node
class LeafNode : public Node
{
	private:
		LeafNode* prev;
		LeafNode* next;
		vector< vector <int> > values;

	public:
		LeafNode();
		void Insert(float key, int value);
		Node* Split(float* keyToParent);
		vector< vector <int> > Get_Values();
		Node* Get_Next();
};


// B+ tree
class BPlusTree
{
	private:
		int order;	
		Node* root;
		ofstream outputFile;
		void Search_Path(Node* node, float key, stack<Node*>* path);
		void Destroy(Node* node);
		void Reveal_Tree(Node* node);

	public:
		void Initialize(int m);
		void Insert(float key,  int value);
		void Search(float key,Storage s);
		void Search(float key1, float key2,Storage s);
		void Search_Delete(float key, Storage s);
		void Update_Tree(Storage s,int m);
		void Open_Output_File();
		void Close_Output_File();
		void Print_Tree();
		~BPlusTree();

};


#endif

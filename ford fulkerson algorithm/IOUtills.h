#pragma warning(disable: 4996)

#ifndef __IOUtills_H
#define __IOUtills_H
#define ERROR 1
#define ZERO_EDGES 2

#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<fstream>
#include"Graph.h"
using namespace std;

class IOUtills
{
public:
	static void OpenFile(char* i_MainInput, ifstream& o_File);
	static void GetGraphDetailsFromFile(ifstream& i_InFile, int& i_NumberOfNodes, int& i_NumberOfEdges, int& i_Source, int& i_Sink);
	static void PrintDetails(double i_Flow, Vector<int>& i_Cut_S, Vector<int>& i_Cut_T, int i_IterNumber);
	static void AddEdgesToGraph(ifstream& i_InFile, Graph& i_Graph, int i_NumberOfEdges);
	static void PrintZeroEdgesDitails(int i_NumberOfNodes, int i_Source);

private:
	static void PostfixFileName(char* i_PostFixedname, char* i_ArgumentName, int i_Size);
	static double GetDoubleFromFile(ifstream& i_InFile);
	static int GetIntFromFile(ifstream& i_InFile);
	static void GetEdgeFromFile(ifstream& i_InFile, int& i_Source, int& i_Destenation, double& i_Weight);
};
#endif // !__IOUtills_H
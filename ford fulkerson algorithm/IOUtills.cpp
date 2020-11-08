#include "IOUtills.h"

// open the file named i_FileNane to o_File if exist
void IOUtills::OpenFile(char* i_FileNane, ifstream& o_File)
{
	if (i_FileNane == nullptr)
	{
		cout << "error, input file name not exist" << endl;
		exit(ERROR);
	}

	int fileNameLen = strlen(i_FileNane);
	char* FileName = new char[fileNameLen + 5];
	IOUtills::PostfixFileName(FileName, i_FileNane, fileNameLen);

	if (FileName == nullptr)
	{
		cout << "error, file name not valid" << endl;
		exit(ERROR);
	}

	o_File.open(FileName);
	delete[] FileName;
}

// add ".txt" to file name if needed
void IOUtills::PostfixFileName(char* i_PostFixedname, char* i_ArgumentName, int i_Size)
{

	if (i_ArgumentName[i_Size - 4] != '.' || i_ArgumentName[i_Size - 3] != 't' ||
		i_ArgumentName[i_Size - 2] != 'x' || i_ArgumentName[i_Size - 1] != 't' ||
		i_ArgumentName[i_Size] != '\0') // add .txt if needed
	{
		strcpy(i_PostFixedname, i_ArgumentName);
		strcat(i_PostFixedname, ".txt");
	}
	else
	{
		strcpy(i_PostFixedname, i_ArgumentName);
	}
}

// read double from file
double IOUtills::GetDoubleFromFile(ifstream& i_InFile)
{
	double number;

	try
	{
		i_InFile >> number;
	}
	catch (exception ex)
	{
		cout << "error, file iS not valid" << endl;
		throw ex;
	}

	return number;
}

// read int from file
int IOUtills::GetIntFromFile(ifstream& i_InFile)
{
	double number = GetDoubleFromFile(i_InFile);

	if (number != (int)number)
	{
		throw exception("number is not int exception");
	}

	return number;
}

// read details needed to create graph from file
void IOUtills::GetGraphDetailsFromFile(ifstream& i_InFile, int& i_NumberOfNodes, int& i_NumberOfEdges, int& i_Source, int& i_Sink)
{
	try
	{
		i_NumberOfNodes = IOUtills::GetIntFromFile(i_InFile);
		i_NumberOfEdges = IOUtills::GetIntFromFile(i_InFile);
		i_Source = IOUtills::GetIntFromFile(i_InFile);
		i_Sink = IOUtills::GetIntFromFile(i_InFile);
	}
	catch (exception ex)
	{
		cout << "error reading data from file, expected an integer" << endl;
		throw ex;
	}
}

// add all edges to graph from the file
void IOUtills::AddEdgesToGraph(ifstream& i_InFile, Graph& i_Graph, int i_NumberOfEdges)
{
	int edgeSorce, edgeDestenation;
	double edgeWeight;
	bool valid = true;

	for (int i = 0; i < i_NumberOfEdges; i++)
	{
		IOUtills::GetEdgeFromFile(i_InFile, edgeSorce, edgeDestenation, edgeWeight);
		valid = i_Graph.AddEdge(edgeSorce, edgeDestenation, edgeWeight);

		if (valid == false)
		{
			throw exception("error, file has illegal edge");
		}
	}
}

void IOUtills::PrintZeroEdgesDitails(int i_NumberOfNodes, int i_Source)
{
	cout << "BFS Method:" << endl << "Max flow = 0" << endl << "Min cut : S = " << i_Source << ". T = ";

	for (int i = 1; i <= i_NumberOfNodes; i++)
	{
		if (i != i_Source)
		{
			cout << i;

			if (i != i_NumberOfNodes)
			{
				cout << ",";
			}
			cout << " ";
		}
	}
	cout << endl << "Number of iterations = 0" << endl;

	cout << "Greedy Method:" << endl << "Max flow = 0" << endl << "Min cut : S = " << i_Source << ". T = ";

	for (int i = 1; i <= i_NumberOfNodes; i++)
	{
		if (i != i_Source)
		{
			cout << i;

			if (i != i_NumberOfNodes)
			{
				cout << ",";
			}
			cout << " ";
		}
	}
	cout << endl << "Number of iterations = 0" << endl;
}

// read next edge from file
void IOUtills::GetEdgeFromFile(ifstream& i_InFile, int& i_Source, int& i_Destenation, double& i_Weight)
{
	try
	{
		i_Source = IOUtills::GetIntFromFile(i_InFile);
		i_Destenation = IOUtills::GetIntFromFile(i_InFile);
		i_Weight = IOUtills::GetDoubleFromFile(i_InFile);
	}
	catch (exception ex)
	{
		cout << "error reading data from file, expected an integer" << endl;
		throw ex;
	}
}

// print details wanted of the Ford Fulkerson algorithm
void IOUtills::PrintDetails(double i_Flow, Vector<int>& i_Cut_S, Vector<int>& i_Cut_T, int i_IterNumber)
{
	cout << "Max flow = " << i_Flow << endl;

	cout << "Min cut: S = " << i_Cut_S.GetArr()[0];


	for (int i = 1; i < i_Cut_S.GetCount(); i++)
	{
		cout << ", " << i_Cut_S.GetArr()[i];
	}

	if (i_Cut_T.GetCount() > 0)
	{
		cout << ". T = " << i_Cut_T.GetArr()[0];

		for (int i = 1; i < i_Cut_T.GetCount(); i++)
		{
			cout << ", " << i_Cut_T.GetArr()[i];
		}
	}
	else
	{
		cout << ". T = Empty" << endl;
	}
	cout << endl << "Number of iterations = " << i_IterNumber;
}
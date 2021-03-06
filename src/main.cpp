#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "parser_clpCLP.h"

void read(string,ofstream&,string,int);
//parameters : input file, output stream, path to add, boolean-like int to save the path

int main(int argc, char* argv[])
{
	PARSE_ARGS;
	string save = "";
	int preums = 0;

	/*cout<<"input filename:"<< inputFilename <<endl;
	cout<<"output filename:"<< outputFilename <<endl;*/

	const char* o_for_ostream = outputFilename.c_str();
	ofstream out(o_for_ostream);

	read(inputFilename,out,save,preums);
	return EXIT_SUCCESS;
}

/*
int main()
{
	string save = "";
	int preums = 0;
	
	//asking the user
	string i_file;
	string o_file;
	cout<<"name OR relative path OR absolute path of the input file :"<<endl;
	cin>> i_file ;
	cout<<endl;
	cout<<"name OR relative path OR absolute path of the output file :"<<endl;
	cin>> o_file ;
	cout<<endl;
	
	//building out stream
	const char* o_for_ostream = o_file.c_str();
	ofstream out(o_for_ostream);
	
	read(i_file, out,save,preums);
	out.close();
	return 0;
}
*/

void read(string i_file, ofstream& out, string save,int preums)
{
	
	out << '\n';
	out << "########################################## " << endl ;
	out << "#INCLUDED FILE : " << i_file << endl;
	out << "########################################## " << endl ;
	out << '\n';
	
	
	string path;
	
	// DEALING WITH THE PATHS
	
	size_t found_1 = i_file.find_first_of("/\\");
	/*if(int(found_1)==0) //for an absolute path, deletes the first slash and treats it like a relative one
	{
		i_file.erase(0,1);
}*/
	
	if ((found_1!=string::npos) && (preums == 0)) //get the path of the input file. the parameter preums makes sure it is not done if a file to include is in a directory
	{
		size_t founds;
	//cout << "Splitting: " << i_file << endl;
		founds=i_file.find_last_of("/\\");
	//cout << " slash repere a  : " <<int(founds)<< endl;
	//cout << " folder: " << i_file.substr(0,founds) << endl;
		path = i_file.substr(0,founds);
	//cout << " path: " << path << endl;
		save = path;
		preums = 1;
	}
	
	else //gives the whole path
	{
		path = save;
		//cout << " path: " << path << endl;
		path += "/";
		path +=  i_file;
		//cout << " test: " << path << endl;
		i_file.assign(path);
	}
	
	// READING FILES
	cout << "i_file : " << i_file << endl;
	ifstream in(i_file.c_str());
	
	if(in.is_open())
	{
		while(in.good())
		{
			size_t found,foundd,foundop,foundcp;
			string line;
			getline(in, line);
			found = line.find("include");
			foundd = line.find("#");
			foundop = line.find("(");
			foundcp = line.find(")");
			
			if(foundd!=string::npos)//diese: on fait rien
			{}
			
			else if((found!=string::npos) && (foundd==string::npos) && (foundop!=string::npos) && (foundcp!=string::npos))
			{
				int size = int(foundcp) - int(foundop);
				char buffer[size];
				size_t l;
				l=line.copy(buffer,size-3,int(foundop)+2);
				buffer[l]='\0';string mot;
				mot.assign(buffer);
				read(mot,out,save,preums);
			}
			
			else 
			{

				out << line;
				out << '\n';
				//cout << line << endl;
			}
		}
		
	out << '\n';
	out << "########################################## " << endl ;
	out << "#END OF FILE : " << i_file << endl;
	out << "########################################## " << endl ;
	out << '\n';
	
		in.close();
	}
	else cout << "Couldn't open file" << endl;
	
}

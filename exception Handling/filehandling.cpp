#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class FileReadException : public runtime_error
{
    public:
    FileReadException(const string &msg) : runtime_error(msg)
    {};
};

vector<string> readFileLines(const string& filename) 
{
    ifstream file(filename);
    vector<string> content;
    string line;

    if (!file.is_open())
    {
        throw FileReadException("Error: Cannot open file '" + filename + "'");
    }
    else 
    {
        while (getline(file, line)) 
        {  // Read line by line
            content.push_back(line);
        }
    }
    return content;
}

int main() 
{
    try 
    {
        vector<string> result = readFileLines("sample.txt");
        for (auto line : result)
        {
            cout << line << endl;
        }
    } 
    catch (const FileReadException& e) 
    {
        cerr << "Exception caught: " << e.what() << endl;
    }
}
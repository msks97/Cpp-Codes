#include <iostream>
using namespace std;

void solve(int disk, char source, char middle, char destination )
{
    if (disk == 0)
    {
        cout<<"Plate "<<disk<<" from "<<source<<" to "<<destination<<endl;
        return;
    }

    solve(disk-1, source, destination, middle);
    cout<<"Plate "<<disk<<" from "<<source<<" to "<<destination<<endl;
    solve(disk-1, middle, source, destination);



}
int main()
{
    solve(4, 'A', 'B', 'C');
    return 0;
}
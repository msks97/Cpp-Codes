#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

/*
// EXAMPLE 2: With loop

std::recursive_mutex m1;

int main() {
	
	for(int i=0; i<5; i++) {
		m1.lock();
		std::cout << "locked " << i << endl;
	}

	for(int i=0; i<5; i++) {
		m1.unlock();
		std::cout << "ulocked " << i << endl;
	}
	
	return 0;
}
    
*/

recursive_mutex m;
int buffer =0;

void recursion(int num, int i)
{
    if(i<0)
        return;

    m.lock();
    cout<<num<<" "<<buffer++<<endl;
    recursion(num, --i);
    m.unlock();
   
}

int main()
{
    thread t1(recursion, 1, 10);
    thread t2(recursion, 2, 10);

    t1.join();
    t2.join();

    return 0;

}
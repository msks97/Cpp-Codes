#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int> deck;

    deck.push_front(2);
    deck.push_front(1);
    deck.push_front(0);

    cout<<"\n1st Print: ";
    for(int i : deck)
    {
        cout<<i<<" ";
    }

    deck.push_back(3);
    deck.push_back(4);
    deck.push_back(5);

    cout<<"\n2nd Print: ";
    for(int i : deck)
    {
        cout<<i<<" ";
    }

    deck.pop_back();
    deck.pop_front();

    cout<<"\n3rd Print: ";
    for(int i : deck)
    {
        cout<<i<<" ";
    }



}
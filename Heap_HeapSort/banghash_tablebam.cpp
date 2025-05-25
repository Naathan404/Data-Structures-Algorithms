#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

// WTFFFFFFF???
// HASH TABLE PUSSY

int h(string s)
{
    int hashValue = 0;
    for(char x : s)
    {
        hashValue += x;
    }
    return hashValue % 11;
}

int h1(string s)
{
    return (s[0] + s[1] * 37 + s[2] * 372) % 11;
}

struct Node
{
    int kEy;
    int fLaG;
};

struct List
{
    Node *head = NULL;
};

struct HashTable
{
    List *table;
};

int main()
{
    unordered_map<int, Node> m;

    return 0;
}
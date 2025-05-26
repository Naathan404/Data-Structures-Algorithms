#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

#define MAXTABLESIZE 10000
const int TableSize = 10000;

#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct USER {
	string username;
	vector<string> password;
};

struct NODE
{
    USER key;
    int flag;
};

struct HASHTABLE
{
    int M, n;
    NODE* table;
};

// int toInt(string s)
// {
//     int res = 0;
//     for(int i = 0; i < s.length(); i++)
//     {
//         res += s[i] * pow(37, i);
//     }
//     return res;
// }

int HF(HASHTABLE H, string username) {
    int s = 0;
    for (int i = 0; i < username.length(); i++)
        s += 37 * username[i] + i;
    return s % H.M;
}


int HF_LinearProbing(HASHTABLE H, string username, int i)
{
    int h = HF(H, username);
    return (h + i) % H.M;
}

bool Insert(HASHTABLE& H, string username, string password)
{
    if(((float)H.n + 1) / H.M > 0.99) return false;
    int i = 0; 
    int pos = HF(H, username);
    while(i < H.M)
    {
        if(H.table[pos].flag == EMPTY || H.table[pos].flag == DELETED)
        {
            H.table[pos].key.username = username;
            H.table[pos].key.password.push_back(password);
            H.table[pos].flag = OCCUPIED;
            H.n++;
            return true;
        }
        if(H.table[pos].flag == OCCUPIED && H.table[pos].key.username == username)
        {
            H.table[pos].key.password.push_back(password);
            return true;
        }
        
        i++;
        pos = HF_LinearProbing(H, username, i);
    }
    return false;
}

void CreateHash(HASHTABLE& H, int n)
{
    H.table = new NODE[n];
    H.M = n;
    for(int i = 0; i < n; i++)
    {
        H.table[i].flag = EMPTY;
    }
    int i = 0;
    string username, password;
    while(i < n)
    {
        cin >> username >> password;
        Insert(H, username, password);
        i++;
    }   
}

void Search(HASHTABLE H, string username)
{
    int pos = HF(H, username);
    int i = 0;
    while(i < H.M)
    {
        if(H.table[pos].flag == EMPTY)
        {
            cout << "Unregistered User." << endl;
            return;
        }
        if(H.table[pos].flag == OCCUPIED && H.table[pos].key.username == username)
        {
            cout << H.table[pos].key.password[H.table[pos].key.password.size() - 1] << endl;
            return;
        }
        i++;
        pos = HF_LinearProbing(H, username, i);
    }
    cout << "Unregistered User." << endl;
}

void OutPassword(HASHTABLE H, int m)
{
    int i = 0; 
    string username;
    while(i < m)
    {
        cin >> username;
        Search(H, username);
        i++;
    }
}


void DeleteHashtable(HASHTABLE &ht) 
{
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;
}



int main() {
	HASHTABLE H;
	int n, m;
	cin >> n >> m;

	CreateHash(H, n);
	OutPassword(H, m);

	return 0;
}



#include <iostream>
using namespace std;

void sort(string &s)
{
    for(int i = 0; i < s.length() - 1; ++i)
    {
        for(int j = i+1; j < s.length(); ++j)
        {
            if(s[i] > s[j])
                swap(s[i], s[j]);
        }
    }
}

int main(){

      string s;

      cin >> s;

      sort(s);

      cout << s;

}
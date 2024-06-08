#include <bits/stdc++.h>

using namespace std;

string s;

vector<bool> check(10, false);

string temp;
set<string> elle;
void createAll()
{
    if (temp.length() == s.length())
    {
        elle.insert(temp);
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (check[i])
            continue;
        check[i] = true;
        temp.push_back(s[i]);
        createAll();
        temp.pop_back();

        check[i] = false;
    }
}

int main()
{

    cin >> s;
    createAll();
    cout<<elle.size()<<endl;
    for(auto c: elle)
    {
        cout<<c<<endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int solve(string A) {
    int n = A.size();
    int to_change = n-1,found = false;
    for (int i = 0; i <= n-1; ++i)
    {
    	string B = A.substr(0,n-i);
    	// cout<<B<<" "<<string(B.rbegin(),B.rend())<<endl;
     	if(B == string(B.rbegin(),B.rend()))
		{
			return i;
		}
    	
    }
    return n-1;
}

int main()
{
	string a;
	cin>>a;
	cout<<solve(a);
}

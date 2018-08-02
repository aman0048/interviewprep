#include <iostream>
using namespace std;

string findlongest(string A){
	int n  = A.size();
	string ans = A.substr(0,1);
	for (int i = 1; i < n; ++i)
	{
		int start = i-1;
		int end = i+1;
		int len = 1;
		while(start>=0 && end< n)
		{
			if(A[start]==A[end])
			{
				len = len+2;
				start--;
				end++;
			}
			else
				break;
		}
		if(ans.size()<len)
		{
			ans = A.substr((i-(len/2)),len);
			// cout<<i<<" "<<len<<" "<<ans<<" ";
		}
		
		start = i-1;
		end = i;
		len = 0;
		while(start>=0 && end<n)
		{
			if(A[start]==A[end])
			{
				len = len+2;
				start--;
				end++;
				// cout<<i<<" ";
			}
			else
				break;
		}
		if(ans.size()<len)
		{
			ans = A.substr((i-(len/2)),len);
			// int
			// cout<<i<<" "<<len<<" "<<i-(len/2)<<" "<<(i+(len/2)-1)<<" "<<A.substr((i-(len/2)),(i+(len/2)-1))<<" ";
		}
	}
	return ans;
}

int main(){
	string A = "caccbcbaabacabaccacaaccaccaaccbbcbcbbaacabccbcccbbacbbacbccaccaacaccbbcc";
	cout<<findlongest(A);
}
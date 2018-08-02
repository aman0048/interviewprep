#include <bits/stdc++.h>
using namespace std;

int dp[200][200];

bool findlongestpalindrome(string s,int start,int end){
	if(start == end)
		return true;
	else if(start>end)
	{
		return true;
	}
	else if(dp[start][end] != -1){
		return dp[start][end];
	}

	else 
	{
		if(findlongestpalindrome(s,start+1,end-1))
		{
			if(s[start]==s[end])
			{
				dp[start][end] = 1;
				return true;
			}
			else
			{
				dp[start][end] = 0;
				return false;
			}
		}
		else if(findlongestpalindrome(s,start,end-1))
		{
			if(s[start]==s[end])
			{
				dp[start][end] = 1;
				return true;
			}
			else
			{
				dp[start][end] = 0;
				return false;
			}
		}

	}
}


int main(){
	memset(dp,-1,sizeof(dp));
	string s = "caccbcbaabacabaccacaaccaccaaccbbcbcbbaacabccbcccbbacbbacbccaccaacaccbbcc";
	int n = s.size();

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			findlongestpalindrome(s,i,j);
		}
		// cout<<endl;
	}

	string ans = "";

	for(int i = 0;i<n;i++)
	{
		for(int j = i;j<n;j++)
		{
			if(dp[i][j]==1)
			{
				if((j-i) > ans.size())
				{
					ans  = s.substr(i,j);
				}
			}

		}
	}
	cout<< ans;

}
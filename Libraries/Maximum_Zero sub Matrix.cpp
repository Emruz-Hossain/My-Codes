//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<iomanip>
#include<ctime>
#include<stack>
using namespace std;
int main()
{
int n, m,k;
cin >> n >> m;
vector < vector<int> > a (n, vector<int> (m));
for (int i=0; i<n; ++i)
	for (int j=0; j<m; ++j)
		cin >> a[i][j];

int ans = 0;
vector<int> d (m, -1), d1 (m), d2 (m);
stack<int> st;
for (int i=0; i<n; ++i)
    {
	for (int j=0; j<m; ++j)
		if (a[i][j] == 1)
			d[j] = i;
    cout<<"d=  ";
    for(k=0;k<m;k++)
        cout<<d[k]<<" ";
    cout<<endl;
	while (!st.empty()) st.pop();
	for (int j=0; j<m; ++j)
	{
		while (!st.empty() && d[st.top()] <= d[j])  st.pop();
		d1[j] = st.empty() ? -1 : st.top();
		st.push (j);
	}
	cout<<"d1=  ";
	for(k=0;k<m;k++)
        cout<<d1[k]<<" ";
    cout<<endl;
	while (!st.empty()) st.pop();
	for (int j=m-1; j>=0; --j)
	{
		while (!st.empty() && d[st.top()] <= d[j])  st.pop();
		d2[j] = st.empty() ? m : st.top();
		st.push (j);
	}
	cout<<"d2=  ";
	for(k=0;k<m;k++)
        cout<<d2[k]<<" ";
    cout<<endl;
	for (int j=0; j<m; ++j)
		ans = max (ans, (i - d[j]) * (d2[j] - d1[j] - 1));
}
cout << ans;
return 0;
}

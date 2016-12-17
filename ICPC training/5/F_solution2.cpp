#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define F cin
#define G cout

const int Nmax = 1010;

int N,A[Nmax],B[Nmax],p[Nmax],C[Nmax];
vector<int> swap1,swap2,swaps;
vector< pair<int,int> > cycle;

bool cmp(int a,int b)
{
    return A[a] < A[b];
}

int main()
{
    F>>N;
    for (int i=1;i<=N;++i)
    {
        F>>A[i];
        p[i] = i;
    }
    sort(p+1,p+N+1,cmp);
    for (int i=1;i<=N;++i)
    {
        B[p[i]] = A[p[i]];
        A[p[i]] = i;
    }
    bool ok = 1;
    for (int i=1;i<=N && ok;++i)
        if ( i != p[i] )
            ok = 0;
    if ( ok )
    {
        G<<"0\n";
        return 0;
    }
    for (int i=1;i<=N;++i)
        if ( A[i] != i )
        {
            swap( A[i],A[p[i]] );
            if ( B[i] != B[p[i]] )
            {
                swaps.push_back(i);
                swaps.push_back(p[i]);
                C[i]++;
                C[p[i]]++;
            }
        }
    ok = 1;
    for (int i=1;i<=N;++i)
        if ( C[i] > 1 )
            ok = 0;
    if ( ok )
    {
        G<<"1\n";
        G<<swaps.size()/2;
        for (size_t i=0;i<swaps.size();++i)
            G<<' '<<swaps[i];
        G<<'\n';
        return 0;
    }
    for (int i=1;i<=N;++i)
    {
        A[p[i]] = i;
        C[i] = 0;
    }
    for (int i=1;i<=N;++i)
    {
        int now = i;
        while ( C[now] == 0 )
        {
            cycle.push_back( make_pair(now,A[now]) );
            C[now] = 1;
            now = A[now];
        }
        if ( cycle.size() == 2 )
        {
            swap1.push_back( cycle.back().first );
            cycle.pop_back();
            swap1.push_back( cycle.back().first );
            cycle.pop_back();
        }
        if ( cycle.size() > 2 )
        {
            for (size_t i=1,j=int(cycle.size())-1;i<j;++i,--j)
            {
                swap1.push_back( cycle[i].first );
                swap1.push_back( cycle[j].first );
                swap(cycle[i].second,cycle[j].second);
            }
            for (size_t i=0;i<cycle.size();++i)
                if ( cycle[i].first != cycle[i].second )
                {
                    int j = 0;
                    for (size_t jj=0;jj<cycle.size();++jj)
                        if ( cycle[i].second == cycle[jj].first )
                            j = jj;
                    swap2.push_back( cycle[i].first );
                    swap2.push_back( cycle[j].first );
                    swap(cycle[i].second,cycle[j].second);
                }
            vector< pair<int,int> >().swap(cycle);
        }
    }
    G<<"2\n";
    G<<swap1.size()/2;
    for (size_t i=0;i<swap1.size();++i)
        G<<' '<<swap1[i];
    G<<'\n';
    G<<swap2.size()/2;
    for (size_t i=0;i<swap2.size();++i)
        G<<' '<<swap2[i];
    G<<'\n';
}

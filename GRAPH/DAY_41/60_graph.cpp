#include<bits/stdc++.h>
using namespace std;

int main(){
    // Implementing Dijkstra Algorithm using priority_queue-> https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
    // T.C->O(E*log(V))

    //  Dijkstra's shortest path using set-> https://www.codingninjas.com/studio/problems/dijkstra-s-shortest-path_920469

    set<pair<int,int>>st;
    st.insert({0,0});
    st.insert({4,1});
    st.insert({4,2});
    st.insert({7,3});
    st.insert({10,5});
    st.insert({5,4});
    st.insert({8,5});

    for(auto it=st.begin();it!=st.end();it++){
        cout<<"{"<<it->first<<","<<it->second<<"} "<<endl;
    }
    auto i=st.begin();
    cout<<i->first<<endl;
    return 0;
}
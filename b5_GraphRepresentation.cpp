#include<iostream>
using namespace std;
class ADJ_Matrix{
    public:

void adj_matrix(){
    cout<<"\nENter the number of vertices : ";
    int v;
    cin>>v;
    cout<<"\nEnter the number of edges : ";
    int e;
    cin>>e;

    int adj [v+1][v+1] ;

    for(int i=0;i<v;i++){
        for(int j =0; j<v;j++){
            adj[i][j]= 0;
        }
    }

    for(int i=0;i<e;i++){
        cout<<"\nEnter the source vertice : ";
        int v1;
        cin>>v1;
        cout<<"\nEnter the destination vertice : ";
        int v2;
        cin>>v2;
        cout<<"\nEnter the edhe weight : ";
        int w;
        cin>>w;

        adj[v1][v2]=w;

    }
    cout<<"\nTHe adjacency matrix is :\n";
    for(int i=0;i<v;i++){
        for(int j =0; j<v;j++){
            cout<<adj[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

};

int main(){
    ADJ_Matrix a1;
    a1.adj_matrix();
    return 0;
}
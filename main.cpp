#include "graph.hpp"
#include<iostream>

using namespace std;
int main()
{
 std::cout<<"Testing Graph object creation\n";
   int adjcMat[][6]={\
                        {0, 1, 0, 0, 1, 1},\
                        {1, 0, 0, 1, 1, 0},\
                        {0, 0, 0, 1, 0, 0},\
                        {0, 1, 1, 0, 1, 1},\
                        {1, 1, 0, 1, 0, 0},\
                        {1, 0, 0, 1, 0, 0}\
                    };
    int* pAdjcMat=(int*)adjcMat;
    std::vector<std::string> vnames(6), enames(8);
    char vn[][6]={"v1", "v2", "v3", "v4", "v5", "v6"};
    char en[][8]={"e1", "e2", "e3", "e4", "e5", "e6", "e7", "e8"};
   
    vnames.assign(vn,vn+6);
    enames.assign(en, en+8);
   
    mits::Graph g(6, 8, vnames, enames, pAdjcMat, mits::ADJACENCY_MATRIX);
    g.printAdjcMat();
    cout<<endl;

    cout<<"\n"<<g.getDegree(3)<<"\n";
    cout<<"\n"<<g.isAdjacent(4,6)<<"\n";




return 0;
}

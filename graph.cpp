#include "graph.hpp"
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace mits;
mits::BitMapMatrix::BitMapMatrix(int nv){
 nvertex=nv;
vbitmap=(char*)malloc((nvertex*nvertex)/8);    
}

bool mits::BitMapMatrix::getBit(int i, int j){
	int k=nvertex*i+j;
	int b=k/8;
	int off=k%8;
	int mask=pow(2,7-off);
	if((vbitmap[b]&mask)==mask)
		return 1;
	else 
		return 0;
 
}

void mits::BitMapMatrix::setBit(int i, int j){
	int k=nvertex*i+j;
	int b=k/8;
	int off=k%8;
	int mask=pow(2,7-off);
	vbitmap[b]=vbitmap[b]|mask;
 
}

void mits::BitMapMatrix::resetBit(int i, int j){
        int k=nvertex*i+j;
	int b=k/8;
	int off=k%8;
	int mask=pow(2,7-off); 
        vbitmap[b]&=(~mask);
}


void mits::BitMapMatrix::deleteEntry(int v){

}
       


mits::Graph::Graph(const int nv, const int ne, std::vector<std::string> &vn, std::vector<std::string> &en, const int* adjcMat, RepType t)
{
 if(nv > MAX_VERTICES)
  std::cout<<"Exceeded Maximum Number of Verices"<<std::endl;
   
nvertex=nv;
nedge=ne;
vnames=vn;
enames=en;
repType=t;
bmm=BitMapMatrix(nvertex);

for(int i=0;i<nvertex;i++){
for(int j=0;j<nvertex;j++){
 if(*(adjcMat+i*nvertex+j) == 1)
     bmm.setBit(i,j);
 else 
  bmm.resetBit(i,j);
        }
    }

}

void mits::Graph::printAdjcMat()
{
for(int i=0;i<nvertex;i++){
for(int j=0;j<nvertex;j++){
if(bmm.getBit(i,j))
   std::cout<<1<<' ';
else
 std::cout<<0<<' ';
    }
 std::cout<<std::endl;
  }

}



int mits::Graph::getVertexCount()
{
return nvertex;


}


int mits::Graph::getEdgeCount()
{
    return nedge;

}


bool mits::Graph::isAdjacent(int v1, int v2)
{
 return bmm.getBit(v1-1, v2-1);


}


int mits::Graph::getDegree(int v)
{
   int deg=0;
    int i=v-1;
    for(int j=0;j<nvertex;j++){
      
        if(i!=j && bmm.getBit(i,j))
            deg++;
    }
    return deg;


}





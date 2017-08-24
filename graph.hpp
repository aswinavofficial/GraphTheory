#ifndef GRAPH_H__
#define GRAPH_H__
#include<iostream>
#include<vector>
#include<string>

namespace mits{

#define MAX_VERTICES 250


	class BitMapMatrix{
		private:
			char* vbitmap;
			int nvertex;
		public:
			BitMapMatrix(){
			}
			
			BitMapMatrix(int nv);

			bool getBit(int i, int j);

			void setBit(int i, int j);

			void resetBit(int i, int j);

			void deleteEntry(int v);
	};
    
    enum RepType{

        ADJACENCY_MATRIX=1,
        INCIDENCE_MATRIX=2
    };
    
    // NOTE: Vertices are assigned numbers from 1 to n
    // Represents UNDIRECTED SELF-LOOP-FREE GRAPH
    class Graph{
        private:
            int nvertex, /* number of vertices */
                nedge;   /* number of edges */
            std::vector<std::string> vnames,  /*  names of vertices */
                                    enames; /* names of edges */
            RepType repType;
            mits::BitMapMatrix bmm;

        public:
           
            Graph(){
		}

     
          Graph(const int nv, const int ne, std::vector<std::string> &vn, std::vector<std::string> &en, const int* adjcMat, RepType t);

            /* print the adjancency matrix */
           void printAdjcMat();
            
            /* get number of vertices */
           int getVertexCount();

            /* get number of edges */
           int getEdgeCount();

            /* check if vertices are adjacent */
          bool isAdjacent(int v1, int v2);

            /* get the degree of the vertex */
        int getDegree(int v);
        
            RepType getRepType();
    };
}
#endif

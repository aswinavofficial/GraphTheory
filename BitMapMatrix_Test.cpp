#include "gtest/gtest.h"
#include "graph.hpp"

class BitMapMatrixTest: public::testing::Test{
    protected:
    virtual void SetUp(){
    }
    virtual void TearDown(){
    }
};

TEST(BitMapMatrixTest, creation){
    	std::cout<<"Testing Bit Map creation";
	mits::BitMapMatrix bMap(3);
	bMap.setBit(1,1);
    	EXPECT_EQ(true, bMap.getBit(1,1));
}



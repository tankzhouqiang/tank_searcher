#include "../SimpleStorage.h"
#include "gtest/gtest.h"

TANK_SEARCHER_BEGIN_NAMESPACE(index)
class SimpleStorageTest : public ::testing::Test {
protected:
    SimpleStorageTest() {
    }

    virtual ~SimpleStorageTest() {
    }

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST_F(SimpleStorageTest, getSimpleTest) {
    SimpleStorage storage;
    storage.setSimpleTest(6);
    EXPECT_EQ(6, storage.getSimpleTest());
}

TANK_SEARCHER_END_NAMESPACE(index);

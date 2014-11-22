#include "../JsonUtil.h"
#include "gtest/gtest.h"
using namespace std;

TANK_SEARCHER_BEGIN_NAMESPACE(util)
class JsonUtilTest : public ::testing::Test {
protected:
    JsonUtilTest() {
    }

    virtual ~JsonUtilTest() {
    }

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST_F(JsonUtilTest, parse) {
    LOG(INFO) << "test parse in JsonUtilTest";
    JsonUtil jsonUtil;
    jsonUtil.parse();
}

TANK_SEARCHER_END_NAMESPACE(util);

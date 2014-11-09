#include "../FileUtil.h"
#include "gtest/gtest.h"
using namespace std;

TANK_SEARCHER_BEGIN_NAMESPACE(util)
class FileUtilTest : public ::testing::Test {
protected:
    FileUtilTest() {
    }

    virtual ~FileUtilTest() {
    }

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST_F(FileUtilTest, getFileContent) {
    FileUtil fileUtil;
    string expectResult = "11\n2222\n444444\n66666666";
    string fileContent;
    
    string fileName = getExecPath() + "/simpleFile";
    EXPECT_EQ(true, 
              fileUtil.getFileContent(fileName.c_str(), fileContent));
    EXPECT_EQ(expectResult, fileContent);
}

TANK_SEARCHER_END_NAMESPACE(util);

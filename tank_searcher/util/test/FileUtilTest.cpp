#include "../FileUtil.h"
#include "gtest/gtest.h"

#include <stdlib.h>
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
    char *filePrefix = getenv("install_root");
    string fileName = filePrefix;
    fileName += "/tank_searcher/util/test/simpleFile";

    cout << "###########install_root" << fileName << endl;
    EXPECT_EQ(true, 
              fileUtil.getFileContent(fileName.c_str(), fileContent));
    EXPECT_EQ(expectResult, fileContent);
}

TANK_SEARCHER_END_NAMESPACE(util);

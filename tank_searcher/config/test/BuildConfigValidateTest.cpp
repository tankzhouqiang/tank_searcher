#include "../BuildConfigValidate.h"
#include <tank_searcher/config/BuildConfigParser.h>
#include <tank_searcher/util/FileUtil.h>

#include "gtest/gtest.h"
#include <folly/json.h>

using namespace std;
using namespace::folly;
using namespace::testing;

TANK_SEARCHER_USE_NAMESPACE(util);

TANK_SEARCHER_BEGIN_NAMESPACE(config);

class BuildConfigValidateTest : public ::testing::Test {
protected:
    BuildConfigValidateTest() {
    }
    virtual ~BuildConfigValidateTest() {
    }
    virtual void SetUp() {
    }
    virtual void TearDown() {
    }
};

TEST_F(BuildConfigValidateTest, validateNormal) {
    string normalConfig[] = 
        {"/build_processor_config.json", 
        "/build_processor_config_empty.json",
         "/build_processor_processor_not_config.json",
         "/build_processor_processor_not_config2.json",
         "/build_processor_processor_not_config3.json"
        };
    uint32_t normalConfigCount = 5;
    for (uint32_t i = 0; i < 5; ++i) {
        string configPath = getExecPath() + normalConfig[i];
        string jsonStr;
        FileUtil fileUtil;
        ASSERT_EQ(true, 
                  fileUtil.getFileContent(configPath.c_str(), jsonStr));
        dynamic jsonFormatContent = parseJson(jsonStr);
        BuildConfigParser parser;
        ASSERT_EQ(true, parser.parse(jsonFormatContent));
        //check result.
        const BuildConfig& config = parser.getBuildConfig();
        ASSERT_EQ(true, BuildConfigValidate::validate(config));
    }
}

TEST_F(BuildConfigValidateTest, validateAbnormal) {
    string abnormalConfig[] = 
        {"/build_processor_config_module_name_not_existed.json", 
         "/build_processor_config_processor_name_not_existed.json"
        };
    uint32_t abnormalConfigCount = 2;
    for (uint32_t i = 0; i < abnormalConfigCount; ++i) {
        string configPath = getExecPath() + abnormalConfig[i];
        string jsonStr;
        FileUtil fileUtil;
        ASSERT_EQ(true, 
                  fileUtil.getFileContent(configPath.c_str(), jsonStr));
        dynamic jsonFormatContent = parseJson(jsonStr);
        BuildConfigParser parser;
        ASSERT_EQ(true, parser.parse(jsonFormatContent));
        //check result.
        const BuildConfig& config = parser.getBuildConfig();
        ASSERT_EQ(false, BuildConfigValidate::validate(config));
    }
}

TANK_SEARCHER_END_NAMESPACE(config);


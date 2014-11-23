#include "../BuildConfigParser.h"
#include <tank_searcher/util/FileUtil.h>
#include <folly/json.h>
#include <gtest/gtest.h>

using namespace std;
using namespace::folly;
using namespace::testing;

TANK_SEARCHER_USE_NAMESPACE(util);

TANK_SEARCHER_BEGIN_NAMESPACE(config);

class BuildConfigParserTest : public ::testing::Test {
protected:
    BuildConfigParserTest() {
    }

    virtual ~BuildConfigParserTest() {
    }

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST_F(BuildConfigParserTest, parse) {
    string configPath = getExecPath() + "/build_processor_config.json";
    string jsonStr;
    FileUtil fileUtil;
    ASSERT_EQ(true, 
              fileUtil.getFileContent(configPath.c_str(), jsonStr));
    dynamic jsonFormatContent = parseJson(jsonStr);
    BuildConfigParser parser;
    ASSERT_EQ(true, parser.parse(jsonFormatContent));
    //check result.
    const BuildConfig& config = parser.getBuildConfig();
    const std::vector<ModulesConfig>& modulesConfig = 
        config.getModulesConfigs();
    ASSERT_EQ((size_t)2, modulesConfig.size());
    ASSERT_EQ(fbstring("builder"), modulesConfig[0].getModuleName());
    ASSERT_EQ(fbstring("libBuilder.so"), 
              modulesConfig[0].getModulePath());

    KeyValueMap kvMap = modulesConfig[0].getParamMap();
    ASSERT_EQ((size_t)2, kvMap.size());
    fbstring key1 = "key1";
    fbstring key2 = "key2";
    ASSERT_EQ(fbstring("value1"), kvMap[key1]);
    ASSERT_EQ(fbstring("value2"), kvMap[key2]);

    ASSERT_EQ(fbstring("builder2"), modulesConfig[1].getModuleName());
    ASSERT_EQ(fbstring("libBuilder2.so"), 
              modulesConfig[1].getModulePath());
    
    KeyValueMap kvMap2 = modulesConfig[1].getParamMap();
    ASSERT_EQ((size_t)1, kvMap2.size());
    ASSERT_EQ(fbstring("value4"), kvMap2[fbstring("key4")]);

    std::vector<DocumentProcessorConfig> processorConfigs = 
        config.getProcessorConfigs();
    ASSERT_EQ((size_t)2, processorConfigs.size());
    ASSERT_EQ(fbstring("DocumentParser"), processorConfigs[0].getName());
    ASSERT_EQ(fbstring("DocumentParserProcessor"), processorConfigs[0].getClassName());
    ASSERT_EQ(fbstring("builder"), processorConfigs[0].getModuleName());
    
    KeyValueMap kvMap3 = processorConfigs[0].getParamMap();
    ASSERT_EQ((size_t)2, kvMap3.size());
    ASSERT_EQ(fbstring("value1"), kvMap3[fbstring("key1")]);
    ASSERT_EQ(fbstring("value2"), kvMap3[fbstring("key2")]);

    ASSERT_EQ(fbstring("DocumentTokenize"), processorConfigs[1].getName());
    ASSERT_EQ(fbstring("DocumentTokenizeProcessor"), processorConfigs[1].getClassName());
    ASSERT_EQ(fbstring("builder2"), processorConfigs[1].getModuleName());
    KeyValueMap kvMap4 = processorConfigs[1].getParamMap();
    ASSERT_EQ((size_t)0, kvMap4.size());

    const std::vector<fbstring> &processorNameChain = 
        config.getProcessorNameChain();
    ASSERT_EQ((size_t)2, processorNameChain.size());
    ASSERT_EQ(fbstring("DocumentParser"), processorNameChain[0]);
    ASSERT_EQ(fbstring("DocumentTokenize"), processorNameChain[1]);
}

TANK_SEARCHER_END_NAMESPACE(config);

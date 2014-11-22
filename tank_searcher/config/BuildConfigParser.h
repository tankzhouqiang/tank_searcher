#ifndef TANK_SEARCHER_BUILDCONFIGPARSER_H
#define TANK_SEARCHER_BUILDCONFIGPARSER_H

#include <tank_searcher/common/Common.h>
#include <tank_searcher/config/BuildConfig.h>
#include <folly/json.h>

TANK_SEARCHER_BEGIN_NAMESPACE(config);

class BuildConfigParser
{
public:
    static const folly::fbstring MODULES_KEY;
    static const folly::fbstring MODULES_NAME_KEY;
    static const folly::fbstring MODULES_PATH_KEY;
    static const folly::fbstring MODULES_PARAM_KEY;

    static const folly::fbstring DOCUMENT_PROCESSOR_KEY;
    static const folly::fbstring DOCUMENT_PROCESSOR_NAME_KEY;
    static const folly::fbstring DOCUMENT_PROCESSOR_CLASS_KEY;
    static const folly::fbstring DOCUMENT_PROCESSOR_PARAM_KEY;

    static const folly::fbstring DOCUMENT_PROCESSOR_CHAIN;
public:
    BuildConfigParser();
    ~BuildConfigParser();
private:
    BuildConfigParser(const BuildConfigParser &);
    BuildConfigParser& operator=(const BuildConfigParser &);
public:
    const BuildConfig& getBuildConfig() const {
        return _config;
    }
    bool parse(const folly::dynamic& jsonConfigFile);
private:
    bool parseModulesConfig(const folly::dynamic& jsonConfigFile);
    bool parseDocumentProcessorConfig(
            const folly::dynamic& jsonConfigFile);
    bool parseDocumentProcessorChain(
            const folly::dynamic& jsonConfigFile);
    bool getJsonMapValue(const folly::dynamic& kvMap, 
                         const folly::fbstring& key, 
                         folly::fbstring& value); 
    bool getParamMapValue(const folly::dynamic& jsonMap, 
                          const folly::fbstring& key, 
                          KeyValueMap& kvMap); 
private:
    BuildConfig _config;
};

TANK_SEARCHER_TYPEDEF_PTR(BuildConfigParser);

TANK_SEARCHER_END_NAMESPACE(config);

#endif //TANK_SEARCHER_BUILDCONFIGPARSER_H

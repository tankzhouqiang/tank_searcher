#include <tank_searcher/config/ModulesConfig.h>

TANK_SEARCHER_BEGIN_NAMESPACE(config);

ModulesConfig::ModulesConfig(folly::fbstring moduleName, 
                             folly::fbstring modulePath, 
                             KeyValueMap paramMap) 
{
    _moduleName = moduleName;
    _modulePath = modulePath;
    _paramMap = paramMap;
}

ModulesConfig::~ModulesConfig() { 
}

TANK_SEARCHER_END_NAMESPACE(config);


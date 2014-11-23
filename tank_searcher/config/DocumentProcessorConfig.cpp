#include <tank_searcher/config/DocumentProcessorConfig.h>

TANK_SEARCHER_BEGIN_NAMESPACE(config);

DocumentProcessorConfig::DocumentProcessorConfig(
        const folly::fbstring& name, 
        const folly::fbstring& className, 
        const folly::fbstring& moduleName, 
        const KeyValueMap& paramMap)
{
    _name = name;
    _className = className;
    _moduleName = moduleName;
    _paramMap = paramMap;
}


DocumentProcessorConfig::~DocumentProcessorConfig() { 
}

TANK_SEARCHER_END_NAMESPACE(config);


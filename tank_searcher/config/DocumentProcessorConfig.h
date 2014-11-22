#ifndef TANK_SEARCHER_DOCUMENTPROCESSORCONFIG_H
#define TANK_SEARCHER_DOCUMENTPROCESSORCONFIG_H

#include <tank_searcher/common/Common.h>

TANK_SEARCHER_BEGIN_NAMESPACE(config);

class DocumentProcessorConfig
{
public:
    DocumentProcessorConfig(const folly::fbstring& name, 
                            const folly::fbstring& className, 
                            const KeyValueMap& paramMap);
    ~DocumentProcessorConfig();
public:
    const folly::fbstring& getName() const {
        return _name;
    }
    const folly::fbstring& getClassName() const {
        return _className;
    }
    const KeyValueMap& getParamMap() const {
        return _paramMap;
    }
    KeyValueMap getParamMap() {
        return _paramMap;
    }
private:
    folly::fbstring _name;
    folly::fbstring _className;
    KeyValueMap _paramMap;
};

TANK_SEARCHER_TYPEDEF_PTR(DocumentProcessorConfig);

TANK_SEARCHER_END_NAMESPACE(config);

#endif //TANK_SEARCHER_DOCUMENTPROCESSORCONFIG_H

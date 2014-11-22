#ifndef TANK_SEARCHER_MODULESCONFIG_H
#define TANK_SEARCHER_MODULESCONFIG_H

#include <tank_searcher/common/Common.h>

TANK_SEARCHER_BEGIN_NAMESPACE(config);

class ModulesConfig
{
public:
    ModulesConfig(folly::fbstring moduleName, 
                  folly::fbstring modulePath, KeyValueMap paramMap);
    ~ModulesConfig();
public:
    void setModuleName(const folly::fbstring& name) {
        _moduleName = name;
    }
    const folly::fbstring& getModuleName() const {
        return _moduleName;
    }

    void setModulePath(const folly::fbstring& name) {
        _modulePath = name;
    }

    const folly::fbstring& getModulePath() const {
        return _modulePath;
    }

    void addKeyValueParam(const folly::fbstring& key, 
                          const folly::fbstring& value) 
    {
        _paramMap[key] = value;
    }

    const KeyValueMap& getParamMap() const {
        return _paramMap;
    }

//for test
    KeyValueMap getParamMap()  {
        return _paramMap;
    }

private:
    folly::fbstring _moduleName;
    folly::fbstring _modulePath;
    KeyValueMap _paramMap;
};

TANK_SEARCHER_TYPEDEF_PTR(ModulesConfig);

TANK_SEARCHER_END_NAMESPACE(config);

#endif //TANK_SEARCHER_MODULESCONFIG_H

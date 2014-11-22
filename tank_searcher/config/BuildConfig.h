#ifndef TANK_SEARCHER_BUILDCONFIG_H
#define TANK_SEARCHER_BUILDCONFIG_H

#include <tank_searcher/common/Common.h>
#include <tank_searcher/config/ModulesConfig.h>
#include <tank_searcher/config/DocumentProcessorConfig.h>

TANK_SEARCHER_BEGIN_NAMESPACE(config);

class BuildConfig
{
public:
    BuildConfig();
    ~BuildConfig();
private:
    BuildConfig(const BuildConfig &);
    BuildConfig& operator=(const BuildConfig &);
public:
    void addModulesConfig(const ModulesConfig& config) {
        _modulesConfigs.push_back(config);
    }
    
    const std::vector<ModulesConfig>& getModulesConfigs() const {
        return _modulesConfigs;
    }
    
    void addProcessorConfig(const DocumentProcessorConfig& config) {
        _processorConfigs.push_back(config);
    }

    const std::vector<DocumentProcessorConfig>& getProcessorConfigs() const {
        return _processorConfigs;
    }
    
    void addProcessorNameChain(const folly::fbstring& processorName) {
        _processorNameChain.push_back(processorName);
    }
    
    const std::vector<folly::fbstring>& getProcessorNameChain() const {
        return _processorNameChain;
    }
private:
    std::vector<ModulesConfig> _modulesConfigs;
    std::vector<DocumentProcessorConfig> _processorConfigs;
    std::vector<folly::fbstring> _processorNameChain;
};

TANK_SEARCHER_TYPEDEF_PTR(BuildConfig);

TANK_SEARCHER_END_NAMESPACE(config);

#endif //TANK_SEARCHER_BUILDCONFIG_H

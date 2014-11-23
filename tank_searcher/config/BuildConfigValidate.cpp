#include <tank_searcher/config/BuildConfigValidate.h>
using namespace std;
using namespace folly;

TANK_SEARCHER_BEGIN_NAMESPACE(config);

BuildConfigValidate::BuildConfigValidate() { 
}

BuildConfigValidate::~BuildConfigValidate() { 
}

bool BuildConfigValidate::validateModuleName(
        const vector<ModulesConfig>& moduleConfig,
        const vector<DocumentProcessorConfig>& processorConfigs) 
{
    for (uint32_t i = 0; i < processorConfigs.size(); ++i) {
        const fbstring& moduleName = 
            processorConfigs[i].getModuleName();
        uint32_t j = 0;
        for (; j < moduleConfig.size(); ++j) {
            if (moduleName == moduleConfig[j].getModuleName()) {
                break;
            }
        }
        if (j == moduleConfig.size()) {
            LOG(ERROR) << "module name " << moduleName
                       << " is not config.";
            return false;
        }
    }
    return true;
}

bool BuildConfigValidate::validateProcessorName(
        const vector<DocumentProcessorConfig>& processorConfigs,
        const vector<fbstring>& processorNameVec) 
{
    for (int32_t i = 0; i < processorNameVec.size(); ++i) {
        const fbstring& processorName = processorNameVec[i];
        uint32_t j = 0;
        for (; j < processorConfigs.size(); ++j) {
            if (processorName == processorConfigs[j].getName()) {
                break;
            }
        }
        if (j == processorConfigs.size()) {
            LOG(ERROR) << "processor name " << processorName
                       << " is not config.";
            return false;
        }
    }
    return true;
}

bool BuildConfigValidate::validate(const BuildConfig& config) {
    const vector<ModulesConfig>& moduleConfig = 
        config.getModulesConfigs();
    const vector<DocumentProcessorConfig>& processorConfigs = 
        config.getProcessorConfigs();

    if (validateModuleName(moduleConfig, processorConfigs) == false) {
        return false;
    }
    const vector<fbstring>& processorNameVec = 
        config.getProcessorNameChain();
    if (validateProcessorName(processorConfigs, processorNameVec) == false) {
        return false;
    }
    return true;
}

TANK_SEARCHER_END_NAMESPACE(config);


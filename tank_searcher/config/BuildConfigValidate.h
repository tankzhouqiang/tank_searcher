#ifndef TANK_SEARCHER_BUILDCONFIGVALIDATE_H
#define TANK_SEARCHER_BUILDCONFIGVALIDATE_H

#include <tank_searcher/common/Common.h>
#include <tank_searcher/config/BuildConfig.h>

TANK_SEARCHER_BEGIN_NAMESPACE(config);

class BuildConfigValidate
{
public:
    BuildConfigValidate();
    ~BuildConfigValidate();
private:
    BuildConfigValidate(const BuildConfigValidate &);
    BuildConfigValidate& operator=(const BuildConfigValidate &);
public:
    static bool validate(const BuildConfig& config);
private:
    static bool validateModuleName(
            const std::vector<ModulesConfig>& moduleConfig,
            const std::vector<DocumentProcessorConfig>& processorConfigs);

    static bool validateProcessorName(
            const std::vector<DocumentProcessorConfig>& processorConfigs,
            const std::vector<folly::fbstring>& processorNameVec);
private:
};

TANK_SEARCHER_TYPEDEF_PTR(BuildConfigValidate);

TANK_SEARCHER_END_NAMESPACE(config);

#endif //TANK_SEARCHER_BUILDCONFIGVALIDATE_H

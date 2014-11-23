#ifndef TANK_SEARCHER_BUILDCONFIGVALIDATE_H
#define TANK_SEARCHER_BUILDCONFIGVALIDATE_H

#include <tank_searcher/common/Common.h>

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

private:
};

TANK_SEARCHER_TYPEDEF_PTR(BuildConfigValidate);

TANK_SEARCHER_END_NAMESPACE(config);

#endif //TANK_SEARCHER_BUILDCONFIGVALIDATE_H

#ifndef TANK_SEARCHER_BUILDERPROCESSORMANAGER_H
#define TANK_SEARCHER_BUILDERPROCESSORMANAGER_H

#include <tank_searcher/common/Common.h>

TANK_SEARCHER_BEGIN_NAMESPACE(builder);

class BuilderProcessorManager
{
public:
    BuilderProcessorManager();
    ~BuilderProcessorManager();
private:
    BuilderProcessorManager(const BuilderProcessorManager &);
    BuilderProcessorManager& operator=(const BuilderProcessorManager &);
public:

private:
};

TANK_SEARCHER_TYPEDEF_PTR(BuilderProcessorManager);

TANK_SEARCHER_END_NAMESPACE(builder);

#endif //TANK_SEARCHER_BUILDERPROCESSORMANAGER_H

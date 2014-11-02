#ifndef TANK_SEARCHER_BUILDERPROCESSOR_H
#define TANK_SEARCHER_BUILDERPROCESSOR_H

#include <tank_searcher/common/Common.h>

TANK_SEARCHER_BEGIN_NAMESPACE(builder);

class BuilderProcessor
{
public:
    BuilderProcessor();
    virtual ~BuilderProcessor() = 0;
public:
    bool init(BuilderConfig config) = 0;
    bool process(Document *document) = 0;
    void destory() = 0;
public:
    BuilderProcessor* clone() = 0;
private:
    BuilderProcessor(const BuilderProcessor &);
    BuilderProcessor& operator=(const BuilderProcessor &);
public:

private:
};

TANK_SEARCHER_TYPEDEF_PTR(BuilderProcessor);

TANK_SEARCHER_END_NAMESPACE(builder);

#endif //TANK_SEARCHER_BUILDERPROCESSOR_H

#ifndef TANK_SEARCHER_JSONUTIL_H
#define TANK_SEARCHER_JSONUTIL_H

#include <tank_searcher/common/Common.h>
#include <folly/json.h>

using folly::dynamic;
using folly::parseJson;
using folly::toJson;

TANK_SEARCHER_BEGIN_NAMESPACE(util);

class JsonUtil
{
public:
    JsonUtil();
    ~JsonUtil();
public:
    void parse() {
    }
private:
    JsonUtil(const JsonUtil &);
    JsonUtil& operator=(const JsonUtil &);
public:

private:
};

TANK_SEARCHER_TYPEDEF_PTR(JsonUtil);

TANK_SEARCHER_END_NAMESPACE(util);

#endif //TANK_SEARCHER_JSONUTIL_H

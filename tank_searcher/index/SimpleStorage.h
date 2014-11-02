#ifndef TANK_SEARCHER_SIMPLESTORAGE_H
#define TANK_SEARCHER_SIMPLESTORAGE_H

#include "../common/Common.h"

TANK_SEARCHER_BEGIN_NAMESPACE(index);

class SimpleStorage
{
public:
    SimpleStorage();
    ~SimpleStorage();
public:
    void setSimpleTest(int num) {
        LOG(INFO) << "SET setSimpleTest" << num ;
        _simpleTest = num;
    }
    int getSimpleTest() const {
        return _simpleTest;
    }
private:
    SimpleStorage(const SimpleStorage &);
    SimpleStorage& operator=(const SimpleStorage &);
private:
    int _simpleTest;
};

TANK_SEARCHER_TYPEDEF_PTR(SimpleStorage);

TANK_SEARCHER_END_NAMESPACE(index);

#endif //TANK_SEARCHER_SIMPLESTORAGE_H

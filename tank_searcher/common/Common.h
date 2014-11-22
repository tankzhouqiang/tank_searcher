#ifndef TANK_SEARCHER_COMMON_H_
#define TANK_SEARCHER_COMMON_H_

#include <assert.h>
#include <iostream>
#include <map>
#include <stdio.h>
#include <libgen.h>
#include <glog/logging.h>
#include <folly/FBString.h>

typedef std::map<folly::fbstring, folly::fbstring> KeyValueMap;

#define TANK_SEARCHER_BEGIN_NAMESPACE(x) namespace Tank_Searcher { namespace x{ 

#define TANK_SEARCHER_END_NAMESPACE(x) } }

#define TANK_SEARCHER_USE_ROOT_NAMESPACE using namespace Tank_Searcher;

#define TANK_SEARCHER_USE_NAMESPACE(x) using namespace Tank_Searcher::x

#define TANK_SEARCHER_NS(x) Tank_Searcher::x

#include <tr1/memory>
#define TANK_SEARCHER_TYPEDEF_PTR(x) typedef std::tr1::shared_ptr<x> x##Ptr

#define TEST_DATA "test_data"

static std::string getExecPath() {    
    char exec_name[2048] = {0};                                                                                                             
    readlink("/proc/self/exe", exec_name, 2048);                                                                                            
    char *dname = dirname(exec_name);                                                                                                       
    return std::string(dname);                                                                                                              
};

#endif /*TANK_SEARCHER_COMMON_H_*/



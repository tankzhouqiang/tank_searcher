#include <tank_searcher/config/BuildConfigParser.h>

using namespace std;
using namespace folly;
TANK_SEARCHER_BEGIN_NAMESPACE(config);

const fbstring BuildConfigParser::MODULES_KEY = "modules";
const fbstring BuildConfigParser::MODULES_NAME_KEY = "module_name";
const fbstring BuildConfigParser::MODULES_PATH_KEY = "module_path";
const fbstring BuildConfigParser::MODULES_PARAM_KEY = "parameters";

const fbstring BuildConfigParser::DOCUMENT_PROCESSOR_KEY = "document_processor";
const fbstring BuildConfigParser::DOCUMENT_PROCESSOR_NAME_KEY = "name";
const fbstring BuildConfigParser::DOCUMENT_PROCESSOR_CLASS_KEY = "class_name";
const fbstring BuildConfigParser::DOCUMENT_PROCESSOR_MODULE_NAME_KEY = "module_name";
const fbstring BuildConfigParser::DOCUMENT_PROCESSOR_PARAM_KEY = "parameter";

const fbstring BuildConfigParser::DOCUMENT_PROCESSOR_CHAIN = "document_processor_chain";

BuildConfigParser::BuildConfigParser() { 
}

BuildConfigParser::~BuildConfigParser() { 
}

bool BuildConfigParser::parseModulesConfig(
        const dynamic& jsonConfigFile)
{
    dynamic::const_item_iterator it = jsonConfigFile.find(MODULES_KEY);
    if (it == jsonConfigFile.items().end()) {
        LOG(INFO) << "build config modules is not config.";
        return true;
    }
    const dynamic& modulesVec = it->second;
    for (dynamic::const_iterator modulesIt = modulesVec.begin(); 
         modulesIt != modulesVec.end(); ++modulesIt) 
    {
        fbstring moduleName;
        if (!getJsonMapValue(*modulesIt, MODULES_NAME_KEY, moduleName)) {
            return false;
        }

        fbstring modulePath;
        if (!getJsonMapValue(*modulesIt, MODULES_PATH_KEY, modulePath)) {
            return false;
        }
        KeyValueMap kvMap;
        getParamMapValue(*modulesIt, MODULES_PARAM_KEY, kvMap);
        ModulesConfig config(moduleName, modulePath, kvMap);
        _config.addModulesConfig(config);
    }    
    return true;
}

bool BuildConfigParser::parseDocumentProcessorConfig(
        const dynamic& jsonConfigFile)
{
    dynamic::const_item_iterator it = jsonConfigFile.find(DOCUMENT_PROCESSOR_KEY);
    if (it == jsonConfigFile.items().end()) {
        LOG(INFO) << "document processor is not config.";
        return true;
    }
    const dynamic& processorVec = it->second;
    for (dynamic::const_iterator processorIt = 
             processorVec.begin(); processorIt != processorVec.end(); 
         ++processorIt) 
    {
        fbstring name;
        if (!getJsonMapValue(*processorIt, 
                             DOCUMENT_PROCESSOR_NAME_KEY, 
                             name)) 
        {
            LOG(ERROR) << "build process name config error.";
            return false;
        }
        fbstring className;
        if (!getJsonMapValue(*processorIt, 
                             DOCUMENT_PROCESSOR_CLASS_KEY,
                             className)) 
        {
            LOG(ERROR) << "build process class name config error.";
            return false;
        }
        fbstring moduleName;
        if (!getJsonMapValue(*processorIt, 
                             DOCUMENT_PROCESSOR_MODULE_NAME_KEY,
                             moduleName)) 
        {
            LOG(ERROR) << "build process class name config error.";
            return false;
        }

        KeyValueMap kvMap;
        getParamMapValue(*processorIt, DOCUMENT_PROCESSOR_PARAM_KEY, 
                         kvMap);
        
        DocumentProcessorConfig config(name, className, moduleName, kvMap);
        _config.addProcessorConfig(config);
    }
    return true;
}

bool BuildConfigParser::parseDocumentProcessorChain(const dynamic& jsonConfigFile) 
{
    dynamic::const_item_iterator it = 
        jsonConfigFile.find(DOCUMENT_PROCESSOR_CHAIN);

    if (it == jsonConfigFile.items().end()) {
        LOG(INFO) << "document processor chain is not config.";
        return true;
    }
    const dynamic& chainVec = it->second;
    for (dynamic::const_iterator chainIt = chainVec.begin(); 
         chainIt != chainVec.end(); ++chainIt) 
    {
        const fbstring& processorName = (*chainIt).asString();
        _config.addProcessorNameChain(processorName);
    }
    return true;
}

bool BuildConfigParser::parse(const dynamic& jsonConfigFile) {
    if (!parseModulesConfig(jsonConfigFile)) {
        LOG(ERROR) << "parse build config modules error.";
        return false;
    }
    if (!parseDocumentProcessorConfig(jsonConfigFile)) {
        LOG(ERROR) << "parse document processor config error";
        return false;
    }

    if (!parseDocumentProcessorChain(jsonConfigFile)) {
        LOG(ERROR) << "parse document processor chain error";
        return false;
    }

    return true;
}

bool BuildConfigParser::getJsonMapValue(const dynamic& kvMap, const fbstring& key, 
                  fbstring& value) 
{
    dynamic::const_item_iterator it = kvMap.find(key);
    if (it == kvMap.items().end()) {
        LOG(ERROR) << "build config error," << key << "is not config.";       return true;  
    }
    value = it->second.asString();
    return true;
}

bool BuildConfigParser::getParamMapValue(const dynamic& jsonMap, const fbstring& key, 
                      KeyValueMap& kvMap) 
{
    dynamic::const_item_iterator it = jsonMap.find(key);
    if (it == jsonMap.items().end()) {
        LOG(INFO) << "build config param " << key << " not config ";
        return true;
    }
    const dynamic& value = it->second;
    for (dynamic::const_item_iterator it2 = value.items().begin();
         it2 != value.items().end(); ++it2) 
    {
        kvMap[it2->first.asString()] = it2->second.asString();
    }
    return true;
    
}

TANK_SEARCHER_END_NAMESPACE(config);


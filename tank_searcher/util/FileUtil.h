#ifndef TANK_SEARCHER_FILEUTIL_H
#define TANK_SEARCHER_FILEUTIL_H

#include <tank_searcher/common/Common.h>

TANK_SEARCHER_BEGIN_NAMESPACE(util);

class FileUtil
{
public:
    FileUtil();
    ~FileUtil();
public:
    bool  getFileContent(const std::string& fileName, 
                         std::string& content);
private:
    bool isExist(const std::string& fileName);
private:
    FileUtil(const FileUtil &);
    FileUtil& operator=(const FileUtil &);
public:

private:
};

TANK_SEARCHER_TYPEDEF_PTR(FileUtil);

TANK_SEARCHER_END_NAMESPACE(util);

#endif //TANK_SEARCHER_FILEUTIL_H

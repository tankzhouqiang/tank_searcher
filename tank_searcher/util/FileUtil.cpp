#include <tank_searcher/util/FileUtil.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;
TANK_SEARCHER_BEGIN_NAMESPACE(util);

FileUtil::FileUtil() { 
}

FileUtil::~FileUtil() { 
}

bool FileUtil::isExist(const std::string& fileName) {
    if (access(fileName.c_str(), F_OK) == 0) {
        return true;
    } else {
        LOG(INFO) << "fileName is not exist: " << fileName;
        return false;
    }
}

bool FileUtil::getFileContent(const string& fileName, 
                              string& content) 
{
    content.clear();
    if (!isExist(fileName)) {
        LOG(ERROR) << "read file error file is not exist: " << fileName;
        return false;
    } 
    FILE *fp = ::fopen(fileName.c_str(), "r");
    if (!fp) {
        LOG(ERROR) << "open file error : " << fileName;
        return false;
    }
    uint32_t length = 1 * 1024 * 1024; //1M

    char buf[1024 * 1024];
    size_t ret = 0;
    while(!feof(fp)) {
        memset(buf, 0, length);
        ret = fread((char*)buf, 1, length, fp);
        if (ferror(fp)) {
            LOG(ERROR) << "read file error : " << fileName;
            return false;
        }
        content.append(buf);
    }
    return true;
}

TANK_SEARCHER_END_NAMESPACE(util);


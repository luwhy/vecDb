#ifndef __HTTP_SERVER_H__
#define __HTTP_SERVER_H__
#include "FaissIndex.h"
#include "base/httplib.h"
#include <rapidjson/document.h>
class HttpServer
{
public:
    enum class CheckType
    {
        SEARCH,
        INSERT,
        UPSERT
    };
    HttpServer(const std::string &host, int port);
};

#endif

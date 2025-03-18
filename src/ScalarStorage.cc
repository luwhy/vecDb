#include "ScalarStorage.h"

ScalarStorage::ScalarStorage(const std::string &db_path)
{
}
ScalarStorage::~ScalarStorage()
{
}

void ScalarStorage::insert_scalar(uint64_t id, const rapidjson::Document &data)
{
}

rapidjson::Document ScalarStorage::get_scalar(uint64_t id)
{
    return rapidjson::Document();
}

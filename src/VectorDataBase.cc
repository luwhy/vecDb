#include "VectorDatabase.h"

VectorDatabase::VectorDatabase(const std::string &db_path)
{
}

VectorDatabase::~VectorDatabase()
{
}

void VectorDatabase::upset(uint64_t id, const rapidjson::Document &data, IndexFactory::IndexType index_type)
{
}

rapidjson::Document VectorDatabase::query(uint64_t id)
{
    return rapidjson::Document();
}

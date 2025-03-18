#ifndef __VECTOR_DATABASE_H__
#define __VECTOR_DATABASE_H__
#include <string>
#include <vector>
#include <rapidjson/document.h>
#include <IndexFactory.h>
class VectorDatabase
{
private:
    /* data */
public:
    VectorDatabase(const std::string &db_path);
    ~VectorDatabase();

    /**
     * @brief 插入或者更新向量
     *
     * @param id
     * @param data
     * @param index_type
     */
    void upset(uint64_t id, const rapidjson::Document &data, IndexFactory::IndexType index_type);

    /**
     * @brief 添加query接口
     *
     * @param id
     * @return rapidjson::Document
     */
    rapidjson::Document query(uint64_t id);

private:
};

#endif
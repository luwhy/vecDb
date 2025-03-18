#ifndef __SCALAR_STORAGE_H__
#define __SCALAR_STORAGE_H__
#include <string>
#include <vector>
#include <rapidjson/document.h>
#include <rocksdb/db.h>
class ScalarStorage
{
    /**
     * @brief 构造函数，打开rocksdb
     *
     * @param db_path
     */
    ScalarStorage(const std::string &db_path);

    /**
     * @brief Destroy the Scalar Storage object
     *
     */
    ~ScalarStorage();
    /**
     * @brief 向量插入函数
     *
     * @param id
     * @param data
     */
    void insert_scalar(uint64_t id, const rapidjson::Document &data);

    rapidjson::Document get_scalar(uint64_t id);

private:
    rocksdb::DB *db;
};
#endif
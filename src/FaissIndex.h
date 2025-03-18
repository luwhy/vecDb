#ifndef FAISSINDEX_H
#define FAISSINDEX_H

#include <faiss/Index.h>
#include <vector>
#include <faiss/index_factory.h>
#include <map>

class FaissIndex
{
public:
    /**
     * @brief 接收index指针
     *
     */
    FaissIndex(faiss::Index *index);
    ~FaissIndex();
    /**
     * @brief 将向量数据和对应标签写入索引
     *
     * @param data 数据
     * @param label
     */
    void insert_vectors(const std::vector<float> &data, uint64_t label);

    /**
     * @brief 查询最邻近K个向量，返回两个数组，一个是标签，一个是相应的距离。
     *
     * @param query
     * @param k
     * @return std::pair<std::vector<long>, std::vector<float>>
     */
    std::pair<std::vector<long>, std::vector<float>> search_vectors(const std::vector<float> &query, int k);

private:
    faiss::Index *m_index;
};

#endif
#include <faiss/Index.h>
#include "FaissIndex.h"
#include <vector>
#include <memory>
#include <faiss/IndexFlat.h>
#include <faiss/MetaIndexes.h>

FaissIndex::FaissIndex(faiss::Index *index)
{
    m_index = index;
}

FaissIndex::~FaissIndex()
{
}

void FaissIndex::insert_vectors(const std::vector<float> &data, uint64_t label)
{
    long id = static_cast<long>(label);
    m_index->add_with_ids(1, data.data(), &id);
}

std::pair<std::vector<long>, std::vector<float>> FaissIndex::search_vectors(const std::vector<float> &query, int k)
{
    int dim = m_index->d;           // 从索引的维度属性中获取查询向量的维度
    int num_queries = query.size(); // 通过数组长度计算查询向量的维度
    // 查询结果数组
    std::vector<long> indices(num_queries * k);
    // 查询结果距离
    std::vector<float> distance(num_queries * k);
    // 执行查询结果
    m_index->search(num_queries, query.data(), k, distance.data(), indices.data());
    return {indices, distance};
}

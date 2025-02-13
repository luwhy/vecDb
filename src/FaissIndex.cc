#include <faiss/Index.h>
#include "FaissIndex.h"
#include <vector>
namespace vecdb
{
    FaissIndex::FaissIndex(faiss::Index *index)
    {
    }

    void FaissIndex::insert_vectors(const std::vector<float> &data, uint64_t label)
    {
        long id = static_cast<long>(label);
        index->add_with_ids(1, data.data(), &id);
    }

    std::pair<std::vector<long>, std::vector<float>> FaissIndex::search_vectors(const std::vector<float> &query, int k)
    {
        int dim = index->d;             // 从索引的维度属性中获取查询向量的维度
        int num_queries = query.size(); // 通过数组长度计算查询向量的维度
        return std::pair<std::vector<long>, std::vector<float>>();
    }

} // namespace vecdb

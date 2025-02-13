#ifndef FAISSINDEX_H
#define FAISSINDEX_H

#include <faiss/Index.h>
#include <vector>

namespace vecdb
{
    class FaissIndex
    {
    public:
        // 构造函数，接收指向faiss::Index的指针
        FaissIndex(faiss::Index *index);

        // 将向量数据和对应标签写入索引
        void insert_vectors(const std::vector<float> &data, uint64_t label);

        // 查询最邻近K个向量，返回两个数组，一个是标签，一个是相应的距离。
        std::pair<std::vector<long>, std::vector<float>> search_vectors(const std::vector<float> &query, int k);

    private:
        faiss::Index *index;
    };
}
#endif
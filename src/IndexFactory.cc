#include "IndexFactory.h"
#include <faiss/Index.h>
#include <faiss/IndexFlat.h>
#include <faiss/MetaIndexes.h>

namespace
{
    IndexFactory globalIndexFactory;
}
IndexFactory *getGlobalIndexFactory()
{
    return &globalIndexFactory;
}

void IndexFactory::init(IndexType type, int dim, MetricType metric = MetricType::L2)
{
    faiss::MetricType faiss_metric = (metric == MetricType::L2) ? faiss::METRIC_L2 : faiss::METRIC_INNER_PRODUCT;
    switch (type)
    {
    case IndexType::FLAT:
        index_map[type] = std::make_shared<FaissIndex>(FaissIndex(new faiss::IndexIDMap(new faiss::IndexFlat(dim, faiss_metric))));
        // indexidmap包装 一个已知的索引，可以指定id
        break;
    default:
        break;
    }
}

std::shared_ptr<FaissIndex> IndexFactory::getIndex(IndexType type) const
{
    auto it = index_map.find(type);
    if (it != index_map.end())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}
IndexFactory *IndexFactory::getGlobalIndexFactory()
{
    if (m_factory == nullptr)
    {
        m_factory = new IndexFactory();
    }
    return m_factory;
}

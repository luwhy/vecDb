#ifndef __INDEX_FACTORY_H__
#define __INDEX_FACTORY_H__
#include "FaissIndex.h"
#include <memory>

/**
 * @brief 管理不同向量FaissIndex类型
 *
 */
class IndexFactory
{
public:
    enum class IndexType
    {
        FLAT,
        UNKOWN = -1
    };
    enum class MetricType
    {
        L2,
        IP
    };

public:
    IndexFactory(IndexFactory &i) = delete;

    /**
     * @brief 初始化索引工厂
     *
     * @param type 类型 Flat还是其他
     * @param dim 维度
     * @param metric 索引度量
     */
    void init(IndexType type, int dim, MetricType metric = MetricType::L2);
    /**
     * @brief 通过调用的type获取对应的索引对象
     *
     * @param type
     * @return std::shared_ptr<FaissIndex>
     */
    std::shared_ptr<FaissIndex> getIndex(IndexType type) const;

    static IndexFactory *getGlobalIndexFactory();

private:
    static IndexFactory *m_factory;
    std::map<IndexType, std::shared_ptr<FaissIndex>> index_map;
    IndexFactory();
};
IndexFactory *getGlobalIndexFactory();
#endif
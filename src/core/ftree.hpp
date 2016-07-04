#ifndef FTREE_HPP
#define FTREE_HPP

#include "fnode.hpp"

namespace fit {

TEMPLATE_NODE
class FTree : public FObject
{
    public:
        FTree(const FNode<DataType>& head = FNode<DataType>::Head);
        FTree(const DataType& headData);

    private:
        FNode<DataType> m_head;
        fuint32 m_nelem;
};

TEMPLATE_NODE
FTree<DataType>::FTree(const FNode<DataType>& head)
    :   m_head(head),
        m_nelem(1)
{

}

} // Namespace fit

#endif // FTREE_HPP

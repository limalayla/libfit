#ifndef FTREE_HPP
#define FTREE_HPP

#include "fobject.hpp"
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

} // Namespace fit

#include "ftree.cpp"

#endif // FTREE_HPP

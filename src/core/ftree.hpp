#ifndef FTREE_HPP
#define FTREE_HPP

#include "fnode.hpp"

namespace fit {

TEMPLATE_NODE
class FTree : public FObject
{
    public:
        FTree(const FNode<DataType>& head = FNode<DataType>::Head)
            :   m_head(head), m_nelem(1)
        {

        }

        FTree(const DataType& headData)
            : FTree(FNode<DataType>(headData))
        {

        }

    private:
        FNode<DataType> m_head;
        fuint32 m_nelem;
}; // Class Ftree

} // Namespace fit

#endif // FTREE_HPP

#ifndef FTREE_HPP
    #include "ftree.hpp"
#else

namespace fit {

TEMPLATE_NODE
FTree<DataType>::FTree(const FNode<DataType>& head)
    :   m_head(head),
        m_nelem(1)
{

}

} // Namespace fit

#endif // FTREE_HPP

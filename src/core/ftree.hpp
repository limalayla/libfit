#ifndef FTREE_HPP
#define FTREE_HPP

#include "fnode.hpp"

namespace fit {

/*!
 * Classic data storing structure.
 * Hierarchical linked list.
 *
 * \todo Copy-Move constructor / way of using it
 */
TEMPLATE_NODE
class FTree : public FObject
{
    public:
        /*!
         * Base Constructor - node version.
         *
         * \param head: Node that will be on the top level.
         */
        FTree(const FNode<DataType>& head)
            :   m_head(head), m_nelem(1)
        {

        }

        /*!
         * Base Constructor - Data version.
         *
         * \param head: Data that will be on the top level.
         */
        FTree(const DataType& headData)
            : FTree(FNode<DataType>(headData))
        {

        }

    private:
        //! Top Level Node
        FNode<DataType> m_head;

        //! Number of elements in the tree
        fuint32 m_nelem;

}; // Class Ftree

} // Namespace fit

#endif // FTREE_HPP

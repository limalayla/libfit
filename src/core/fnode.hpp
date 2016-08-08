#ifndef FNODE_HPP
#define FNODE_HPP

#include "app.hpp"

namespace fit {

#define TEMPLATE_NODE template<typename DataType>

/*!
 * Element of a Linked List (FLinkList)
 */
TEMPLATE_NODE
class FNode : public FObject
{
    /* Members */
    protected:
        //! Data held by the node
        DataType m_data;

        //! Pointer to the next node
        FNode<DataType>* m_child;

    /* Methods */
    public:
        /*!
         * Default Constructor
         *
         * \param data: Data filling the head node
         * \param child: Optional pointer to the next child (default: nullptr)
         *
         */
        FNode(const DataType& data, FNode<DataType>* child = nullptr)
            : m_data(DataType(data)), m_child(child)
        {
            App::log.d() << "Creating " << m_id;
        }

        /*!
         * Copy Constructor
         *
         * \param other: Other FNode to copy
         */
        FNode(const FNode<DataType>& other)
            : m_data(DataType(other.m_data))
        {
            App::log.d() << "Copying from " << other.m_id << " to " << m_id;
            m_child = other.isLeaf() ? nullptr : new FNode<DataType>(*other.m_child);
        }

        /*!
         * Move Constructor
         *
         * \param other: Other FNode to move
         */
        FNode(const FNode<DataType>&& other)
            : m_data(std::move(other.m_data)), m_child(other.m_child)
        {
            App::log.d() << "Moving from " << other.m_id << " to " << m_id;
            m_child = other.m_child;
            other.m_child = nullptr;
        }

        /*!
         * Destructor.
         * Recursively deletes all nodes
         */
        virtual ~FNode()
        {
            App::log.d() << "Deleting " << m_id;

            if(!isLeaf())
                delete m_child;
        }

        /*!
         * Checks if the node have a children
         *
         * \return False if have a child, true otherwise
         */
        bool isLeaf() const
        {
            return m_child == nullptr;
        }

        /*!
         * Add a child to the node.
         * Works if the node's child is null, or if the child to set is null
         *
         * \param child: Pointer to FNode to add to self
         * \return Reference to itself
        */
        FNode<DataType>& setChild(FNode<DataType>* child)
        {
            if(m_child != nullptr && child != nullptr)
                App::log.d() << "Replaced a child with another one (this= "
                             << this->getData() << ", child= " << child->getData() << ")";

            m_child = child;
            return *this;
        }

        /*!
         * Add a child to the node.
         *
         * \param child: FNode to add to self
         * \return Reference to itself
        */
        FNode<DataType>& setChild(const FNode<DataType>& child)
        {
            return setChild(&child);
        }

        /*!
         * Get the child of the node.
         *
         * \param child: Pointer to FNode to add to self
         * \return Reference to itself
        */
        FNode<DataType>* getChild() const
        {
            return m_child;
        }

        /*!
         * Get the number of childs.
         *
         * \return Number of childs of the node
        */
        fuint32 nchild() const
        {
            return isLeaf() ? 0 : m_child->nchild() + 1;
        }

        /*!
         * Get the data contained in the node.
         *
         * \return Reference to the Data
        */
        DataType& getData()
        {
            return m_data;
        }
};

} // Namespace fit

#endif // FNODE_HPP

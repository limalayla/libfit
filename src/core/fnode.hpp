#ifndef FNODE_HPP
#define FNODE_HPP

#include "fobject.hpp"

namespace fit {

#define TEMPLATE_NODE template<typename DataType>
/*!
 * \brief Element of a Linked List (FLinkList)
 */
TEMPLATE_NODE
class FNode : public FObject
{
    /* Members */
    protected:
        //! Data hold by the node
        DataType m_data;
        
        //! Pointer to the next node
        FNode<DataType>* m_child;

    /* Methods */
    public:
        /*!
         * Default Constructor
         *
         * @param data  Data filling the head node
         * @param child Optional pointer to the next child
         *
         */
        FNode(const DataType& data, FNode<DataType>* child = nullptr)
            : m_data(DataType(data)), m_child(child)
        {
                #ifdef DEBUG
                std::cout << "Creating " << m_id << std::endl;
                #endif
        }

        /*!
         * Copy Constructor
         *
         * @param other Other FNode to be copied
         *
         */
        FNode(const FNode<DataType>& other)
            : m_data(DataType(other.m_data))
        {
                #ifdef DEBUG
            std::cout << "Copying from " << other.m_id << " to " << m_id << std::endl;
                #endif
            m_child = other.isLeaf() ? nullptr : new FNode<DataType>(*other.m_child);
        }

        /*!
         * Move Constructor
         *
         * @param other Other FNode to be moved
         *
         */
        FNode(const FNode<DataType>&& other)
            : m_data(std::move(other.m_data))
        {
            std::cout << "Moving from " << other.m_id << " to " << m_id << std::endl;
            m_child = other.isLeaf() ? nullptr : other.m_child;
            other.m_child = nullptr;
        }

        /*!
         * Destructor
         * Recursively deletes all nodes
         *
         */
        ~FNode()
        {
            std::cout << "Deleting " << m_id << std::endl;
            if(!isLeaf())
                delete m_child;
        }


        bool isLeaf() const
        {
            return m_child == nullptr;
        }

        /**
            Write description of function here.
            The function should follow these comments.
            Use of "brief" tag is optional. (no point to it)

            The function arguments listed with "param" will be compared
            to the declaration and verified.

            @param[in]     child Description of first function argument.
            @return Description of returned value.
        */
        FNode<DataType>& setChild(FNode<DataType>* child)
        {
            std::cout << "setchild" << std::endl;
            if(!isLeaf() && false) /* Not sure that's useful */
                #ifdef DEBUG
                throw std::runtime_error(FString("Tried adding a child to a node that already have one (this= ")
                                         + std::to_string(this->getData()) + FString(", child= ")
                                         + std::to_string(child->getData()) + FString(")"));
                #else
                throw std::runtime_error("Tried adding a child to a node that already have one");
                #endif

            m_child = child;
            return *this;
        }

        FNode<DataType>& setChild(const FNode<DataType>& child)
        {
            return setChild(&child);
        }

        FNode<DataType>* getChild() const
        {
            return m_child;
        }

        fuint32 nchild() const
        {
            return isLeaf() ? 1 : m_child->nchild()+1;
        }

        DataType& getData()
        {
            return m_data;
        }
};

} // Namespace fit

#endif // FNODE_HPP

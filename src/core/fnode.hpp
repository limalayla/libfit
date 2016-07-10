#ifndef FNODE_HPP
#define FNODE_HPP

#include "fobject.hpp"

namespace fit {

#define TEMPLATE_NODE template<typename DataType>

TEMPLATE_NODE
class FNode : public FObject
{
    /* Members */
    protected:
        DataType m_data;
        FNode<DataType>* m_child;

    /* Methods */
    public:
        FNode(const DataType& data, FNode<DataType>* child = nullptr)
            : m_data(DataType(data)), m_child(child)
        {
            std::cout << "Creating " << m_id << std::endl;
        }

        FNode(const FNode<DataType>& other)
            : m_data(DataType(other.m_data))
        {
            std::cout << "Copying from " << other.m_id << " to " << m_id << std::endl;
            m_child = other.isLeaf() ? nullptr : new FNode<DataType>(*other.m_child);
        }

        FNode(const FNode<DataType>&& other)
            : m_data(other.m_data)
        {
            std::cout << "Moving from " << other.m_id << " to " << m_id << std::endl;
            m_child = other.isLeaf() ? nullptr : other.m_child;
            other.m_child = nullptr;
        }

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

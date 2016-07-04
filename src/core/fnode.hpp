#ifndef FNODE_HPP
#define FNODE_HPP

#include "fobject.hpp"
#include <memory>
#include <stdexcept>
#include <sstream>

namespace fit {

#define TEMPLATE_NODE template<typename DataType>

TEMPLATE_NODE
class FNode : public FObject
{
    public:
        FNode(const DataType& data); // Classc Constructor
        FNode(const FNode<DataType>& other); // Copy Constructor
        FNode(const FNode<DataType>&& other); // Move Constructor
        ~FNode(); // Desctructor

        bool isLeaf() const;
        bool isBinary() const;

        void display(int level = 0) const;
        fuint32 nchild();

        FNode<DataType>& addChild(const FNode<DataType>& child);

        FNode<DataType>& operator()(fuint32 index);
        DataType&        operator[](fuint32 index);

    protected:
        DataType m_data;
        std::unique_ptr<FNode<DataType>> m_child;
        std::unique_ptr<FNode<DataType>> m_bro;

        bool isLastBro() const;
        FNode<DataType>* getLastBro();
};

TEMPLATE_NODE
FNode<DataType>::FNode(const DataType& data)
    : m_data(DataType(data)), m_child(nullptr), m_bro(nullptr)
{
    std::cout << "Creating " << m_id << std::endl;
}

TEMPLATE_NODE
FNode<DataType>::FNode(const FNode<DataType>& other)
    : m_data(DataType(other.m_data))
{
    std::cout << "Copying from " << other.m_id << " to " << m_id << std::endl;
    m_child = !other.isLeaf()    ? std::unique_ptr<FNode<DataType>>(new FNode<DataType>(*other.m_child)) : nullptr;
    m_child = !other.isLastBro() ? std::unique_ptr<FNode<DataType>>(new FNode<DataType>(*other.m_bro))   : nullptr;
}

TEMPLATE_NODE
FNode<DataType>::FNode(const FNode<DataType>&& other)
    : m_data(other.m_data)
{
    std::cout << "Moving from " << other.m_id << " to " << m_id << std::endl;
    m_child = !other.isLeaf()    ? std::unique_ptr<FNode<DataType>>(std::move(other.m_child)) : nullptr;
    m_child = !other.isLastBro() ? std::unique_ptr<FNode<DataType>>(std::move(other.m_bro))   : nullptr;
}

TEMPLATE_NODE
FNode<DataType>::~FNode()
{
    std::cout << "Deleting " << m_id << std::endl;
    //delete m_child;
    //delete m_bro;
}


TEMPLATE_NODE bool
FNode<DataType>::isLeaf() const
{
    return m_child == nullptr;
}

TEMPLATE_NODE bool
FNode<DataType>::isLastBro() const
{
    return m_bro == nullptr;
}

TEMPLATE_NODE bool
FNode<DataType>::isBinary() const
{
    return nchild() < 3;
}

TEMPLATE_NODE void
FNode<DataType>::display(int level) const
{
    for(uint16_t i= 0; i< level; i++)
        std::cout << "\t";

    std::cout << m_data << std::endl;

    if(!isLeaf())    m_child->display(level+1);
    if(!isLastBro()) m_bro->display(level);
}

TEMPLATE_NODE fuint32
FNode<DataType>::nchild()
{
    FNode<DataType>* curNode = this;
    fuint32 count(0);

    while(!curNode->isLeaf())
    {
        curNode = curNode->m_child.get();
        count++;
    }

    return count;
}

TEMPLATE_NODE FNode<DataType>*
FNode<DataType>::getLastBro()
{
    FNode<DataType>* curNode = this;

    while(!curNode->isLastBro())
        curNode = curNode->m_bro.get();

    return curNode;
}

TEMPLATE_NODE FNode<DataType>&
FNode<DataType>::addChild(const FNode<DataType>& child)
{
    FNode<DataType>* curNode = m_child.get();

    if(curNode == nullptr)
    {
        m_child = std::unique_ptr<FNode<DataType>> (new FNode<DataType>(child));
        std::cout << "Adding " << m_child->m_id << "("<< child.m_id << ")"<< " under " << m_id << std::endl;
    }

    else
    {
        curNode = curNode->getLastBro();
        curNode->m_bro = std::unique_ptr<FNode<DataType>> (new FNode<DataType>(child));
        std::cout << "Adding " << curNode->m_bro->m_id << "("<< child.m_id << ")"<< " under " << m_id << " and after " << curNode->m_id << std::endl;
    }

    return *this;
}

TEMPLATE_NODE FNode<DataType>&
FNode<DataType>::operator()(fuint32 index)
{
    FNode<DataType>* curNode = this;
    fuint32 curIndex(0);

    while(curIndex < index && curNode->m_child != nullptr)
    {
        curNode = curNode->m_child.get();
        curIndex++;
    }

    if(index != curIndex)
    {
        std::stringstream ss;
        ss << "Trying to access out of range element: " << index << " while size is " << curIndex;
        throw std::out_of_range(ss.str());
    }

    return *curNode;
}

TEMPLATE_NODE DataType&
FNode<DataType>::operator[](fuint32 index)
{
    return (*this)(index).m_data;
}

} // Namespace fit

#endif // FNODE_HPP

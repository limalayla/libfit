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

} // Namespace fit

#include "fnode.cpp"

#endif // FNODE_HPP

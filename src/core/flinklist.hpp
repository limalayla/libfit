#ifndef FLINKLIST_HPP
#define FLINKLIST_HPP

#include "fnode.hpp"

namespace fit {

TEMPLATE_NODE
class FLinkList : public FObject
{
    /* Members */
    protected:
        FNode<DataType>* m_head;
        fuint32 m_nelem;

    /* Methods */
    public:
        FLinkList(FNode<DataType>* head = nullptr)
            : m_head(head), m_nelem(1)
        {
            if(!m_head->isLeaf())
                m_nelem = m_head->nchild();
        }

        FLinkList(const DataType& headData)
            : FLinkList(new FNode<DataType>(headData))
        {

        }

        FLinkList(const FLinkList<DataType>& other)
            : m_head(new FNode<DataType>(m_head)), m_nelem(other.m_nelem)
        {

        }

        FLinkList(const FLinkList<DataType>&& other)
            : m_head(other.m_head), m_nelem(other.m_nelem)
        {
            other.m_head = nullptr;
        }

        ~FLinkList()
        {
            if(m_head != nullptr)
                delete m_head;
        }

        FLinkList& add(const DataType& data, fuint32 pos)
        {
            pos = std::min(pos, m_nelem);
            FNode<DataType>* newNode = new FNode<DataType>(data);

            if(pos == 0)
            {
                newNode->setChild(m_head);
                m_head = newNode;
            }
            else
            {
                FNode<DataType>* curNode = m_head;

                for(fuint32 i= 1; i< pos; i++)
                    curNode = curNode->getChild();

                newNode->setChild(curNode->getChild());
                curNode->setChild(newNode);
            }

            m_nelem++;
            return *this;
        }

        FLinkList& push(const DataType& data)
        {
            return add(data, m_nelem);
        }

        void display() const
        {
            using namespace std;
            FNode<DataType>* curNode = m_head;

            cout << "LinkList (" << m_nelem << ")" << endl;

            while(curNode != nullptr)
            {
                cout << "  -> " ;

                #ifdef DEBUG
                cout << "(" << std::hex << curNode << std::dec << ") ";
                #endif

                cout << curNode->getData() << "\t" << endl;
                curNode = curNode->getChild();
            }

            cout << endl;
        }

        FNode<DataType>& operator()(fuint32 index)
        {
            if(index >= m_nelem)
                throw(std::out_of_range("Index ("   + std::to_string(index)
                                                    + ") exceeds the linked list's number of elements ("
                                                    + std::to_string(m_nelem) + ")"
                ));

            FNode<DataType>* curNode = m_head;

            for(fuint32 i= 0; i< index; i++)
                curNode = curNode->getChild();

            return *curNode;
        }

        DataType& operator[](fuint32 index)
        {
            return (*this)(index).getData();
        }
};

} // Namespace fit

#endif // FNODE_HPP

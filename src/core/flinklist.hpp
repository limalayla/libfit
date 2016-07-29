#ifndef FLINKLIST_HPP
#define FLINKLIST_HPP

#include "fnode.hpp"

namespace fit {

/*!
 * Linked List class.
 * For those who don't know, a linked list is a data structure made out of nodes, each one being a piece of data and a link to the next.
 */
TEMPLATE_NODE
class FLinkList : public FObject
{
    /* Members */
    protected:
        //! Head Node
        FNode<DataType>* m_head;

        //! Total number of elements
        fuint32 m_nelem;

    /* Methods */
    public:
        /*!
         * Default constructor - Node version
         * \param Pointer to the head node
         */
        FLinkList(FNode<DataType>* head)
            : m_head(head), m_nelem(1 + head->nchild())
        {

        }

        /*!
         * Default constructor - Data version
         * \param First data of the linked list
         */
        FLinkList(const DataType& headData)
            : FLinkList(new FNode<DataType>(headData))
        {

        }

        /*!
         * Copy constructor
         * \param Linked List to be copied
         */
        FLinkList(const FLinkList<DataType>& other)
            : m_head(new FNode<DataType>(m_head)), m_nelem(other.m_nelem)
        {

        }

        /*!
         * Move constructor
         * \param Linked List to be moved
         */
        FLinkList(const FLinkList<DataType>&& other)
            : m_head(other.m_head), m_nelem(other.m_nelem)
        {
            other.m_head = nullptr;
        }

        /*!
         * Destructor
         */
        ~FLinkList()
        {
            if(m_head != nullptr)
                delete m_head;
        }

        /*!
         * Inserts an element to the Linked List, at the specified position
         * \param Data to insert
         * \param Position at which the data is inserted, going from 0 to N-1
         * \return Reference to the updated Linked List
         */
        FLinkList& insert(const DataType& data, fuint32 pos)
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

        /*!
         * Insert data at the end of the Linked List
         * \param Data to insert
         * \return Reference to the updated Linked List
         */
        FLinkList& push(const DataType& data)
        {
            return insert(data, m_nelem);
        }

        /*!
         * Outputs the Linked List
         */
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

        /*!
         * Node Getter
         * \param Position of the node to get (range checked)
         * \return Reference to the node
         */
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

        /*!
         * Data Getter
         * \param Position of the data to get (range checked)
         * \return Reference to the data
         */
        DataType& operator[](fuint32 index)
        {
            return (*this)(index).getData();
        }
};

} // Namespace fit

#endif // FNODE_HPP

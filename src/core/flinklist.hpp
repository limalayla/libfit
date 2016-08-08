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
        //! Head Node.
        FNode<DataType>* m_head;

        //! Total number of elements.
        fuint32 m_nelem;

    /* Methods */
    public:
        /*!
         * Default constructor - Node version.
         *
         * \param head: Pointer to the head node.
         */
        FLinkList(FNode<DataType>* head)
            : m_head(head), m_nelem(1 + head->nchild())
        {

        }

        /*!
         * Default constructor - Data version.
         *
         * \param headData: First data of the linked list.
         */
        FLinkList(const DataType& headData)
            : FLinkList(new FNode<DataType>(headData))
        {

        }

        /*!
         * Copy constructor.
         *
         * \param other: FLinkList to copy.
         */
        FLinkList(const FLinkList<DataType>& other)
            : m_head(new FNode<DataType>(m_head)), m_nelem(other.m_nelem)
        {

        }

        /*!
         * Move constructor.
         *
         * \param other: FLinkList to move.
         */
        FLinkList(const FLinkList<DataType>&& other)
            : m_head(other.m_head), m_nelem(other.m_nelem)
        {
            other.m_head = nullptr;
        }

        /*!
         * Destructor.
         */
        virtual ~FLinkList()
        {
            if(m_head != nullptr)
                delete m_head;
        }

        /*!
         * Inserts an element to the Linked List, at the specified position.
         *
         * \param data: Data to insert.
         * \param pos: Position at which the data is inserted, going from 0 to N-1.
         * \return Reference to itself.
         */
        FLinkList& insert(const DataType& data, fuint32 pos)
        {
            // Limit the insertion pos to the end of the linked list
            pos = std::min(pos, m_nelem);

            // Create the node to insert
            FNode<DataType>* newNode = new FNode<DataType>(data);

            if(pos == 0)
            {
                newNode->setChild(m_head);
                m_head = newNode;
            }
            else
            {
                FNode<DataType>* curNode = m_head;

                // Travel to the insertion point
                for(fuint32 i= 1; i< pos; i++)
                {
                    if(curNode != nullptr)
                        curNode = curNode->getChild();
                    else
                        App::log.w() << "m_nelem doesn't match the node count (" << i << ")";
                }

                // Insert
                newNode->setChild(curNode->getChild());
                curNode->setChild(newNode);
            }

            m_nelem++;
            return *this;
        }

        /*!
         * Insert data at the end of the linked list.
         *
         * \param data: Data to insert.
         * \return Reference to itself.
         */
        FLinkList& push(const DataType& data)
        {
            return insert(data, m_nelem);
        }

        /*!
         * Outputs the Linked List (Debug purposes).
         */
        void display() const
        {
            using namespace std;
            FNode<DataType>* curNode = m_head;

            cout << endl <<  "LinkList (" << m_nelem << ")" << endl;

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
         * Node Getter.
         *
         * \param index: Position of the node to get (range checked).
         * \return Reference to the node.
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
         * Data Getter.
         *
         * \param index: Position of the data to get (range checked).
         * \return Reference to the data.
         */
        DataType& operator[](fuint32 index)
        {
            return (*this)(index).getData();
        }

}; // Class FLinkList

} // Namespace fit

#endif // FLINKLIST_HPP

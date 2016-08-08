#include "fstringlist.hpp"

namespace fit
{

    /*!
     * Base Constructor.
     */
    FStringList::FStringList()
        : m_strlist()
    {}

    /*!
     * Copy Constructor.
     */
    FStringList::FStringList(const FStringList& other)
        : m_strlist(other.m_strlist)
    {}

    /*!
     * Constructor with an const array of C-style strings.
     *
     * \param strings: Const array of C-style strings that will fill the list.
     */
    FStringList::FStringList(const char** strings)
        : m_strlist()
    {
        std::vector<FString> res;
        fuint16 i(0);

        while(strings[i] != nullptr)
        {
            res.push_back(FString(strings[i]));
            i++;
        }

        m_strlist = res;
    }

    /*!
     * Constructor with an array of C-style strings.
     *
     * \param strings: Array of C-style strings that will fill the list.
     */
    FStringList::FStringList(char** strings)
        : m_strlist()
    {
        std::vector<FString> res;
        fuint16 i(0);

        while(strings[i] != nullptr)
        {
            res.push_back(FString(strings[i]));
            i++;
        }

        m_strlist = res;
    }

    /*!
     * Constructor with an array of FString.
     *
     * \param strings: Array of FString that will fill the list.
     */
    FStringList::FStringList(const std::vector<FString>& strings)
        : m_strlist(strings)
    {}

    /*!
     * Constructor with a single FString.
     *
     * \param string: FString that will be the unique string of the list.
     */
    FStringList::FStringList(const FString& string)
        : m_strlist()
    {
        m_strlist.push_back(string);
    }

    /*!
     * Constructor with a single C-style string.
     *
     * \param string: C-style string that will be the unique string of the list.
     */
    FStringList::FStringList(const char* string)
        : FStringList(FString(string))
    {}

    /*!
     * Destructor.
     */
    FStringList::~FStringList()
    {

    }

    /*!
     * \todo Doc
     */
    FStringList& FStringList::add(const FString& string, fuint32 pos)
    {
        m_strlist.insert(m_strlist.cbegin() + pos, string);
        return *this;
    }

    /*!
     * \todo Doc
     */
    FStringList& FStringList::add(const char* string, fuint32 pos)
    {
        return add(FString(string), pos);
    }

    /*!
     * \todo Doc
     */
    FStringList& FStringList::del(fuint32 pos)
    {
        m_strlist.erase(m_strlist.cbegin() + pos);

        return *this;
    }

    /*!
     * \todo Doc
     */
    FStringList FStringList::get(fuint32 start, fuint32 end) const
    {
        FStringList res;

        for(fuint32 i= start; i<= end; i++)
            res.add(m_strlist[i], res.size());

        return res;
    }

    /*!
     * \todo Doc
     */
    FString FStringList::get(fuint32 index) const
    {
        return m_strlist.at(index);
    }

    /*!
     * Accessor at a given index.
     *
     * \param index: Wanted FString position.
     * \return FString at the given index.
     */
     FString FStringList::operator[](const fuint32 index) const
     {
         return m_strlist[index];
     }

     /*!
      * \todo Doc
      */
     fuint32 FStringList::size() const
     {
         return m_strlist.size();
     }

     /*!
      * \todo Doc
      */
     std::vector<FString> FStringList::toVector() const
     {
         return m_strlist;
     }

     #ifdef DEBUG
         FString FStringList::debug() const
         {
             std::stringstream res;

             for(const FString& str : m_strlist)
                res << str << std::endl;

             return res.str();
         }
     #endif

} // Namespace fit

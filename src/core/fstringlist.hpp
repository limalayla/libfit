#ifndef FSTRINGLIST_HPP
#define FSTRINGLIST_HPP

#include "fobject.hpp"

namespace fit
{

    /*!
     * Hold an array of string and provide tools to use it.
     *
     * \todo Tools like sort etc.
     */
    class FStringList : public FObject
    {
        protected:
            std::vector<FString> m_strlist;

        public:
            FStringList();
            FStringList(const FStringList& other);
            FStringList(const std::vector<FString>& strings);
            FStringList(const char** strings);
            FStringList(      char** strings);
            FStringList(const FString& string);
            FStringList(const char* string);
            virtual ~FStringList();

            FStringList& add(const FString& string, fuint32 pos);
            FStringList& add(const char* string, fuint32 pos);
            FStringList& del(fuint32 pos);

            FStringList get(fuint32 start, fuint32 end) const;
            FString get(fuint32 index) const;
            FString operator[](const fuint32 index) const;
            fuint32 size() const;

            std::vector<FString> toVector() const;

            #ifdef DEBUG
                FString debug() const;
            #endif

    }; // Class FStringList

} // Namespace fit

#endif // FSTRINGLIST_HPP

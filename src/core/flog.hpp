#ifndef FLOG_HPP
#define FLOG_HPP

#include "fobject.hpp"
#include "ftools.hpp"

namespace fit {

/*!
 * Logging utility class
 */
class FLog : public FObject
{
    /* Members */
    protected:
        // Time related members (used in the format function)
        std::time_t m_time;
        char m_timeString[100];

        std::ostream& m_os;
        std::ostream m_dummyOs;
        fuint8 m_minLevel;
        static const std::vector<FString> m_levels;

    /* Methods */
    protected:
        FString format(const fuint8 level);
        std::ostream& getOs(fuint8 level);

    public:
        FLog(const fuint8 level = FLog::Info, std::ostream& os = std::cout);
        ~FLog();

        std::ostream& d();
        std::ostream& i();
        std::ostream& w();
        std::ostream& e();

        enum levels
        {
            Debug,
            Info ,
            Warn ,
            Error
        };
};

} // Namespace fit

#endif // FLOG_HPP

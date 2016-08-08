#ifndef FLOG_HPP
#define FLOG_HPP

#include "fobject.hpp"

namespace fit {

/*!
 * Logging utility class.
 * Not an optimal one since it will still create the message content client-side, even if the level is too low,
 *  in opposition to macro-based ones.
 */
class FLog : public FObject
{
    /* Members */
    public:
        enum class LogLevel
        {
            Debug,
            Info ,
            Warn ,
            Error,
            None
        };

    protected:
        /* Time related members (used in the format function) */
            //! Current time while formating the output.
            //! Class member so that in the FLog::format function, it wont be re-computed if within the same second.
            std::time_t m_time;

            //! Formated string representing the current time (used in FLog::format).
            //! Class member so that in the FLog::format function, it wont be re-computed if within the same second.
            char m_timeString[100];

        /* Output related stuff */
            //! Output OStream used to write the messages.
            std::ostream& m_os;

            //! Dummy OStream used like /dev/null, to send all ouput into hell.
            std::ostream m_dummyOs;

        /* Level related stuff */
            //! Store the minimum level that will trigger the output.
            LogLevel m_minLevel;

            //! Vector mapping a level with its string.
            static const std::vector<FString> m_levels;

    /* Methods */
    protected:
        FString format(const LogLevel level);
        std::ostream& getOs(const LogLevel level);

    public:
        FLog(const LogLevel level = LogLevel::Info, std::ostream& os = std::cout);
        FLog(const FLog& other);
        virtual ~FLog();

        FLog& operator=(const FLog& other);

        std::ostream& d();
        std::ostream& i();
        std::ostream& w();
        std::ostream& e();

}; // Class FLog

} // Namespace fit

#endif // FLOG_HPP

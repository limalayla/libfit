#include "flog.hpp"

namespace fit {

const std::vector<FString> FLog::m_levels = {   "DEBUG",
                                                "INFO ",
                                                "WARN ",
                                                "ERROR"
};

#ifdef DEBUG
    FLog FLog::dev = FLog(FLog::LogLevel::Debug);
#else
    FLog FLog::dev = FLog(FLog::LogLevel::Warn);
#endif

/*!
 * Base constructor.
 *
 * \param level: Minimum level triggering the output (default: Info).
 * \param os: Optionnal ostream for the output (default: std::cout).
 */
FLog::FLog(const FLog::LogLevel level, std::ostream& os)
    : m_time(0), m_timeString(""), m_os(os), m_dummyOs(nullptr), m_minLevel(level)
{

}


/*!
 * Copy constructor.
 *
 * \param other: FLog to copy.
 * \bug m_minLevel isn't copied.
 */
FLog::FLog(const FLog& other)
    :   m_time(other.m_time),
        m_os(*(&other.m_os)), // Eh, wat?
        m_dummyOs(nullptr),
        m_minLevel(LogLevel::Debug/*other.m_minLevel*/)
{
    strcpy(m_timeString, other.m_timeString);
}

/*!
 * Destructor.
 *
 * \bug When closing the ostream, a % symbols appears. A workaround is to put a newline but the formating is then bad.
 */
FLog::~FLog()
{
    m_os << std::endl;
    m_os.clear();
    m_os.flush();
}

/*!
 * Deep assignement operator.
 *
 * \param other: FLog to assign.
 * \return Reference to itself.
 *
 * \bug m_os isn't copied.
 */
FLog& FLog::operator=(const FLog& other)
{
    m_time = 0;
    //m_timeString = "";
    //m_os = other.m_os;
    m_minLevel = other.m_minLevel;

    return(*this);
}

//! Provides Debug Log.
std::ostream& FLog::d()
{ return getOs(FLog::LogLevel::Debug); }

//! Provides Info Log.
std::ostream& FLog::i()
{ return getOs(FLog::LogLevel::Info); }

//! Provides Warn Log.
std::ostream& FLog::w()
{ return getOs(FLog::LogLevel::Warn); }

//! Provides Error Log.
std::ostream& FLog::e()
{ return getOs(FLog::LogLevel::Error); }

/*!
 * Utility function formating a string that will be output at the begining of the output.
 *
 * \param level: Level of the format.
 * \return Formated String.
 */
FString FLog::format(const FLog::LogLevel level)
{
    std::stringstream ss;
    if(m_time != time(nullptr))
    {
        m_time = time(nullptr);
        struct tm* tstruct = localtime(&m_time);
        strftime(m_timeString, sizeof(m_timeString), "%Y-%m-%d.%X", tstruct);
    }

    ss << std::endl << "[" << m_levels[static_cast<int>(level)] << "] " << m_timeString << " -- ";
    return ss.str();
}

/*!
 * Provides either the already formated ostream, or a dummy ostream.
 * Whether the level is higher enough to trigger the output or not.
 *
 * \param level: Log level.
 * \return Either the ostream, with some info already written, or a dummy ostream (like /dev/null).
 */
std::ostream& FLog::getOs(const FLog::LogLevel level)
{
    if(m_minLevel <= level)
    {
        m_os << format(level);
        return m_os;
    }
    else
    {
        return m_dummyOs;
    }
}

} // Namespace fit

#include "flog.hpp"

namespace fit {

const std::vector<FString> FLog::m_levels = {   "DEBUG",
                                                "INFO ",
                                                "WARN ",
                                                "ERROR"
};

/*!
 * Default constructor
 * \param Minimum level triggering the output. Defaults to Info
 * \param Optionnal ostream for the output. Defaults to std::cout
 */
FLog::FLog(const FLog::LogLevel level, std::ostream& os)
    : m_time(0), m_timeString(""), m_os(os), m_dummyOs(nullptr), m_minLevel(level)
{

}

/*!
 * Destructor
 */
FLog::~FLog()
{
    m_os.clear();
    m_os << std::endl;
}


/*! Provides Debug Log */
std::ostream& FLog::d()
{ return getOs(FLog::LogLevel::Debug); }

/*! Provides Info Log */
std::ostream& FLog::i()
{ return getOs(FLog::LogLevel::Info); }

/*! Provides Warn Log */
std::ostream& FLog::w()
{ return getOs(FLog::LogLevel::Warn); }

/*! Provides Error Log */
std::ostream& FLog::e()
{ return getOs(FLog::LogLevel::Error); }

/*!
 * Utility function formating a string that will be output at the begining of the output
 * \param Level of the format
 * \return Formated String
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
 * Provides either the already formated ostream, or a dummy ostream, whether the level is higher enough to trigger the output or not
 * \param Log level
 * \return Either the ostream, with some info already written, or a dummy ostream (like /dev/null)
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

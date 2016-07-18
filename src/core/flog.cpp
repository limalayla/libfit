#include "flog.hpp"

namespace fit {

const std::vector<FString> FLog::m_levels = {   "DEBUG",
                                                "INFO ",
                                                "WARN ",
                                                "ERROR"
};

FLog::FLog(const fuint8 level, std::ostream& os)
    : m_time(0), m_timeString(""), m_os(os), m_dummyOs(nullptr), m_minLevel(level)
{

}

FLog::~FLog()
{
    m_os.clear();
    m_os << std::endl;
}

std::ostream& FLog::d()
{ return getOs(0); }

std::ostream& FLog::i()
{ return getOs(1); }

std::ostream& FLog::w()
{ return getOs(2); }

std::ostream& FLog::e()
{ return getOs(3); }

FString FLog::format(const fuint8 level)
{
    std::stringstream ss;
    if(m_time != time(nullptr))
    {
        m_time = time(nullptr);
        struct tm* tstruct = localtime(&m_time);
        strftime(m_timeString, sizeof(m_timeString), "%Y-%m-%d.%X", tstruct);
    }

    ss << std::endl << "[" << m_levels.at(level) << "] " << m_timeString << " -- ";
    return ss.str();
}

std::ostream& FLog::getOs(fuint8 level)
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

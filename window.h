#ifndef WINDOW
#define WINDOW

#include "client.h"

class Window
{
private:
    int m_id;
    int m_busyTime;
    int m_workTime;
    int m_clientsServed;

public:
    Window(int id)
        : m_id(id)
        , m_busyTime(0)
        , m_workTime(0)
        , m_clientsServed(0)
    {

    }

    void doService(Client& client)
    {
        if (m_clientsServed == 0)
            m_workTime = client.getArrivedTime();
        m_busyTime = client.getServiceTime();
        m_workTime += m_busyTime;
        m_clientsServed++;
    }

    int waitPeriod(Client& client)
    {
        if (m_clientsServed == 0)
            return 0;
        int waitPeriod = m_workTime - client.getArrivedTime();
        if (waitPeriod < 0)
            waitPeriod = 0;
        return waitPeriod;
    }

    int getBusyTime() const
    {
        return m_busyTime;
    }

    int getId() const
    {
        return m_id;
    }

    int getWorkedTime() const
    {
        return m_workTime;
    }
};

#endif // WINDOW


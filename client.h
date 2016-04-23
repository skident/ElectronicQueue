#ifndef CLIENT
#define CLIENT

class Client
{
private:
    int m_arrivedTime;
    int m_serviceTime;
    int m_id;
    int m_followerId;
    int m_windowId;

public:
    Client()
        : m_arrivedTime(0)
        , m_serviceTime(0)
        , m_id(0)
        , m_followerId(-1)
        , m_windowId(-1)
    {

    }

    void setup(int id, int arrivedTime, int serviceTime)
    {
        m_id = id;
        m_arrivedTime = arrivedTime;
        m_serviceTime = serviceTime;
    }

    void setFollowerId(int id)
    {
        m_followerId = id;
    }

    void setWindowId(int id)
    {
        m_windowId = id;
    }

    int getFollowerId() const
    {
        return m_followerId;
    }

    int getWindowId() const
    {
        return m_windowId;
    }

    int getArrivedTime() const
    {
        return m_arrivedTime;
    }

    int getServiceTime() const
    {
        return m_serviceTime;
    }
};

#endif // CLIENT


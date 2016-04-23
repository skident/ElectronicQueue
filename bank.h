#ifndef BANK
#define BANK

#include <vector>
#include <set>
#include "client.h"
#include "window.h"
#include <iostream>

using namespace std;

class Bank
{
private:
    vector<Client> m_clients;
    vector<Window> m_windows;
    int m_clientId;
    set<int, greater<int> > m_topWaiters;
    set<int, greater<int> >::iterator it;

    Window& getWindow(int id)
    {
        if (id != -1)
            return m_windows[id];

        int idx = 0;
        for (size_t i = 1; i < m_windows.size(); i++)
        {
            if (m_windows[idx].getBusyTime() > m_windows[i].getBusyTime())
            {
                idx = i;
            }
        }
        return m_windows[idx];
    }

    void setFollowerWindowId(const Client& client, int winId)
    {
        int followerId = client.getFollowerId();
        if (followerId != -1)
            m_clients[followerId].setWindowId(winId);
    }

public:
    Bank(int windowsNum)
        : m_clientId(0)
    {
        for (int i = 0; i < windowsNum; i++)
        {
            Window tmp(i);
            m_windows.push_back(tmp);
        }
    }

    void addClient(int arriveTime, int serviceTime)
    {
        Client tmp;
        tmp.setup(m_clientId, arriveTime, serviceTime);
        m_clients.push_back(tmp);
        m_clientId++;
    }

    void setNeighbour(int first, int second)
    {
        m_clients[first-1].setFollowerId(second-1);
    }

    void processQueue()
    {
        for (size_t i = 0; i < m_clients.size(); i++)
        {
            Client& client = m_clients[i];
            Window& window = getWindow(client.getWindowId());
            setFollowerWindowId(client, window.getId());

            int period = window.waitPeriod(client);
            m_topWaiters.insert(period);
            window.doService(client);
        }

        int maxWorkingTime = -1;
        for (int i = 0; i < m_windows.size(); i++)
        {
            int workingTime = m_windows[i].getWorkedTime();
            if (workingTime > maxWorkingTime)
                maxWorkingTime = workingTime;
        }

        it = m_topWaiters.begin();
        cout << maxWorkingTime << " " << *it << " ";
        it++;
        cout << *it << " ";
        it++;
        cout << *it << " ";
        cout << endl;
    }
};

#endif // BANK



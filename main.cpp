#include <iostream>
#include <fstream>
#include "bank.h"

using namespace std;

int main()
{
    fstream file("../ElectronicQueue/file.txt", ios::in);

    for (int i = 0; i < 3; i++)
    {
        int clientsNum = 0;
        int windowsNum = 0;
        file >> clientsNum; // read clients count
        file >> windowsNum; // read windows count

        cout << "Clients: " << clientsNum << " WIndows: " << windowsNum << endl;

        Bank bank(windowsNum);
        for (int i = 0; i < clientsNum; i++)
        {
            int arriveTime = 0;
            int serviceTime = 0;

            file >> arriveTime;
            file >> serviceTime;
            cout << "Client #0: " << arriveTime<< " | " << serviceTime << endl;
            bank.addClient(arriveTime, serviceTime);
        }

        int pairs = 0;
        file >> pairs;
        for (int i = 0; i <= pairs; i+=2)
        {
            int first = 0;
            int second = 0;
            file >> first;
            file >> second;
            bank.setNeighbour(first, second);
        }

        bank.processQueue();
    }

    return 0;
}


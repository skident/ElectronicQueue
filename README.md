# ElectronicQueue
Processor of electornic queue.
We have a bank. In bank we have count of working windows and count of clients.
Every client know own arrive time and time for service (how much time he spent in a window). Time of arrive expressions in minutes since bank starts work.
Also we have pairs of clients, for example 1, 3. It means that client 3 must go to the same window with the client 1, but not at the same time (1 window - 1 client).
We need to calculate the window which has the longest work time and top 3 waiting time in queue (difference between client arrive into bank and time when he was serviced).

So we need to read data from file.
Sample.txt:
4 1
10 10 10 20 10 15 15 20
1 1 3
4 2
10 10 10 20 10 15 15 20
1 1 3

Explanations:
line1:
  4 - number of clients
  1 - number of windows

line2:
  10 10 - arrive time 10, service time 10
  10 20 - arrive time 10, service time 20
  10 15 - arrive time 10, service time 15
  15 20 - arrive time 15, service time 20

line3:
  1 - number of pairs
  1 3 - client 3 will go to a window after client 1
  

Example:
Sample input:
4 1
10 10 10 20 10 15 15 20
1 1 3
4 2
10 10 10 20 10 15 15 20
1 1 3

Sample output:
75 40 30 10 
55 20 10 0 
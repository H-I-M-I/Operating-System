// C++ implementation of the FCFS algorithm
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

class process
{
public:
    pid_t p_no = 0;
    time_t start_AT = 0, AT = 0, BT_left = 0, BT = 0, temp_BT = 0, CT = 0, TAT = 0, WT = 0, RT = 0;
    int priority = 0;

    // Function for completion time
    void set_CT(time_t time)
    {
        CT = time;
        set_TAT();
        set_WT();
    }

    // Function for Turn Around Time
    void set_TAT()
    {
        TAT = CT - start_AT;
    }

    // Function for Waiting Time
    void set_WT()
    {
        WT = TAT - BT;
    }

    void P_set()
    {
        start_AT = AT;
        BT_left = BT;
    }
    // Function to set Response Time
    void set_RT(time_t time)
    {
        RT = time - start_AT;
    }

    friend bool operator<(const process &a, const process &b)
    {
        return a.AT > b.AT;
    }
};

// Function to implement FCFS algorithm
priority_queue<process> FCFS_run(priority_queue<process> ready_queue, queue<process> *gantt)
{
    priority_queue<process> completion_queue;
    process p;
    time_t clock = 0;

    // Till ready queue is not empty
    while (!ready_queue.empty())
    {

        // While clock is less than
        // Arrival Time
        while (clock < ready_queue.top().AT)
        {
            p.temp_BT++;
            clock++;
        }
        if (p.temp_BT > 0)
        {
            p.p_no = -1;
            p.CT = clock;
            (*gantt).push(p);
        }
        p = ready_queue.top();
        ready_queue.pop();
        p.set_RT(clock);
        while (p.BT_left > 0)
        {
            p.temp_BT++;
            p.BT_left--;
            clock++;
        }
        p.set_CT(clock);

        // Update the Gantt Chart
        (*gantt).push(p);
        p.temp_BT = 0;

        // Update the completion time to
        // the queue
        completion_queue.push(p);
    }
    return completion_queue;
}

// Set data on the basis of given table
priority_queue<process> set_sample_data()
{
    priority_queue<process> ready_queue;
    process temp;
    temp.AT = 0;
    temp.BT = 5;
    temp.priority = 3;
    temp.p_no = 1;
    temp.P_set();
    ready_queue.push(temp);
    temp.AT = 1;
    temp.BT = 2;
    temp.priority = 2;
    temp.p_no = 2;
    temp.P_set();
    ready_queue.push(temp);
    temp.AT = 2;
    temp.BT = 4;
    temp.priority = 1;
    temp.p_no = 3;
    temp.P_set();
    ready_queue.push(temp);

    return ready_queue;
}

// Function to get total Waiting Time
double get_total_WT(priority_queue<process> processes)
{
    double total = 0;
    while (!processes.empty())
    {
        total += processes.top().WT;
        processes.pop();
    }
    return total;
}

// Function to get total Turn Around Time
double get_total_TAT(priority_queue<process> processes)
{
    double total = 0;
    while (!processes.empty())
    {
        total += processes.top().TAT;
        processes.pop();
    }
    return total;
}

// Function to get total Completion Time
double get_total_CT(priority_queue<process> processes)
{
    double total = 0;
    while (!processes.empty())
    {
        total += processes.top().CT;
        processes.pop();
    }
    return total;
}

// Function to get total Response Time
double get_total_RT(priority_queue<process> processes)
{
    double total = 0;
    while (!processes.empty())
    {
        total += processes.top().RT;
        processes.pop();
    }
    return total;
}

// Function to display Completion Queue and
// all the time
void disp(priority_queue<process> main_queue, bool high)
{
    int i = 0, temp, size = main_queue.size();
    priority_queue<process> tempq = main_queue;
    double temp1;

    if (high == true)
        cout << "  " << endl;
    else
        cout << endl;
    cout << " Process No.  Arrival Time ";
    cout << " Burst Time  ";
    cout << " Turnaround Time  Waiting Time ";
    if (high == true)
        cout << " Priority " << endl;
    else
        cout << endl;

    if (high == true)
        cout << "  " << endl;
    else
        cout << endl;
    while (!main_queue.empty())
    {
        temp = to_string(main_queue.top().p_no).length();
        cout << ' ' << string(6 - temp / 2 - temp % 2, ' ') << main_queue.top().p_no << string(7 - temp / 2, ' ');
        temp = to_string(main_queue.top().start_AT).length();
        cout << ' ' << string(7 - temp / 2 - temp % 2, ' ') << main_queue.top().start_AT << string(7 - temp / 2, ' ');
        temp = to_string(main_queue.top().BT).length();
        cout << ' ' << string(6 - temp / 2 - temp % 2, ' ') << main_queue.top().BT << string(6 - temp / 2, ' ');
        temp = to_string(main_queue.top().CT).length();
        // cout << ' ' << string(8 - temp / 2 - temp % 2, ' ')<< main_queue.top().CT << string(9 - temp / 2, ' ');
        temp = to_string(main_queue.top().TAT).length();
        cout << ' ' << string(8 - temp / 2 - temp % 2, ' ') << main_queue.top().TAT << string(9 - temp / 2, ' ');
        temp = to_string(main_queue.top().WT).length();
        cout << ' ' << string(7 - temp / 2 - temp % 2, ' ') << main_queue.top().WT << string(7 - temp / 2, ' ');
        temp = to_string(main_queue.top().RT).length();
        // cout << ' ' << string(7 - temp / 2 - temp % 2, ' ')<< main_queue.top().RT << string(8 - temp / 2, ' ');
        if (high == true)
        {
            temp = to_string(main_queue.top().priority).length();
            cout << ' ' << string(5 - temp / 2 - temp % 2, ' ') << main_queue.top().priority << string(5 - temp / 2, ' ');
        }
        cout << " \n";
        main_queue.pop();
    }

    if (high == true)
        cout << "  ";
    cout << endl;
    temp1 = get_total_CT(tempq);
    // cout << "\nTotal completion time :- " << temp1<< endl;
    // cout << "Average completion time :- " << temp1 / size<< endl;
    temp1 = get_total_TAT(tempq);
    //cout << "\nTotal turnaround time: " << temp1 << endl;
    cout << "Average turnaround time: " << temp1 / size << endl;
    temp1 = get_total_WT(tempq);
    //cout << "\nTotal waiting time: " << temp1 << endl;
    cout << "Average waiting time: " << temp1 / size << endl;
    temp1 = get_total_RT(tempq);
    // cout << "\nTotal response time :- " << temp1<< endl;
    // cout << "Average response time :- " << temp1 / size<< endl;
}

// Function to display Gantt Chart
void disp_gantt_chart(queue<process> gantt)
{
    int temp, prev = 0;
    queue<process> spaces = gantt;
    cout << "\nGantt Chart: \n";

    // For 1st row of gantt chart
    while (!spaces.empty())
    {
        cout << string(to_string(spaces.front().p_no).length() + (spaces.front().p_no != -1) + 2 * spaces.front().temp_BT, ' ');
        spaces.pop();
    }
    cout << "\n|";
    spaces = gantt;

    // For process no. in 2nd row
    while (!spaces.empty())
    {
        cout << string(spaces.front().temp_BT, ' ');
        if (spaces.front().p_no == -1)
            cout << "Idle" << string(spaces.front().temp_BT, ' ') << '|';
        else
            cout << "P" << spaces.front().p_no << string(spaces.front().temp_BT, ' ') << '|';
        spaces.pop();
    }
    spaces = gantt;
    //cout << "\n";

    while (!spaces.empty())
    {
        cout << (string(to_string(spaces.front().p_no).length() + (spaces.front().p_no != -1) + 2 * spaces.front().temp_BT, ' '));
        spaces.pop();
    }
    spaces = gantt;
    cout << "\n0";
    // For 3rd row of gantt chart
    while (!spaces.empty())
    {
        temp = to_string(spaces.front().CT).length();
        cout << (string(to_string(spaces.front().p_no).length() + (spaces.front().p_no != -1) + 2 * spaces.front().temp_BT - temp / 2 - prev, ' ')) << spaces.front().CT;
        prev = temp / 2 - temp % 2 == 0;
        spaces.pop();
    }
    cout << "\n\n";
}

// Driver Code
int main()
{
    // Initialise Ready and Completion Queue
    priority_queue<process> ready_queue;
    priority_queue<process> completion_queue;

    // queue for Gantt Chart
    queue<process> gantt;
    ready_queue = set_sample_data();

    // Function call for completion data
    completion_queue = FCFS_run(ready_queue, &gantt);

    disp_gantt_chart(gantt);
    disp(completion_queue, false);

    
    return 0;
}

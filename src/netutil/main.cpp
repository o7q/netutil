#include <iostream>
#include <ctime>
#include <string>

using namespace std;

// functions

// info functions
void about();  // 1
void github(); // 2
// module functions
void ping();        // 3
void netactivity(); // 4
void dnsquery();    // 5
void geolocator();  // 6
void routetracer(); // 7
// program functions
void updLogStr(); // update log string
// graphical functions
void sp();  // spacer
void clr(); // clear
void ps();  // pause
void col(); // color transition

// global variables

// program variables
string srtArgs = "powershell -command "; // powershell arguments
// graphical variables
string ver = "v1.1.0";                                   // version
string cred = "                                 by o7q"; // credit
string head = "               __        __  _ __\n"
              "   ____  ___  / /___  __/ /_(_) /\n"
              "  / __ \\/ _ \\/ __/ / / / __/ / / \n"
              " / / / /  __/ /_/ /_/ / /_/ / /  \n"
              "/_/ /_/\\___/\\__/\\__,_/\\__/_/_/   " +
              ver;                                                                                       // header
string qt = "To quit, input \"q\".";                                                                     // quit notice
string d = "\n\nDONE!";                                                                                      // done notice
string sep = "\n\n===============================================================================+\n\n"; // separator
// session variables
string sessDate;   // session date
int logNum;        // log number
string logType;    // log type
string logNum_str; // log number string
string logArgs;    // log arguments

main()
{
    // create session

    // configure ctime
    time_t n = time(NULL);
    tm *tm = localtime(&n);
    // create time ints
    int m = 1 + tm->tm_mon;
    int d = tm->tm_mday;
    int y = 1900 + tm->tm_year;
    int t_h = tm->tm_hour;
    int t_m = tm->tm_min;
    int t_s = tm->tm_sec;
    // ints -> strings
    string m_str = to_string(m);
    string d_str = to_string(d);
    string y_str = to_string(y);
    string t_h_str = to_string(t_h);
    string t_m_str = to_string(t_m);
    string t_s_str = to_string(t_s);
    // configure session date
    sessDate = m_str + d_str + y_str + "_" + t_h_str + t_m_str + t_s_str;
    // create session directory
    string dirCmd = "mkdir netutil\\sessions\\session" + sessDate + "\\logs";
    system(dirCmd.c_str());

    while (true)
    {
        clr();

        // show info and header
        cout << head + " [Menu]\n" + cred + "\n\nTo navigate, input a number.\nTo quit, input any non-number.\n\n"
                                            "INFO:\n[1] About\n[2] Open GitHub Repo\n\n"
                                            "MODULES:\n[3] Ping\n[4] Net Activity\n[5] DNS Query\n[6] Geolocator\n[7] Route Tracer\n\n";

        // module switch
        int i;
        cin >> i;
        col();
        switch (i)
        {
        case 0:
            col();
            _Exit(0);
            break;

        case 1:
            about();
            break;

        case 2:
            github();
            break;

        case 3:
            ping();
            break;

        case 4:
            netactivity();
            break;

        case 5:
            dnsquery();
            break;

        case 6:
            geolocator();
            break;

        case 7:
            routetracer();
            break;
        }
    }

    return 0;
}

// info functions

// about function (1)
void about()
{
    clr();

    // header
    cout << head + " [About]\n" + cred + "\n\nTo quit, press any key.";

    // about
    cout << sep + "netutil by o7q\nA command-line based utility-box full of helpful networking commands.\n\n"
                  "Operating Components:\n- ping\n- netstat\n- nslookup\n- ipinfo.io\n- tracert\n\n"
                  "* Farther documentation can be found on the netutil GitHub page which can be accessed from the menu." +
                sep;

    // quit
    sp();
    ps();
    col();
}

// github function (2)
void github()
{
    clr();

    system("start https://github.com/o7q/netutil");
}

// module functions

// ping function (3)
void ping()
{
    clr();

    // header
    cout << head + " [Ping]\n" + cred + "\n\n" + qt;

    // address input
    cout << sep + "Specify an address to ping:\n";
    string ip;
    cin >> ip;
    if (ip == "q")
    {
        col();

        return;
    }
    cout << "\n";

    // ping input
    cout << "Specify the number of pings:\n";
    string pi;
    cin >> pi;
    if (pi == "q")
    {
        col();

        return;
    }
    sp();

    // ping work
    logType = "ping";
    updLogStr();
    pi = srtArgs + " \"ping -n " + pi + " " + ip + logArgs;
    system(pi.c_str());
    logNum += 1;
    cout << d;
    cout << sep;
    sp();

    // quit
    ps();
    col();
}

// net activity function (4)
void netactivity()
{
    clr();

    // header
    cout << head + " [Net Activity]\n" + cred + "\n\n" + qt;

    // continue input
    cout << sep + "To continue, input any key. (\"q\" to quit)\n";
    string q;
    cin >> q;
    sp();

    // netactivity work
    if (q != "q")
    {
        logType = "netactivity";
        updLogStr();
        string nact = srtArgs + " \"netstat -a" + logArgs;
        system(nact.c_str());
        logNum += 1;
        cout << d;
        cout << sep;
        sp();

        // quit
        ps();
    }

    // quit
    col();
}

// dnsquery function (uses nslookup cmd) (5)
void dnsquery()
{
    clr();

    // header
    cout << head + " [DNS Query]\n" + cred + "\n\n" + qt;

    // domain input
    cout << sep + "Specify a domain to query:\n";
    string dm;
    cin >> dm;
    sp();

    // dnsquery work
    if (dm != "q")
    {
        logType = "dnsquery";
        updLogStr();
        string ns = srtArgs + " \"nslookup " + dm + logArgs;
        system(ns.c_str());
        logNum += 1;
        cout << d;
        cout << sep;
        sp();

        // quit
        ps();
    }

    // quit
    col();
}

// geolocator function (uses ipinfo.io curl) (6)
void geolocator()
{
    clr();

    // header
    cout << head + " [Geolocator]\n" + cred + "\n\n" + qt;

    // address input
    cout << sep + "Specify an address to lookup:\n";
    string ip;
    cin >> ip;
    sp();

    // geolocator work
    if (ip != "q")
    {
        logType = "geolocator";
        updLogStr();
        string geo = srtArgs + " \"curl ipinfo.io/" + ip + logArgs;
        system(geo.c_str());
        logNum += 1;
        cout << d;
        cout << sep;
        sp();

        // quit
        ps();
    }

    // quit
    col();
}

// routetracer function (uses tracert cmd) (7)
void routetracer()
{
    clr();

    // header
    cout << head + " [Route Tracer]\n" + cred + "\n\n" + qt;

    // address input
    cout << sep + "Specify an address to trace:\n";
    string ip;
    cin >> ip;
    if (ip == "q")
    {
        // quit
        col();
        return;
    }
    cout << "\n";

    // hops input
    cout << "Specify the max number of hops:\n";
    string ho;
    cin >> ho;
    if (ho == "q")
    {
        // quit
        col();
        return;
    }
    sp();

    // routetracer work
    logType = "routetracer";
    updLogStr();
    string tr = srtArgs + " \"tracert -h " + ho + " " + ip + logArgs;
    system(tr.c_str());
    logNum += 1;
    cout << d;
    cout << sep;
    sp();

    // quit
    ps();
    col();
}

// functions

// program functions

// update log string function
void updLogStr()
{
    logNum_str = to_string(logNum);
    logArgs = " | tee-object netutil\\sessions\\session" + sessDate + "\\logs\\" + logNum_str + "_log-" + logType + ".txt\"";
}

// graphical functions

// spacer function
void sp()
{
    cout << "\n\n";
}

// clear function
void clr()
{
    system("cls");
    system("color e");
}

// pause function
void ps()
{
    system("pause");
}

// color function
void col()
{
    system("color 6");
}
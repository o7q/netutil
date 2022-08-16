#include <iostream>
#include <sstream>
#include <sys/stat.h>

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
void col(); // color transition
void clr(); // clear
void ps();  // pause

// global variables

// graphical variables
string ver = "v1.0.0";                                   // version
string cred = "                                 by o7q"; // credit
string head = "               __        __  _ __\n"
              "   ____  ___  / /___  __/ /_(_) /\n"
              "  / __ \\/ _ \\/ __/ / / / __/ / / \n"
              " / / / /  __/ /_/ /_/ / /_/ / /  \n"
              "/_/ /_/\\___/\\__/\\__,_/\\__/_/_/   " +
              ver;                                                                                        // header
string qtnot = "To quit, input \"q\".";                                                                   // quit notice
string spcr = "\n\n===============================================================================+\n\n"; // spacer
string srtArgs = "powershell -command ";                                                                  // power shell arguments
// log variables
int lognum;        // log number
string lognum_str; // log number string
string logArgs;    // log arguments

main()
{
    struct stat buf;
    string dir = "netutil";
    if (stat(dir.c_str(), &buf) != 0)
    {
        system("mkdir netutil\\logs");
    }

    while (true)
    {
        clr();

        cout << head + " [Menu]\n" + cred + "\n\nTo navigate, input a number.\nTo quit, input any non-number.\n\n"
                                            "INFO:\n(1) About\n(2) Open GitHub Repo\n\n"
                                            "MODULES:\n(3) Ping\n(4) Net Activity\n(5) DNS Query\n(6) Geolocator\n(7) Route Tracer\n\n";

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

    cout << head + " [About]\n" + cred + "\n\nTo quit, input any character.";

    cout << spcr + "netutil by o7q\nA command-line based utility-box full of helpful networking commands.\n\nnetutil is licensed under GPL-3.0-only\n\n"
                   "Individual Components:\n- ping\n- netstat\n- nslookup\n- ipinfo.io\n- tracert\n\n"
                   "* Farther documentation can be found on the netutil GitHub page which can be accessed from the menu." +
                spcr;

    string a;
    cin >> a;

    sp();

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

    cout << head + " [Ping]\n" + cred + "\n\n" + qtnot;

    cout << spcr + "Specify an address to ping:\n";

    string ip;
    cin >> ip;

    if (ip == "q")
    {
        col();

        return;
    }

    cout << "\n";

    cout << "Specify the number of pings:\n";

    string pi;
    cin >> pi;

    if (pi == "q")
    {
        col();

        return;
    }

    sp();

    updLogStr();

    pi = srtArgs + " \"ping -n " + pi + " " + ip + logArgs;
    system(pi.c_str());

    lognum += 1;

    cout << spcr;
    sp();

    ps();

    col();
}

// net activity function (4)
void netactivity()
{
    clr();

    cout << head + " [Net Activity]\n" + cred + "\n\n" + qtnot;

    cout << spcr + "To continue, input any key. (\"q\" to quit)\n";

    string q;
    cin >> q;

    sp();

    if (q != "q")
    {
        updLogStr();

        string nact = srtArgs + " \"netstat -a" + logArgs;
        system(nact.c_str());

        lognum += 1;

        cout << spcr;
        sp();

        ps();
    }

    col();
}

// dnsquery function (uses nslookup cmd) (5)
void dnsquery()
{
    clr();

    cout << head + " [DNS Query]\n" + cred + "\n\n" + qtnot;

    cout << spcr + "Specify a domain to query:\n";

    string dm;
    cin >> dm;

    sp();

    if (dm != "q")
    {
        updLogStr();

        string ns = srtArgs + " \"nslookup " + dm + logArgs;
        system(ns.c_str());

        lognum += 1;

        cout << spcr;
        sp();

        ps();
    }

    col();
}

// geolocator function (uses ipinfo.io curl) (6)
void geolocator()
{
    clr();

    cout << head + " [Geolocator]\n" + cred + "\n\n" + qtnot;

    cout << spcr + "Specify an address to lookup:\n";

    string ip;
    cin >> ip;

    sp();

    if (ip != "q")
    {
        updLogStr();

        string geo = srtArgs + " \"curl ipinfo.io/" + ip + logArgs;
        system(geo.c_str());

        lognum += 1;

        cout << spcr;
        sp();

        ps();
    }

    col();
}

// routetracer function (uses tracert cmd) (7)
void routetracer()
{
    clr();

    cout << head + " [Route Tracer]\n" + cred + "\n\n" + qtnot;

    cout << spcr + "Specify an address or domain to trace:\n";

    string ip;
    cin >> ip;

    if (ip == "q")
    {
        col();

        return;
    }

    cout << "\n";

    cout << "Specify the max number of hops:\n";

    string ho;
    cin >> ho;

    if (ho == "q")
    {
        col();

        return;
    }

    sp();

    updLogStr();

    string tr = srtArgs + " \"tracert -h " + ho + " " + ip + logArgs;
    system(tr.c_str());

    lognum += 1;

    cout << spcr;
    sp();

    ps();

    col();
}

// functions

// program functions

// update log string function
void updLogStr()
{
    lognum_str = to_string(lognum);
    logArgs = " | tee-object netutil\\logs\\log" + lognum_str + ".txt\"";
}

// graphical functions

// spacer function
void sp()
{
    cout << "\n\n";
}

// color function
void col()
{
    system("color 6");
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
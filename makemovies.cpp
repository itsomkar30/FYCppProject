#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <unistd.h>
using namespace std;
string email, ema, password, pass, name1, adminhome, adminname, adminpass;
char admin, login, any1, erasechoice;
string movie1;
string th[3] = {"1. Cinepolis, Viviana (Thane)", "2. PVR, Phoenix Marketcity (Kurla)", "3. INOX Cinemas, Metro mall (Kalyan)"};
int array[3][3][3][101], t, Time;
// Admin Functions dont modify
char choice, name, movie;
string m1[3] = {"Phir Hera Pheri ", "Interstellar ", "One Piece Film Red (Anime) "};
// string time1 = "8:00 AM", time2 = "11:00 PM", time3 = "2:00 PM", time4 = "4:00 PM", time5 = "6:00PM", time6 = "9:00 PM", time7 = "11.00PM";
string timefinal, moviefinal;
string time1[3] = {"9:00 AM", "2:00 PM", "8:00 PM"};
int m1price = 170, m2price = 250, m3price = 300, seatfinal, monthfinal, datefinal, pricefinal;
// bool m1restrict, m2restrict, m3restrict;
bool m1restrict = false, m2restrict = false, m3restrict = false;
float duration = 2.50;
char userui();
void chosetime();
void choseTH();
void mytc(string);
int chosemovie();
void checkS(int);
int adminui();
void movieprice();
int agerestrict();
void checkseats(int);
int WMN();
void moviename(int);
int exitsystem();
void selectmovie();
int resetfile();
// void savearray();
void showtickets();
void resetseats();

class person
{
    int seat, no, id = 100;
    // string name;
public:
    void getData(int a)
    {
        system("cls");
        cout << "\n                                 SCREEN\n\n\n";
        for (int i = 1; i <= 100; i++)
        {
            if (array[t][Time][a][i] == 0)
                cout << i << "\t";
            else if (array[t][Time][a][i] == 1)
                cout << "*\t";
            if (i % 10 == 0)
                cout << "\n\n";
        }
        cout << "\nNormal Seats: 1 - 30\tExecutive Seats: 31 - 80\tPremium Seats: 81 - 100\t\t";
        cout << "\nNormal Seats Price: " << pricefinal << "\tExecutive Seats Price:" << pricefinal + 70 << "\tPremium Seats Price: " << pricefinal + 130 << "\t\t";

        int j;
        movie1 = m1[a];

    SeatN1:
        cout << "\n\n\tPlease enter the seat number you want: ";
        cin >> j;
    seatN:
        if (j > 100 || j < 1)
        {
            cout << "\n\tSeat number is unavailable in this theater";
            cout << "\n\tPlease re-enter seat number: ";
            cin >> j;
            goto seatN;
        }
        if (array[t][Time][a][j] == 1)
        {
            printf("\n\tSorry, this ticket is already booked! Please choose another seat.\n");
            goto SeatN1;
        }
        else
            array[t][Time][a][j] = 1;
        // savearray();
        id++;

        seatfinal = j; // previous seat
    }
    void showTC(string s);
    void savearray();

} p;

void userup();
int main()
{
    //************Files**************
    // ifstream mfile("movies.txt");

    // getline(mfile, m1[0]);
    // getline(mfile, m1[1]);
    // getline(mfile, m1[2]);
    // mfile.close();

    // ifstream pfile("price.txt");
    // while (!pfile.eof())
    // {
    //     pfile >> m1price;
    //     pfile >> m2price;
    //     pfile >> m3price;
    // }
    // pfile.close();
    ifstream infile("array_data.txt");

    if (infile.is_open())
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 101; l++)
                        infile >> array[i][j][k][l];
                }
            }
        }
        infile.close();
    }
    else
    {
        cout << "Failed to open the file." << endl;
        system("pause");
    }
admin:
    system("cls");
    system("Color F4");
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\t\tHello! Welcome to the MakeMovie\n";
    cout << "\n\t\t\t\t\t\t\tGetting started!\n";
    cout << "\n\n";
    cout << "\t\t\t\t\t1. Administrator\t\t\t2. User\n";
    cout << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\tWhat should we call you? ";
    cin >> admin;
    switch (admin)
    {
    case '1':
        system("cls");
        goto adminauth;
        break;
    case '2':
        goto relogin;
        break;

    default:
        cout << "\nInvalid input.. Redirecting...\n\n";
        goto admin;
        break;
    }

adminauth:
    system("cls");
    system("Color D0");
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\t\tHello! Welcome to the MakeMovie\n";
    cout << "\n\t\t\t\t\t\t      Administrator login\n";
    cout << "\n\tEnter the Admin name: ";
    cin >> adminname;
    cout << "\n\tEnter the Admin password: ";
    cin >> adminpass;
    cout << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    if (adminname == "admin" && adminpass == "admin1234")
    {
        cout << "\n\tAuthentication Successful!...\n\n";
        cout << "\t";
        system("pause");
        system("cls");
        int a = adminui();
        goto admin;
    }
    else
    {
        cout << "\n\tAuthentication Failed! Redirecting...\n\n\t";
        system("pause");

        goto adminauth;
    }
    system("cls");
relogin:
    system("Color E0");
    system("cls");
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\t\tHello! Welcome to the MakeMovie\n";
    cout << "\n\t\t\t\t\t\t\tGetting started!\n";
    cout << "\n\n";
    cout << "\t\t\t1. Sign in\t\t\t2. Sign up\t\t\t3. Exit\n";
    cout << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\tChosse the preferred option: ";
    cin >> login;
    switch (login)
    {
    case '1':
        goto resignin;
        break;

    case '2':
        goto resignup;
        break;
    case '3':
        goto admin;
    default:
        cout << "\nInvalid input.. Redirecting...\n\n";
        goto relogin;
        break;
    }
    system("cls");

resignin:
    system("cls");
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\t\tSign in to your MakeMovie Account\n";
    if (ema.length() == 5 && pass.length() == 100)
    {
        cout << "\n\n\tNot existing accounts found, Try creating a new one! ";
        cout << "\n\n\t";
        system("pause");
        system("cls");
        goto relogin;
    }
    else
    {
        ifstream emailpass("email.txt");
        cout << "\n\tEnter your email: ";
        cin >> email;
        cout << "\n\tEnter your password: ";
        cin >> password;
        while (!emailpass.eof())
        {
            emailpass >> ema;
            emailpass >> pass;
            if (password == pass && email == ema)

                break;
        }
        if (password != pass && email != ema)
        {
            goto authfail;
        }

        if (password == pass && email == ema)
        {
            // system("cls");
            cout << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
            cout << "\n\tAuthentication Completed! Press any key to continue...\n";

            any1 = getch();
            userup();
            goto relogin;
            int auth1 = 0;
            auth1++;
            return auth1;
            system("cls");
        }
        else
        {
        authfail:
            cout << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
            cout << "\n\tAuthentication Failed! You haven't created a A/c or it's Invalid email and password combination, Redirecting...\n";
            cout << "\n\t";
            system("pause");
            goto relogin;
        }
    }
resignup:
    system("cls");
    ofstream emfile("email.txt", ios::app);
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\t\tSign up to your MakeMovie Account\n";
    cout << "\n\tEnter your name: ";
    cin >> name1;
    cout << "\n\tEnter your email: ";
    cin >> ema;
    emfile << ema << " ";
    cout << "\n\tEnter your password: ";
    cin >> pass;
    emfile << pass << endl;

    cout << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\tAccount Created! Please log in again to continue...\n";
    cout << "\n\t";
    // infile.close();
    system("pause");
    system("cls");
    goto relogin;

    return 0;
}
// User home starts here
void userup()
{
re:
    switch (userui())
    {
    case '1':
        p.getData(chosemovie() - 1);
        p.showTC(ema);
        p.savearray();
        // system("pause");
        goto re;
    case '2':
        mytc(ema += ".txt");
        system("pause");
        goto re;
    case '3':
        checkS(chosemovie() - 1);
        goto re;
    case '4':
    {
        int exitsyst = exitsystem();
        if (exitsyst == 1)
            goto re;
        break;
    }
    default:
        cout << "Enter correct choise..\n";
        system("pause");
        goto re;
    }
}
void choseTH()
{
    int i; // int
TH:
    system("cls");
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\tSelect the theatre to watch movie\n";
    cout << "\n\t\t\t\t\tPress 1 for " << th[0];
    cout << "\n\t\t\t\t\tPress 2 for " << th[1];
    cout << "\n\t\t\t\t\tPress 3 for " << th[2];
    // cout << "\n\t\t\t\t\tPress 4 for to go back to home";
    cout << "\n\n\t\t\t\t\tNote: These are the default theatres ";
    cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";

    cout << "\n\n\tSelect the theatre to watch movie: ";
    cin >> i;

    if (i < 1 || i > 3)
    {
        cout << "\n\n\tEnter correct one\n";
        cout << "\n\n\t";
        system("pause");
        goto TH;
    }
    t = i - 1;
}

void chosetime()
{
    int i; // int
time1:
    system("cls");
    system("cls");
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\tAvaliable timings for your movie are follows\n";
    cout << "\n\t\t\t\t\t\t\t1. 9:00 AM";
    cout << "\n\t\t\t\t\t\t\t2. 2:00 PM";
    cout << "\n\t\t\t\t\t\t\t3. 8:00 PM";
    cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\tSelect the time: ";
    cin >> i;
    // start here
    if (i < 1 || i > 3)
    {
        cout << "\n\n\tEnter correct one\n";
        cout << "\n\n\t";
        system("pause");
        goto time1;
    }
    if (i == 1)
    {
        timefinal = time1[0];
    }
    if (i == 2)
    {
        timefinal = time1[1];
    }
    if (i == 3)
    {
        timefinal = time1[2];
    }
    Time = i - 1;
}
void mytc(string s)
{
    system("cls");
    ifstream myfile(s);
    string my;
    while (!myfile.eof())
    {
        // cin.ignore();
        getline(myfile, my);
        cout << my << endl;
    }
    myfile.close();
}

int chosemovie()
{
    choseTH();
    chosetime();
    int i;
Movie1:
    system("cls");
    system("cls");
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\tWhich movie do you want to see\n";
    cout << "\n\t\t\t\t\tPress 1 for " << m1[0];
    cout << "\n\t\t\t\t\tPress 2 for " << m1[1];
    cout << "\n\t\t\t\t\tPress 3 for " << m1[2];
    cout << "\n\t\t\t\t\tPress 4 for to go back to home";
    cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\tSelect the movie: ";
    cin >> i;

    if (i < 1 || i > 3)
    {
        cout << "\n\tEnter correct one\n";
        cout << "\n\n\t";
        system("pause");
        goto Movie1;
    }
    if (i == 1)
    {
        pricefinal = m1price;
        movie = '1';
        name = '1';
        moviefinal = m1[0];
    }
    else if (i == 2)
    {
        pricefinal = m2price;
        movie = '2';
        name = '2';
        moviefinal = m1[1];
    }
    else if (i == 3)
    {
        pricefinal = m3price;
        movie = '3';
        name = '3';
        moviefinal = m1[2];
    }

    // m[i]=movie;
    system("cls");
    return i;
}

void checkS(int a)
{
    system("cls");
    cout << "\n                                 SCREEN\n\n\n";
    for (int i = 1; i <= 100; i++)
    {
        if (array[t][Time][a][i] == 0)
            cout << i << "\t";
        else if (array[t][Time][a][i] == 1)
            cout << "*\t";
        if (i % 10 == 0)
            cout << "\n\n";
    }
    cout << "\nNormal Seats: 1 - 30\tExecutive Seats: 31 - 80\tPremium Seats: 81 - 100\t\t";
    cout << "\nNormal Seats Price: " << pricefinal << "\tExecutive Seats Price:" << pricefinal + 70 << "\tPremium Seats Price: " << pricefinal + 130 << "\t\t";

    cout << "\n\n\t";
    system("pause");
}

void person::showTC(string s)
{
    // system("cls");
    // cout << "\tPlease take screenshort of the ticket and save it for checkin\n\n";
    // cout << "\t-----------------THEATER BOOKING TICKET----------------\n";
    // cout << "\t============================================================\n";
    // cout << "\t           \t\t\tShow Name : " << movie1 << "\n";
    // cout << "\t\n";
    // cout << "\t\t           Date      : 22-01-2023\n";
    // cout << "\t\t           Time      : 08:00pm\n";
    // cout << "\t\t           Hall      : 01\n";
    // cout << "\t\t           seats No. : " << seat << "  \n";
    // cout << "\t\t           price     : 150rs  \n\n";
    // cout << "\t============================================================\n";
    // system("pause");
    system("cls");
    int enterage;
    if ((m1restrict == true && name == '1') || (m2restrict == true && name == '2') || (m3restrict == true && name == '3'))
    {
    rechooseage:

        system("cls");
        cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
        cout << "\n\t\t\t\tThis movie has an age restriction of 18+, Please verify your age to proceed  ";
        cout << "\n\n\t\t\t\t\t\t\tAre you older than 18 years";
        cout << "\n\n\t\t\t\t\t\t1. Yes\t\t\t\t\t2.No";
        cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> ";
        cout << "\n\n\tEnter your choice: ";
        cin >> enterage;

        if (enterage == 1)
        {
            system("cls");
            // add color
            system("Color 02");
            cout << "Gathering the information...";
            sleep(1);
            cout << "\n\nPlease wait...";
            sleep(1);
            cout << "\n\nBooking your ticket...";
            sleep(1);
            system("cls");
            system("Color F0");
            cout << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> ";
            cout << "\n\n\t\t\t\t\t\tTicket Booked!";
            cout << "\n\n";
            if (movie == '1')
            {
                cout << "\n\n\tMovie Category: U";
            }
            else if (movie == '2')
            {
                cout << "\n\n\tMovie Category: U/A";
            }
            else if (movie == '3')
            {
                cout << "\n\n\tMovie Category: U/A";
            }
            cout << "\t\t\t\t\t\t\t";
            if (seatfinal >= 1 && seatfinal <= 30)
            {
                cout << "Seat no: " << seatfinal;
                cout << "\n\t\t\t\t\t\t\t\t\t\tCategory: Normal Class";
                pricefinal = pricefinal;
            }
            else if (seatfinal > 31 && seatfinal <= 80)
            {
                cout << "Seat no: " << seatfinal;
                cout << "\n\t\t\t\t\t\t\t\t\t\tCategory: Executive Class";
                pricefinal = pricefinal + 70;
            }
            else if (seatfinal > 81 && seatfinal <= 100)
            {
                cout << "Seat no: " << seatfinal;
                cout << "\n\t\t\t\t\t\t\t\t\t\tCategory: Premium Class";
                pricefinal = pricefinal + 130;
            }
            cout << "\n\t";
            cout << "Dolby 7.1";
            cout << "\n";
            cout << "\n\n\t\t\t\t\t\tMovie Details";
            cout << "\n\n\t\t\t\t\tMovie Name: " << moviefinal;
            cout << "\n\t\t\t\t\tMovie Duration: " << duration << " Hours";
            cout << "\n\t\t\t\t\tMovie Time: " << timefinal;
            cout << "\n\t\t\t\t\tMovie Price: " << pricefinal;
            cout << "\n\n\n\t\t\t\t\tBooked by Makemovie\n\n";
            cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";

            // ofstream outputFile("ticket.txt", ios::app);

            // if (outputFile.is_open())
            // {
            //     outputFile << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>";
            //     outputFile << "\n\n\t\t\t\t\t\tTicket Booked!\n\n";

            //     if (movie == '1')
            //     {
            //         outputFile << "\tMovie Category: U";
            //     }
            //     else if (movie == '2')
            //     {
            //         outputFile << "\tMovie Category: U/A";
            //     }
            //     else if (movie == '3')
            //     {
            //         outputFile << "\tMovie Category: U/A";
            //     }

            //     outputFile << "\t\t\t\t\t\t\t";

            //     if (seatfinal >= 1 && seatfinal <= 30)
            //     {
            //         outputFile << "Seat no: " << seatfinal;
            //         outputFile << "\n\t\t\t\t\t\t\t\t\t\tCategory: Normal Class";
            //         pricefinal = pricefinal;
            //     }
            //     else if (seatfinal > 31 && seatfinal <= 80)
            //     {
            //         outputFile << "Seat no: " << seatfinal;
            //         outputFile << "\n\t\t\t\t\t\t\t\t\t\tCategory: Executive Class";
            //         pricefinal = pricefinal + 70;
            //     }
            //     else if (seatfinal > 81 && seatfinal <= 100)
            //     {
            //         outputFile << "Seat no: " << seatfinal;
            //         outputFile << "\n\t\t\t\t\t\t\t\t\t\tCategory: Premium Class";
            //         pricefinal = pricefinal + 130;
            //     }

            //     outputFile << "\n\tDolby 7.1\n";
            //     outputFile << "\n\n\t\t\t\t\tMovie Details";
            //     outputFile << "\n\n\t\t\t\t\tMovie Name: " << moviefinal;
            //     outputFile << "\n\t\t\t\t\tMovie Duration: " << duration << " Hours";
            //     outputFile << "\n\t\t\t\t\tMovie Time: " << timefinal;
            //     outputFile << "\n\t\t\t\t\tMovie Price: " << pricefinal;
            //     outputFile << "\n\n\n\t\t\t\t\tBooked by Makemovie\n\n";
            //     outputFile << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n";

            //     outputFile.close();
            //     cout << "\n\n\tTicket printed successfully" << endl;
            // }
            // else
            // {
            //     cout << "\n\n\tUnable to open the file ticket.txt" << endl;
            // }
            // cout << "\n\n\t";
            // system("pause");

            // // return 20;
        }

        else if (enterage == 2)
        {
            cout << "\n\n\tSorry, Unable to book tickets as this movie is age restricted or maybe it is an 'A' category movie\n";
            cout << "\n\n\t";
            system("pause");
            return;
        }

        else
        {
            goto rechooseage;
        }
    }

    if ((m1restrict == false && name == '1') || (m2restrict == false && name == '2') || (m3restrict == false && name == '3'))
    {
        system("cls");
        // add color
        system("Color 02");
        cout << "Gathering the information...";
        sleep(1);
        cout << "\n\nPlease wait...";
        sleep(1);
        cout << "\n\nBooking your ticket...";
        sleep(1);
        system("cls");
        system("Color F0");
        cout << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> ";
        cout << "\n\n\t\t\t\t\t\tTicket Booked!";
        cout << "\n\n";
        if (movie == '1')
        {
            cout << "\n\n\tMovie Category: U";
        }
        else if (movie == '2')
        {
            cout << "\n\n\tMovie Category: U/A";
        }
        else if (movie == '3')
        {
            cout << "\n\n\tMovie Category: U/A";
        }
        cout << "\t\t\t\t\t\t\t";
        if (seatfinal >= 1 && seatfinal <= 30)
        {
            cout << "Seat no: " << seatfinal;
            cout << "\n\t\t\t\t\t\t\t\t\t\tCategory: Normal Class";
            pricefinal = pricefinal;
        }
        else if (seatfinal > 31 && seatfinal <= 80)
        {
            cout << "Seat no: " << seatfinal;
            cout << "\n\t\t\t\t\t\t\t\t\t\tCategory: Executive Class";
            pricefinal = pricefinal + 70;
        }
        else if (seatfinal > 81 && seatfinal <= 100)
        {
            cout << "Seat no: " << seatfinal;
            cout << "\n\t\t\t\t\t\t\t\t\t\tCategory: Premium Class";
            pricefinal = pricefinal + 130;
        }
        cout << "\n\t";
        cout << "Dolby 7.1";
        cout << "\n";
        cout << "\n\n\t\t\t\t\t\tMovie Details";
        cout << "\n\n\t\t\t\t\tMovie Name: " << moviefinal;
        cout << "\n\t\t\t\t\tMovie Duration: " << duration << " Hours";
        cout << "\n\t\t\t\t\tMovie Time: " << timefinal;
        cout << "\n\t\t\t\t\tMovie Price: " << pricefinal;
        cout << "\n\n\n\t\t\t\t\tBooked by Makemovie\n\n";
        cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    }

    // age else close

    ofstream tcfile(s + ".txt", ios::app);
    // tcfile << "\t-----------------THEATER BOOKING TICKET----------------\n";
    // tcfile << "\t============================================================\n";
    // tcfile << "\t           \t\t\tShow Name : " << movie1 << "\n\n";
    // tcfile << "\t\t           Date      : 22-01-2023\n";
    // tcfile << "\t\t           Time      : 08:00pm\n";
    // tcfile << "\t\t           Hall      : 01\n";
    // tcfile << "\t\t           seats No. : " << seat << "  \n";
    // tcfile << "\t\t           price     : 150rs  \n\n";
    // tcfile << "\t============================================================\n\n";
    // tcfile.close();
    if (tcfile.is_open())
    {
        tcfile << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>";
        tcfile << "\n\n\t\t\t\t\t\tTicket Booked!\n\n";

        if (movie == '1')
        {
            tcfile << "\tMovie Category: U";
        }
        else if (movie == '2')
        {
            tcfile << "\tMovie Category: U/A";
        }
        else if (movie == '3')
        {
            tcfile << "\tMovie Category: U/A";
        }

        tcfile << "\t\t\t\t\t\t\t";

        if (seatfinal >= 1 && seatfinal <= 30)
        {
            tcfile << "Seat no: " << seatfinal;
            tcfile << "\n\t\t\t\t\t\t\t\t\t\tCategory: Normal Class";
            pricefinal = pricefinal;
        }
        else if (seatfinal > 31 && seatfinal <= 80)
        {
            tcfile << "Seat no: " << seatfinal;
            tcfile << "\n\t\t\t\t\t\t\t\t\t\tCategory: Executive Class";
            pricefinal = pricefinal + 70;
        }
        else if (seatfinal > 81 && seatfinal <= 100)
        {
            tcfile << "Seat no: " << seatfinal;
            tcfile << "\n\t\t\t\t\t\t\t\t\t\tCategory: Premium Class";
            pricefinal = pricefinal + 130;
        }

        tcfile << "\n\tDolby 7.1\n";
        tcfile << "\n\n\t\t\t\t\tMovie Details";
        tcfile << "\n\n\t\t\t\t\tMovie Name: " << moviefinal;
        tcfile << "\n\t\t\t\t\tMovie Duration: " << duration << " Hours";
        tcfile << "\n\t\t\t\t\tMovie Time: " << timefinal;
        tcfile << "\n\t\t\t\t\tMovie Price: " << pricefinal;
        tcfile << "\n\n\n\t\t\t\t\tBooked by Makemovie\n\n";
        tcfile << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n";

        tcfile.close();
        cout << "\n\n\tTicket printed successfully" << endl;
    }
    else
    {
        cout << "\n\n\tUnable to open the file ticket.txt" << endl;
    }
    cout << "\n\n\t";
    system("pause");

    // system("pause");
}

void person::savearray()
{
    ofstream outfile("array_data.txt");

    if (outfile.is_open())
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 101; l++)
                        outfile << array[i][j][k][l] << " ";
                }
                outfile << endl;
            }
        }
        outfile.close();
        cout << " " << endl;
    }
    else
    {
        cout << "\nFailed to open the file array_data.txt " << endl;
        system("pause");
    }
}

char userui()
{
    char c;
    system("cls");
    system("Color E0");
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\t\t\tMakeMovies Home (User)\n";
    cout << "\n\t\t1. Book the movie ticket";
    cout << "\n\t\t2. Show my movie ticket";
    cout << "\n\t\t3. Check seats availability";
    cout << "\n\t\t4. Exit";
    cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\tEnter your choice : ";
    cin >> c;
    return c;
}

// Admin starts here

int adminui()
{
adminui:
    system("cls");
    system("Color F4");
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\t\tMakeMovies Home (Administrator)\n";
    cout << "\n\t\t1. Edit the ticket price";
    cout << "\n\t\t2. Add a age restriction to movie";
    cout << "\n\t\t3. Book the ticket";
    cout << "\n\t\t4. View the printed ticket";
    cout << "\n\t\t5. Check seats availability";
    cout << "\n\t\t6. Change movie name";
    cout << "\n\t\t7. Reset all records and tickets";
    cout << "\n\t\t8. Exit";
    cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\tEnter your choice : ";
    cin >> choice;

rest:
    switch (choice)
    {
    case '1':
    {
        movieprice();
        goto adminui;
    }
    case '2':
    {
        int restrictsystem = agerestrict();
        goto adminui;
    }
    case '3':
    {
        selectmovie();
        goto adminui;
    }
    case '4':
    {
        system("cls");
        showtickets();
        goto adminui;
    }
    case '5':
    {
        chosetime();
        checkseats(WMN());
        goto adminui;
    }
    case '6':
        moviename(WMN());
        goto adminui;
    case '7':
    {
        int resetfiles = resetfile();
        if (resetfiles == false)
        {
            goto adminui;
        }
        goto rest;
        break;
    }
    case '8':
    {
        int exitsys = exitsystem();
        if (exitsys == 1)
            goto adminui;
        break;
    }
    default:
        cout << "\nChoose correct option Redirecting...";
        system("pause");
        goto rest;
    }
    return 0;
}

int exitsystem()
{
    system("cls");
reexit:
    int a = 1; // Going back
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\tLeaving us too early!\t\t\t\t\tAre you sure you want to quit? \n";
    cout << "\n\t\t\t\t\tExiting will close the application and close all files";
    cout << "\n\n\t\t\t\t\t\t1. Back\t\t\t2. Exit anyway\n";
    cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";

    cout << "\n\tAre you still want to exit? ";
    char exit;
    cin >> exit;
    switch (exit)
    {
    case '1':
        cout << "Redirecting to home...";
        return a;
        break;
    case '2':
        system("cls");
        cout << "Termination point...\n";
        // cout << "\n";
        // system("pause");
        cout << "\n\n\t\t\t\t\tProject by Omkar & Prajjval\n\n\n";
        // cout << "\n";
        sleep(2);
        cout << "\n\n";
        system("pause");
        return 0;
        break;

    default:
        cout << "\nInvalid input.. Redirecting...\n\n";
        goto reexit;
        break;
    }

    return 0;
}

void movieprice()
{

    char i;
Movie:
    system("cls");
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\tWhich movie price do you want to change?\n";
    cout << "\n\t\t\t\t\tPress 1 for " << m1[0] << " [" << m1price << "]";
    cout << "\n\t\t\t\t\tPress 2 for " << m1[1] << " [" << m2price << "]";
    cout << "\n\t\t\t\t\tPress 3 for " << m1[2] << " [" << m3price << "]";
    cout << "\n\t\t\t\t\tPress 4 for to go back to home";
    cout << "\n\n\t\t\t\t\tNote: These are the default movies ";
    cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";

    cout << "\n\n\tChoose a movie to change the price: ";
    cin >> i;
    // system("cls");
    switch (i)
    {
    case '1':
        cout << "\n\tEnter the new price: ";
        cin >> m1price;
        cout << "\n\tTicket price changed successfully!";
        break;
    case '2':
        cout << "\n\tEnter the new price: ";
        cin >> m2price;
        cout << "\n\tTicket price changed successfully!";
        break;
    case '3':
        cout << "\n\tEnter the new price: ";
        cin >> m3price;
        cout << "\n\tTicket price changed successfully!";
        break;
    case '4':
        break;
    default:
        cout << "Enter correct one\n";
        system("pause");
        goto Movie;
    }
    ofstream prfile("price.txt");

    prfile << m1price << " ";
    prfile << m2price << " ";
    prfile << m3price << " ";

    prfile.close();
}

void moviename(int s)
{
    if (s >= 0 && s <= 2)
    {
        cout << "\n\n\tEnter new movie name to change: ";
        cin.ignore();
        getline(cin, m1[s]);
        cout << "\n\n\tMovie name changed successfully!";
    }
    ofstream mofile("movies.txt");

    mofile << m1[0] << endl;
    mofile << m1[1] << endl;
    mofile << m1[2] << endl;
    mofile.close();
}

int WMN()
{
    int i;
Movie:
    system("cls");

    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\tWhich movie name do you want to change?\n";
    cout << "\n\t\t\t\t\tPress 1 for " << m1[0];
    cout << "\n\t\t\t\t\tPress 2 for " << m1[1];
    cout << "\n\t\t\t\t\tPress 3 for " << m1[2];
    cout << "\n\t\t\t\t\tPress 4 for to go back to home";
    cout << "\n\n\t\t\t\t\tNote: These are the default movies ";
    cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";

    cout << "\n\n\tChoose a movie to change the name: ";
    cin >> i;

    // flush

    if (i >= 0 && i <= 4)
    {
        return i - 1;
    }
    else
    {
        cout << "\n\tInvalid input! Redirecting...";
        cout << "\n\n\t";
        system("pause");
        goto Movie;
    }
}

void checkseats(int a)
{
    system("cls");
    cout << "\n                                 SCREEN\n\n\n";
    for (int i = 1; i <= 100; i++)
    {
        if (array[1][Time][a][i] == 0)
            cout << i << "\t";
        else if (array[1][Time][a][i] == 1)
            cout << "*\t";
        if (i % 10 == 0)
            cout << "\n\n";
    }
    cout << "\nNormal Seats: 1 - 30\t\tExecutive Seats: 31 - 80\t\tPremium Seats: 81 - 100\t\t";
    cout << "\nNormal Seats Price: " << pricefinal << "\t\tExecutive Seats Price:" << pricefinal + 70 << "\t\tPremium Seats Price: " << pricefinal + 130 << "\t\t";

    cout << "\n\n\t";
    system("pause");
}

int agerestrict()
{
    system("cls");
    char selectage;
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\tWhich movie you want to apply age restriction\n";
    cout << "\n\t\t\t\t\tPress 1 for " << m1[0];
    cout << "\n\t\t\t\t\tPress 2 for " << m1[1];
    cout << "\n\t\t\t\t\tPress 3 for " << m1[2];
    cout << "\n\t\t\t\t\tPress 4 for to go back to home";
    cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\n\tSelect the movie: ";
    cin >> selectage;
    if (selectage == '1')
    {
    selectage1:
        system("cls");
        cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
        cout << "\n\t\t\t\tDo you want to apply age restriction to " << m1[0];
        cout << "\n\n\t\t\t\t\t\t1. Yes \t\t 2. No ";
        cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
        cout << "\n\tSelect option: ";
        char m1restrictopt;
        cin >> m1restrictopt;
        if (m1restrictopt == '1')
        {
            system("cls");
            cout << "\nThe age restriction of 18 years is sucessfully applied to " << m1[0];
            m1restrict = 18;
            cout << "\n\n";
            system("pause");
            return m1restrict = true;
        }
        else if (m1restrictopt == '2')
        {
            system("cls");
            cout << "\nAge restriction is denied ";
            cout << "\n\n\t";
            m1restrict = false;

            return 1;
        }
        else
        {
            goto selectage1;
        }
    }
    else if (selectage == '2')
    {
    selectage2:
        system("cls");
        cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
        cout << "\n\t\t\t\tDo you want to apply age restriction to " << m1[1];
        cout << "\n\n\t\t\t\t\t\t1. Yes \t\t 2. No ";
        cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
        cout << "\n\tSelect option: ";
        char m2restrictopt;
        cin >> m2restrictopt;
        if (m2restrictopt == '1')
        {
            system("cls");
            cout << "\nThe age restriction of 18 years is sucessfully applied to " << m1[1];
            m2restrict = 18;
            cout << "\n\n";
            system("pause");
            return m2restrict = true;
        }
        else if (m2restrictopt == '2')
        {
            system("cls");
            cout << "\nAge restriction is denied ";
            cout << "\n\n\t";
            m2restrict = false;
            return 1;
        }
        else
        {
            goto selectage2;
        }
    }
    else if (selectage == '3')
    {
    selectage3:
        system("cls");
        cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
        cout << "\n\t\t\t\tDo you want to apply age restriction to " << m1[2];
        cout << "\n\n\t\t\t\t\t\t1. Yes \t\t 2. No ";
        cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
        cout << "\n\tSelect option: ";
        char m3restrictopt;
        cin >> m3restrictopt;
        if (m3restrictopt == '1')
        {
            system("cls");
            cout << "\nThe age restriction of 18 years is sucessfully applied to " << m1[2];
            m3restrict = 18;
            cout << "\n\n";
            system("pause");
            return m3restrict = true;
        }
        else if (m3restrictopt == '2')
        {
            system("cls");
            cout << "\nAge restriction is denied ";
            cout << "\n\n\t";
            m3restrict = false;
            return 1;
        }
        else
        {
            goto selectage3;
        }
    }
    else if (selectage == '4')
    {
        return 1;
    }
}

// void chosetime(){
//     int i;
//     Time1:
//     system("cls");
//     cout<<"\t\t\tWhen do you want to see?\n";
//     cout<<"\t\t\t----------------------------\n\n";
// 	cout<<"\t\t\tpress 1 for 09:00 AM";
// 	cout<<"\n\n\t\t\tpress 2 for 02:00 PM";
// 	cout<<"\n\n\t\t\tpress 3 for 08:00 PM"<<endl;
//     cin>>i;

// 	if(i<1 || i>3){
// 		cout<<"Enter correct one\n";
// 		system("pause");
// 		goto Time1;
// 	}
//     Time=i-1;
// }

void selectmovie()
{
reselectmovie:
    int a;
    char name;
    system("cls");
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\tWhich movie do you want to see\n";
    cout << "\n\t\t\t\t\tPress 1 for " << m1[0];
    cout << "\n\t\t\t\t\tPress 2 for " << m1[1];
    cout << "\n\t\t\t\t\tPress 3 for " << m1[2];
    cout << "\n\t\t\t\t\tPress 4 for to go back to home";
    cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\tSelect the movie: ";
    cin >> name;
    movie = name; // declare name as a global variable in char movie //Omkar
    if (name == '1')
    {
        cout << "\n\tThe selected movie is : " << m1[0];
        moviefinal = m1[0];
        pricefinal = m1price;
        a = 0;
    }
    else if (name == '2')
    {
        cout << "\n\tThe selected movie is : " << m1[1];
        moviefinal = m1[1];
        pricefinal = m2price;
        a = 1;
    }
    else if (name == '3')
    {
        cout << "\n\tThe selected movie is : " << m1[2];
        moviefinal = m1[2];
        pricefinal = m3price;
        a = 2;
    }
    else if (name == '4')
        return;
    else
    {
        cout << "\n\nInvalid Input.. Redirecting...\n\n";
        system("cls");
        goto reselectmovie;
    }

    cout << "\n\n\t";
    system("pause");
    system("cls");
    char returntime;

retime:
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\t\t\tThe avaliable timings for your movie are ";
    // switch (name)
    // {
    // case '1':
    cout << "\n\n\t\t\t\t\t\t\t1. " << time1[0];
    cout << "\n\n\t\t\t\t\t\t\t2. " << time1[1];
    cout << "\n\n\t\t\t\t\t\t\t3. " << time1[2];
    cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\tPlease select the time slot: ";
    cin >> returntime;
    cout << "\n\t";
    switch (returntime)
    {
    case '1':
        cout << "The timing you have selected is : " << time1[0];
        timefinal = time1[0];
        Time = 0;
        break;
    case '2':
        cout << "The timing you have selected is : " << time1[1];
        timefinal = time1[1];
        Time = 1;
        break;
    case '3':
        cout << "The timing you have selected is : " << time1[2];
        timefinal = time1[2];
        Time = 2;
        break;

    default:
        cout << "\n\n\t\tInvalid Input! Try again.";
        goto retime;
        break;
    }
    //     break;
    // case '2':
    //     cout << "\n\n\t\t\t\t\t1. " << time2;
    //     cout << "\n\n\t\t\t\t\t2. " << time4;
    //     cout << "\n\n\t\t\t\t\t3. " << time6;
    //     cout << "\n\tPlease select the time slot: ";
    //     cin >> returntime;
    //     switch (returntime)
    //     {
    //     case '1':
    //         cout << "The timing you have selected is : " << time2;
    //         timefinal = time2;
    //         Time = 0;
    //         break;
    //     case '2':
    //         cout << "The timing you have selected is : " << time4;
    //         timefinal = time4;
    //         Time = 1;
    //         break;
    //     case '3':
    //         cout << "The timing you have selected is : " << time6;
    //         timefinal = time6;
    //         Time = 2;
    //         break;
    //     default:
    //         cout << "\n\n\t\tInvalid Input! Try again.";
    //         goto retime;
    //         break;
    //     }
    //     break;
    // case '3':
    //     cout << "\n\n\t\t\t\t\t1. " << time3;
    //     cout << "\n\n\t\t\t\t\t2. " << time5;
    //     cout << "\n\n\t\t\t\t\t3. " << time7;
    //     cout << "\n\tPlease select the time slot: ";
    //     cin >> returntime;
    //     switch (returntime)
    //     {
    //     case '1':
    //         cout << "The timing you have selected is : " << time3;
    //         timefinal = time3;
    //         Time = 0;
    //         break;
    //     case '2':
    //         cout << "The timing you have selected is : " << time5;
    //         timefinal = time5;
    //         Time = 1;
    //         break;
    //     case '3':
    //         cout << "The timing you have selected is : " << time7;
    //         timefinal = time7;
    //         Time = 2;
    //         break;
    //     default:
    //         cout << "\n\n\t\tInvalid Input! Try again.";
    //         goto retime;
    //         break;
    //     }
    //     break;

    // default:
    //     cout << "\n\n\t\tInvalid Input! Try again.";
    //     system("cls");
    //     goto retime;
    //     break;
    // }
    cout << "\n\n\t";
    system("pause");
    system("cls");
    int i, j;

    cout << "\n                                 SCREEN\n\n\n";
    for (int i = 1; i <= 100; i++)
    {
        if (array[1][Time][a][i] == 0)
            cout << i << "\t";
        else if (array[1][Time][a][i] == 1)
            cout << "*\t";
        if (i % 10 == 0)
            cout << "\n\n";
    }
    cout << "\nNormal Seats: 1 - 30\t\tExecutive Seats: 31 - 80\t\tPremium Seats: 81 - 100\t\t";
    cout << "\nNormal Seats Price: " << pricefinal << "\t\tExecutive Seats Price:" << pricefinal + 70 << "\t\tPremium Seats Price: " << pricefinal + 130 << "\t\t";

seatchoose:
    cout << "\n\n\tPlease enter the seat number you want: ";
    cin >> j;
    seatfinal = j;
    array[1][Time][a][i] == 1;

seatproper:
    if (j > 100 || j < 1)
    {
        cout << "\n\tSeat number is unavailable in this theater\n";
        cout << "\n\tPlease re-enter seat number: ";
        cin >> j;
        goto seatproper;
    }
    if (array[1][Time][a][j] == 1)
    {
        cout << "\n\tSorry, this ticket is already booked! Please choose another seat.\n";
        goto seatchoose;
    }
    else
        array[1][Time][a][j] = 1;

    p.savearray();
    system("cls");
    if ((m1restrict == true && name == '1') || (m2restrict == true && name == '2') || (m3restrict == true && name == '3'))
    {
    rechooseage:
        int enterage;
        system("cls");
        cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
        cout << "\n\t\t\t\tThis movie has an age restriction of 18+, Please verify your age to proceed  ";
        cout << "\n\n\t\t\t\t\t\t\tAre you older than 18 years";
        cout << "\n\n\t\t\t\t\t\t1. Yes\t\t\t\t\t2.No";
        cout << "\n\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> ";
        cout << "\n\n\tEnter your choice: ";
        cin >> enterage;

        if (enterage == 1)
        {
            system("cls");
            // add color
            system("Color 02");
            cout << "Gathering the information...";
            sleep(1);
            cout << "\n\nPlease wait...";
            sleep(1);
            cout << "\n\nBooking your ticket...";
            sleep(1);
            system("cls");
            system("Color F0");
            cout << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> ";
            cout << "\n\n\t\t\t\t\t\tTicket Booked!";
            cout << "\n\n";
            if (movie == '1')
            {
                cout << "\n\n\tMovie Category: U";
            }
            else if (movie == '2')
            {
                cout << "\n\n\tMovie Category: U/A";
            }
            else if (movie == '3')
            {
                cout << "\n\n\tMovie Category: U/A";
            }
            cout << "\t\t\t\t\t\t\t";
            if (seatfinal >= 1 && seatfinal <= 30)
            {
                cout << "Seat no: " << seatfinal;
                cout << "\n\t\t\t\t\t\t\t\t\t\tCategory: Normal Class";
                pricefinal = pricefinal;
            }
            else if (seatfinal > 31 && seatfinal <= 80)
            {
                cout << "Seat no: " << seatfinal;
                cout << "\n\t\t\t\t\t\t\t\t\t\tCategory: Executive Class";
                pricefinal = pricefinal + 70;
            }
            else if (seatfinal > 81 && seatfinal <= 100)
            {
                cout << "Seat no: " << seatfinal;
                cout << "\n\t\t\t\t\t\t\t\t\t\tCategory: Premium Class";
                pricefinal = pricefinal + 130;
            }
            cout << "\n\t";
            cout << "Dolby 7.1";
            cout << "\n";
            cout << "\n\n\t\t\t\t\t\tMovie Details";
            cout << "\n\n\t\t\t\t\tMovie Name: " << moviefinal;
            cout << "\n\t\t\t\t\tMovie Duration: " << duration << " Hours";
            // cout << "\n\t\t\t\t\tMovie Date: " << datefinal;
            cout << "\n\t\t\t\t\tMovie Time: " << timefinal;
            cout << "\n\t\t\t\t\tMovie Price: " << pricefinal;
            cout << "\n\n\n\t\t\t\t\tBooked by Makemovie\n\n";
            cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";

            ofstream outputFile("ticket.txt", ios::app);

            if (outputFile.is_open())
            {
                outputFile << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>";
                outputFile << "\n\n\t\t\t\t\t\tTicket Booked!\n\n";

                if (movie == '1')
                {
                    outputFile << "\tMovie Category: U";
                }
                else if (movie == '2')
                {
                    outputFile << "\tMovie Category: U/A";
                }
                else if (movie == '3')
                {
                    outputFile << "\tMovie Category: U/A";
                }

                outputFile << "\t\t\t\t\t\t\t";

                if (seatfinal >= 1 && seatfinal <= 30)
                {
                    outputFile << "Seat no: " << seatfinal;
                    outputFile << "\n\t\t\t\t\t\t\t\t\t\tCategory: Normal Class";
                    pricefinal = pricefinal;
                }
                else if (seatfinal > 31 && seatfinal <= 80)
                {
                    outputFile << "Seat no: " << seatfinal;
                    outputFile << "\n\t\t\t\t\t\t\t\t\t\tCategory: Executive Class";
                    pricefinal = pricefinal + 70;
                }
                else if (seatfinal > 81 && seatfinal <= 100)
                {
                    outputFile << "Seat no: " << seatfinal;
                    outputFile << "\n\t\t\t\t\t\t\t\t\t\tCategory: Premium Class";
                    pricefinal = pricefinal + 130;
                }

                outputFile << "\n\tDolby 7.1\n";
                outputFile << "\n\n\t\t\t\t\tMovie Details";
                outputFile << "\n\n\t\t\t\t\tMovie Name: " << moviefinal;
                outputFile << "\n\t\t\t\t\tMovie Duration: " << duration << " Hours";
                // outputFile << "\n\t\t\t\t\tMovie Date: " << datefinal;
                outputFile << "\n\t\t\t\t\tMovie Time: " << timefinal;
                outputFile << "\n\t\t\t\t\tMovie Price: " << pricefinal;
                outputFile << "\n\n\n\t\t\t\t\tBooked by Makemovie\n\n";
                outputFile << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n";

                outputFile.close();
                cout << "\n\n\tTicket printed successfully" << endl;
            }
            else
            {
                cout << "\n\n\tUnable to open the file ticket.txt" << endl;
            }
            cout << "\n\n\t";
            system("pause");

            // return 20;
        }

        else if (enterage == 2)
        {
            cout << "\n\n\tSorry, Unable to book tickets as this movie is age restricted or maybe it is an 'A' category movie\n";
            cout << "\n\n\t";
            system("pause");
            // return 18;
        }
        else
        {
            goto rechooseage;
        }
        // age else close
    }
    else
    {
        system("cls");
        // add color
        system("Color 02");
        cout << "Gathering the information...";
        sleep(1);
        cout << "\n\nPlease wait...";
        sleep(1);
        cout << "\n\nBooking your ticket...";
        sleep(1);
        system("cls");
        system("Color F0");
        cout << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> ";
        cout << "\n\n\t\t\t\t\t\tTicket Booked!";
        cout << "\n\n";
        if (movie == '1')
        {
            cout << "\n\n\tMovie Category: U";
        }
        else if (movie == '2')
        {
            cout << "\n\n\tMovie Category: U/A";
        }
        else if (movie == '3')
        {
            cout << "\n\n\tMovie Category: U/A";
        }
        cout << "\t\t\t\t\t\t\t";
        if (seatfinal >= 1 && seatfinal <= 30)
        {
            cout << "Seat no: " << seatfinal;
            cout << "\n\t\t\t\t\t\t\t\t\t\tCategory: Normal Class";
            pricefinal = pricefinal;
        }
        else if (seatfinal > 31 && seatfinal <= 80)
        {
            cout << "Seat no: " << seatfinal;
            cout << "\n\t\t\t\t\t\t\t\t\t\tCategory: Executive Class";
            pricefinal = pricefinal + 70;
        }
        else if (seatfinal > 81 && seatfinal <= 100)
        {
            cout << "Seat no: " << seatfinal;
            cout << "\n\t\t\t\t\t\t\t\t\t\tCategory: Premium Class";
            pricefinal = pricefinal + 130;
        }
        cout << "\n\t";
        cout << "Dolby 7.1";
        cout << "\n";
        cout << "\n\n\t\t\t\t\t\tMovie Details";
        cout << "\n\n\t\t\t\t\tMovie Name: " << moviefinal;
        cout << "\n\t\t\t\t\tMovie Duration: " << duration << " Hours";
        // cout << "\n\t\t\t\t\tMovie Date: " << datefinal;
        cout << "\n\t\t\t\t\tMovie Time: " << timefinal;
        cout << "\n\t\t\t\t\tMovie Price: " << pricefinal;
        cout << "\n\n\n\t\t\t\t\tBooked by Makemovie\n\n";
        cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";

        ofstream outputFile("ticket.txt", ios::app);

        if (outputFile.is_open())
        {
            outputFile << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>";
            outputFile << "\n\n\t\t\t\t\t\tTicket Booked!\n\n";
            if (movie == '1')
            {
                outputFile << "\tMovie Category: U";
            }
            else if (movie == '2')
            {
                outputFile << "\tMovie Category: U/A";
            }
            else if (movie == '3')
            {
                outputFile << "\tMovie Category: U/A";
            }

            outputFile << "\t\t\t\t\t\t\t";

            if (seatfinal >= 1 && seatfinal <= 30)
            {
                outputFile << "Seat no: " << seatfinal;
                outputFile << "\n\t\t\t\t\t\t\t\t\t\tCategory: Normal Class";
                pricefinal = pricefinal;
            }
            else if (seatfinal > 31 && seatfinal <= 80)
            {
                outputFile << "Seat no: " << seatfinal;
                outputFile << "\n\t\t\t\t\t\t\t\t\t\tCategory: Executive Class";
                pricefinal = pricefinal + 70;
            }
            else if (seatfinal > 81 && seatfinal <= 100)
            {
                outputFile << "Seat no: " << seatfinal;
                outputFile << "\n\t\t\t\t\t\t\t\t\t\tCategory: Premium Class";
                pricefinal = pricefinal + 130;
            }

            outputFile << "\n\tDolby 7.1\n";
            outputFile << "\n\n\t\t\t\t\tMovie Details";
            outputFile << "\n\n\t\t\t\t\tMovie Name: " << moviefinal;
            outputFile << "\n\t\t\t\t\tMovie Duration: " << duration << " Hours";
            // outputFile << "\n\t\t\t\t\tMovie Date: " << datefinal;
            outputFile << "\n\t\t\t\t\tMovie Time: " << timefinal;
            outputFile << "\n\t\t\t\t\tMovie Price: " << pricefinal;
            outputFile << "\n\n\n\t\t\t\t\tBooked by Makemovie\n\n";
            outputFile << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n";

            outputFile.close();
            cout << "\n\n\tTicket printed successfully" << endl;
        }
        else
        {
            cout << "\n\n\tUnable to open the file ticket.txt" << endl;
        }
        cout << "\n\n\t";
        system("pause");

        // return 18;
    }
}

void showtickets()
{
    ifstream inputFile("ticket.txt");

    if (inputFile.is_open())
    {
        string line;

        while (getline(inputFile, line))
        {
            cout << line << endl;
        }

        inputFile.close();
    }
    else
    {
        cout << "Unable to open the file ticket.txt." << endl;
    }
    cout << "\n\n\t";
    system("pause");
}
int resetfile()
{
rereset:
    system("cls");
    cout << ">> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\t\t\tThe action you are going to perform will reset all records and it can't be redone";
    cout << "\n\n\t\t\t\t\t\tAre you sure you want to proceed?";
    cout << "\n\n\n\t\t\t\t1. Yes erase data\t\t\t2. No don't erase\n";
    cout << "\n>> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >> >>\n ";
    cout << "\n\tChosse the preferred option: ";
    cin >> erasechoice;
    if (erasechoice == '1')
    {
        ofstream outputFile("ticket.txt");
        outputFile.close();
        resetseats();
        system("cls");
        cout << "\n\tYour files are erased successfully, Redirecting to home...";
        cout << "\n\n\t";
        system("pause");
        return false;
    }
    else if (erasechoice == '2')
    {
        system("cls");
        cout << "\n\tYour files are not erased, Redirecting to home...";
        cout << "\n\n\t";
        system("pause");
        return false;
    }
    else
    {
        goto rereset;
    }
}

void resetseats()
{
    int array[3][3][3][101];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 101; l++)
                    array[i][j][k][l] = 0;
            }
        }
    }

    ofstream outfile("array_data.txt");
    if (outfile.is_open())
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 101; l++)
                        outfile << array[i][j][k][l] << " ";
                }
                outfile << endl;
            }
        }
        outfile.close();
        cout << "Data saved to file." << endl;
    }
    else
    {
        cout << "Failed to open the file." << endl;
    }
}

#include<iostream>
#include<vector>
using namespace std;
class MOVIE
{
protected:
    string Title;
    string Genre;
    string Duration;
    double Rating;
public:
    MOVIE(string t,string g,string d,double r)
    {
        Title=t;
        Genre=g;
        Duration=d;
        Rating =r;
    }
    string get_title()
    {
        return Title;
    }
    string get_genre()
    {
        return Genre;
    }
    string get_duration()
    {
        return Duration;
    }
    double get_rating()
    {
        return Rating;
    }
    virtual double get_price()=0;
    virtual void details()
    {
        cout<<"Title     : "<<get_title()<<endl;
        cout<<"Genre     : "<<get_genre()<<endl;
        cout<<"Durration : "<<get_duration()<<endl;
        cout<<"Rating    : "<<get_rating()<<endl;
    }
};
class REG_MOVIE:public MOVIE
{
protected:
    double Price;
public:
    REG_MOVIE(string t,string g,string d,double p,double r):MOVIE(t,g,d,r)
    {
        Price=p;
    }
    double get_price()
    {
        return Price;
    }
    void details()
    {
        MOVIE::details();
        cout<<"Price     : "<<get_price()<<endl;
    }
};
class THREE_D_MOVIE:public MOVIE
{
protected:
    double Price;
    double Ext_Charges;
public:
    THREE_D_MOVIE(string t,string g,string d,double p,double ec,double r):MOVIE(t,g,d,r)
    {
        Price=p;
        Ext_Charges=ec;
    }
    double get_price()
    {
        return Price+Ext_Charges;
    }
    void details()
    {
        MOVIE::details();
        cout<<"Price     : "<<get_price()<<endl;
    }
};

class COSTUMER
{
protected:
    string Name;
    string Email;
    string Type;
    string Password;
public:
    COSTUMER(string n,string t,string e,string p)
    {
        Name=n;
        Type=t;
        Email=e;
        Password=p;
    }
    string get_name()
    {
        return Name;
    }
    string get_type()
    {
        return Type;
    }


    string get_email()
    {
        return Email;
    }
    string get_password()
    {
        return Password;
    }
    virtual double discounted_rate()=0;
};
class REG_COSTUMER:public COSTUMER
{
protected:
    double Discounted_Rate;
public:
    REG_COSTUMER(string n,string t,double dr,string e,string p):COSTUMER(n,t,e,p)
    {
        Discounted_Rate=dr;
    }
    double discounted_rate()
    {
        return Discounted_Rate;
    }
};
class VIP_COSTUMER:public COSTUMER
{
protected:
    double Discounted_Rate;
    int Loyality_Points;
public:
    VIP_COSTUMER(string n,string t,double dr,int lp,string e,string p):COSTUMER(n,t,e,p)
    {
        Discounted_Rate=dr;
        Loyality_Points=lp;
    }
    double discounted_rate()
    {
        return Discounted_Rate;
    }
    int set_loyality_points(int lp)
    {
        Loyality_Points=lp;
    }
    int get_loyality_points()
    {
        return Loyality_Points;
    }
};
class TICKET
{
protected:
    string mov;
    string cos;
    int rw;
    int cl;
    double costumer_discount;
    double moviprice;
public:
    TICKET()
    {
    int rw;
    int cl;
    }
    void set_m(string m)
    {
        mov=m;
    }
    void set_cd(double cd)
    {
        costumer_discount=cd;
    }
    void set_md(double movdis)
    {
        moviprice=movdis;
    }
    double prd()
    {
        return ((costumer_discount/100)*moviprice);
    }
    void set_c(string c)
    {
        cos=c;
        cout<<cos;
    }
    void set_s(int r,int c)
    {
        rw=r;
        cl=c;
    }
    void get_seat()
    {
        cout<<"Row "<<rw<<" Col "<<cl;
    }
    void details()
    {
        cout<<"Ticket Details    :"<<endl;
        cout<<endl;
        cout<<"Name              : "<<cos<<endl;
        cout<<"Movie             : "<<mov<<endl;
        cout<<"Seat              : ";
        get_seat();
        cout<<endl;
        cout<<"Orignal Price     : "<<moviprice<<endl;
        cout<<"Discount          : "<<costumer_discount<<"%"<<endl;
        cout<<"Discounted Price  : "<<moviprice-prd()<<endl;
    }
};

class MOVIE_BOOKING
{
protected:
    vector <MOVIE *> movies;
    vector <COSTUMER *>costumers;
public:
    MOVIE_BOOKING()
    {
        movies.push_back(new REG_MOVIE("The Matrix","Sci-Fi","136",10,3.6));
        movies.push_back(new REG_MOVIE("The Lion","Animation","88",9,4.2));
        movies.push_back(new THREE_D_MOVIE("Avatar","Sci-Fi","162",12,3,3.9));
        movies.push_back(new THREE_D_MOVIE("Jurassic World","Action","124",11,2.5,4.9));

        costumers.push_back(new REG_COSTUMER("Umar","REG",5,"umar@gmail.com","pass1"));
        costumers.push_back(new REG_COSTUMER("Abubakar","REG",5,"abubakar@gmail.com","pass1"));
        costumers.push_back(new VIP_COSTUMER("Ali","VIP",10,100,"ali@gmail.com","pass1"));
        costumers.push_back(new VIP_COSTUMER("Usama","VIP",10,210,"usama@gmail.com","pass1"));
    }
    void add_movie()
    {
        int check=1;
        while(check==1)
        {
        cout<<"1. Regular Movie             2. 3D-Movie"<<endl;
        int choice;
        cin>>choice;
        check=0;
        if(choice==1)
        {
            string title,genre,duration;
            double rating,price;
            cout<<"Enter Movie Title ";
            cin>>title;
            cout<<endl;
            cout<<"Enter Genre ";
            cin>>genre;
            cout<<endl;
            cout<<"Enter Duration ";
            cin>>duration;
            cout<<endl;
            cout<<"Enter Rating ";
            cin>>rating;
            cout<<endl;
            cout<<"Enter Price : ";
            cin>>price;
            cout<<endl;
            movies.push_back(new REG_MOVIE(title,genre,duration,price,rating));
        }

        if(choice==2)
        {
            string title,genre,duration;
            double rating,price,extracharges;
            cout<<"Enter Movie Title ";
            cin>>title;
            cout<<endl;
            cout<<"Enter Genre ";
            cin>>genre;
            cout<<endl;
            cout<<"Enter Duration ";
            cin>>duration;
            cout<<endl;
            cout<<"Enter Rating ";
            cin>>rating;
            cout<<endl;
            cout<<"Enter Price : ";
            cin>>price;
            cout<<endl;
            cout<<"Enter Extra_charges : ";
            cin>>extracharges;
            cout<<endl;
            movies.push_back(new THREE_D_MOVIE(title,genre,duration,price,extracharges,rating));
        }
        if(choice!=1 && choice!=2)
        {
            cout<<"Invalid Output Enter Again "<<endl;
            check=1;
        }
        }
    }


    void add_costumer()
    {
        cout<<"1.   Regular Costumer            2.  VIP Costumer"<<endl;
        int choice,check;
        check=0;
        cin>>choice;
        if(choice==1)
        {
            string name,type,password,email;
            double dis_rate=5;
            cout<<"Enter Name : ";
            cin>>name;
            cout<<endl;
            cout<<"Enter Email : ";
            cin>>email;
            cout<<endl;
            cout<<"Enter Password : ";
            cin>>password;
            cout<<endl;
            costumers.push_back(new REG_COSTUMER(name,"Reg",dis_rate,email,password));
        }

                if(choice==2)
        {
            string name,password,email;
            double dis_rate=10;
            double loyal=1;
            cout<<"Enter Name : ";
            cin>>name;
            cout<<endl;
            cout<<"Enter Email : ";
            cin>>email;
            cout<<endl;
            cout<<"Enter Password : ";
            cin>>password;
            cout<<endl;
            costumers.push_back(new VIP_COSTUMER(name,"VIP",dis_rate,loyal,email,password));
        }
        if(choice!=1 && choice!=2)
        {
            cout<<"Invalid Output Enter Again "<<endl;
            check+=1;
        }
    }
    template <class T,class U>
    T* smtc(U index)
    {
        system("cls");
        cout<<endl;
        cout<<"Movie # "<<index<<" "<<movies[index-1]->get_title()<<" Selected "<<endl;
        set_mon(movies[index-1]->get_title());
        set_movdis(movies[index-1]->get_price());
        cout<<endl;
        cout<<endl;
    }
    void select_movie()
    {
        int c=1;
        while(c==1)
        {
        c=0;
        print_movies();
        cout<<"Select Movie Number From Above ";
        int index;
        cin>>index;
        cout<<endl;
        int r=0;
        if(index>0 && index<=movies.size())
        {
            smtc<MOVIE*,int>(index);
            r=1;
//cout<<"Movie # "<<index<<" "<<movies[index-1]->get_title()<<" Selected "<<endl;


        int rows=5, cols=5;
    vector<vector<bool>> seats(rows, vector<bool>(cols, false));

    int choice;
    int row, col;
    while (true) {
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"1. Display Seat Map"<<endl;
        cout<<"2. Book a Seat"<<endl;
        cout<<"3. Quit"<<endl;
        cout<<"4. Get Ticket"<<endl;
        cout<<"Enter your choice: ";
        cin >> choice;
        cout<<endl;
        cout<<endl;

        switch (choice) {
            case 1:
                system("cls");
                cout<<endl;
                cout<<endl;
                displaySeats(seats, rows, cols);
                cout<<endl;
                cout<<endl;
                break;
            case 2:
                cout<<endl;
                cout<<endl;
                cout<<"Enter row number (0-" << rows - 1 << "): ";
                cin>>row;
                cout<<"Enter column number (0-" << cols - 1 << "): ";
                cin>>col;
                set_seat(row,col);
                bookSeat(seats, row, col);
                cout<<endl;
                cout<<endl;
                break;
            case 3:
                cout << "Exiting the program."<<endl;
                cout<<endl;
                abort();
            case 4:
                system("cls");
                cout<<endl;
                cout<<endl;
                cout<<endl;
                t1.details();
                cout<<endl;
                cout<<endl;
                cout<<endl;
                abort();
                break;
            default:
                cout << "Invalid choice. Please try again."<<endl;
                cout<<endl;
                cout<<endl;
        }
    }
        }
        if(r==0)
        {
            system("cls");
            cout<<"Wrong Index Enter Again "<<endl;
            c=1;
        }
        }
    }
    void print_movies()
    {
        cout<<"Available Movies "<<endl;
        cout<<endl;
        for(int i=0;i<movies.size();i++)
        {
            cout<<"Movie # "<<i+1<<endl;
            movies[i]->details();
            cout<<endl;
        }
        cout<<endl;
    }

        void print_costumers()
    {
        cout<<"Costumers "<<endl;
        cout<<endl;
        for(int i=0;i<costumers.size();i++)
        {
            cout<<"Costumer # "<<i+1<<endl;
            cout<<"Name     : "<<costumers[i]->get_name();
            cout<<endl;
            cout<<"Email    : "<<costumers[i]->get_email();
            cout<<endl;
            cout<<"Password : "<<costumers[i]->get_password();
            cout<<endl;
            if(costumers[i]->get_type()=="VIP")
            {
                cout<<costumers[i]->get_type();
                cout<<endl<<endl;
            }
            cout<<endl;
            cout<<endl;
        }
        cout<<endl;
    }

    void displaySeats(const vector<vector<bool>>& seats, int rows, int cols) {
    cout<<endl;
    cout<<"       Seat Map      "<<endl;
    cout<<endl;

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if (seats[i][j])
            {
                cout<<"X ";
            }
            else{
                cout<<"O ";
            }
        }
        cout<<endl;
    }

    cout<<endl;
}

void bookSeat(vector<vector<bool>>& seats, int row, int col) {
    if (row >= 0 && row < seats.size() && col >= 0 && col < seats[0].size())
    {
        if (!seats[row][col])
        {
            seats[row][col] = true;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"Seat booked successfully."<<endl;
        } else
        {
            system("cls");
            cout<<"Sorry, the seat is already booked."<<endl;
        }
    }
    else{
        cout<<"Invalid seat selection."<<endl;
    }
}

    void login()
    {
        int g=1;
        while(g==1)
        {
            g=0;
            print_costumers();
            cout<<"Enter Email And Password Frorm above List to login "<<endl;
            string email;
            string password;
            cout<<"Enter Email : ";
            cin>>email;
            cout<<"Enter Password : ";
            cin>>password;
            int s=0;
        for(int i=0;i<costumers.size();i++)
        {
            if(costumers[i]->get_email()==email && costumers[i]->get_password()==password)
            {
                system("cls");
                cout<<"You are now loged in"<<endl;
                set_csn(costumers[i]->get_name());
                set_csd(costumers[i]->discounted_rate());
                cout<<endl;
                s=1;
                select_movie();

            }
            }
            if(s==0)
            {
                system("cls");
                cout<<"Invalid Login"<<endl;
                g=1;
            }
        }
}
TICKET t1;
        void set_csn(string cost)
        {
            t1.set_c(cost);
        }
        void set_mon(string mn)
        {
            t1.set_m(mn);
        }
        void set_seat(int r,int c)
        {
            t1.set_s(r,c);
        }
        void set_csd(double cd)
        {
            t1.set_cd(cd);
        }
        void set_movdis(double pr)
        {
            t1.set_md(pr);
        }
};
int main()
{
    MOVIE_BOOKING mb;
    cout<<"1. Admin         2. Costumer"<<endl;
    int choice;
    cin>>choice;
    cout<<endl;
    system("cls");
    if(choice==1)
    {
        char c='c';
        while(c=='c')
        {
    cout<<"1. Add Movie"<<endl;
    cout<<"2. Add Costumer"<<endl;
    cout<<"3. Display Movies"<<endl;
    cout<<"4. Display Costumers"<<endl;
    cout<<"5. Switch To Costumer Mode"<<endl;
    cout<<"Choice = ";
    int ch;
    cin>>ch;
    cout<<endl;
    if(ch==1)
    {
        mb.add_movie();
        system("cls");
        cout<<"Movie Added Successfully "<<endl;
    }
    if(ch==2)
    {
        mb.add_costumer();
        system("cls");
        cout<<"Costumer Added Successfully "<<endl;
    }
    if(ch==3)
    {
        system("cls");
        mb.print_movies();
    }
    if(ch==4)
    {

        mb.print_costumers();
    }
    if((ch!=1)&&(ch!=2)&&(ch!=3)&&(ch!=4)&&(ch!=5))
    {
        system("cls");
        cout<<endl;
        cout<<endl;
        cout<<"Invalid Option plz enter your option again "<<endl;
        cout<<endl;
        cout<<endl;
    }
    if(ch==5)
    {
        choice=2;
        c='b';
    }
        }
    }
    if(choice==2)
    {
        cout<<"Costumer Mode "<<endl;
        cout<<"1.REGISTER           2.LOGIN"<<endl;
        int lr;
        cin>>lr;
        {
        if(lr==1)
        {
            system("cls");
            mb.add_costumer();
            cout<<endl<<"1. Add Costumer        2. Login";
            int ce;
            cin>>ce;
            if(ce==2)
            {
                lr=2;
            }
        }
        if(lr==2)
        {
            system("cls");
            cout<<endl;
            cout<<endl;
            mb.login();
        }
        }
    }
    return 0;
}

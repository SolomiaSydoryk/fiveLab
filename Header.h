#pragma once
#include <iostream>
#include <string>
using namespace std;
class Movie
{
public:
    int id;
    string title;
    string ranking;
    int release_date;
    int number_of_tickets;
    int ticket_price_in_uan;
    string comment;
    int GetID(){
        return id;
    }
    string GetTITLE(){
        return title;
    }
    string GetRANKING(){
        return ranking;
    }
    int GetRELEASE_DATE(){
        return release_date;
    }
    int GetNUMBER_OF_TICKETS(){
        return number_of_tickets;
    }
    int GetTICKET_PRICE_IN_UAN(){
        return ticket_price_in_uan;
    }
    string GetCOMMENT(){
        return comment;
    };
    Movie() {};
    enum filmType
    {
        ACTION,
        ADVENTURE,
        COMEDY,
        CRIME,
        CRIMINAL,
        DETECTIVE,
        DRAMA,
        FAMILY,
        FANTASY,
        HORRORS,
        MELODRAMA,
        ROMANCE,
        THRILLER
    };
    void calculateProfit()
    {
        int a = number_of_tickets;
        int b = ticket_price_in_uan;
        int c = a * b;
        cout << "Calculation of profit for a certain day (UAN) : " << c << endl;
    };
    Movie(int id, string title, string ranking, int release_date, int  number_of_tickets, int ticket_price_in_uan, string comment)
    {
        this->id = id;
        this->title = title;
        this->ranking = ranking;
        this->release_date = release_date;
        this->number_of_tickets = number_of_tickets;
        this->ticket_price_in_uan = ticket_price_in_uan;
        this->comment = comment;
    }
    void Print()
    {
        cout << "Id:\t\t" << id << endl;
        cout << "Title:\t\t" << title << endl;
        cout << "Ranking:\t" << ranking << endl;
        cout << "Release date:\t" << release_date << endl;
        cout << "Number of tickets:\t" << number_of_tickets << endl;
        cout << "Ticket price (UAN):\t" << ticket_price_in_uan << endl;
        cout << "Comment:\t" << comment << endl;
    }
    ~Movie()
    {

    }
};
class Cinema
{
public:
    string location;
    string GetLOCATION()
    {
        return location;
    }
    Cinema() {};
    Cinema(string location)
    {
        this->location = location;
    }
    void Print()
    {
        cout << "Location:\t" << location << endl;
    }
    ~Cinema()
    {
    }
    Movie arr[99];
    Movie arr_sorted[1];
    int numberelements = 0;
    void MovieAdd(Movie movie)
    {
        arr[numberelements] = movie;
        numberelements++;
    }
    void SortByYear()
    {
        for (int i = 0; i < numberelements; i++)
        {
            for (int j = 0; j < numberelements; j++)
                if (arr[j].release_date < arr[j + 1].release_date)
                {
                    arr_sorted[0] = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = arr_sorted[0];
                }
        }
        for (int n = 0; n < numberelements; n++)
        {
            arr[n].Print();
        }
    };
    void TheHighestRanking()
    {
        for (int i = 0; i < numberelements; i++)
        {
            for (int j = 0; j < numberelements; j++)
            {
                if (arr[j].ranking < arr[j + 1].ranking)
                {
                    arr_sorted[0] = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = arr_sorted[0];
                }
            }
        }
        arr[0].Print();
    };
};

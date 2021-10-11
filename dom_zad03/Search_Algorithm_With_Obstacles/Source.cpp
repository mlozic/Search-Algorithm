#include<iostream>
#include<chrono>
#include<thread>


using namespace std;
using namespace chrono;

void search_obst(char polje[20][40], int ax, int ay, int bx, int by, int xx, int xy) {
	system("cls");

	duration<int, std::milli> timespan(100);
	this_thread::sleep_for(timespan);


	for (unsigned i = 0; i < 20; i++)
	{
		for (unsigned j = 0; j < 40; j++) {

			if (i<10 && j==13)
			{
				polje[i][j] = '#';
			}

			else if (i == ay - 1 && j == ax - 1)
			{
				if (xx == ax && xy == ay)
				{
					polje[i][j] = 'X';
				}
				else
				{
					polje[i][j] = 'A';
				}
			}

			else if (i == by - 1 && j == bx - 1)
			{
				if (xx == bx && xy == by)
				{
					polje[i][j] = 'X';
				}
				else
				{
					polje[i][j] = 'B';
				}
			}

			else if (i == xy - 1 && j == xx - 1)
			{
				polje[i][j] = 'X';
			}

			else
			{
				polje[i][j] = '-';
			}
		}
	}
	for (unsigned i = 0; i < 20; i++)
	{
		for (unsigned j = 0; j < 40; j++) {

			cout << polje[i][j];
		}
		cout << endl;
	}


	if (xx == bx && xy == by)
	{
		throw exception(":)");
	}



	if (bx > xx)
	{
		if (xy<=10 && xx==13)
		{
			search_obst(polje, ax, ay, bx, by, xx, xy + 1);
		}
		else
		{
			search_obst(polje, ax, ay, bx, by, xx + 1, xy);
		}
	}
	if (bx < xx)
	{
		if (xy <= 10 && xx == 15)
		{
			search_obst(polje, ax, ay, bx, by, xx, xy + 1);
		}
		else
		{
			search_obst(polje, ax, ay, bx, by, xx - 1, xy);
		}
	}
	if (by < xy)
	{
		search_obst(polje, ax, ay, bx, by, xx, xy - 1);
	}
	if (by > xy)
	{
		search_obst(polje, ax, ay, bx, by, xx, xy + 1);
	}

}

int main() {

	char polje[20][40];
	int ax, ay, bx, by;
	bool netocno=true;

	do
	{
		system("cls");
		

		cout << "TRAZILICA" << endl
			<< "PRAVILO: X KOORDINATA TOCAKA 'A' I 'B' NE SMIJE BITI 14 JER SE NA TOM MJESTU NALAZI ZID, \nTAKODJER KOORDINATE TOCAKA MORAJU BITI UNUTAR POLJA 20X40!" << endl
			<< "________________________________________________________________________________________" << endl<<endl;

		if (!netocno)
		{
			cout << "Unjeli ste nevazecu koordinatu, molim unesite ponovo." << endl;
		}

		cout << "Unseite koordinate pocetne tocke! \nX Kordinata tocke A= ";
		cin >> ax;
		cout << endl << "Y koordinata tocke A= ";
		cin >> ay;
		cout << endl;
		cout << "Unseite koordinate krajnje tocke! \nX Kordinata tocke B= ";
		cin >> bx;
		cout << endl << "Y koordinata tocke B= ";
		cin >> by;

		if (ax==14 || bx==14 || ax<=0 || bx<=0 || ay<=0 || by<=0)
		{
			netocno = false;
		}
		else
		{
			netocno = true;
		}
	} while (!netocno);

	int xx = ax, xy = ay;

	try
	{
		search_obst(polje, ax, ay, bx, by, xx, xy);
	}
	catch (const exception& e)
	{
		cout << "Thats all folks " << e.what() << endl;
	}

	return 0;
}
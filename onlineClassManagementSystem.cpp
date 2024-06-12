#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
struct onlineClass{
	string name;
	string openedDaysPerWeek;
	string teacher;
	float durationInMonth;
	string contactPhoneNumber;
};
void clearScreen(){
	cout<<"\n";
	getch();
	system("cls");
}
class onlineClassBookingSystem{
	onlineClass classes[100];
	int count = 0;
	int bookedClass[100] = {};
	int bookedCount = 0;
	public:
		void addAClass(){
			system("cls");
			cout<<"Inputting an online class";
			cout<<"\n\nEnter class name : ";
			cin>>classes[count].name;
			cout<<"\nEnter teacher's name : ";
			cin>>classes[count].teacher;
			cout<<"\nEnter opened days per week : ";
			cin>>classes[count].openedDaysPerWeek;
			cout<<"\nEnter total duration in month(n) : ";
			cin>>classes[count].durationInMonth;
			cout<<"\nEnter contact number : ";
			cin>>classes[count].contactPhoneNumber;
			count++;
			cout<<"\nSuccessfully added a class!";
			clearScreen();
		}

		void viewAllClasses(){
			system("cls");
			cout<<setw(10)<<"No"<<setw(20)<<"Name"<<setw(20)<<"Teacher's name"<<setw(20)<<"Days per week"<<setw(20)
				<<"Total months"<<setw(20)<<"Contact number"<<endl;
			for(int i=0; i<count; i++){	
				cout<<setw(10)<<i+1<<setw(20)<<classes[i].name<<setw(20)<<classes[i].teacher<<setw(20)
					<<classes[i].openedDaysPerWeek<<setw(20)<<classes[i].durationInMonth<<setw(20)
					<<classes[i].contactPhoneNumber<<endl;
			}
			clearScreen();
		}
		
		void bookAClass(){
			system("cls");
			int index;
			
			cout<<setw(10)<<"No"<<setw(20)<<"Name"<<setw(20)<<"Teacher's name"<<setw(20)<<"Days per week"<<setw(20)
				<<"Total months"<<setw(20)<<"Contact number"<<endl;
			for(int i=0; i<count; i++){	
				cout<<setw(10)<<i+1<<setw(20)<<classes[i].name<<setw(20)<<classes[i].teacher<<setw(20)
					<<classes[i].openedDaysPerWeek<<setw(20)<<classes[i].durationInMonth<<setw(20)
					<<classes[i].contactPhoneNumber<<endl;
			}
			cout<<"\nEnter the number of the class that you want to book - ";
			cin>>index;
			index--;
			if(index < 0 || index > count) {
				cout<<"There is no class at that number!";
				clearScreen();
				return;
			}
			char y_n = 'n';
			cout<<"\nThis will book the class - \""<<classes[index].name<<"\" (y/n)";
			cin>>y_n;
			if(y_n == 'n'){
				cout<<"No booking done!";
				clearScreen();
				return;
			}
			cout<<"Booking done!";
			bookedClass[bookedCount] = index;
			bookedCount++;
			cout<<"\nContact "<<classes[index].contactPhoneNumber<<" for more details!";
			clearScreen();
		}
		
};

int main(){
	onlineClassBookingSystem o;
	int menu = 0;
	
	menuLabel:
	cout<<"Welcome from online class booking system!"
		<<"\n\n1. Add an online class."
		<<"\n\n2. View all online classes."
		<<"\n\n4. Book an online class."
		<<"\n\n0. Quit the system.\n\n";
	cin>>menu;

	if(menu == 0) return 0;
	else if(menu == 1) o.addAClass();
	else if(menu == 2) o.viewAllClasses();
	else if(menu == 3) o.bookAClass();
	
	goto menuLabel;
}

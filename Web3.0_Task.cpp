#include<bits/stdc++.h>
using namespace std;

string to_upper(string s); /*This function helps by converting all the inputted letters to uppercase therefore, if the user inputs any
                            of the letters of the input, upper or lower case by mistake it doesn't matter*/

class Slot{
    public:
    string slot_time;
    bool availability;
    int slot_no;
    int student_booked;
    static int count; // Unlike in badminton, 10 seats are available in each slot in Gym
    Slot(bool value, int no): availability(value), slot_no(no){
        if(count>10) availability = false; // This is only for Gym. Doesn't affect badminton since count in badminton is always 0
    }
    void book_Gym(int rollno){
        count++;
        student_booked = rollno;
    }
    void book_badminton(int rollno){
        student_booked = rollno;
        availability = false; // Since, the slot will be no longer available after booking
    }
}; 
int Slot :: count = 0; 

class Gym{
    public:
    vector <Slot> monthly_slots;
    vector <Slot> halfyearly_slots;
    Gym(){
        for(int i = 0; i<4; i++){
            monthly_slots.push_back(Slot(true,i+1));
            halfyearly_slots.push_back(Slot(true,i+1));
        }
        monthly_slots[0].slot_time = "7-8 AM - Slot 1";
        monthly_slots[1].slot_time = "8-9 AM - Slot 2";
        monthly_slots[2].slot_time = "5-6 PM - Slot 3";
        monthly_slots[3].slot_time = "6-7 PM - Slot 4";
        for(int i = 0; i<4; i++){
            halfyearly_slots[i].slot_time = monthly_slots[i].slot_time;
        }
    }
    void display_available_monthlySlots(){
        for(int i = 0; i<4; i++){
            if(monthly_slots[i].availability && halfyearly_slots[i].availability) cout<<monthly_slots[i].slot_time<<endl;
            else monthly_slots[i].availability = false;
        }
    }
    void display_available_halfyearlySlots(){
        for(int i = 0; i<4; i++){
            if(halfyearly_slots[i].availability) cout<<halfyearly_slots[i].slot_time<<endl;
        }
    }
    void Gym_Booking_Rules(){ // Only for Gym booking
        cout<<"Gym booking Rules:"<<endl;
        cout<<"Monthly slot booking starts only 10 days before the month start"<<endl;
        cout<<"Half-Yearly slot booking closes 10 days before a month start"<<endl;
    }

};

class Badminton : public Gym{
    public:
    vector <Slot> slots;
    Badminton(){
        for(int i = 0; i<4; i++){
            slots.push_back(Slot(true,i+1));
            slots[i].slot_time = monthly_slots[i].slot_time; // Inherited from Gym class
        }
    }
    void display_available_slots(){
        for(int i=0; i<4; i++){
            if(slots[i].availability) cout<<slots[i].slot_time<<endl;
        }
    }
};

class Student_Booking_history{
    public:
    bool flag = true;
    void display_history(int rollno, vector <Slot>& slots,int n){
        cout<<"Booking History:"<<endl;
        for(int i = 0; i<n; i++){
            if(slots[i].student_booked == rollno){
                cout<<slots[i].slot_time<<endl;
                flag = false;
            }
        }
        if(flag) cout<<"Booking history not available"<<endl;
    }
};
 
int main(){
    Gym gym;
    Badminton badminton;
    while(true){
        int rollno; 
        int temp = 0;
        cout<<"Enter your roll number:"<<endl;
        cin>>rollno;
        string sport;
        cout<<"Select the sport facility:"<<endl<<"Gym"<<"  "<<"Badminton"<<"   "<<"None(For Check booking history)"<<endl;
        cin>>sport;
        int slot_number;
        string slot_type;

        if(to_upper(sport) == "GYM" ){

            gym.Gym_Booking_Rules();
            cout<<"Do you want to book a monthly slot or half-yearly slot?(Enter monthly or half-yearly)"<<endl;
            cin>>slot_type;
            if(to_upper(slot_type) == "MONTHLY"){
                cout<<"Available montly slots for Gym:"<<endl;
                gym.display_available_monthlySlots();
                cout<<"Enter the slot number you want to book: "<<endl;
                cin>>slot_number;
                if(!(slot_number>=0 && slot_number<=4)) cout<<"Choose a valid slot"<<endl;
                else if(gym.monthly_slots[slot_number-1].availability){
                    gym.monthly_slots[slot_number-1].book_Gym(rollno);
                    cout<<"Slot "<<slot_number<<" has been succesfully booked"<<endl;
                }
                else if(!gym.monthly_slots[slot_number-1].availability) cout<<"This slot is already full"<<endl;
            }
            else if(slot_type == "half-yearly"){
                cout<<"Available half-yearly slots for Gym"<<endl;
                gym.display_available_halfyearlySlots();
                cout<<"Enter the slot number you want to book: "<<endl;
                cin>>slot_number;
                if(!(slot_number>=0 && slot_number<=4)) cout<<"Choose a valid slot"<<endl;
                else if(gym.halfyearly_slots[slot_number-1].availability){
                    gym.halfyearly_slots[slot_number-1].book_Gym(rollno);
                    cout<<"Slot "<<slot_number<<" has been succesfully booked"<<endl;
                }
                else if(!gym.halfyearly_slots[slot_number-1].availability) cout<<"This slot is already full"<<endl;
            }
            else cout<<"Invalid";
        }

        else if(to_upper(sport) == "BADMINTON"){

            cout<<"Available slots for Badminton:"<<endl;
            badminton.display_available_slots();
            cout<<"Enter the slot number you want to book: "<<endl;
            cin>>slot_number;
            if(!(slot_number>=0 && slot_number<=4)) cout<<"Choose a valid slot"<<endl;
            else if(!badminton.slots[slot_number-1].availability) cout<<"This slot has been already booked"<<endl;
            else if(badminton.slots[slot_number-1].availability){
                badminton.slots[slot_number-1].book_badminton(rollno);
                cout<<"Slot "<<slot_number<<" has been succesfully booked"<<endl;
            }

        }

        cout<<"Do you want to check your booking history(Yes/No)?"<<endl;
        string ans;
        cin>>ans;
        if(to_upper(ans) == "YES"){
            Student_Booking_history obj;
            // if(to_upper(sport) == "GYM" && to_upper(slot_type) == "MONTHLY")
            obj.display_history(rollno, gym.monthly_slots, gym.monthly_slots.size());
            // else if(to_upper(sport) == "GYM" && slot_type == "half-yearly") 
            obj.display_history(rollno, gym.halfyearly_slots, gym.halfyearly_slots.size());
            // else if(to_upper(sport) == "BADMINTON") 
            obj.display_history(rollno, badminton.slots, badminton.slots.size());
            temp = rollno;
        }
        cout<<"Do you want to book another slot for same or different student(Yes/No)"<<endl;
        cin>>ans;
        if(to_upper(ans) == "NO") break;
    }
}

string to_upper(string s){
    int i=0;
    while(s[i] != '\0'){
        s[i] = toupper(s[i]);
        i++;
    }
    return s;
}
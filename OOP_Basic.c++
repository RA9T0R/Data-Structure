#include <iostream>
using namespace std;

//   class
//   object
//   field -> public,protected,private
//   method  -> funtion

class Company{
    private:
        string founder = "Boss";
        string address = "Bangkok";
        // friend void showCompany(); //Friend Method
        friend class Employee; //Friend Class
    public :
        static int count; //Static Field
};

class Employee{ //abstract class กำหนดเป็น class ให้ class ลูกๆใช้คำสั่งต่างๆ
    // field & method
    public:
        //default Constructor
        Employee() { cout << "Create Empty Object" << endl; }
        //parameter Constructor and overloading 
        Employee(string n,int s) { 
            name = n;
            salary = s;
            cout << "Create Employee = " << n << " | Have salary : " << s << endl;
        }
        //setter method
        void setName(string n) { name = n; }
        void setSalary(int n) { salary = n; }
        //getter method
        string getName() { return name; }
        int getSalary() { return salary; }

        void showData(){
            cout << "Name = " << name << endl;
            cout << "Salary = " << salary << endl;
            cout << "---------------" << endl;
        }
        string address;
        int age;
        //Pure virtual method ถ้าใช้แล้วจะกำหนด object ของ Employee ไม่ได้
        virtual void about() = 0;
        //Friend Class
        void showCompany(){
            Company c;
            cout << "CEO = " << c.founder << endl;
            cout << "Address = " << c.address << endl;
        }   
    private:
        string name="no name"; //ค่าเริ่มต้น
        int salary=0;
};
//การสืบทอดคุณสมบัติ (Inheritance)
class IT : public Employee {
    public:
        IT() { cout << "Create IT Object" << endl; }
        IT(string n,int s) : Employee(n,s){Company::count++;}
        //Overriding Method
        void showData(){
            cout << "---IT Department---" << endl;
            cout << "   Name = " << getName() << endl;
            cout << "   Salary = " << getSalary() << endl;
            cout << "-------------------" << endl;
        }
        void about() {
            cout << " | Development Product | " << endl;
        }
};
class Sale : public Employee {
    public:
        Sale() { cout << "Create Sale Object" << endl; }
        Sale(string n,int s) : Employee(n,s) {Company::count++;}
        //Overriding Method
        void showData(){
            cout << "---Sale Department---" << endl;
            cout << "   Name = " << getName() << endl;
            cout << "   Salary = " << getSalary() << endl;
            cout << "-------------------" << endl;
        }
        void about() {
            cout << " | Sales Product | " << endl;
        }
};

int Company::count = 0; 
int main(){
    cout << "----------------!!! OOP !!!----------------" <<endl;
    cout << "-----------------Set Data-----------------" <<endl;
    IT emp1("jake",45000);
    emp1.showData(); //ใช้คำสั้ง บรรทัดที่ 62
    IT emp2("rudy",50000);
    emp2.showData();
    IT emp3("Golf",100000);
    emp3.showData();
    
    Sale emp4("Toon",20000);
    emp4.showData(); //ใช้คำสั้ง บรรทัดที่ 78
    Sale emp5("Iron",30000);
    emp5.showData();
    Sale emp6("koko",35000);
    emp6.showData();

    cout << "======================================================="<< endl;
    emp1.showCompany();
    cout << "Empolyee Total : " << Company::count << endl;
    emp1.about();
    cout << "IT Salary Total = " << emp1.getSalary()+emp2.getSalary()+emp3.getSalary() <<endl;
    emp4.about();
    cout << "Sale Salary Total = " << emp4.getSalary()+emp5.getSalary()+emp6.getSalary() << endl;
    cout << "-- All IT Employee Name --\n";
    cout << emp1.getName() << " , " << emp2.getName()<< " , "  << emp3.getName() <<  endl;
    cout << "-- All Sale Employee Name --\n";
    cout << emp4.getName() << " , " << emp5.getName()<< " , "  << emp6.getName() <<  endl;

    char choose;
    cout << "Do you want to change Salary In Data ? (Y/N) : ";
    cin >>  choose;
    if(choose=='Y' || choose=='y'){
        string department;
        int n,x;
        cout << "What department you want to change ? (IT/Sale) : ";
        cin >> department;
        if(department == "IT" || department == "it"){
            cout << "Who you want to change ? (1,2,3) : ";
            cin >> n;
            cout << "What new Salary : ";
            cin >> x;
            switch (n){
                case 1:emp1.setSalary(x); 
                    cout << "OK new data of emp1 is\n";
                    emp1.showData();
                    break;
                case 2:emp2.setSalary(x); 
                    cout << "OK new data of emp2 is\n";
                    emp2.showData();
                    break;
                case 3:emp3.setSalary(x); 
                    cout << "OK new data of emp3 is\n";
                    emp3.showData();
                    break;
            default : cout << "OK WE DONE\n"; break;
            }
        }else if(department == "Sale" || department == "sale"){
            cout << "Who you want to change ? (1,2,3) : ";
            cin >> n;
            cout << "What new Salary : ";
            cin >> x;
            switch (n){
                case 1:emp4.setSalary(x); 
                    cout << "OK new data of emp1 is\n";
                    emp4.showData();
                    break;
                case 2:emp5.setSalary(x); 
                    cout << "OK new data of emp2 is\n";
                    emp5.showData();
                    break;
                case 3:emp6.setSalary(x); 
                    cout << "OK new data of emp3 is\n";
                    emp6.showData();
                    break;
            default : cout << "OK WE DONE\n"; break;
            }
        }
    }else{
        cout << "Thank You :)\n";
    }
    return 0;
}

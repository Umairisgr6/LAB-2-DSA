//#include <iostream>
//using namespace std;
//
//class employee {
//public:
//    virtual double calc_salary() = 0; 
//};
//
//class FullTimeemployee : public employee {
//private:
//    double fixedSalary;
//
//public:
//    FullTimeemployee(double salary) : fixedSalary(salary) {}
//
//    double calc_salary()  {
//        return fixedSalary;
//    }
//};
//
//class PartTimeemployee : public employee {
//private:
//    double hourly_wage;
//    int working_hours;
//
//public:
//    PartTimeemployee(double rate, int hours) : hourly_wage(rate), working_hours(hours) {}
//
//    double calc_salary()  {
//        return hourly_wage * working_hours;
//    }
//};
//
//int main() {
//    FullTimeemployee fullTimeemployee(50000);
//    PartTimeemployee partTimeemployee(15, 80);
//
//    cout << "Full-time employee salary: " << fullTimeemployee.calc_salary() << endl;
//    cout << "Part-time employee salary: " << partTimeemployee.calc_salary() << endl;
//
//    return 0;
//}
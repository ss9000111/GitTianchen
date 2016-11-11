
#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <vector>

using namespace std;

class Signal {
private:
    int length;
    double max;
    double average;
    double data_average();
    void data_max();
    vector<double> data;
public:
    Signal();
    Signal(int num);
    Signal(string str);
    ~Signal();
    void display_menu();
    void choice(int choice);
    void offset(double offset);
    void scale(double scale);
    void normalize();
    void center();

    void operator+(double offset);
    void operator*(int scale);

    void sig_info();
    void save_file(string str);

    vector<double> data_in(){
        return data;
    }

    int data_length(){
        return length;
    }
    double data_maximum(){
        data_max();
        return max;
    }
    void set_max(double dmax){
        max = dmax;
    }
    double get_average(){
        return data_average();
    }
    void set_average(double avg){
        average = avg;
    }
    void set_data(vector<double> data1, vector<double> data2);
};

Signal::Signal() { //default constructor
    length = 0;
    max = 0;
    vector<double> data;
}

Signal::Signal(int num) { //constructor taking int number in
    string txt = ".txt";
    string file = "Raw_data_";

    file.push_back(num);//use push_back()
    file = file + txt;

    int i;
    FILE *file1 = fopen(file.c_str(), "r");
    if (file1 == NULL)
        printf("error can not open file");
    else

    fscanf(file1, "%d %f", &length, &max);

    vector<double> data[length];
    while (!feof(file1)) {
        fscanf(file1, "%f\n", &data[i++]);
    }
}


Signal::Signal(string name) { //constructor taking character pointer in
    string file = name + ".txt";
    int i = 0;

    FILE *file2 = fopen(file.c_str(), "r");
    if (file2 == NULL) {
        printf("error can not open file");
    }
    else

    fscanf(file2, "%d %f", &length, &max);

    vector<double> data[length];
    while (!feof(file2)) {
        fscanf(file2, "%f\n", &data[i++]);

    }
}

Signal::~Signal() { //Destructor
}

void Signal::display_menu() {
    cout << "Choose an option:\n"
    		"1. Signal Info\n"
            "2. Offset\n"
            "3. Scale\n"
            "4. Normalize\n"
            "5. Center\n"
            "6. Save Signal\n";
}
void Signal::offset(double offet) {
    operator+(offset);
}//operator part

void Signal::scale(double scale) {
    operator*(scale);
}          //operator part

void Signal::normalize() {
    operator *(1/max);
}//operator part

void Signal::center() {
    double avg = data_average();
    operator +(-(avg));
}//operator part

void Signal::operator +(double offset){
    int i = 0;
    while (i < length){
        data[i] += offset;
    }
}//operator part

void Signal::operator *(int scale){
    int i = 0;
    while(i < length){
        data[i] *= scale;
    }
}//operator part

void Signal::choice(int choice) {
    double offset, scale;
    string file = "Raw_data_11";
    switch (choice) {
        case 1:
            sig_info();
            break;
        case 2:
            cout << "Enter the offset value:";
            cin >> offset;
            data operator+(offset);
            data_max();
            break;
        case 3:
            cout << "Enter the scale you want to multiply:";
            cin >> scale;
            data operator*(scale);
            break;
        case 4:
            normalize();
            break;
        case 5:
            center();
            break;
        case 6:
            save_file(file);
            break;
        default:
            cerr << "Invalid option, please enter from 1 to 5" << endl;
            break;
    }
}

void Signal::offset(double offset) {
    operator+(offset);
}
void Signal::scale(double scale) {
    operator*(scale);
}

void Signal::normalize() {
    operator *(1/max);
}

void Signal::center() {
    double avg = average();
    operator +(-(avg));
}
double Signal::data_average() { //method for average
    int i = 0;
    double total = 0, avg;
    while (i < length) {
        total += data[i];
        i++;
    }
    avg = total / length;
    return avg;
}

void Signal::data_max() { //method for maximum number
    int i = 0;
    double maximum = 0;
    while (i < length) {
        if (data[i] > maximum) {
            maximum = data[i];
        }
        i++;
    }
    max = maximum;
}

void Signal::sig_info() {
    cout << "Length is : " << length << endl;
    cout << "Maximum value : " << max << endl;
    cout << "Average is : " << average << endl;
}

void Signal::save_file(string name) {
    string txt = ".txt";
    string file = name + txt;
    int i = 0;
    FILE* file1 = fopen(file.c_str(), "w");
    if (file1 == NULL) {
        printf("Error can not open file");

    }
    fprintf(file1, "%d %f\n", length, max);
    while (i < length) {
        fprintf(file1, "%f\n", data[i]);
        i++;
    }
    fclose(file1);

    cout << "file saved " << file1; //Prompts on success.
}

void Signal::set_data(vector<double> data1, vector<double> data2){
    int i = 0;
    while (i < length){
        data[i] = data1[i] + data2[i];
        i++;
    }
}


int main(int argc, char** argv) {
    string input;
    int file_num, choice = 0;
    if (argc < 2) {
        cout << "Please enter the file name:"; //argc should be more than 2
        cin >> input;
        Signal signal1(input);
        while (choice != 6) {
            signal1.display_menu();
            cin >> choice;
            signal1.choice(choice);
        }
    }
    else if (argv[1][0] == '-' && argv[1][1] == 'n') { //-n
        file_num = atoi(argv[2]);
        Signal signal1(file_num);
        while (choice != 6) {
            signal1.display_menu();
            cin >> choice;
            signal1.choice(choice);
        }
    }
    else if (argv[1][0] == '-' && argv[1][1] == 'f') { //-f
        Signal signal1(argv[2]);
        while (choice != 6) {
            signal1.display_menu();
            cin >> choice;
            signal1.choice(choice);
        }
    } else { //exception handling
        std::cout << "Invalid input\n -n follow a number\n -f follow a filename.\n";
        return 1;
    }
    return 0;
}

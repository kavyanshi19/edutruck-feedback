/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ============================
// Class Definitions
// ============================

class Feedback {
public:
    int studentId;
    int courseId;
    string text;
    int rating;  // 1 to 5

    Feedback(int sId, int cId, string t, int r)
        : studentId(sId), courseId(cId), text(t), rating(r) {}
};

class Course {
public:
    int courseId;
    string courseName;
    vector<Feedback> feedbackList;

    Course(int id, string name) : courseId(id), courseName(name) {}

    void addFeedback(Feedback fb) {
        feedbackList.push_back(fb);
    }
};

class Student {
public:
    int studentId;
    string name;

    Student(int id, string n) : studentId(id), name(n) {}

    void submitFeedback(Course &course) {
        string feedbackText;
        int rating;

        cout << "\n??  " << name << ", enter your feedback for " << course.courseName << ": ";
        cin.ignore();
        getline(cin, feedbackText);

        cout << "? Enter your rating (1-5): ";
        cin >> rating;

        Feedback fb(studentId, course.courseId, feedbackText, rating);
        course.addFeedback(fb);
        cout << "? Feedback submitted successfully!\n";
    }
};

class Report {
public:
    Course &course;

    Report(Course &c) : course(c) {}

    void generateSummary() {
        int total = course.feedbackList.size();
        if (total == 0) {
            cout << "\nNo feedback yet for " << course.courseName << ".\n";
            return;
        }

        int totalRating = 0;
        cout << "\n?? Feedback Report for " << course.courseName << endl;
        cout << "-------------------------------------------\n";
        for (auto &fb : course.feedbackList) {
            totalRating += fb.rating;
            cout << "? Rating: " << fb.rating << " | Feedback: " << fb.text << endl;
        }
        double avg = (double)totalRating / total;
        cout << "-------------------------------------------\n";
        cout << "Total Feedback: " << total << endl;
        cout << "Average Rating: " << avg << "/5\n";
        cout << "-------------------------------------------\n";
    }
};

class Faculty {
public:
    int facultyId;
    string name;

    Faculty(int id, string n) : facultyId(id), name(n) {}

    void viewReport(Course &course) {
        Report report(course);
        report.generateSummary();
    }
};

// ============================
// Main Program
// ============================

int main() {
    // Create Course and Faculty
    Course course1(101, "Software Engineering");
    Faculty faculty1(201, "Dr. Smith");

    // Create Students
    Student student1(1, "Kavyanshi");
    Student student2(2, "Amit");

    cout << "\n---- EduTrack Course Feedback System ----\n";

    // Students give feedback
    student1.submitFeedback(course1);
    student2.submitFeedback(course1);

    // Faculty views report
    faculty1.viewReport(course1);

    cout << "\nThank you for using EduTrack!\n";
    return 0;
}

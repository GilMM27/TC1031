/*
    act1-3.cpp
    data-structure
    Created by Ricardo Gaspar Ochoa, Gilberto Malagamba Montejo and Gerardo Fregoso Jimenez on 08/09/24.
    Este programa Solicita al usuario las fechas de inicio y fin de la búsqueda de información, registros en un archivo TXT, creando uno nuevo con los registros solicitados.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Structure to hold each log entry
struct LogEntry {
    string month;
    int day;
    string time;
    string ip;
    string message;

    // Function to convert month into an integer for sorting purposes
    int getMonthValue() const {
        if (month == "Jan") return 1;
        if (month == "Feb") return 2;
        if (month == "Mar") return 3;
        if (month == "Apr") return 4;
        if (month == "May") return 5;
        if (month == "Jun") return 6;
        if (month == "Jul") return 7;
        if (month == "Aug") return 8;
        if (month == "Sep") return 9;
        if (month == "Oct") return 10;
        if (month == "Nov") return 11;
        if (month == "Dec") return 12;
        return 0;
    }
};

// Function to compare two log entries by date
bool compareEntries(const LogEntry &a, const LogEntry &b) {
    if (a.getMonthValue() != b.getMonthValue()) {
        return a.getMonthValue() < b.getMonthValue();
    } else if (a.day != b.day) {
        return a.day < b.day;
    } else {
        return a.time < b.time;
    }
}

void readLogFile(const string &filename, vector<LogEntry> &logEntries) {
    ifstream file(filename);
    string line;
    
    while (getline(file, line)) {
        stringstream ss(line);
        LogEntry entry;
        ss >> entry.month >> entry.day >> entry.time >> entry.ip;
        getline(ss, entry.message);
        logEntries.push_back(entry);
    }
    file.close();
}

void displayEntries(const vector<LogEntry> &entries, const string &startMonth, int startDay, const string &endMonth, int endDay) {
    int startMonthValue = LogEntry{startMonth, 0, "", "", ""}.getMonthValue();
    int endMonthValue = LogEntry{endMonth, 0, "", "", ""}.getMonthValue();

    for (const auto &entry : entries) {
        int entryMonthValue = entry.getMonthValue();
        if ((entryMonthValue > startMonthValue || (entryMonthValue == startMonthValue && entry.day >= startDay)) &&
            (entryMonthValue < endMonthValue || (entryMonthValue == endMonthValue && entry.day <= endDay))) {
            cout << entry.month << " " << entry.day << " " << entry.time << " " << entry.ip << entry.message << endl;
        }
    }
}


void saveFilteredEntriesToFile(const string &filename, const vector<LogEntry> &entries, const string &startMonth, int startDay, const string &endMonth, int endDay) {
    ofstream outFile(filename);
    
    if (!outFile.is_open()) {
        cerr << "Error creating file: " << filename << endl;
        return;
    }
    
    cout << "Saving filtered entries to file: " << filename << endl;

    int startMonthValue = LogEntry{startMonth, 0, "", "", ""}.getMonthValue();
    int endMonthValue = LogEntry{endMonth, 0, "", "", ""}.getMonthValue();

    for (const auto &entry : entries) {
        int entryMonthValue = entry.getMonthValue();
        if ((entryMonthValue > startMonthValue || (entryMonthValue == startMonthValue && entry.day >= startDay)) &&
            (entryMonthValue < endMonthValue || (entryMonthValue == endMonthValue && entry.day <= endDay))) {
            
            // Write the entry to the file
            outFile << entry.month << " " << entry.day << " " << entry.time << " " << entry.ip << entry.message << endl;
        }
    }

    if (outFile.good()) {
        cout << "Filtered entries saved successfully!" << endl;
    } else {
        cerr << "Error writing filtered entries to file." << endl;
    }
    
    outFile.close();
}

int main() {
    vector<LogEntry> logEntries;
    
    // Step 1: Read log file and store entries using a relative or absolute path
    readLogFile("./bitacora.txt", logEntries);  // Adjust to your actual path
    
    if (logEntries.empty()) {
        cerr << "No log entries found, or file could not be read." << endl;
        return 1;
    }
    
    // Step 2: Sort the log entries by date
    sort(logEntries.begin(), logEntries.end(), compareEntries);
    
    // Step 3: Ask user for start and end dates
    string startMonth, endMonth;
    int startDay, endDay;
    cout << "Enter the start month (e.g., Aug): ";
    cin >> startMonth;
    cout << "Enter the start day: ";
    cin >> startDay;
    cout << "Enter the end month (e.g., Oct): ";
    cin >> endMonth;
    cout << "Enter the end day: ";
    cin >> endDay;
    
    // Step 4: Display entries between the given date range
    displayEntries(logEntries, startMonth, startDay, endMonth, endDay);
    
    // Step 5: Save the filtered entries to a file
    saveFilteredEntriesToFile("./bitacoraSorted.txt", logEntries, startMonth, startDay, endMonth, endDay);  // Adjust path as needed
    
    return 0;
}

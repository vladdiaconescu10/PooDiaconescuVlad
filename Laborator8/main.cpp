#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct WordCount {
    string word;
    int count;
};

struct CompareWordCount {
    bool operator()(const WordCount& a, const WordCount& b) {
        if (a.count != b.count) {
            return a.count < b.count;
        }
        return a.word > b.word;
    }
};

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "Eroare la deschiderea fisierului\n";
        return 1;
    }

    string phrase;
    getline(file, phrase);
    file.close();

    string separators = " ,?!.";
    map<string, int> wordMap;

    size_t start = phrase.find_first_not_of(separators);

    while (start != string::npos) {
        size_t end = phrase.find_first_of(separators, start);
        string word = phrase.substr(start, end - start);

        for (char& c : word) {
            if (c >= 'A' && c <= 'Z') {
                c += 32;
            }
        }

        wordMap[word]++;

        if (end == string::npos) break;
        start = phrase.find_first_not_of(separators, end);
    }

    priority_queue<WordCount, vector<WordCount>, CompareWordCount> pq;

    for (auto const& pair : wordMap) {
        pq.push({ pair.first, pair.second });
    }

    while (!pq.empty()) {
        WordCount current = pq.top();
        cout << current.word << " => " << current.count << '\n';
        pq.pop();
    }

    return 0;
}
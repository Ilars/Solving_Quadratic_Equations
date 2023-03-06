#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

vector<float> readCoefs(string infile_path) {
	ifstream fin(infile_path);
    vector<float> coefs(3);
    for (int i = 0; i < 3; i++) {
        fin >> coefs[i];
    }
    return coefs;
}

float findDiscriminant(const vector<float> &coefs) {
    return (coefs[1]*coefs[1]) - 4 * coefs[0] * coefs[2];
}

vector<float> quaEquationSolver(const vector<float> &coefs) {
    vector<float> answers(3);
    float discriminant = findDiscriminant(coefs);
    if (coefs[0] == 0) {
        answers[2] = -1;
    }
    else if (discriminant == 0) {
        answers[0] = -coefs[1] / (2 * coefs[0]);
        answers[2] = 1;
    }
    else if (discriminant > 0) {
        answers[0] = (-coefs[1]+sqrt(discriminant)) / (2 * coefs[0]);
        answers[1] = (-coefs[1]-sqrt(discriminant)) / (2 * coefs[0]);
        answers[2] = 2;
    }
    else if (discriminant < 0) {
        answers[2] = 0;
    }
    return answers;
}

void writeAnswers(const vector<float> &answers, string outfile_path) {
    ofstream fout(outfile_path);
    if (answers[2] == 0) {
        fout << "No answer on the real field of numbers";
    }
    if (answers[2] == 1) {
        fout << answers[0];
    }
    if (answers[2] == 2) {
        fout << answers[0] << "\n";
        fout << answers[1];
    }
    if (answers[2] == -1) {
        fout << "This is not quadratic equation";
    }
}

int main() {
    string infilePath = "input.txt";
    string outfilePath = "output.txt";
	
    vector<float> coefs;
    vector<float> answers;
	
    coefs = readCoefs(infilePath);
    answers = quaEquationSolver(coefs);
    writeAnswers(answers, outfilePath);
    return 0;
}

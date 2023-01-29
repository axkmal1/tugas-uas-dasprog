#include <iostream>
#include <algorithm>
using namespace std;

//struct untuk menyimpan data
struct Data {
    int values[100];
    int count;
};

//fungsi untuk menghitung rata rata
double average(Data data) {
    int sum = 0;
    for (int i = 0; i < data.count; i++) {
        sum += data.values[i];
    }
    return (double)sum / data.count;
}

//fungsi untuk menghitung median
double median(Data data) {
    sort(data.values, data.values + data.count);
    if (data.count % 2 == 0) {
        return (data.values[data.count / 2 - 1] + data.values[data.count / 2]) / 2.0;
    } else {
        return data.values[data.count / 2];
    }
}

//fungsi untuk menghitung modus
double modus(Data data) {
    int maxCount = 0, modus = -1;
    for (int i = 0; i < data.count; i++) {
        int count = 0;
        for (int j = 0; j < data.count; j++) {
            if (data.values[j] == data.values[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            modus = data.values[i];
        }
    }
    return modus;
}

//fungsi main
int main() {
    Data data;
    cout << "Masukkan jumlah nilai: ";
    cin >> data.count;
    cout << "Masukkan nilai: ";
    for (int i = 0; i < data.count; i++) {
        cin >> data.values[i];
    }
    cout << "Rata-rata: " << average(data) << endl;
    cout << "Median: " << median(data) << endl;
	cout << "Modus: " << modus(data) << endl;
    return 0;
}

#include<iostream>

using namespace std;

typedef struct BuyTime{
	int startTime;
	int endTime;
}B;

B H[2001], W[2001];
int n,chattime=0;
void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> H[i].startTime >> H[i].endTime;
	}
	for (int i = 0; i < n; i++) {
		cin >> W[i].startTime >> W[i].endTime;
	}
}

void sovle() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (H[j].startTime <= W[i].startTime&&W[i].endTime <= H[j].endTime) {
				chattime += (W[i].endTime - W[i].startTime);
			}
			else if (W[i].startTime <= H[j].startTime&&H[j].endTime <= W[i].endTime) {
				chattime += (H[j].endTime - H[j].startTime);
			}
			else if (H[j].startTime <= W[i].startTime&&W[i].startTime <= H[j].endTime) {
				chattime += (H[j].endTime - W[i].startTime);
		    }
			else if (H[j].startTime < W[i].endTime&&W[i].endTime < H[j].endTime) {
				chattime += (W[i].endTime - H[j].startTime);
			}

		}
	}
}

int main() {
	init();
	sovle();
	cout<<chattime;
}
